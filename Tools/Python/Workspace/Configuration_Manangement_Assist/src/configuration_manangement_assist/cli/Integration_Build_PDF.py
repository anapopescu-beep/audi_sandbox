"""Integration_Build_PDF.py: Used to generate a PDF file with integration of SW components from build outputs of Jenkins
"""

__author__ = 'Emilian Gustescu'
__copyright__ = "Copyright 2023, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'emilian.gustescu@autoliv.com'
__status__ = 'Released'

import argparse
import re
import fpdf


def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path-file', help="Path to changelog file.", required=True)
    parser.add_argument('-t', '--input-build-number', help="Build number from Jenkins", required=True)
    parser.add_argument('-o', '--output-path-file', help="Path to output PDF file.", required=True)
    args = parser.parse_args()

    path_to_input_log = args.input_path_file
    path_to_build_number = args.input_build_number
    path_to_output_file = args.output_path_file

    list_of_text = []

    with open(path_to_input_log) as mytxt:
        for line in mytxt:
            list_of_text.append(line)

    list_of_files = []
    list_of_paths = []
    list_of_modules = []
    current_elem = 0
    for elem in list_of_text:
        if ".c<" in elem or ".h<" in elem:
            if "Implementation" in list_of_text[current_elem + 2]:
                file = elem
                file = file.strip()
                file = file.replace("<file>", "").replace("</file>", "")
                list_of_files.append(file)
                path = list_of_text[current_elem + 2]
                path = path.strip()
                path = path.replace("<context>", "").replace("</context>", "").replace("project.pj", file)
                list_of_paths.append(path)
                first_match = (re.search("Autoliv/", path))
                first_find = first_match.span()
                first_pos = first_find[1]
                second_match = (re.search("/Implementation", path))
                second_find = second_match.span()
                second_pos = second_find[0]
                module = ""
                for letter in range(first_pos, second_pos):
                    module = module + path[letter]
                list_of_modules.append(module)

        current_elem+=1

    pdf = fpdf.FPDF(format='letter')
    pdf.add_page()
    pdf.set_font("Arial", size=12)


    for elem in range(0, len(list_of_paths)):
        pdf.write(5, "File:   ")
        pdf.write(5, list_of_files[elem])
        pdf.ln()
        pdf.write(5, "Path:   ")
        pdf.write(5, list_of_paths[elem])
        pdf.ln()
        pdf.write(5, "Module:   ")
        pdf.write(5, list_of_modules[elem])
        pdf.ln()
        pdf.ln()
        pdf.ln()
        pdf.ln()

    pdf.write(5, "Changelog from Build number:  " + str(path_to_build_number))

    pdf.output(path_to_output_file + "\Build_Integration_Report.pdf")

    print("Script ran successfully")

if __name__ == "__main__":
    main()
