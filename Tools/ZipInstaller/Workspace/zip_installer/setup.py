"""Minmal setup file for SWATT Helper"""

from setuptools import setup, find_packages

import sys

setup(
    name='zip_installer',
    version = '1.0.1',
    license = 'proprietary',
    description="The installation tools for the Zip packages",

    author = 'Reymond Zhang',
    author_email = "reymond.zhang@autoliv.com",
    url="",

    python_requires=">=3.5",

    packages = find_packages(where='src'),
    package_dir= {'': 'src'},

    #install_requires=['configparser', 'xlrd', 'xlwt'],
    install_requires=['configparser'],

    include_package_data=True,
    
    extras_require={'pytest': 'pytest-cov'},

    entry_points={
        'console_scripts': [
            'zip_installer    = zip_installer.cli.installer:installer_cli',
            #'mcal_variant   = zip_installer.cli.mcal_variant:mcal_variant_cli',
            #'vda_cali       = zip_installer.cli.vda_cali:vda_cali_cli',
            #'xdm_format     = zip_installer.cli.xdm:xdm_format_cli',
            #'pp4g_can       = zip_installer.cli.pp4g_can:pp4g_can_cli'
        ]
    }
)
