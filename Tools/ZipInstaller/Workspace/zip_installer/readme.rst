=============
zip_installer
=============

Purpose
-------

To install the zip package automatically

Unit test
---------

Run `pip install pytest pytest-cov` to install pytest.

Run `pytest --cov=alvsetup --cov-report term-missing`
to verify all the functionality.

Create a distribution and wheel
-------------------------------

Run `python setup.py sdist bdist_wheel`
or `py -3 setup.py sdist bdist_wheel`

CLI
---


zip_installer
~~~~~~~~~~~~~

**The utility tools to install the zip file according to the ini setting**

`zip_installer [-d arg] [--zip arg] [--path arg] [-h|--help] [-v|--verbose]`

-h              Show the help information
-d arg          Root path for the installation
-v              Print verbose information
--zip arg       The zip file name
--path arg      The installation path name
--verbose       Print verbose information
--help          Show this information

Example of the zip_installer
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

** Unpack the zip file to the specifc path directly **

`zip_installer --zip C:\Sandbox\GWM_VV7_Phase_01_Development\Tools\UnitTesting\Installation\cmocka.zip --path c:\prog\Unittesting -v`

** Installation with ini file **

`zip_installer -d C:\Sandbox\GWM_VV7_Phase_01_Development\Tools\UnitTesting`