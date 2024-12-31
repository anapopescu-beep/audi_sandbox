"""
MAIN ENTRY FOR SETUP OF CONFIGURATION MANAGEMENT ASSIST
The assistant for the Autoliv configuration management environment.
"""

from setuptools import setup, find_packages
import sys

setup(
    name='configuration_manangement_assist',
    version = '1.0.0',
    license = 'proprietary',
    description="The assistant for the autoliv configuration_manangement_assist environment",

    author = 'Lucian Ardeleanu',
    author_email = "lucian.ardeleanu@autoliv.com",
    url="",
    
    packages = find_packages(where='src'),
    package_dir= {'': 'src'},

    install_requires=['setuptools', 'pyyaml', 'bincopy', 'fpdf', 'openpyxl', 'image', 'matplotlib', 'argparse', 'pathlib', 'pywin32','pywin32-ctypes', 'pypiwin32', 'numpy', 'pandas', 'selenium', 'wrap', 'PyYAML', 'natsort', 'xlrd', 'xlsxwriter', 'openpyxl', 'Pillow'],

    include_package_data=True,
    
    extras_require={'pytest': 'pytest-cov'},

    entry_points={
        'console_scripts': [
            'Integration_Build_PDF                    = configuration_manangement_assist.cli.Integration_Build_PDF:main',
            'Issue_Report                             = configuration_manangement_assist.cli.Issue_Report:main',
            'Jenkins_build_analyser                   = configuration_manangement_assist.cli.Jenkins_build_analyser:main',
            'peer_review_and_warningReport_analysis   = configuration_manangement_assist.cli.peer_review_and_warningReport_analysis:main',
            'plm_tracker                              = configuration_manangement_assist.cli.plm_tracker:main',
            'Process_OpenProject_Data                 = configuration_manangement_assist.cli.Process_OpenProject_Data:main',
            'ptc_cp_wrapper                           = configuration_manangement_assist.cli.ptc_cp_wrapper:main',
            'ptc_issue_report                         = configuration_manangement_assist.cli.ptc_issue_report:main',
            'ptc_tracker                              = configuration_manangement_assist.cli.ptc_tracker:main',
            'qac_warning_parser                       = configuration_manangement_assist.cli.qac_warning_parser:main',
            'qac_warning_plotter                      = configuration_manangement_assist.cli.qac_warning_plotter:main',
            'SysSwPF_generator                        = configuration_manangement_assist.cli.SysSwPF_generator:main', 
            'VeraRunner                               = configuration_manangement_assist.cli.VeraRunner:main',
            'warning_parser                           = configuration_manangement_assist.cli.warning_parser:main'
        ]
    }
)
