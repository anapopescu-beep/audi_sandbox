pdfReport: 
ifneq ($(REPORT_GENERATION),FALSE)
	echo "Generating build environment report"
	echo "project_name: $(PROJECT_NAME)" > $(CURRENT_DIR)/report_config.yaml
	
	echo "module_groups: {\
	heading: Module groups,\
	description: List of different source file groups present in the project,\
	values: [$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT),)] }\
	" >> $(CURRENT_DIR)/report_config.yaml

	echo "module_list: {\
	heading: Module list,\
	description: List of source files that can be found in the module groups,\
	values: {$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT): [$(foreach FILE,$(COMPONENT_C_SOURCES_$(COMPONENT)) $(COMPONENT_ASM_SOURCES_$(COMPONENT)),'$(FILE)',)],)} }\
	" >> $(CURRENT_DIR)/report_config.yaml
	
	echo "module_header_list: {\
	heading: Module Header list,\
	description: List of header files that can be found in the module groups,\
	values: {$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT): [$(foreach FILE,$(COMPONENT_H_SOURCES_$(COMPONENT)),'$(FILE)',)],)} }\
	" >> $(CURRENT_DIR)/report_config.yaml

#	echo "compiler_defines: {\
	heading: Compiler defines,\
	description: Global compiler defines,\
	values: [$(foreach DEF,$(COMP_DEFINES),'$(DEF)',)] }\
	" >> $(CURRENT_DIR)/report_config.yaml
	
#	echo "compiler_includes: {\
	heading: Compiler includes,\
	description: Global compiler includes,\
	values: [$(foreach INC,$(COMP_INCLUDES),'$(INC)',)] }\
	" >> $(CURRENT_DIR)/report_config.yaml

	echo "dep_opt: {\
	heading: Dependency options,\
	description: Global dependency options used by gcc for dependency tracking,\
	values: [\"(DEP_OPT)\"] }\
	" >> $(CURRENT_DIR)/report_config.yaml
	
	echo "comp_opt: {\
	heading: Compiler options,\
	description: Compiler options used by module groups,\
	values: {$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT): [\"$(COMP_OPT_$(COMPONENT))\"],)} }\
	" >> $(CURRENT_DIR)/report_config.yaml

	echo "asm_opt: {\
	heading: Assembler options,\
	description: Assembler options used by module groups,\
	values: {$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT): [$(foreach AOPT,$(ASM_OPT_$(COMPONENT)),'$(subst $@,$(TARGET),$(AOPT))',)],)} }\
	" >> $(CURRENT_DIR)/report_config.yaml	
	
	echo "link_opt: {\
	heading: Linker options,\
	description: Global linker options,\
	values: [$(foreach LOPT,$(LINK_OPT),'$(subst $@,$(TARGET),$(LOPT))',)] }\
	" >> $(CURRENT_DIR)/report_config.yaml	
	
	echo "link_libraries: {\
	heading: Link libraries,\
	description: Global link libraries,\
	values: [$(foreach LLIB,$(LINK_LIB_OBJ),'$(LLIB)',)] }\
	" >> $(CURRENT_DIR)/report_config.yaml	

	report_gen.exe -o=$(call getWinDir,$(CURRENT_DIR)/Report/$(TARGET_KEY)_build_report.pdf)
	
	rm -f $(CURRENT_DIR)/report_config.yaml > /dev/null 2>&1 || true 
endif

ifneq ($(VERA_DYN_FILTER),)
override FILTER:=$(VERA_DYN_FILTER)
endif

%-sanity_checks: ## %-sanity_checks FILTER= : runs vera++ to check common coding rules, FILTER must take the value of a source file e.g. FILTER=Adc.c
	echo "Running vera++ sanity check on $(notdir $(FILTER))"
		
	echo $(filter %$(notdir $(FILTER)),$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT_C_SOURCES_$(COMPONENT)))) | $(VERA_INSTALLATION_DIR)/bin/vera++.exe --transform trim_right;
	echo $(filter %$(notdir $(FILTER)),$(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT_C_SOURCES_$(COMPONENT)))) | $(VERA_INSTALLATION_DIR)/bin/vera++.exe --profile autoliv --warning;
	

.PHONY: pdfReport
	
# filename    : Makefile.report
# description : Makefile contains pdf report generation targets
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018, Autoliv Electronic
# version     : 1.0.2
# email       : dan.dustinta@autoliv.com
# status      : Released
