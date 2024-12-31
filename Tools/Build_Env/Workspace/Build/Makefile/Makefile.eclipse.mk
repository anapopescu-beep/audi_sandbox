%-eclipse: ## %-eclipse : generates an eclipse project and workspace for the selected software component
ifeq ($(GENERATE_ECLIPSE),TRUE)
ifeq ($(CLEAN_ECLIPSE_PROJECT),TRUE)
	if [ -d "$(ECLIPSE_WORKSPACE_DIR)/eclipse_project/$(TARGET_KEY)" ]
	then
		echo "Cleaning directory: $(ECLIPSE_WORKSPACE_DIR)/eclipse_project/$(TARGET_KEY)"
		rm -rf $(ECLIPSE_WORKSPACE_DIR)/eclipse_project/$(TARGET_KEY) > /dev/null 2>&1 || true 
	fi
endif
ifeq ($(CLEAN_ECLIPSE_WORKSPACE),TRUE)
	if [ -d "$(ECLIPSE_WORKSPACE_DIR)/eclipse_workspace" ]
	then
		echo "Cleaning directory: $(ECLIPSE_WORKSPACE_DIR)/eclipse_workspace"
		rm -rf $(ECLIPSE_WORKSPACE_DIR)/eclipse_workspace > /dev/null 2>&1 || true 
	fi
endif
	echo "Generating eclipse project"
ifneq (,$(findstring Application,$(TARGET_KEY)))
	echo -e "linkDirs:\\n \
	- $(call getWinDir,$(CURRENT_DIR)/../)\\n \
	- $(call getWinDir,$(OUTPUT_DIR)/../Includes)\\n \
	- $(call getWinDir,$(OUTPUT_DIR))\\n" > $(CURRENT_DIR)/eclipse_config.yaml
else
	echo -e "linkDirs:\\n \
	- $(call getWinDir,$(CURRENT_DIR))\\n \
	- $(call getWinDir,$(OUTPUT_DIR))\\n" > $(CURRENT_DIR)/eclipse_config.yaml
endif
	echo -e -n "linkFiles:\\n\
	$(subst $(space)$(space),$(space),$(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach COMP,$(COMPONENT_C_SOURCES_$(COMPONENT)), - $(call getWinDir,$(COMP))\\n)))\
	$(subst $(space)$(space),$(space),$(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach COMP,$(COMPONENT_ASM_SOURCES_$(COMPONENT)), - $(call getWinDir,$(COMP))\\n)))\
	$(subst $(space)$(space),$(space),$(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach COMP,$(COMPONENT_H_SOURCES_$(COMPONENT)), - $(call getWinDir,$(COMP))\\n)))" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "\\nsystemDefines:\\n\
	$(subst $(space)$(space),$(space),$(foreach DEF,$(COMP_DEFINES) HIDE_IAR_SPECIFIC, - $(DEF)\\n))" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "incPathList:\\n\
	$(subst $(space)$(space),$(space),$(foreach INC,$(COMP_INCLUDES), - $(call getWinDir,$(INC))\\n))" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "genyComponentsPath: $(call getWinDir,$(GENY_COMPONENTS))" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "genyGnyPath: $(call getWinDir,$(GENY_GNY))" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "eclipseFolderConfig:" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(BSW_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Autoliv']" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(TGEN_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Supplier']" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(TGENMCAL_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Supplier']" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(EBSW_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Supplier']" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(NXPMCAL_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Supplier']" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(NXPSCST_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Supplier']" >> $(CURRENT_DIR)/eclipse_config.yaml
	echo -e "- [[$(foreach COMPONENT,$(T1_COMPONENTS_LIST),$(COMPONENT)$(comma) )], 'Sources/Supplier']" >> $(CURRENT_DIR)/eclipse_config.yaml
	eclipse_prj_gen "-p=$(PROJECT_NAME)" "-b=$(TARGET)" "-w=$(ECLIPSE_WORKSPACE_DIR)/eclipse_project/$(TARGET_KEY)" "-c=$(ECLIPSE_WORKSPACE_DIR)/../Config"
	cd $(CURRENT_DIR)/../
	$(CURRENT_DIR)/../eclipse.bat import_workspace $(TARGET_KEY)
	cd $(CURRENT_DIR)
endif
	cp -f $(CURRENT_DIR)/eclipse_config.yaml $(CURRENT_DIR)/tmp/eclipse_config_$(TARGET_KEY).yaml > /dev/null 2>&1 || true
	rm -f $(CURRENT_DIR)/eclipse_config.yaml > /dev/null 2>&1 || true

ifeq ($(RUN_ECLIPSE),TRUE)
	cd $(CURRENT_DIR)/../
	$(CURRENT_DIR)/../eclipse.bat post_import_workspace
	cd $(CURRENT_DIR)
endif

# filename    : Makefile.eclipse.mk
# description : Makefile contains eclipse project generation targets
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
