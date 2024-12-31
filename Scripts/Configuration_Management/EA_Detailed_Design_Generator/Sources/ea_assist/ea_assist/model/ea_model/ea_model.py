import win32com.client
import sys
import json
import re

from .element import Package, App, Repository, Element, Method, Attribute, Parameter, TaggedValue

class EAInstance:
    GUID_PACKAGES = "packages"
    GUID_MODELS = "models"
    GUID_ELEMENTS = "elements"
    GUID_METHODS = "methods"
    GUID_ATTRIBUTES = "attributes"
    GUID_DIAGRAMS = "diagrams"
    GUID_PORTS = "ports"

    def __init__(self):
        self._app = None         # type: App
        self._connect()
        self._guid = {
            EAInstance.GUID_PACKAGES: {},
            EAInstance.GUID_MODELS: {},
            EAInstance.GUID_ELEMENTS: {},
            EAInstance.GUID_METHODS: {},
            EAInstance.GUID_ATTRIBUTES: {},
            EAInstance.GUID_DIAGRAMS: {},
            EAInstance.GUID_PORTS: {},
        }
        self._project_prefix = ""


    def setProjectPrefix(self, prefix: str) -> None:
        self._project_prefix = prefix


    def getApp(self) -> App:
        return self._app


    def getRepository(self) -> Repository:
        return self._app.Repository


    def get_model(self, name: str) -> Package:
        guid = self.getGuid(EAInstance.GUID_MODELS, name)
        model = None
        if guid:
            model = self.getRepository().GetPackageByGuid(guid)
            if not model:
                self.removeGuid(EAInstance.GUID_MODELS, name)
        if not model:
            for idx in range(0, self.getRepository().Models.Count):
                current_model: Package = self.getRepository().Models.GetAt(idx)
                self.addGuid(EAInstance.GUID_MODELS,
                             current_model.Name, current_model.PackageGUID)
                if current_model.Name == name:
                    model = current_model
                    break
        return model


    def _connect(self) -> None:
        """Try to connect to the "EA.App".

        @exception Exception if unable to connect to EA
        """
        try:
            self._app = win32com.client.gencache.EnsureDispatch('EA.App')  # type: App
            # self._app = win32com.client.Dispatch('EA.App')  # type: App
            #models = self.eaRep.models
        except Exception as e:
            sys.stderr.write("Unable to connect to EA\n")
            sys.stderr.write(
                "Please try to run `Remove-Item -path $env:LOCALAPPDATA\\Temp\\"
                "gen_py -recurse` to fix the issue"
            )
            raise e


    def findOrCreateModel(self, name: str) -> Package:
        model = self.get_model(name)
        if (model == None):
            model = self.getRepository().Models.AddNew(name, "")  # type: Package
            model.Update()
            self.getRepository().Models.Refresh()
            self.addGuid(EAInstance.GUID_MODELS, model.Name, model.PackageGUID)

        return model


    def findSubPackage(self, parent: Package, name: str) -> Package | None:
        for idx in range(0, parent.Packages.Count):
            current_package = parent.Packages.GetAt(idx)  # type: Package
            if current_package.Name == name:
                return current_package
        return None


    def findPackageRecursive(self, parent: Package, name: str,
                             ) -> Package | None:
        if parent.Name == name:
            return parent

        for idx in range(0, parent.Packages.Count):
            current_package = parent.Packages.GetAt(idx)  # type: Package
            self.addGuid(EAInstance.GUID_PACKAGES,
                         current_package.Name, current_package.PackageGUID)
            child_package = self.findPackageRecursive(current_package, name)
            if child_package:
                return child_package
        return None


    def findPackage(self, parent: Package, name: str) -> Package | None:
        package = None
        guid = self.getGuid(EAInstance.GUID_PACKAGES, name)
        if guid:
            package = self.getRepository().GetPackageByGuid(guid)
        if not package:
            print("Find in recursive: %s" % name)
            package = self.findPackageRecursive(parent, name)
        return package


    def removePackage(self, parent: Package, name: str):
        for idx in range(0, parent.Packages.Count):
            current_package = parent.Packages.GetAt(idx)  # type: Package
            if current_package.Name == name:
                parent.Packages.Delete(idx)
                break


    def findOrCreatePackage(self, parent: Package, name: str, skip_guid: bool = False) -> Package:
        if not skip_guid:
            package = self.findPackage(parent, name)
        else:
            package = self.findSubPackage(parent, name)

        if not package:
            package: Package = parent.Packages.AddNew(name, "")
            package.Update()
            if not skip_guid:
                self.addGuid(
                    EAInstance.GUID_PACKAGES, package.Name, package.PackageGUID,
                )
        return package


    def getElementGuidKey(self, primary_key: str, secondary_key: str) -> str:
        return f'{primary_key}-{secondary_key}'


    def findSubElement(self, parent: Package, name: str, meta_type: str,
                       ) -> Element | None:
        for idx in range(0, parent.Elements.Count):
            current_element: Element = parent.Elements.GetAt(idx)
            if current_element.MetaType == meta_type:
                if current_element.Name == name:
                    return current_element
                # pattern = r'(?:\[[\w_]*\])?\s*' f'({name})'
                # match = re.match(pattern, current_element.Name)
                # if match:
                #     return current_element
        return None


    def findElement(self, parent: Package, name: str, meta_type: str,
                    ) -> Element:
        guid = self.getGuid(
            EAInstance.GUID_ELEMENTS, self.getElementGuidKey(name, meta_type),
        )
        element = None
        if guid:
            element = self.getRepository().GetElementByGuid(guid)
            if not element:
                self.removeGuid(
                    EAInstance.GUID_ELEMENTS,
                    self.getElementGuidKey(name, meta_type)
                )
        if not element:
            for idx in range(0, parent.Elements.Count):
                current_element = parent.Elements.GetAt(idx)  # type: Element
                self.addGuid(
                    EAInstance.GUID_ELEMENTS,
                    self.getElementGuidKey(
                        current_element.Name, current_element.MetaType
                    ),
                    current_element.ElementGUID)
                if (
                        current_element.Name == name
                        and current_element.Type == meta_type
                ):
                    element = current_element
                    break
        return element


    def removeElement(self, parent: Package, name: str, meta_type: str):
        for idx in range(0, parent.Elements.Count):
            current_element = parent.Elements.GetAt(idx)  # type: Element
            print(current_element.Name)
            if (
                    current_element.Name == name
                    and current_element.MetaType == meta_type
            ):
                #print(f"Find {name}")
                parent.Elements.DeleteAt(idx, False)


    def createElementOnPackage(self, parent: Package, name: str, type: str):
        element: Element = parent.Elements.AddNew(name, type)
        self.addGuid(
            EAInstance.GUID_ELEMENTS,
            self.getElementGuidKey(element.Name, element.MetaType),
            element.ElementGUID
        )

        return element


    def findOrCreateElement(self, parent: Package, name: str, meta_type: str, type = None,
                            skip_guid: bool = False) -> Element:
        if type == None:
            type = meta_type

        try:
            if not skip_guid:
                element = self.findElement(parent, name, meta_type)
            else:
                element = self.findSubElement(parent, name, meta_type)

            if not element:
                element: Element = parent.Elements.AddNew(name, type)
                self.addGuid(
                    EAInstance.GUID_ELEMENTS,
                    self.getElementGuidKey(element.Name, element.MetaType),
                    element.ElementGUID
                )

            element.Update()
            parent.Elements.Refresh()

            return element
        except Exception as err:
            if err.excepinfo[2] == "Element locked":
                print(f'EA Element <{name}> is locked')
                raise err


    def findConnector(self, parent: Element, name: str) -> Method:
        for idx in range(0, parent.Connectors.Count):
            current_connector = parent.Connectors.GetAt(idx)  # type: Method
            if (current_connector.Name == name):
                return current_connector
        return None


    def findMethod(self, parent: Element, name: str) -> Method:
        for idx in range(0, parent.Methods.Count):
            current_method = parent.Methods.GetAt(idx)  # type: Method
            pattern = r'(?:\[[\w_]*\])?\s*' + '(%s)' % name
            match = re.match(pattern, current_method.Name)
            if match:
                return current_method
        return None


    def findOrCreateMethod(self, parent: Element, name: str, return_type: str) -> Method:
        method = self.findMethod(parent, name)
        if method is None:
            method = parent.Methods.AddNew(name, return_type)  # type: Method
        method.Update()
        parent.Methods.Refresh()
        # elf.addGuid(EAInstance.GUID_METHODS, method.Name, method.MethodGUID)

        return method


    def findParameter(self, parent: Method, name: str) -> Parameter:
        for idx in range(0, parent.Parameters.Count):
            current_parameter = parent.Parameters.GetAt(idx)  # type: Parameter
            if (current_parameter.Name == name):
                return current_parameter
        return None


    def findOrCreateParameter(self, parent: Method, name: str, data_type: str, direction: str) -> Parameter:
        parameter = self.findParameter(parent, name)
        if (parameter == None):
            parameter = parent.Parameters.AddNew(name, "")  # type: Parameter
        parameter.Kind = direction
        parameter.Type = data_type
        parameter.Update()
        parent.Parameters.Refresh()
        return parameter


    def findAttribute(self, parent: Element, name: str) -> Attribute:
        for idx in range(0, parent.Attributes.Count):
            current_attribute = parent.Attributes.GetAt(idx)  # type: Attribute
            pattern = r'(?:\[[\w_]*\])?\s*' + '(%s)' % name
            match = re.match(pattern, current_attribute.Name)
            if match:
                return current_attribute
        return None


    def findOrCreateAttribute(self, parent: Element, name: str, datatype: str) -> Attribute:
        attribute = self.findAttribute(parent, name)
        if attribute is None:
            attribute = parent.Attributes.AddNew(name, datatype)  # type: Attribute
        attribute.Update()
        parent.Attributes.Refresh()

        return attribute


    def findPort(self, parent: Element, name: str, skip_guid = False) -> Attribute:
        guid = self.getGuid(EAInstance.GUID_PORTS, self.getElementGuidKey(parent.Name, name))
        port = None
        if skip_guid:
            if (guid != ""):
                port = self.getRepository().GetElementByGuid(guid)
                if (port == None):
                    self.removeGuid(EAInstance.GUID_PORTS, name)
        if (port == None):
            #print("find port slowly <%s, %s>" % (name, guid))
            for idx in range(0, parent.EmbeddedElements.Count):
                current_port = parent.EmbeddedElements.GetAt(idx)  # type: Element
                self.addGuid(EAInstance.GUID_PORTS, self.getElementGuidKey(parent.Name, current_port.Name), current_port.ElementGUID)
                if (current_port.Name == name):
                    port = current_port
                    break
        return port


    def findOrCreatePort(self, parent: Element, name: str, stereo_type: str, data_type_ref: int, direction: str) -> Method:
        port = self.findPort(parent, name)
        if not port:
            port = parent.EmbeddedElements.AddNew(name, "Port") # type: Attribute
            self.addGuid(EAInstance.GUID_PORTS, self.getElementGuidKey(parent.Name, port.Name), port.ElementGUID)
        port.StereotypeEx = stereo_type
        port.PropertyType = data_type_ref
        port.Update()

        self.findOrCreateTaggedValue(port, "direction", direction)

        parent.EmbeddedElements.Refresh()
        return port


    def findTaggedValue(self, parent: Element, name: str) -> TaggedValue:
        tagged_value = None
        for idx in range(0, parent.TaggedValues.Count):
            current_tagged_value = parent.TaggedValues.GetAt(idx)  # type: TaggedValue
            if (current_tagged_value.Name == name):
                tagged_value = current_tagged_value
                break
        return tagged_value


    def findOrCreateTaggedValue(self, parent: Element, name: str, value: str) -> TaggedValue:
        tagged_value = self.findTaggedValue(parent, name)
        if (tagged_value == None):
            tagged_value = parent.TaggedValues.AddNew(name, value) # type: TaggedValue
        tagged_value.Update()
        parent.TaggedValuesEx.Refresh()
        return tagged_value


    def findTaggedExValue(self, parent: Element, name: str) -> TaggedValue:
        tagged_value = None
        for idx in range(0, parent.TaggedValuesEx.Count):
            current_tagged_value = parent.TaggedValuesEx.GetAt(idx)  # type: TaggedValue
            if (current_tagged_value.Name == name):
                tagged_value = current_tagged_value
                break
        return tagged_value


    def findOrCreateTaggedExValue(self, parent: Element, name: str, value: str) -> TaggedValue:
        tagged_value = self.findTaggedExValue(parent, name)
        if not tagged_value:
            tagged_value = parent.TaggedValuesEx.AddNew(name, value) # type: TaggedValue
        tagged_value.Update()
        parent.TaggedValuesEx.Refresh()
        return tagged_value


    def findDiagram(self, parent: Element, name: str, diag_type: str) -> 'Diagram':
        guid = self.getGuid(EAInstance.GUID_DIAGRAMS, self.getElementGuidKey(name, diag_type))
        diagram = None
        if (guid != ""):
            try:
                diagram = self.getRepository().GetDiagramByGuid(guid)
            except:
                pass
            if (diagram == None):
                self.removeGuid(EAInstance.GUID_DIAGRAMS, name)
        if (diagram == None):
            for idx in range(0, parent.Diagrams.Count):
                current_diagram = parent.Diagrams.GetAt(idx)  # type: Diagram
                self.addGuid(EAInstance.GUID_DIAGRAMS, self.getElementGuidKey(current_diagram.Name, diag_type), current_diagram.DiagramGUID)
                if (current_diagram.Name == name and current_diagram.Type == diag_type):
                    diagram = current_diagram
        return diagram


    def findOrCreateDiagram(self, parent: Element, name: str, diag_type: str) -> 'Diagram':
        diagram = self.findDiagram(parent, name, diag_type)
        if (diagram == None):
            diagram = parent.Diagrams.AddNew(name, diag_type) # type: Diagram
            diagram.Update()
            parent.Diagrams.Refresh()
            self.addGuid(EAInstance.GUID_DIAGRAMS, self.getElementGuidKey(diagram.Name, diagram.Type), diagram.DiagramGUID)

        return diagram


    def get_related_diagramLink_by_connector(self, parentDiagram, connectorObj):
        parentDiagram.DiagramLinks.Refresh()
        for diag_link in parentDiagram.DiagramLinks:
            if diag_link.ConnectorID == connectorObj.ConnectorID:
                return diag_link


    def process_link_visual_path(self, diagramLink, yFlowGenLink):
        path = ''
        for pointStr in yFlowGenLink['path']:
            path += pointStr.replace(',', ':-') + ';'
        diagramLink.Path = path
        diagramLink.Update()


    def findOrCreateConnector(self, source_port, destination_port,
                             connector_name, prefixes: list[str], notes=""):
        # find if the connector already exist
        connector_is_present = False
        new_connector = None

        for connector in source_port.Connectors:
            if connector.SupplierID == destination_port.ElementID:
                new_connector = connector
                connector_is_present = True
                break

        # create a new connector
        if not connector_is_present:
            new_connector = source_port.Connectors.AddNew(connector_name, '')
            new_connector.SupplierID = destination_port.ElementID
            new_connector.Update()
            source_port.Connectors.Refresh()

        supplier_role = prefixes[0]
        new_connector.SupplierEnd.Role = supplier_role
        new_connector.SupplierEnd.Update()
        new_connector.ClientEnd.Role = prefixes[1]
        new_connector.ClientEnd.Update()
        new_connector.Notes = notes
        new_connector.Update()

        return new_connector

    def createConnectorBetweenTwoNods(self, source_element, target_element, connector_name):
        # create a new connector
        new_connector = source_element.Connectors.AddNew(connector_name, '')
        new_connector.SupplierID = target_element.ElementID
        new_connector.MetaType = 'ControlFlow'
        new_connector.Type = 'ControlFlow'
        new_connector.Update()
        source_element.Connectors.Refresh()

        return new_connector


    def findOrCreateDiagramObject(self, parentDiagram: 'Diagram', elmID: int, position):
        diagramObj = parentDiagram.DiagramObjects.AddNew("l=" + str(position['x']) +
                                                         ";r=" + str(position['x'] + position['w']) +
                                                         ";t=" + str(position['y']) +
                                                         ";b=" + str(position['y'] + position['h']) + ";", "")
        diagramObj.ElementID = elmID
        diagramObj.Update()
        parentDiagram.DiagramObjects.Refresh()

        return diagramObj


    def getGuid(self, group_name, name) -> str:
        guid = ""
        if (name in self._guid[group_name]):
            guid = self._guid[group_name][name]
        return guid


    def addGuid(self, group: str, name: str, guid: str):
        self._guid[group][name] = guid


    def removeGuid(self, group: str, name: str):
        if (name in self._guid[group]):
            del self._guid[group][name]


    def _addGuidList(self, group: str, values):
        for key in values:
            self.addGuid(group, key, values[key])


    def loadGuidFromFile(self, filename: str) -> None:
        try:
            with open(filename) as f_in:
                data = json.load(f_in)
                for group in data:
                    if (group == EAInstance.GUID_PACKAGES):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_ATTRIBUTES):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_DIAGRAMS):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_ELEMENTS):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_METHODS):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_MODELS):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_PACKAGES):
                        self._addGuidList(group, data[group])
                    elif (group == EAInstance.GUID_PORTS):
                        self._addGuidList(group, data[group])
                    else:
                        raise ValueError("Invalid group <%s>" % group)
        except Exception as _:
            print("Invalid Json file <%s>" % filename)


    def saveGuidToFile(self, filename: str) -> None:
        with open(filename, 'w') as json_file:
            json.dump(self._guid, json_file, indent=4, sort_keys=True)


from .diagram import Diagram # noqa
