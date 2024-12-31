"""change_sw_version.py: Used to change the SW version in given file"""

__author__ = 'Lucian Ardeleanu'
__copyright__ = "Copyright 2023, Autoliv Electronics"
__version__ = "1.0.0"
__email__ = 'lucian.ardeleanu@autoliv.com'
__status__ = 'Released'

import argparse
import re
import sys
import os

currentDir = os.getcwd()
sys.path.append(currentDir)

def get_pattern_from_DIA_src_file_without_old_sw_version(line):
    found_sw_version = re.findall('\s*=\s*"((\w*).(\w*))"\s*;', line)
    list_of_matches = []
    if found_sw_version is not None:
        for match in found_sw_version:
            list_of_matches.append(match[0])
        return list_of_matches
    else:
        return None

def get_old_sw_version_from_DIA_src_file(line, old_sw_version):
    found_sw_version = re.search('\s*=\s*"(' + old_sw_version + ')"\s*;', line)
    if found_sw_version is not None:
        return found_sw_version.group(1)
    else:
        return None

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file-path', help="Path to file in which to change SW version", required=True)
    parser.add_argument('-s', '--new-swversion', help="New Software Version", required=True)
    parser.add_argument('-o', '--old-swversion', help="Old Software Version. Legacy option, should not be used. If not given, will be search a pattern defined by XXXXXX.XXX", required=False, default=None)
    args = parser.parse_args()

    # Routine used to read given input file
    input_file_obj = open(args.file_path, 'r')
    input_file = input_file_obj.read()
    input_file_obj.close()

    # Get new software version from arguments
    new_sw_version = args.new_swversion

    # Initialise a modified file variable with a input file data in order to avoid file corruption
    modified_file = input_file

    print('Change Software Version Script')

    # Check if an old software version is given
    if args.old_swversion is not None:

        # Search for old sw version
        old_sw_version = get_old_sw_version_from_DIA_src_file(input_file, args.old_swversion)

        if old_sw_version is not None:
            (modified_file, no_of_replacements) = re.subn(old_sw_version, new_sw_version, input_file)
            print('Old software version', old_sw_version, 'was changed with', new_sw_version, 'in', no_of_replacements, 'occurences!')
        else:

            # if we don't find a sw version, we will try to find a pattern in order to be changed.
            print('Old software version not found in source code file! Will be tried changing of a pattern like XXXXXX.XXX')

            # Search for a pattern writed in source code file that should look like a software version
            found_pattern_list = get_pattern_from_DIA_src_file_without_old_sw_version(input_file)

            # if a pattern was found in source code file
            if found_pattern_list is not None:

                # iterate in each pattern found and it's index
                for found_pattern, found_pattern_idx in zip(found_pattern_list, range(0, len(found_pattern_list))):

                    # If we are in the first pattern
                    if (found_pattern_idx == 0):

                        # Modify the input_file
                        (modified_file, no_of_replacements) = re.subn(found_pattern, new_sw_version, input_file)
                    else:

                        # Otherwise, modify modified_file, in order to keep modifications from the first occurence!
                        (modified_file, no_of_replacements) = re.subn(found_pattern, new_sw_version, modified_file)

                    print('Pattern found', found_pattern, 'was changed with', new_sw_version, 'in', no_of_replacements,'occurences!')

    else:
        print('No old SW version was given, a pattern like XXXXXX.XXX will be replaced with given SW version!')

        # Search for a pattern writed in source code file that should look like a software version
        found_pattern_list = get_pattern_from_DIA_src_file_without_old_sw_version(input_file)

        # if a pattern was found in source code file
        if found_pattern_list is not None:

            # iterate in each pattern found and it's index
            for found_pattern, found_pattern_idx in zip(found_pattern_list, range(0, len(found_pattern_list))):

                # If we are in the first pattern
                if ( found_pattern_idx == 0):

                    # Modify the input_file
                    (modified_file, no_of_replacements) = re.subn(found_pattern, new_sw_version, input_file)
                else:

                    # Otherwise, modify modified_file, in order to keep modifications from the first occurence!
                    (modified_file, no_of_replacements) = re.subn(found_pattern, new_sw_version, modified_file)
                print('Pattern found', found_pattern, 'was changed with', new_sw_version, 'in', no_of_replacements, 'occurences!')
        else:
            print('Neither an old sw version is given or a pattern like XXXXXX.XXX found, sw version will not be changed!')


    output_file = open(args.file_path, 'w+')
    output_file.write(modified_file)
    output_file.close()

if __name__ == '__main__':
    main()
