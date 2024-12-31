from ea_assist.lib.ea_generator import EAGenerator


list_of_selected_swcs = ['SWC_name1', 'SWC_name2']


def main():
    createEaPrj()


def createEaPrj():
    # generate EA project
    ea_generator = EAGenerator()
    ea_generator.sw_components_instance(list_of_selected_swcs)


main()