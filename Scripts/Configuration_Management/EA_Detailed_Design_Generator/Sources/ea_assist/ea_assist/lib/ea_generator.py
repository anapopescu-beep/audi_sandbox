import subprocess
import os, signal

from ..model.ea_model import (
    Package,
    EAInstance,
    Parameter,
    TaggedValue,
    PropertyType,
    Element,
    Connector,
    Diagram,
)

class EAGenerator:
    def __init__(self) -> None:
        self._pkg_interfaces_mapping = {}
        self._instance = None  # EAInstance
        self._interface_mapping = {}  # Dict[str, int]


    def locate_root_package(self) -> Package:
        model = self._instance.findOrCreateModel("SW Detailed Design")
        package = self._instance.findOrCreatePackage(model, "SW Detailed Design")
        package = self._instance.findOrCreatePackage(package, "SW Components", True)
        return package


    def _create_function_diagram(self, parent: Package, function_name) -> Diagram:
        diagram = self._instance.findOrCreateDiagram(parent, "AAU : %s" % function_name, "Component")
        self._showVerboseInfo("Diagram " + diagram.Name + " is created")

        return diagram


    def add_component_in_diagram(self, parentDiagram, component_to_add, position, color: int = -1, fontColor: int = -1, fontBold: bool = False, borderColor: int = -1, notes: str = ''):
        component_to_add.Stereotype = ''
        # component_to_add.Notes = notes
        component_to_add.Update()

        diagramObj = self._instance.findOrCreateDiagramObject(parentDiagram, component_to_add.ElementID, position)
        diagramObj.BackgroundColor = color
        diagramObj.FontColor = fontColor
        diagramObj.FontBold = fontBold
        diagramObj.BorderColor = borderColor
        diagramObj.ElementDisplayMode = 2
        if component_to_add.MetaType == 'DecisionNode':
            center_x_position = position['x'] + (position['w'] / 2)
            maxLineWidth = 0
            nr_of_lines = len(component_to_add.Name.split('\n'))
            for line in component_to_add.Name.split('\n'):
                if self.get_calibri6_word_width_in_pixels(line) > maxLineWidth:
                    maxLineWidth = self.get_calibri6_word_width_in_pixels(line)
            label_text_width = maxLineWidth * 0.872
            OX = (center_x_position - (label_text_width / 2)) - position['x']
            diagramObj.Style = diagramObj.Style + 'LBL=CX=' + str(label_text_width + 10) + ':CY=15:OX=' + str(OX) + ':OY=' + str(9.5 + (nr_of_lines * 2.5)) + ':HDN=0:BLD=0:ITA=0:UND=0:CLR=-1:ALN=1:ALT=0:ROT=0;'
        diagramObj.Update()

        return diagramObj


    def create_customTable_for_macro(self, parent: Package, macroName: str, defineDoxyDict: dict):
        table_width = 500
        cell_margin = 5
        table_full_cell_width = table_width - (2 * cell_margin)
        name_cell_width = int(0.686 * table_width) - (2 * cell_margin)
        value_cell_width = int(0.314 * table_width) - (2 * cell_margin)

        name_cell_nr_of_rows = self.get_number_of_text_rows(defineDoxyDict['name'], name_cell_width)
        value_cell_nr_of_rows = self.get_number_of_text_rows(defineDoxyDict['initializer'], value_cell_width)

        if name_cell_nr_of_rows > value_cell_nr_of_rows:
            nameOrVlue_row_nr_of_rows = name_cell_nr_of_rows
        else:
            nameOrVlue_row_nr_of_rows = value_cell_nr_of_rows

        definitionString = '#define ' + defineDoxyDict['name'] + ' ' + defineDoxyDict['initializer']
        definition_cell_nr_of_rows = self.get_number_of_text_rows(definitionString, table_full_cell_width)
        description_cell_nr_of_rows = self.get_number_of_text_rows(defineDoxyDict['briefdescription'], table_full_cell_width)

        nr_of_rows = 3 + nameOrVlue_row_nr_of_rows + definition_cell_nr_of_rows + description_cell_nr_of_rows

        table_name = 'Table of macro "' + macroName + '"'
        macroTable = self._instance.findOrCreateElement(parent, table_name, 'Artifact')
        macroTable.Stereotype = 'custom table'
        dataTaggedValue = self._instance.findOrCreateTaggedValue(macroTable, 'data', '<memo>')
        notes =  '''<?xml version="1.0"?>
<customtable>
    <table>
        <row>
            <column>Name</column>
            <column>Value</column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(defineDoxyDict['name']) + '''</column>
            <column>''' + self.replace_xml_special_chars(defineDoxyDict['initializer']) + '''</column>
        </row>
        <row>
            <column>Definition</column>
            <column></column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(definitionString) + '''</column>
            <column></column>
        </row>
        <row>
            <column>Description</column>
            <column></column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(defineDoxyDict['briefdescription']) + '''</column>
            <column></column>
        </row>
    </table>
</customtable>'''
        dataTaggedValue.Notes = notes
        dataTaggedValue.Update()

        dataFormatTaggedValue = self._instance.findOrCreateTaggedValue(macroTable, 'dataFormat', '<memo>')
        notes = '''<?xml version="1.0"?>
<dataformat>
    <style>
        <grid rows="6" columns="2">
            <gridcolor>0</gridcolor>
        </grid>
        <cells>
            <cell row="0" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="0" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="2" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
                <merge>
                    <left>0</left>
                    <top>2</top>
                    <right>1</right>
                    <bottom>2</bottom>
                </merge>
            </cell>
            <cell row="2" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="3" col="0">
                <merge>
                    <left>0</left>
                    <top>3</top>
                    <right>1</right>
                    <bottom>3</bottom>
                </merge>
            </cell>
            <cell row="4" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
                <merge>
                    <left>0</left>
                    <top>4</top>
                    <right>1</right>
                    <bottom>4</bottom>
                </merge>
            </cell>
            <cell row="4" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="5" col="0">
                <merge>
                    <left>0</left>
                    <top>5</top>
                    <right>1</right>
                    <bottom>5</bottom>
                </merge>
            </cell>
        </cells>'''

        if (nameOrVlue_row_nr_of_rows > 1) \
                or (definition_cell_nr_of_rows > 1) \
                or (description_cell_nr_of_rows > 1):
            notes += '''
        <rows>'''
            if nameOrVlue_row_nr_of_rows > 1:
                notes += '''
            <row id="1" lines="''' + str(nameOrVlue_row_nr_of_rows) + '''"/>'''
            if definition_cell_nr_of_rows > 1:
                notes += '''
            <row id="3" lines="''' + str(definition_cell_nr_of_rows) + '''"/>'''
            if description_cell_nr_of_rows > 1:
                notes += '''
            <row id="5" lines="''' + str(description_cell_nr_of_rows) + '''"/>'''

            notes += '''
        </rows>'''
        else:
            notes += '''
        <rows/>'''
        notes += '''
        </style>
	<layout autosizecolumns="1" version="1" xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">AgABAAAAAQAAAAIAsQEAAMYAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=</layout>
</dataformat>'''
        dataFormatTaggedValue.Notes = notes
        dataFormatTaggedValue.Update()
        macroTable.TaggedValues.Refresh()
        macroTable.Update()

        return [macroTable, nr_of_rows]


    def create_diagram_for_macro(self, parent: Package, macroName: str, macroTable, nr_of_rows: int, macroTablesPackage):
        macroDiagram = self._instance.findOrCreateDiagram(parent, macroName, "Component")
        macroDiagram.HighlightImports = False
        macroDiagram.Update()

        table_default_row_height = 17
        table_added_row_height = 13.5
        table_top_margin = 21
        table_bottom_margin = 12
        default_number_of_rows = 6

        macroTitleLabel_element = self.create_label(macroTablesPackage, macroName, diagramType='macro')
        position = {}
        position['x'] = 50
        position['y'] = 50
        position['h'] = 36
        position['w'] = 600
        color = -1
        self.add_component_in_diagram(macroDiagram, macroTitleLabel_element, position, color=color)

        position = {}
        position['x'] = 50
        position['y'] = 100
        position['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin
        position['w'] = 500
        color = 0xffffff
        self.add_component_in_diagram(macroDiagram, macroTable, position, color=color)

        table_background_element = self.create_emptyAction(macroTablesPackage)
        position1 = {}
        position1['x'] = 25
        position1['y'] = 25
        position1['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin + 100
        position1['w'] = 550
        color = -1
        table_background_diagramObject = self.add_component_in_diagram(macroDiagram, table_background_element, position1, color=color)
        table_background_diagramObject.Update()
        macroDiagram.DiagramObjects.Refresh()
        macroDiagram.Update()

        # set layers
        backElementsCounter = 0
        for idx in range(macroDiagram.DiagramObjects.Count):
            elm = macroDiagram.DiagramObjects.GetAt(idx)
            if elm.ElementID == table_background_diagramObject.ElementID:
                backElementsCounter += 1
                elm.Sequence = macroDiagram.DiagramObjects.Count
            else:
                elm.Sequence = idx + 1 - backElementsCounter
            elm.Update()

        return macroDiagram


    def create_customTable_for_variable(self, parent: Package, variableName: str, variableDoxyDict: dict):
        table_width = 500
        cell_margin = 5
        table_full_cell_width = table_width - (2 * cell_margin)
        type_cell_width = int(0.7 * table_width) - (2 * cell_margin)
        value_cell_width = int(0.3 * table_width) - (2 * cell_margin)

        type_cell_nr_of_rows = self.get_number_of_text_rows(variableDoxyDict['type'], type_cell_width)
        value_cell_nr_of_rows = self.get_number_of_text_rows(variableDoxyDict['initializer'].replace('=', '').strip(), value_cell_width)
        if type_cell_nr_of_rows > value_cell_nr_of_rows:
            typeOrVlue_row_nr_of_rows = type_cell_nr_of_rows
        else:
            typeOrVlue_row_nr_of_rows = value_cell_nr_of_rows

        briefdescription_cell_nr_of_rows = self.get_number_of_text_rows(variableDoxyDict['briefdescription'], table_full_cell_width)
        definition_cell_nr_of_rows = self.get_number_of_text_rows(variableDoxyDict['type'] + ' ' + variableDoxyDict['name'] + ' ' + variableDoxyDict['initializer'], table_full_cell_width)
        initialization_cell_nr_of_rows = self.get_number_of_text_rows(variableDoxyDict['initialization'], table_full_cell_width)
        range_cell_nr_of_rows = self.get_number_of_text_rows(variableDoxyDict['range'], table_full_cell_width)

        nr_of_rows = 5 + typeOrVlue_row_nr_of_rows + briefdescription_cell_nr_of_rows + definition_cell_nr_of_rows + initialization_cell_nr_of_rows + range_cell_nr_of_rows

        table_name = 'Table of variable "' + variableName + '"'
        variableTable = self._instance.findOrCreateElement(parent, table_name, 'Artifact')
        variableTable.Stereotype = 'custom table'
        dataTaggedValue = self._instance.findOrCreateTaggedValue(variableTable, 'data', '<memo>')
        notes =  '''<?xml version="1.0"?>
<customtable>
    <table>
        <row>
            <column>Type</column>
            <column>Value</column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(variableDoxyDict['type']) + '''</column>
            <column>''' + self.replace_xml_special_chars(variableDoxyDict['initializer'].replace('=', '').strip()) + '''</column>
        </row>
        <row>
            <column>Description</column>
            <column></column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(variableDoxyDict['briefdescription']) + '''</column>
            <column></column>
        </row>
        <row>
            <column>Definition</column>
            <column></column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(variableDoxyDict['type'] + ' ' + variableDoxyDict['name'] + ' ' + variableDoxyDict['initializer']) + '''</column>
            <column></column>
        </row>
        <row>
            <column>Initialization</column>
            <column></column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(variableDoxyDict['initialization']) + '''</column>
            <column></column>
        </row>
        <row>
            <column>Range</column>
            <column></column>
        </row>
        <row>
            <column>''' + self.replace_xml_special_chars(variableDoxyDict['range']) + '''</column>
            <column></column>
        </row>
    </table>
</customtable>'''
        dataTaggedValue.Notes = notes
        dataTaggedValue.Update()

        dataFormatTaggedValue = self._instance.findOrCreateTaggedValue(variableTable, 'dataFormat', '<memo>')
        notes = '''<?xml version="1.0"?>
<dataformat>
    <style>
        <grid rows="10" columns="2">
            <gridcolor>0</gridcolor>
        </grid>
        <cells>
            <cell row="0" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="0" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="2" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
                <merge>
                    <left>0</left>
                    <top>2</top>
                    <right>1</right>
                    <bottom>2</bottom>
                </merge>
            </cell>
            <cell row="2" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="3" col="0">
                <merge>
                    <left>0</left>
                    <top>3</top>
                    <right>1</right>
                    <bottom>3</bottom>
                </merge>
            </cell>
            <cell row="4" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
                <merge>
                    <left>0</left>
                    <top>4</top>
                    <right>1</right>
                    <bottom>4</bottom>
                </merge>
            </cell>
            <cell row="4" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="5" col="0">
                <merge>
                    <left>0</left>
                    <top>5</top>
                    <right>1</right>
                    <bottom>5</bottom>
                </merge>
            </cell>
            <cell row="6" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
                <merge>
                    <left>0</left>
                    <top>6</top>
                    <right>1</right>
                    <bottom>6</bottom>
                </merge>
            </cell>
            <cell row="6" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="7" col="0">
                <merge>
                    <left>0</left>
                    <top>7</top>
                    <right>1</right>
                    <bottom>7</bottom>
                </merge>
            </cell>
            <cell row="8" col="0">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
                <merge>
                    <left>0</left>
                    <top>8</top>
                    <right>1</right>
                    <bottom>8</bottom>
                </merge>
            </cell>
            <cell row="8" col="1">
                <bold>true</bold>
                <txtcolor>16777215</txtcolor>
                <bgcolor>8388608</bgcolor>
            </cell>
            <cell row="9" col="0">
                <merge>
                    <left>0</left>
                    <top>9</top>
                    <right>1</right>
                    <bottom>9</bottom>
                </merge>
            </cell>
        </cells>'''
        if (typeOrVlue_row_nr_of_rows > 1) \
                or (briefdescription_cell_nr_of_rows > 1) \
                or (definition_cell_nr_of_rows > 1) \
                or (initialization_cell_nr_of_rows > 1) \
                or (range_cell_nr_of_rows > 1):
            notes += '''
        <rows>'''
            if typeOrVlue_row_nr_of_rows > 1:
                notes += '''
            <row id="1" lines="''' + str(typeOrVlue_row_nr_of_rows) + '''"/>'''
            if briefdescription_cell_nr_of_rows > 1:
                notes += '''
            <row id="3" lines="''' + str(briefdescription_cell_nr_of_rows) + '''"/>'''
            if definition_cell_nr_of_rows > 1:
                notes += '''
            <row id="5" lines="''' + str(definition_cell_nr_of_rows) + '''"/>'''
            if typeOrVlue_row_nr_of_rows > 1:
                notes += '''
            <row id="7" lines="''' + str(initialization_cell_nr_of_rows) + '''"/>'''
            if typeOrVlue_row_nr_of_rows > 1:
                notes += '''
            <row id="9" lines="''' + str(range_cell_nr_of_rows) + '''"/>'''
            notes += '''
        </rows>'''
        else:
            notes += '''
        <rows/>'''
        notes += '''
        </style>
    <layout autosizecolumns="1" version="1" xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">AgABAAAAAQAAAAIADQIAAOMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=</layout>
</dataformat>'''
        dataFormatTaggedValue.Notes = notes
        dataFormatTaggedValue.Update()
        variableTable.TaggedValues.Refresh()
        variableTable.Update()

        return [variableTable, nr_of_rows]


    def create_diagram_for_variable(self, parent: Package, variableName: str, variableTable, nr_of_rows: int, variableTablesPackage):
        variableDiagram = self._instance.findOrCreateDiagram(parent, variableName, "Component")
        variableDiagram.HighlightImports = False
        variableDiagram.Update()

        table_default_row_height = 17
        table_added_row_height = 13.5
        table_top_margin = 21
        table_bottom_margin = 12
        default_number_of_rows = 10

        variableTitleLabel_element = self.create_label(variableTablesPackage, variableName)
        position = {}
        position['x'] = 50
        position['y'] = 50
        position['h'] = 36
        position['w'] = 500
        color = -1
        self.add_component_in_diagram(variableDiagram, variableTitleLabel_element, position, color=color)

        position = {}
        position['x'] = 50
        position['y'] = 100
        position['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin
        position['w'] = 500
        color = 0xffffff
        self.add_component_in_diagram(variableDiagram, variableTable, position, color=color)

        table_background_element = self.create_emptyAction(variableTablesPackage)
        position1 = {}
        position1['x'] = 25
        position1['y'] = 25
        position1['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin + 100
        position1['w'] = 550
        color = -1
        table_background_diagramObject = self.add_component_in_diagram(variableDiagram, table_background_element, position1, color=color)
        table_background_diagramObject.Update()
        variableDiagram.DiagramObjects.Refresh()
        variableDiagram.Update()

        # set layers
        backElementsCounter = 0
        for idx in range(variableDiagram.DiagramObjects.Count):
            elm = variableDiagram.DiagramObjects.GetAt(idx)
            if elm.ElementID == table_background_diagramObject.ElementID:
                backElementsCounter += 1
                elm.Sequence = variableDiagram.DiagramObjects.Count
            else:
                elm.Sequence = idx + 1 - backElementsCounter
            elm.Update()

        return variableDiagram


    def create_customTable_for_function(self, parent: Package, functionName: str, functionDoxyDict: dict):
        table_width = 600
        cell_margin = 5
        table_full_cell_width = table_width - (2 * cell_margin)
        col1_width = int(0.25 * table_width) - (2 * cell_margin)
        col2_width = int(0.25 * table_width) - (2 * cell_margin)
        col3_width = int(0.25 * table_width) - (2 * cell_margin)
        col4_width = int(0.25 * table_width) - (2 * cell_margin)
        col234_width = int(0.75 * table_width) - (2 * cell_margin)

        function_prototype = functionDoxyDict['definition'] + functionDoxyDict['argsstring']

        object_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['briefdescription'],table_full_cell_width)
        prototype_cell_nr_of_rows = self.get_number_of_text_rows(function_prototype, table_full_cell_width)
        exceptions_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['exception'], table_full_cell_width)
        precondition_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['precondition'], table_full_cell_width)
        postcondition_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['postcondition'], table_full_cell_width)
        ddrequirement_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['ddesignrequirement'], table_full_cell_width)
        archrequirement_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['archrequirement'], table_full_cell_width)

        inparams_cell_nr_of_rows_list = []
        all_inparams_cell_nr_of_rows_list = 0
        outparams_cell_nr_of_rows_list = []
        all_outparams_cell_nr_of_rows_list = 0

        for inparam in functionDoxyDict['inputParameters'].values():
            inparamName_cell_nr_of_rows = self.get_number_of_text_rows(inparam['name'], col1_width)
            inparamType_cell_nr_of_rows = self.get_number_of_text_rows(inparam['type'], col2_width)
            inparamDescription_cell_nr_of_rows = self.get_number_of_text_rows(inparam['description'], col3_width)
            inparamRange_cell_nr_of_rows = self.get_number_of_text_rows(inparam['range'], col4_width)

            number_of_rows = inparamName_cell_nr_of_rows
            if inparamType_cell_nr_of_rows > number_of_rows:
                number_of_rows = inparamType_cell_nr_of_rows
            if inparamDescription_cell_nr_of_rows > number_of_rows:
                number_of_rows = inparamDescription_cell_nr_of_rows
            if inparamRange_cell_nr_of_rows > number_of_rows:
                number_of_rows = inparamRange_cell_nr_of_rows

            inparams_cell_nr_of_rows_list.append(number_of_rows)
            all_inparams_cell_nr_of_rows_list += number_of_rows

        for outparam in functionDoxyDict['outputParameters'].values():
            outparamName_cell_nr_of_rows = self.get_number_of_text_rows(outparam['name'], col1_width)
            outparamType_cell_nr_of_rows = self.get_number_of_text_rows(outparam['type'], col2_width)
            outparamDescription_cell_nr_of_rows = self.get_number_of_text_rows(outparam['description'], col3_width)
            outparamRange_cell_nr_of_rows = self.get_number_of_text_rows(outparam['range'], col4_width)

            number_of_rows = outparamName_cell_nr_of_rows
            if outparamType_cell_nr_of_rows > number_of_rows:
                number_of_rows = outparamType_cell_nr_of_rows
            if outparamDescription_cell_nr_of_rows > number_of_rows:
                number_of_rows = outparamDescription_cell_nr_of_rows
            if outparamRange_cell_nr_of_rows > number_of_rows:
                number_of_rows = outparamRange_cell_nr_of_rows

            outparams_cell_nr_of_rows_list.append(number_of_rows)
            all_outparams_cell_nr_of_rows_list += number_of_rows

        returnType = functionDoxyDict['type'].split(' ')[-1]
        returnType_cell_nr_of_rows = self.get_number_of_text_rows(returnType, col1_width)
        returnDescription_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['return'], col234_width)

        return_cell_nr_of_rows = returnType_cell_nr_of_rows
        if returnDescription_cell_nr_of_rows > return_cell_nr_of_rows:
            return_cell_nr_of_rows = returnDescription_cell_nr_of_rows

        dynamicAspectCaller_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['dynamicAspectCaller'], col1_width)
        dynamicAspectDescription_cell_nr_of_rows = self.get_number_of_text_rows( functionDoxyDict['dynamicAspectDescription'], col234_width)

        dynamicAspect_cell_nr_of_rows = dynamicAspectCaller_cell_nr_of_rows
        if dynamicAspectDescription_cell_nr_of_rows > dynamicAspect_cell_nr_of_rows:
            dynamicAspect_cell_nr_of_rows = dynamicAspectDescription_cell_nr_of_rows

        staticAspect_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['staticAspect'], table_full_cell_width)
        constrains_cell_nr_of_rows = self.get_number_of_text_rows(functionDoxyDict['constrains'], table_full_cell_width)

        nr_of_rows = 17 + object_cell_nr_of_rows \
                    + prototype_cell_nr_of_rows \
                    + exceptions_cell_nr_of_rows \
                    + precondition_cell_nr_of_rows \
                    + postcondition_cell_nr_of_rows \
                    + ddrequirement_cell_nr_of_rows \
                    + archrequirement_cell_nr_of_rows \
                    + all_inparams_cell_nr_of_rows_list \
                    + all_outparams_cell_nr_of_rows_list \
                    + return_cell_nr_of_rows \
                    + dynamicAspect_cell_nr_of_rows \
                    + staticAspect_cell_nr_of_rows \
                    + constrains_cell_nr_of_rows

        table_name = 'Table of function "' + functionName + '"'
        functionTable = self._instance.findOrCreateElement(parent, table_name, 'Artifact')
        functionTable.Stereotype = 'custom table'
        dataTaggedValue = self._instance.findOrCreateTaggedValue(functionTable, 'data', '<memo>')
        notes = '''<?xml version="1.0"?>
<customtable>
	<table>
		<row>
			<column>Object</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['briefdescription']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Prototype</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(function_prototype) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Exceptions</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['exception']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Precondition</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['precondition']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Postcondition</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['postcondition']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Detailed Design Requirement</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['ddesignrequirement']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Architecture Requirement</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['archrequirement']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Input parameters</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Name</column>
			<column>Type</column>
			<column>Description</column>
			<column>Range</column>
		</row>'''
        for inparam in functionDoxyDict['inputParameters'].values():
            notes += '''
        <row>
            <column>''' + self.replace_xml_special_chars(inparam['name']) + '''</column>
            <column>''' + self.replace_xml_special_chars(inparam['type']) + '''</column>
            <column>''' + self.replace_xml_special_chars(inparam['description']) + '''</column>
            <column>''' + self.replace_xml_special_chars(inparam['range']) + '''</column>
        </row>'''
        notes += '''
		<row>
			<column>Output parameters</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Name</column>
			<column>Type</column>
			<column>Description</column>
			<column>Range</column>
		</row>'''
        for outparam in functionDoxyDict['outputParameters'].values():
            notes += '''
        <row>
            <column>''' + self.replace_xml_special_chars(outparam['name']) + '''</column>
            <column>''' + self.replace_xml_special_chars(outparam['type']) + '''</column>
            <column>''' + self.replace_xml_special_chars(outparam['description']) + '''</column>
            <column>''' + self.replace_xml_special_chars(outparam['range']) + '''</column>
        </row>'''
        notes += '''
		<row>
			<column>Return value</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Type</column>
			<column>Description</column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(returnType) + '''</column>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['return']) + '''</column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Dynamic aspect</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Who(callers)</column>
			<column>Description</column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['dynamicAspectCaller']) + '''</column>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['dynamicAspectDescription']) + '''</column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Static aspect</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['staticAspect']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>Constrains</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
		<row>
			<column>''' + self.replace_xml_special_chars(functionDoxyDict['constrains']) + '''</column>
			<column></column>
			<column></column>
			<column></column>
		</row>
	</table>
</customtable>'''
        dataTaggedValue.Notes = notes
        dataTaggedValue.Update()

        dataFormatTaggedValue = self._instance.findOrCreateTaggedValue(functionTable, 'dataFormat', '<memo>')
        nr_of_table_rows = 28 + len(functionDoxyDict['inputParameters']) + len(functionDoxyDict['outputParameters'])
        notes = '''<?xml version="1.0"?>
<dataformat>
	<style>
		<grid rows="''' + str(nr_of_table_rows) + '''" columns="4">
			<gridcolor>0</gridcolor>
		</grid>
		<cells>
			<cell row="0" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>0</top>
					<right>3</right>
					<bottom>0</bottom>
				</merge>
			</cell>
			<cell row="0" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="0" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="0" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="1" col="0">
				<merge>
					<left>0</left>
					<top>1</top>
					<right>3</right>
					<bottom>1</bottom>
				</merge>
			</cell>
			<cell row="2" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>2</top>
					<right>3</right>
					<bottom>2</bottom>
				</merge>
			</cell>
			<cell row="2" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="2" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="2" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="3" col="0">
				<merge>
					<left>0</left>
					<top>3</top>
					<right>3</right>
					<bottom>3</bottom>
				</merge>
			</cell>
			<cell row="4" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>4</top>
					<right>3</right>
					<bottom>4</bottom>
				</merge>
			</cell>
			<cell row="4" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="4" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="4" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="5" col="0">
				<merge>
					<left>0</left>
					<top>5</top>
					<right>3</right>
					<bottom>5</bottom>
				</merge>
			</cell>
			<cell row="6" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>6</top>
					<right>3</right>
					<bottom>6</bottom>
				</merge>
			</cell>
			<cell row="6" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="6" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="6" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="7" col="0">
				<merge>
					<left>0</left>
					<top>7</top>
					<right>3</right>
					<bottom>7</bottom>
				</merge>
			</cell>
			<cell row="8" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>8</top>
					<right>3</right>
					<bottom>8</bottom>
				</merge>
			</cell>
			<cell row="8" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="8" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="8" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="9" col="0">
				<merge>
					<left>0</left>
					<top>9</top>
					<right>3</right>
					<bottom>9</bottom>
				</merge>
			</cell>
			<cell row="10" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>10</top>
					<right>3</right>
					<bottom>10</bottom>
				</merge>
			</cell>
			<cell row="10" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="10" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="10" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="11" col="0">
				<merge>
					<left>0</left>
					<top>11</top>
					<right>3</right>
					<bottom>11</bottom>
				</merge>
			</cell>
			<cell row="12" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>12</top>
					<right>3</right>
					<bottom>12</bottom>
				</merge>
			</cell>
			<cell row="12" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="12" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="12" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="13" col="0">
				<merge>
					<left>0</left>
					<top>13</top>
					<right>3</right>
					<bottom>13</bottom>
				</merge>
			</cell>
			<cell row="14" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>14</top>
					<right>3</right>
					<bottom>14</bottom>
				</merge>
			</cell>
			<cell row="14" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="14" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="14" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="15" col="0">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="15" col="1">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="15" col="2">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="15" col="3">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(17 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="0"> 
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>''' + str(17 + len(functionDoxyDict['inputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(17 + len(functionDoxyDict['inputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(17 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(17 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(17 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(18 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(18 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(18 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(18 + len(functionDoxyDict['inputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(20 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>''' + str(20 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(20 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(20 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(20 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(20 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(21 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(21 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
				<merge>
					<left>1</left>
					<top>''' + str(21 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(21 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(21 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(21 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(22 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<merge>
					<left>1</left>
					<top>''' + str(22 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(22 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(23 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>''' + str(23 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(23 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(23 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(23 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(23 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(24 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(24 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
				<merge>
					<left>1</left>
					<top>''' + str(24 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(24 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(24 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(24 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<bgcolor>15453831</bgcolor>
			</cell>
			<cell row="''' + str(25 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<merge>
					<left>1</left>
					<top>''' + str(25 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(25 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(26 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>''' + str(26 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(26 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(26 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(26 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(26 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(27 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<merge>
					<left>0</left>
					<top>''' + str(27 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(27 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(28 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
				<merge>
					<left>0</left>
					<top>''' + str(28 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(28 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
			<cell row="''' + str(28 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="1">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(28 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="2">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(28 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="3">
				<bold>true</bold>
				<txtcolor>16777215</txtcolor>
				<bgcolor>8388608</bgcolor>
			</cell>
			<cell row="''' + str(29 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''" col="0">
				<merge>
					<left>0</left>
					<top>''' + str(29 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</top>
					<right>3</right>
					<bottom>''' + str(29 + len(functionDoxyDict['inputParameters']) - 1 + len(functionDoxyDict['outputParameters']) - 1) + '''</bottom>
				</merge>
			</cell>
		</cells>'''
        if (object_cell_nr_of_rows > 1) \
                or (prototype_cell_nr_of_rows > 1) \
                or (exceptions_cell_nr_of_rows > 1) \
                or (precondition_cell_nr_of_rows > 1) \
                or (postcondition_cell_nr_of_rows > 1) \
                or (ddrequirement_cell_nr_of_rows > 1) \
                or (archrequirement_cell_nr_of_rows > 1) \
                or ((all_inparams_cell_nr_of_rows_list / len(functionDoxyDict['inputParameters'])) > 1) \
                or ((all_outparams_cell_nr_of_rows_list / len(functionDoxyDict['outputParameters'])) > 1) \
                or (return_cell_nr_of_rows > 1) \
                or (dynamicAspect_cell_nr_of_rows > 1) \
                or (staticAspect_cell_nr_of_rows > 1) \
                or (constrains_cell_nr_of_rows > 1):
            notes += '''
        <rows>'''
            if object_cell_nr_of_rows > 1:
                notes += '''
            <row id="1" lines="''' + str(object_cell_nr_of_rows) + '''"/>'''
            if prototype_cell_nr_of_rows > 1:
                notes += '''
            <row id="3" lines="''' + str(prototype_cell_nr_of_rows) + '''"/>'''
            if exceptions_cell_nr_of_rows > 1:
                notes += '''
            <row id="5" lines="''' + str(exceptions_cell_nr_of_rows) + '''"/>'''
            if precondition_cell_nr_of_rows > 1:
                notes += '''
            <row id="7" lines="''' + str(precondition_cell_nr_of_rows) + '''"/>'''
            if postcondition_cell_nr_of_rows > 1:
                notes += '''
            <row id="9" lines="''' + str(postcondition_cell_nr_of_rows) + '''"/>'''
            if ddrequirement_cell_nr_of_rows > 1:
                notes += '''
            <row id="11" lines="''' + str(ddrequirement_cell_nr_of_rows) + '''"/>'''
            if archrequirement_cell_nr_of_rows > 1:
                notes += '''
            <row id="13" lines="''' + str(archrequirement_cell_nr_of_rows) + '''"/>'''

            for idx, inparam_nr_of_rows in enumerate(inparams_cell_nr_of_rows_list):
                if inparam_nr_of_rows > 1:
                    notes += '''
                <row id="''' + str(16 + idx) + '''" lines="''' + str(inparam_nr_of_rows) + '''"/>'''

            for idx, outparam_nr_of_rows in enumerate(outparams_cell_nr_of_rows_list):
                if outparam_nr_of_rows > 1:
                    notes += '''
                <row id="''' + str(19 + len(inparams_cell_nr_of_rows_list) - 1 + idx) + '''" lines="''' + str(outparam_nr_of_rows) + '''"/>'''

            if return_cell_nr_of_rows > 1:
                notes += '''
            <row id="''' + str(22 + len(inparams_cell_nr_of_rows_list) - 1 + len(outparams_cell_nr_of_rows_list) - 1) + '''" lines="''' + str(return_cell_nr_of_rows) + '''"/>'''
            if dynamicAspect_cell_nr_of_rows > 1:
                notes += '''
            <row id="''' + str(25 + len(inparams_cell_nr_of_rows_list) - 1 + len(outparams_cell_nr_of_rows_list) - 1) + '''" lines="''' + str(dynamicAspect_cell_nr_of_rows) + '''"/>'''
            if staticAspect_cell_nr_of_rows > 1:
                notes += '''
            <row id="''' + str(27 + len(inparams_cell_nr_of_rows_list) - 1 + len(outparams_cell_nr_of_rows_list) - 1) + '''" lines="''' + str(staticAspect_cell_nr_of_rows) + '''"/>'''
            if constrains_cell_nr_of_rows > 1:
                notes += '''
            <row id="''' + str(29 + len(inparams_cell_nr_of_rows_list) - 1 + len(outparams_cell_nr_of_rows_list) - 1) + '''" lines="''' + str(constrains_cell_nr_of_rows) + '''"/>'''
            notes += '''
        </rows>'''
        else:
            notes += '''
        <rows/>'''
        notes += '''
	</style>
	<layout autosizecolumns="1" version="1" xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">BAABAAAAAQAAAAEAAAABAAAABAAoAAAAKAAAACgAAAAoAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA</layout>
</dataformat>'''
        dataFormatTaggedValue.Notes = notes
        dataFormatTaggedValue.Update()
        functionTable.TaggedValues.Refresh()
        functionTable.Update()

        return [functionTable, nr_of_rows]


    def create_label(self, parent, text, diagramType='default'):
        labelElm = self._instance.createElementOnPackage(parent, text, 'Text')
        labelElm.Gentype = '<none>'
        labelElm.Notes = '<b>' + text + '</b>'
        if diagramType == 'macro':
            labelElm.StyleEx = 'font=Calibri;fontsz=120;black=0;bold=1;italic=0;ul=0;charset=1;pitch=0;'
        else:
            labelElm.StyleEx = 'font=Calibri;fontsz=150;black=0;bold=1;italic=0;ul=0;charset=1;pitch=0;'
        labelElm.Subtype = 0
        labelElm.Update()

        return labelElm


    def create_activityInitial_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'StateNode')
        node.Subtype = 100
        node.Update()

        return node


    def create_activityInitialFunction_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'Action')
        node.Update()

        return node


    def create_activityCode_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'Action')
        node.Update()

        return node


    def create_emptyAction(self, parent):
        node = self._instance.createElementOnPackage(parent, ' ', 'Action')
        node.Update()

        return node


    def create_activityCodeFunctionCall_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'Action')
        node.Update()

        return node


    def create_activityFinal_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'StateNode')
        node.Subtype = 101
        node.Update()

        return node


    def create_decision_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'Decision')
        # node.Subtype = 101
        node.Update()

        return node


    def create_merge_node(self, parent, element):
        node = self._instance.createElementOnPackage(parent, element['name'], 'MergeNode')
        node.Subtype = 101
        node.Update()

        return node


    def create_diagram_for_function(self, parent: Package, functionName: str, functionTable, nr_of_rows: int, functionYFlowgenDict: dict, serviceDiagramContentPackage: Package):
        functionDiagram = self._instance.findOrCreateDiagram(parent, functionName, "Activity")
        functionDiagram.HighlightImports = False
        functionDiagram.Update()

        table_default_row_height = 17
        table_added_row_height = 13.5
        table_top_margin = 21
        table_bottom_margin = 15
        default_number_of_rows = 30

        functionTitleLabel_element = self.create_label(serviceDiagramContentPackage, functionName)
        position = {}
        position['x'] = 50
        position['y'] = 50
        position['h'] = 36
        position['w'] = 600
        color = -1
        self.add_component_in_diagram(functionDiagram, functionTitleLabel_element, position, color=color)

        position = {}
        position['x'] = 50
        position['y'] = 100
        position['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin
        position['w'] = 600
        table_end_position_y = position['y'] + position['h'] + 25
        color = 0xffffff
        self.add_component_in_diagram(functionDiagram, functionTable, position, color=color)

        # add logical diagram
        if functionYFlowgenDict is not None:
            diagramPosition = {}
            diagramPosition['x'] = 50 - functionYFlowgenDict['x_min']
            diagramPosition['y'] = 50 - functionYFlowgenDict['y_min'] + table_end_position_y

            dict_of_diagramElements = {}
            dict_of_yFlowGenNodes_by_id = {}
            end_y_position = 0
            for element in functionYFlowgenDict['elements']:
                if element['type'] == 'initial':
                    diagramElm = self.create_activityInitial_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = element['fill']
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'initialFunction':
                    diagramElm = self.create_activityInitialFunction_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = 0x800000
                    fontColor = 0xffffff
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color, fontColor=fontColor, fontBold=True)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'code':
                    diagramElm = self.create_activityCode_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = element['fill']
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'startLoop' or element['type'] == 'endLoop':
                    diagramElm = self.create_activityCode_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = element['fill']
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'codeFunctionCall':
                    diagramElm = self.create_activityCodeFunctionCall_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = element['fill']
                    borderColor = 0x000001
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color, borderColor=borderColor)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'end':
                    diagramElm = self.create_activityFinal_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    end_y_position = position['y'] + position['h']
                    color = 0x000000
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'decision':
                    diagramElm = self.create_decision_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = element['fill']
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element
                if element['type'] == 'mergePoint':
                    diagramElm = self.create_merge_node(serviceDiagramContentPackage, element)
                    position = {}
                    position['x'] = element['position']['x_corner'] + diagramPosition['x']
                    position['y'] = element['position']['y_corner'] + diagramPosition['y']
                    position['h'] = element['position']['h']
                    position['w'] = element['position']['w']
                    color = element['fill']
                    diagramObject = self.add_component_in_diagram(functionDiagram, diagramElm, position, color=color)
                    dict_of_diagramElements[element['id']] = diagramElm
                    dict_of_yFlowGenNodes_by_id[element['id']] = element

            for element in functionYFlowgenDict['elements']:
                if element['type'] == 'link':
                    source_element = dict_of_diagramElements[element['source_node']]
                    target_element = dict_of_diagramElements[element['target_node']]
                    source_yFlowGenNode = dict_of_yFlowGenNodes_by_id[element['source_node']]
                    target_yFlowGenNode = dict_of_yFlowGenNodes_by_id[element['target_node']]
                    connector = self._instance.createConnectorBetweenTwoNods(source_element, target_element, element['label'])
                    diagramLink = self._instance.get_related_diagramLink_by_connector(functionDiagram, connector)
                    new_pathList = []
                    node_margin_to_ignore_points = 10
                    for idx, pointStr in enumerate(element['path']):
                        point_x = float(pointStr.split(',')[0]) + diagramPosition['x']
                        point_y = float(pointStr.split(',')[1]) + diagramPosition['y']
                        if not (((point_x > source_yFlowGenNode['position']['x_corner'] - node_margin_to_ignore_points + diagramPosition['x']) \
                                and (point_x < (source_yFlowGenNode['position']['x_corner'] + node_margin_to_ignore_points + diagramPosition['x'] + source_yFlowGenNode['position']['w'])) \
                                and (point_y > source_yFlowGenNode['position']['y_corner'] - node_margin_to_ignore_points + diagramPosition['y']) \
                                and (point_y < (source_yFlowGenNode['position']['y_corner'] + node_margin_to_ignore_points + diagramPosition['y'] + source_yFlowGenNode['position']['h']))) \
                            or ((point_x > target_yFlowGenNode['position']['x_corner'] - node_margin_to_ignore_points + diagramPosition['x']) \
                                and (point_x < (target_yFlowGenNode['position']['x_corner'] + node_margin_to_ignore_points + diagramPosition['x'] + target_yFlowGenNode['position']['w'])) \
                                and (point_y > target_yFlowGenNode['position']['y_corner'] - node_margin_to_ignore_points + diagramPosition['y']) \
                                and (point_y < (target_yFlowGenNode['position']['y_corner'] + node_margin_to_ignore_points + diagramPosition['y'] + target_yFlowGenNode['position']['h'])))):
                            new_pathList.append(str(point_x) + ',' + str(point_y))
                    element['path'] = new_pathList
                    self._instance.process_link_visual_path(diagramLink, element)

            functionDiagram.Update()

            table_background_element = self.create_emptyAction(serviceDiagramContentPackage)
            position1 = {}
            position1['x'] = 25
            position1['y'] = 25
            position1['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin + 100
            position1['w'] = 650
            color = -1
            table_background_diagramObject = self.add_component_in_diagram(functionDiagram, table_background_element, position1, color=color)
            table_background_diagramObject.Update()
            functionDiagram.DiagramObjects.Refresh()
            functionDiagram.Update()

            diagram_background_element = self.create_emptyAction(serviceDiagramContentPackage)
            position2 = {}
            position2['x'] = 25
            position2['y'] = position1['x'] + position1['h'] + 25
            if end_y_position != 0:
                position2['h'] = end_y_position - position2['y'] + 25
            else:
                position2['h'] = (functionYFlowgenDict['y_max'] - functionYFlowgenDict['y_min']) + 130
            position2['w'] = (functionYFlowgenDict['x_max'] - functionYFlowgenDict['x_min']) + 50
            color = 0xf0f2e3
            diagram_background_diagramObject = self.add_component_in_diagram(functionDiagram, diagram_background_element, position2, color=color)
            diagram_background_diagramObject.Update()
            functionDiagram.DiagramObjects.Refresh()
            functionDiagram.Update()

            # set layers
            backElementsCounter = 0
            for idx in range(functionDiagram.DiagramObjects.Count):
                elm = functionDiagram.DiagramObjects.GetAt(idx)
                if elm.ElementID == table_background_diagramObject.ElementID:
                    backElementsCounter += 1
                    elm.Sequence = functionDiagram.DiagramObjects.Count - 1
                elif elm.ElementID == diagram_background_diagramObject.ElementID:
                    backElementsCounter += 1
                    elm.Sequence = functionDiagram.DiagramObjects.Count
                else:
                    elm.Sequence = idx + 1 - backElementsCounter
                elm.Update()

        else:
            table_background_element = self.create_emptyAction(serviceDiagramContentPackage)
            position1 = {}
            position1['x'] = 25
            position1['y'] = 25
            position1['h'] = table_top_margin + (default_number_of_rows * table_default_row_height) + ((nr_of_rows - default_number_of_rows) * table_added_row_height) + table_bottom_margin + 100
            position1['w'] = 650
            color = -1
            table_background_diagramObject = self.add_component_in_diagram(functionDiagram, table_background_element, position1, color=color)
            table_background_diagramObject.Update()
            functionDiagram.DiagramObjects.Refresh()
            functionDiagram.Update()

            # set layers
            backElementsCounter = 0
            for idx in range(functionDiagram.DiagramObjects.Count):
                elm = functionDiagram.DiagramObjects.GetAt(idx)
                if elm.ElementID == table_background_diagramObject.ElementID:
                    backElementsCounter += 1
                    elm.Sequence = functionDiagram.DiagramObjects.Count
                else:
                    elm.Sequence = idx + 1 - backElementsCounter
                elm.Update()

        return functionDiagram


    def get_number_of_text_rows(self, text: str, cell_width: int):
        nr_of_rows = 0

        for paragraph in text.split('\n'):
            line_width = 0
            nr_of_rows += 1
            for word in paragraph.split(' '):
                word_width = self.get_calibri6_word_width_in_pixels(word + ' ')
                sameWordFlag = True
                while sameWordFlag:
                    if line_width == 0 and word_width > cell_width:
                        nr_of_rows += 1
                        word_width -= cell_width
                        line_width = 0
                    elif (line_width + word_width) > cell_width:
                        nr_of_rows += 1
                        line_width = 0
                    else:
                        sameWordFlag = False
                        line_width += word_width

        return nr_of_rows


    def get_calibri6_word_width_in_pixels(self, word: str):
        calibri_widths_60 = {' ': 2, '!': 2, '"': 3, '#': 5, '$': 5, '%': 8, '&': 6, "'": 2, '(': 3, ')': 3, '*': 4,
                             '+': 5, ',': 2, '-': 3, '.': 2, '/': 3, '0': 5, '1': 5, '2': 5, '3': 5, '4': 5, '5': 5,
                             '6': 5, '7': 5, '8': 5, '9': 5, ':': 2, ';': 2, '<': 5, '=': 5, '>': 5, '?': 4, '@': 8,
                             'A': 6, 'B': 5, 'C': 6, 'D': 6, 'E': 5, 'F': 5, 'G': 6, 'H': 6, 'I': 2, 'J': 4, 'K': 6,
                             'L': 5, 'M': 9, 'N': 6, 'O': 6, 'P': 5, 'Q': 6, 'R': 6, 'S': 5, 'T': 5, 'U': 6, 'V': 6,
                             'W': 9, 'X': 6, 'Y': 5, 'Z': 5, '[': 3, '\\': 3, ']': 3, '^': 4, '_': 5, '`': 3, 'a': 4,
                             'b': 5, 'c': 4, 'd': 5, 'e': 4, 'f': 4, 'g': 5, 'h': 5, 'i': 2, 'j': 2, 'k': 5, 'l': 2,
                             'm': 9, 'n': 5, 'o': 5, 'p': 5, 'q': 5, 'r': 4, 's': 4, 't': 4, 'u': 5, 'v': 5, 'w': 7,
                             'x': 5, 'y': 5, 'z': 4, '{': 3, '|': 2, '}': 3, '~': 5}

        other_char_width = 3
        dist_between_two_chars = 0.5

        word_width_in_pixels = 0
        for char in word:
            if char in calibri_widths_60.keys():
                word_width_in_pixels += (calibri_widths_60[char] * 1.05) + dist_between_two_chars
            else:
                word_width_in_pixels += other_char_width + dist_between_two_chars

        return word_width_in_pixels


    def replace_xml_special_chars(self, text):
        text = text.replace('&', '&amp;')
        text = text.replace('<', '&#60;')
        text = text.replace('>', '&#62;')
        text = text.replace('"', '&quot;')
        text = text.replace("'", '&apos;')
        return text


    def create_sw_component_package(self, parent: Package, swcName: str, doxygen_Dictionary_for_swc: dict, yFlowgen_Dictionary_for_swc: dict, yaml_config_file: dict):
        swc_package = self._instance.findOrCreatePackage(parent, swcName, True)

        tryCount = 0
        while tryCount < 10:
            try:
                for packageIndex in range(swc_package.Packages.Count):
                    swc_package.Packages.DeleteAt(packageIndex, True)
                tryCount = 10
            except:
                print('Retry to delete package "' + swcName + '" !')
                tryCount += 1

        macros_package = self._instance.findOrCreatePackage(swc_package, 'Macros', True)
        macroTablesPackage = self._instance.findOrCreatePackage(macros_package, 'macroTables', True)
        for macroName in doxygen_Dictionary_for_swc['defines']:
            defineDoxyDict = doxygen_Dictionary_for_swc['defines'][macroName]
            [macroTable, nr_of_rows] = self.create_customTable_for_macro(macroTablesPackage, macroName, defineDoxyDict)
            self.create_diagram_for_macro(macros_package, macroName, macroTable, nr_of_rows, macroTablesPackage)

        variables_package = self._instance.findOrCreatePackage(swc_package, 'Variables', True)
        variableTablesPackage = self._instance.findOrCreatePackage(variables_package, 'variablesTables', True)
        for variableName in doxygen_Dictionary_for_swc['variables']:
            variableDoxyDict = doxygen_Dictionary_for_swc['variables'][variableName]
            [variableTable, nr_of_rows] = self.create_customTable_for_variable(variableTablesPackage, variableName, variableDoxyDict)
            self.create_diagram_for_variable(variables_package, variableName, variableTable, nr_of_rows, variableTablesPackage)

        services_package = self._instance.findOrCreatePackage(swc_package, 'Services', True)
        elements = []
        for index in range(services_package.Elements.Count):
            elements.append(services_package.Elements.GetAt(index))
        servicesDiagramsContentPackage = self._instance.findOrCreatePackage(services_package, 'servicesDiagramsContent', True)
        for functionName in doxygen_Dictionary_for_swc['functions']:
            functionDoxyDict = doxygen_Dictionary_for_swc['functions'][functionName]
            serviceDiagramContentPackage = self._instance.findOrCreatePackage(servicesDiagramsContentPackage, functionName, True)
            [functionTable, nr_of_rows] = self.create_customTable_for_function(serviceDiagramContentPackage, functionName, functionDoxyDict)

            if functionName in yFlowgen_Dictionary_for_swc.keys():
                functionYFlowgenDict = yFlowgen_Dictionary_for_swc[functionName]
            else:
                functionYFlowgenDict = None
                print('WARN -> Function "' + functionName + '" does not have a corresponding yFlowgen generated Diagram!!')

            self.create_diagram_for_function(services_package, functionName, functionTable, nr_of_rows, functionYFlowgenDict, serviceDiagramContentPackage)


    def kill_EA_process(self):
        call = 'TASKLIST', '/FI', 'imagename eq %s' % 'EA.exe'
        # use buildin check_output right away
        output = subprocess.check_output(call).decode()
        # check in last line for process name
        last_line = output.strip().split('\r\n')[-1]
        last_line_split = last_line.split(' ')
        last_line_words = []
        for word in last_line_split:
            if not word == '':
                last_line_words.append(word)
        PID = int(last_line_words[1])
        os.kill(PID, signal.SIGTERM)


    def sw_components_instance(self, swc: str,  doxygen_Dictionary_for_swc: dict, yFlowgen_Dictionary_for_swc: dict, yaml_config_file: dict):
        project_open_in_background = False
        self._instance = EAInstance()
        repository = self._instance._app.Repository
        try:
            models = repository.Models
        except:
            repository.OpenFile(yaml_config_file['EA_project_path'])
            project_open_in_background = True

        package = self.locate_root_package()
        self.create_sw_component_package(package, swc, doxygen_Dictionary_for_swc, yFlowgen_Dictionary_for_swc, yaml_config_file)

        if project_open_in_background:
            self.kill_EA_process()