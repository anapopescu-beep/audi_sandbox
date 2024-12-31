PLS UDE {#UDE}
=======

Script to read out the T1.scope trace buffer and write it to text files , for using
with the PLS UDE.

The script comes in two variants:

1. _T1_coreX.vbs_, this Visual Basic Script is meant to be executed as a UDE macro.
   - Go to _Tools_ -> _Macros..._
   - _Open File..._
   - Browse to and open _T1_coreX.vbs_
   - A new entry in the list of macros should appear: _readT1TraceBufferCoreAll_
   - You can run the script by selecting it and hit _Run_ or by creating a dedicated
     menu or toolbar item. Use the _Assign to_ button to create these entries.
2. _T1_coreX.py_, this script is meant to be executed using an external Python 3
   interpreter. It will use Windows Component Object Model (COM) to communicate with
   the UDE.
