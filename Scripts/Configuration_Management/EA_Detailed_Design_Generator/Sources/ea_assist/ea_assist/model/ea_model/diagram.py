from .exception import MethodCallError
from .type_def import ObjectType
from typing import Protocol, runtime_checkable

from .element import Collection, Updateable

class Connector:
    def __init__(self):
        pass


@runtime_checkable
class Diagram(Updateable, Protocol):
    Author: str
    createdData: str
    cx: int
    cy: int
    DiagramGUID: str
    DiagramID: int
    DiagramLinks: Collection
    DiagramObjects: Collection
    ExtendedStyle: str
    FilterElements: str
    HighlightImports: bool
    IsLocked: bool
    MetaType: str
    ModifiedDate: str
    Name: str
    Notes: str
    ObjectType: ObjectType
    Orientation: str
    PackageID: int
    PageHeight: int
    PageWidth: int
    ParentID: int
    Scale: int
    SelectedConnector: Connector
    SelectedObjects: Connector
    ShowDetails: int
    ShowPackageContents: bool
    ShowPrivate: bool
    ShowProtected: bool
    ShowPublic: bool
    Stereotype: str
    StyleEx: str
    Swimlanes: str
    SwimlaneDef: SwimlaneDef  = None  # type: SwimlaneDef
    Type: str
    Version: str

    def FindElementInDiagram(self, element_id: int) -> bool: ...