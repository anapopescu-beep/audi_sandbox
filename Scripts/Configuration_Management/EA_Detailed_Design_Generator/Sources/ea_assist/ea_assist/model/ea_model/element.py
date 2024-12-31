from .type_def import ObjectType
from enum import IntEnum
from typing import Protocol, runtime_checkable, Any, TypeVar

@runtime_checkable
class Updateable(Protocol):
    def Update(self) -> bool: ...


@runtime_checkable
class Collection(Updateable, Protocol):
    """See also https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/collection.html
    """
    Count: int
    ObjectType: ObjectType

    def AddNew(self, name: str, type: str) -> Any: ...
    def Delete(self, index: int) -> None: ...
    def GetAt(self, index: int) -> Any: ...
    def DeleteAt(self, index: int, refresh: bool) -> None: ...
    def Refresh(self) -> None: ...

@runtime_checkable
class TaggedValue(Updateable, Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/taggedvalue.html
    """
    ElementID: int
    FQName: str
    Name: str
    Notes: str
    ObjectType: ObjectType
    PropertyGUID: str
    PropertyID: int
    Value: str

    def GetAttribute(self, prop_name: str) -> str: ...
    def GetLastError(self) -> str: ...
    def HasAttributes(self) -> bool: ...
    def SetAttribute(self, prop_name: str, prop_value:str) -> bool: ...


@runtime_checkable
class PropertyType(Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/propertytype.html
    """
    Description: str
    Detail: str
    ObjectType: str
    Tag: str


class EnumRelationSetType(IntEnum):
    rsGeneralizeStart = 0
    rsGeneralizeEnd = 1
    rsRealizeStart = 2
    rsRealizeEnd = 3
    rsDependStart = 4
    rsDependEnd = 5
    rsParents = 6


@runtime_checkable
class ConnectorEnd(Updateable, Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/connectorend.html
    """
    Aggregation: int
    Alias: str
    AllowDuplicates: bool
    Cardinality: str
    Constraint: str
    Containment: str
    Derived: bool
    DerivedUnion: bool
    End: str
    # NOTE: Valid values: "frozen", "addOnly", "" (empty string)
    IsChangeable: str
    IsNavigable: bool
    Navigable: str
    ObjectType: ObjectType
    Role: str
    RoleType: str

    def GetLastError(self) -> str: ...


@runtime_checkable
class Connector(Updateable, Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/connector2_2.html
    """
    Alias: str
    AssociationClass: 'Element'
    ClientEnd: ConnectorEnd
    ConnectorGUID: str
    ConnectorID: int
    Constraints: Collection
    ConveyedItems: Collection
    CustomProperties: Collection
    DiagramID: int
    Direction: str
    EndPointX: int
    EndPointY: int
    EventFlags: str
    FQStereotype: str
    ForeignKeyInformation: str
    IsLeaf: bool
    IsRoot: bool
    IsSpec: bool
    MessageArguments: str
    MetaType: str
    MiscData: str
    Name: str
    Notes: str
    ObjectType: ObjectType
    Properties: Any
    ReturnValueAlias: str
    RouteStyle: int
    SequenceNo: int
    StartPointX: int
    StartPointY: int
    StateFlags: int
    Stereotype: str
    StereotypeEx: str
    StyleEx: str
    Subtype: str
    SupplierEnd: str
    SupplierID: str
    TaggedValues: str

    Type: str

    def GetLastError(self) -> str: ...
    def IsConnectorValid(self) -> bool: ...


@runtime_checkable
class Element(Updateable, Protocol):
    Abstract: str
    ActionFlags: str
    Alias: str
    AssociationClassConnectorID: int
    Attributes: Collection
    AttributesEx: Collection
    Author: str
    BaseClasses: Collection
    ClassfierID: int
    ClassifierID: int
    ClassifierName: str
    ClassifierType: str
    Complexity: str
    CompositeDiagram: 'Diagram'
    Connectors: Collection
    Constraints: Collection
    ConstraintsEx: Collection
    Created: 'Date'
    CustomProperties: Collection
    Diagrams: Collection
    Difficulty: str
    Efforts: Collection
    ElementGUID: str
    ElementID: int
    Elements: Collection
    EmbeddedElements: Collection
    EventFlags: str = ""
    Files: Collection
    GenFile: str
    Genlinks: str
    Gentype: str
    IsComposite: bool
    IsLeaf: bool
    IsNew: bool
    IsSpec: bool
    Issues: Collection
    Locked: bool = False
    MetaType: str
    Methods: Collection
    MethodsEx: Collection
    Name: str
    Notes: str
    ObjectType: ObjectType
    PackageID: int
    ParentID: int
    Properties: Collection
    PropertyType: PropertyType
    Requirements: Collection
    Stereotype: str
    StereotypeEx: str
    Tag: str
    TaggedValues: Collection
    TaggedValuesEx: Collection
    Tests: Collection
    Type: str

    def GetRelationSet(self, type: EnumRelationSetType) -> str: ...
    def Refresh(self) -> None: ...


@runtime_checkable
class Parameter(Updateable, Protocol):
    Alias: str
    ClassifierID: str
    Default: str
    IsConst: str
    Kind: str
    Name: str
    Notes: str
    ObjectType: ObjectType
    OperationID: int
    ParameterGUID: str
    Position: int
    Stereotype: str
    StereotypeEx: str
    Type: str


@runtime_checkable
class Method(Updateable, Protocol):
    Abstract: bool
    Behavior: str
    ClassifierID: str
    Code: str
    Concurrency: str
    FQStereotype: str
    IsConst: bool
    IsLeaf: bool
    IsPure: bool
    IsQuery: bool
    IsRoot: bool
    IsStatic: bool
    IsSynchronized: bool
    MethodGUID: str
    MethodID: int
    Name: str
    Notes: str
    ObjectType: ObjectType
    Parameters: Collection
    ParentID: int
    Pos: int
    PostConditions: Collection
    PreConditions: Collection
    ReturnIsArray: bool
    ReturnType: str
    StateFlags: str
    Stereotype: str
    StereotypeEx: str
    Style: str
    StyleEx: str
    TaggedValues: Collection
    Throws: str
    Visibility: str


class Project:
    def __init__(self):
        pass


class Reference:
    def __init__(self):
        pass


@runtime_checkable
class Package(Updateable, Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/package_2.html
    """
    BatchLoad: int
    BatchSave: int
    CodePath: str
    Connectors: Collection
    Diagrams: Collection
    Elements: Collection
    Name: str
    Notes: str
    ObjectType: ObjectType
    Owner: str
    Packages: Collection
    PackageId: int
    PackageGUID: str
    ParentId: int
    StereotypeEx: str

    def FindObject(self, dotted_id: str) -> Any: ...

@runtime_checkable
class Attribute(Updateable, Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/method.html
    """
    Alias: str
    AllowDuplicates: bool
    AttributeGUID: str
    AttributeID: int
    ClassifierID: int
    Container: str
    Containment: str
    Constraints: Collection
    Default: str
    FQStereotype: str
    IsCollection: bool
    IsConst: bool
    IsDerived: bool
    IsID: bool
    IsOrdered: bool
    IsStatic: bool
    Length: str
    LowerBound: str
    Name: str
    Notes: str
    ObjectType: ObjectType
    ParentID: int
    Pos: int
    Precision: str
    RedefinedProperty: str
    Scale: str
    Stereotype: str
    StereotypeEx: str
    SubsettedProperty: str
    TaggedValues: Collection
    TaggedValuesEx: Collection
    Type: str
    UpperBound: str
    Visibility: str


@runtime_checkable
class Repository(Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/repository3.html
    """
    Authors: Collection
    BatchAppend: bool
    Clients: Collection
    ConnectionString: str
    Datatypes: Collection
    EnableUIUpdates: bool
    FlagUpdate: bool
    InstanceGUID: str
    IsSecurityEnabled: bool
    Issues: Collection
    Models: Collection
    ProjectGUID: str
    Terms: Collection

    def CloseFile(self) -> None: ...
    def GetAttributeByGuid(self, guid: str) -> Attribute: ...
    def GetAttributeByID(self, id: str) -> Attribute: ...
    def GetConnectorByGuid(self, guid: str) -> Connector: ...
    def GetConnectorByID(self, connector_id: int) -> Connector: ...
    def GetContextItem(self, obj: Any) -> ObjectType: ...
    def GetContextItemType(self) -> ObjectType: ...
    def GetContextObject(self) -> Any: ...
    def GetCounts(self) -> str: ...
    def GetCurrentDiagram(self) -> 'Diagram': ...
    def GetDiagramByGuid(self, guid: str) -> 'Diagram': ...
    def GetDiagramByID(self, id: int) -> 'Diagram': ...
    def GetElementByGuid(self, guid: str) -> Element: ...
    def GetElementByID(self, id: int) -> Element: ...
    def GetElementsByQuery(self, query_name: str, search_term: str,
                           ) -> Collection: ...
    def GetElementSet(self, id_list: str, options: int) -> Collection: ...
    def GetLastError(self) -> str: ...
    def GetLocalPath(self, type: str, path: str) -> str: ...
    def GetMethodByGuid(self, guid: str) -> Method: ...
    def GetMethodById(self, id: int) -> Method: ...
    def GetPackageByGuid(self, guid: str) -> Package: ...
    def GetPackageByID(self, id: int) -> Package: ...
    def GetProjectInterface(self) -> Project: ...
    def GetReferenceList(self, type: str) -> Reference:
        """ Valid types:
            Diagram, Element, Constraint, Requirement, Connector
            Status, Cardinality, Effort, Metric, Scenario, Status
            Test, List:DifficultyType, List:PriorityType
            List:TestStatusType, List:ConstStatusType

            @param type one of the valid types
        """
        ...
    def GetTreeSelectedElements(self) -> Collection: ...
    def GetTreeSelectedItem(self, object: Any) -> ObjectType: ...
    def GetTreeSelectedItemType(self, object: Any) -> ObjectType: ...
    def GetTreeSelectedObject(self, object: Any) -> ObjectType: ...
    def GetTreeSelectedPackage(self) -> Package: ...
    def OpenFile(self, filename: str) -> bool: ...
    def SQLQuery(self, query: str) -> bool: ...


@runtime_checkable
class Model(Updateable, Protocol):
    """See
    """
    Name: str
    PackageID: int
    Packages: Collection


@runtime_checkable
class App(Protocol):
    """See https://sparxsystems.com/enterprise_architect_user_guide/15.2/automation/app.html
    """
    Project: str
    Repository: Repository
    Visible: bool

from .diagram import Diagram # noqa