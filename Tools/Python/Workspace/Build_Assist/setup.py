"""
MAIN ENTRY FOR SETUP OF BUILD MANAGEMENT ASSIST
The assistant for the Autoliv build management environment.
"""

from setuptools import setup, find_packages
import sys

setup(

    name='build_assist',
    version = '2.0.0',
    license = 'proprietary',
    description="The assistant for the autoliv build environment",

    author = 'Dan Dan Dustinta',
    author_email = "dan.dustinta@autoliv.com",
    url="",

    packages = find_packages(where='src'),
    package_dir= {'': 'src'},

    install_requires=['setuptools', 'pyyaml', 'bincopy', 'fpdf', 'openpyxl', 'image', 'matplotlib', 'argparse', 'pathlib', 'pywin32', 'numpy'],

    include_package_data=True,
    
    extras_require={'pytest': 'pytest-cov'},

    entry_points={
        'console_scripts': [
            'change_sw_version    = build_assist.cli.change_sw_version:main',
            'cksum                = build_assist.cli.cksum:main',
            'eclipse_prj_gen      = build_assist.cli.eclipse_prj_gen:main',
            'generate_nvp_files   = build_assist.cli.generate_nvp_files:main',
            'path_cleaner         = build_assist.cli.path_cleaner:main',
            'report_gen           = build_assist.cli.report_gen:main',
            'srec_cat_wrapper     = build_assist.cli.srec_cat_wrapper:main',
            'zip                  = build_assist.cli.zip:main'
        ]
    }
)
