============
build_assist
============

Purpose
-------

The utility is aim to create the make build environment.

Create a distribution and wheel
-------------------------------

Run `python setup.py sdist bdist_wheel`
or `py -3 setup.py sdist bdist_wheel`

CLI
---

aria_wrapper
~~~~~~~~~~~~

**ARIA utility tools for the makefile environment**

`aria_wrapper -m --excel arg --xml arg -h`

-m              To generate the mockup xml for the unit test
--excel arg     The file name of NVM calibrate data (Excel format)
--xml arg       The file name of unit test mockup xml file
-h              show the help information

Example for aria_wrapper
^^^^^^^^^^^^^^^^^^^^^^^^

To be defined

qac_analysis
~~~~~~~~~~~~~~~

**QAC analysis**

`qac_analysis [-c arg][-a][-r arg][-m arg][-h|--help]`

-c arg    Specific the component name which needs to be check
-a        Check all the components
-r arg    The root path of the components (Example: S:\Components\Application)
-m arg    The root path of the metrics (Example: S:\Metrics)
-h        Show this information
--help    Show this information

Note: Component name is case-sensitive.

Example for qac_analysis
^^^^^^^^^^^^^^^^^^^^^^^^

**Perform the QAC analysis for ATM module**

`qac_analysis -c ATM`

**Perform the QAC analysis for all modules**

`qac_analysis -a`

**Perform the QAC analysis for ATM module with the specific path**

`qac_analysis -c ATM -r C:\Sandbox\GWM_VV7_Phase_01_Development\Components\Application -m C:\Sandbox\GWM_VV7_Phase_01_Development\Metrics`

