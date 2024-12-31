$(eval VARIANT_TARGET_KEY := $(if $(findstring Application,$(TARGET_KEY)),Application,$(TARGET_KEY)))
include $(VARIANT_TARGET_KEY)/Makefile.compiler.mk
include $(VARIANT_TARGET_KEY)/Makefile.config.mk
ifneq ($(MAKECMDGOALS),$(TARGET)-clean)
ifneq ($(TARGET),help)
ifneq ($(MAKECMDGOALS),callCheckInIARLicense)
include Makefile.utilities.mk
ifeq ($(MAKECMDGOALS),$(TARGET)-eclipse)
include Makefile.eclipse.mk
endif # ifeq ($(MAKECMDGOALS),$(TARGET)-eclipse)
include Makefile.report.mk

#SHELL += -x

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval SRC_COMPONENT_PATH_LIST_$(COMPONENT) := $(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_SOURCES_DIR,$(MODULE)))))

ifeq ($(PARSE_HEADER_FILES),TRUE)
$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval INC_COMPONENT_PATH_LIST_$(COMPONENT) := $(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE)))))
endif # ifeq ($(PARSE_HEADER_FILES),TRUE)

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval IGNORE_SOURCES_LIST_$(COMPONENT) := $(foreach IGNORE_SOURCE,$($(COMPONENT)_IGNORE_SOURCES_LIST),$(IGNORE_SOURCE))))

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval COMPONENT_C_SOURCES_$(COMPONENT) := $(foreach COMPONENT_PATH,$(SRC_COMPONENT_PATH_LIST_$(COMPONENT)),$(call not-containing,$(IGNORE_SOURCES_LIST_$(COMPONENT)),$(call rwildcard,$(COMPONENT_PATH)/,*.$(C_SUFFIX))))))

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval COMPONENT_ASM_SOURCES_$(COMPONENT) := $(foreach COMPONENT_PATH,$(SRC_COMPONENT_PATH_LIST_$(COMPONENT)),$(call not-containing,$(IGNORE_SOURCES_LIST_$(COMPONENT)),$(call rwildcard,$(COMPONENT_PATH)/,*.$(ASM_SUFFIX))))))

ifeq ($(PARSE_HEADER_FILES),TRUE)
$(info Parsing header files)
$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval COMPONENT_H_SOURCES_$(COMPONENT) := $(foreach COMPONENT_PATH,$(INC_COMPONENT_PATH_LIST_$(COMPONENT)),$(call not-containing,$(IGNORE_SOURCES_LIST_$(COMPONENT)),$(call rwildcard,$(COMPONENT_PATH)/,*.$(H_SUFFIX))))))
endif # ifeq ($(PARSE_HEADER_FILES),TRUE)

$(eval DEP_FILES := $(addprefix $(DEP_DIR)/,$(addsuffix .$(DEP_SUFFIX),$(basename $(notdir $(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT_C_SOURCES_$(COMPONENT))))))))

$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval OBJ_C_SOURCES_$(COMPONENT) := $(addprefix $(OBJ_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(notdir $(COMPONENT_C_SOURCES_$(COMPONENT))))))))
$(foreach COMPONENT,$(COMPONENTS_LIST),$(eval OBJ_ASM_SOURCES_$(COMPONENT) := $(addprefix $(OBJ_DIR)/,$(addsuffix .$(OBJ_SUFFIX),$(basename $(notdir $(COMPONENT_ASM_SOURCES_$(COMPONENT))))))))

$(eval ALL_COMPONENT_C_SOURCES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(COMPONENT_C_SOURCES_$(COMPONENT))))

$(eval ALL_OBJ_C_SOURCES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(OBJ_C_SOURCES_$(COMPONENT))))
$(eval ALL_OBJ_ASM_SOURCES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(OBJ_ASM_SOURCES_$(COMPONENT))))
$(eval ALL_OBJ_SOURCES := $(ALL_OBJ_C_SOURCES) $(ALL_OBJ_ASM_SOURCES))

include $(VARIANT_TARGET_KEY)/Makefile.compiler.options.mk

$(eval BINARY_FILE := $(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX))
ifeq ($(ELF_FILE_GENERATION),TRUE)
$(eval ELF_FILE := $(OUT_DIR)/$(TARGET).$(SYMBOL_SUFFIX))
endif # ifeq ($(ELF_FILE_GENERATION),TRUE)
$(eval SREC_FILE := $(OUT_DIR)/$(TARGET).$(SREC_SUFFIX))
$(eval LINKER_FILE := $(VARIANT_TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX))
ifneq ($(MAKECMDGOALS),$(TARGET)-eclipse)
	-include $(shell find $(DEP_DIR) -name '*.$(DEP_SUFFIX)')
endif # ifneq ($(MAKECMDGOALS),$(TARGET)-eclipse)
endif # ifneq ($(MAKECMDGOALS),callCheckInIARLicense)
endif # ifneq ($(TARGET),help)
endif # ifneq ($(MAKECMDGOALS),$(TARGET)-clean)

NECESSARY_OUTPUT_PATHS := $(OUTPUT_DIR) \
                          $(DEP_DIR) \
                          $(ERR_DIR) \
                          $(LST_DIR) \
                          $(OBJ_DIR) \
                          $(OUT_DIR)

$(RELEASE_DIR)/$(notdir $(SREC_FILE)): $(SREC_FILE) $(BINARY_FILE) $(UNIFIED_CALIBRATION_FILE) $(FULL_MEMORY_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE)) | $(RELEASE_DIR)
	if [ -d "$(RELEASE_DIR)" ]
	then
		echo "Cleaning directory: $(RELEASE_DIR)"
		rm -rf $(RELEASE_DIR) > /dev/null 2>&1 || true 
		mkdir -p $(RELEASE_DIR) > /dev/null 2>&1 || true 
	fi
	if [ ! -d $(RELEASE_DIR) ]
	then
		echo "Creating directory: $(RELEASE_DIR)"
		mkdir -p $(RELEASE_DIR) > /dev/null 2>&1 || true 
	fi
	if [ ! -d $(BASE_RELEASE_DIR)/CanFlash ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash"
		mkdir -p $(BASE_RELEASE_DIR)/CanFlash > /dev/null 2>&1 || true 
	fi
	echo Copying output to release folder
	cp -f $(OUT_DIR)/* $(RELEASE_DIR)
	
ifneq (,$(findstring Bootmanager,$(TARGET_KEY)))
	$(call srec_cat,$@ -fill 0xFF $(FBM_CROP_RANGE) -o  $(subst .s19,_$(FINAL_FILE_SUFFIX).s19,$@))
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/winIDEA"
	mkdir -p $(BASE_RELEASE_DIR)/winIDEA > /dev/null 2>&1 || true

	echo "Copying files that will be used for on-target flashing"
	cp -f $(subst .$(SREC_SUFFIX),_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX),$(BOOTMANAGER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(BOOTMANAGER_FILE))
	cp -f $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTMANAGER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTMANAGER_FILE)))

endif # ifneq (,$(findstring Bootmanager,$(TARGET_KEY)))

ifneq (,$(findstring Bootloader_updater,$(TARGET_KEY)))
	$(call srec_cat,$@ -fill 0xFF $(FBL_UPD_CROP_RANGE) -o  $(subst .s19,_$(FINAL_FILE_SUFFIX).s19,$@))
else
ifneq (,$(findstring Bootloader,$(TARGET_KEY)))
ifeq ($(BOLO_FLASH_VALIDATION),TRUE)
	$(call srec_cat,$@ -exclude $(FLASH_VALIDATION_START_ADDR_FBL) $(FLASH_VALIDATION_END_ADDR_FBL) -generate $(FLASH_VALIDATION_START_ADDR_FBL) $(FLASH_VALIDATION_END_ADDR_FBL) -repeat-data $(FLASH_VALIDATION_FLAG_FBL) -o $(subst .s19,_$(PFLASH_PATT_FILE_SUFFIX).s19,$@))
	$(call srec_cat,$(subst .s19,_$(PFLASH_PATT_FILE_SUFFIX).s19,$@) -fill 0xFF $(FBL_CROP_RANGE) -o  $(subst .s19,_$(PFLASH_PATT_FILE_SUFFIX).s19,$@))
endif # ifeq ($(BOLO_FLASH_VALIDATION),TRUE)
	echo "Creating Bootloader.c file"
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR)/hexview.exe $(subst .s19,_$(PFLASH_PATT_FILE_SUFFIX).s19,$@) /XC /P:$(POST_PROSESSING_DIR)/Makefile/Bootloader_updater/Bootloader_c_array.ini -o $(BASE_RELEASE_DIR)/CanFlash/Bootloader.c /G /s)
	cat $(BASE_RELEASE_DIR)/CanFlash/Bootloader.c  | sed '/_GEN_RAND/,/endif/d' > $(SOURCES_DIR)/../Bootloader_updater/Autoliv/FblUpdUsr/Implementation/src/Bootloader.c
	cat $(BASE_RELEASE_DIR)/CanFlash/Bootloader.h  | sed '/_GEN_RAND/d' > $(SOURCES_DIR)/../Bootloader_updater/Autoliv/FblUpdUsr/Implementation/inc/Bootloader.h
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/winIDEA"
	mkdir -p $(BASE_RELEASE_DIR)/winIDEA > /dev/null 2>&1 || true

	echo "Copying files that will be used for on-target flashing"
	cp -f $(subst .$(SREC_SUFFIX),_$(PFLASH_PATT_FILE_SUFFIX).$(SREC_SUFFIX),$(BOOTLOADER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(BOOTLOADER_FILE))
	cp -f $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTLOADER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTLOADER_FILE)))
endif # ifneq (,$(findstring Bootloader,$(TARGET_KEY)))
endif # else ifneq (,$(findstring Bootloader_updater,$(TARGET_KEY)))

ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	cp -f $(AEC_CALIBRATION_FILE) $(RELEASE_DIR)
endif
	cp -f $(CALIBRATION_FLASH_FILE) $(RELEASE_DIR)
	cp -f $(DEFAULT_FILE) $(RELEASE_DIR)
ifeq ($(DYNAMIC_E2P_SUPPORT),TRUE)
	cp -f $(DYNAMIC_E2P_FILE) $(RELEASE_DIR)
endif
	cp -f $(E2P_STUDY_FILE) $(RELEASE_DIR)
ifeq ($(E2P_SYMBOL_SUPPORT),TRUE)
	cp -f $(E2P_SYMBOL_FILE) $(RELEASE_DIR)
endif
	$(call srec_cat,$(DEFAULT_FILE) -crop $(DEFAULT_NVP_RANGE) -fill 0xFF $(DEFAULT_NVP_RANGE) -o $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX))
	$(call srec_cat,$(UNIFIED_CALIBRATION_FILE) -crop $(CALIBRATION_RANGE) -fill 0xFF $(CALIBRATION_RANGE) -o $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX))
	$(call srec_cat,$(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX)) -crop $(APPL_CROP_RANGE) -o $(RELEASE_DIR)/$(notdir $(basename $(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX))))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX))

ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(BOLO_FLASH_VALIDATION),TRUE)
	$(call srec_cat,$(RELEASE_DIR)/$(notdir $(basename $(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX))))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) -exclude $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -generate $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -repeat-data $(FLASH_VALIDATION_FLAG_APPL) -o $(RELEASE_DIR)/$(notdir $(basename $(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX))))_$(PFLASH_PATT_FILE_SUFFIX).$(SREC_SUFFIX))
	$(call srec_cat,$(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) -exclude $(FLASH_VALIDATION_START_ADDR_DEFAULT) $(FLASH_VALIDATION_END_ADDR_DEFAULT) -generate $(FLASH_VALIDATION_START_ADDR_DEFAULT) $(FLASH_VALIDATION_END_ADDR_DEFAULT) -repeat-data $(FLASH_VALIDATION_FLAG_DEFAULT) -o $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_$(PFLASH_PATT_FILE_SUFFIX).$(SREC_SUFFIX))
endif	
endif

	echo "Creating directory: $(BASE_RELEASE_DIR)/winIDEA"
	rm -rf $(BASE_RELEASE_DIR)/winIDEA > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/winIDEA > /dev/null 2>&1 || true

	echo "Copying files that will be used for on-target flashing"

	cp -f $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_$(PFLASH_PATT_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(basename $(DEFAULT_FILE))).$(SREC_SUFFIX)
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX))))_$(PFLASH_PATT_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(basename $(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX)))).$(SREC_SUFFIX)
	cp -f $(BINARY_FILE) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(BINARY_FILE))
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE))).$(SREC_SUFFIX)
	cp -f $(E2P_STUDY_FILE) $(BASE_RELEASE_DIR)/winIDEA
ifeq ($(BOOTMANAGER_SUPPORT),TRUE)
	cp -f $(subst .$(SREC_SUFFIX),_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX),$(BOOTMANAGER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(BOOTMANAGER_FILE))
	cp -f $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTMANAGER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTMANAGER_FILE)))
endif
ifeq ($(BOOTLOADER_SUPPORT),TRUE)
	cp -f $(subst .$(SREC_SUFFIX),_$(PFLASH_PATT_FILE_SUFFIX).$(SREC_SUFFIX),$(BOOTLOADER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(BOOTLOADER_FILE))
	cp -f $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTLOADER_FILE)) $(BASE_RELEASE_DIR)/winIDEA/$(notdir $(subst .$(SREC_SUFFIX),.$(BINARY_SUFFIX),$(BOOTLOADER_FILE)))
endif

ifeq ($(BUILD_MODE),RELEASE)

	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/app/default"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/app/default > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/app/compressed"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/app/compressed > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/app/encrypted"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/app/encrypted > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/app/compressed_encrypted"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/app/compressed_encrypted > /dev/null 2>&1 || true 

ifeq ($(BOOTLOADER_UPDATER_SUPPORT),TRUE)
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/fbl_u/default"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/fbl_u/default > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/fbl_u/compressed"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/fbl_u/compressed > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/fbl_u/encrypted"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/fbl_u/encrypted > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/CanFlash/fbl_u/compressed_encrypted"
	mkdir -p $(BASE_RELEASE_DIR)/CanFlash/fbl_u/compressed_encrypted > /dev/null 2>&1 || true 
endif

	cp -f $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash
	cp -f $(RELEASE_DIR)/$(notdir $(basename $(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX))))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash/Application.$(SREC_SUFFIX)
	$(call srec_cat, $(RELEASE_DIR)/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) $(RELEASE_DIR)/$(notdir $(basename $(DEFAULT_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) -o $(BASE_RELEASE_DIR)/CanFlash/Calibration.$(SREC_SUFFIX))
	$(call srec_cat, $(BASE_RELEASE_DIR)/CanFlash/Calibration.$(SREC_SUFFIX) -fill 0xFF $(firstword $(CALIBRATION_RANGE)) $(lastword $(DEFAULT_NVP_RANGE)) -o $(BASE_RELEASE_DIR)/CanFlash/Calibration.$(SREC_SUFFIX))

	cp -f $(BASE_RELEASE_DIR)/Bootloader_updater/$(notdir $(basename $(BOOTLOADER_UPDATER_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX) $(BASE_RELEASE_DIR)/CanFlash/Bootloader_updater.s19

	rm -f $(BASE_RELEASE_DIR)/CanFlash/$(notdir $(basename $(UNIFIED_CALIBRATION_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX)
	rm -f $(BASE_RELEASE_DIR)/CanFlash/$(notdir $(basename $(DEFAULT_FILE)))_$(FINAL_FILE_SUFFIX).$(SREC_SUFFIX)
	
	$(POST_PROSESSING_DIR)/post_processing.bat "$(BASE_RELEASE_DIR)/CanFlash/Calibration.$(SREC_SUFFIX)" "$(BASE_RELEASE_DIR)/CanFlash/Application.$(SREC_SUFFIX)" "$(BASE_RELEASE_DIR)/CanFlash/Bootloader_updater.s19" "$(BASE_RELEASE_DIR)/CanFlash" "$(OEM_APPL_VERSION_REV)" "$(OEM_CALIB_VERSION_REV)" "$(OEM_BTLD_VERSION_REV)" "$(OEM_BTLD_UPD_VERSION_REV)" "$(OEM_CONTAINER_VERSION_REV)" 

	echo "Creating directory: $(BASE_RELEASE_DIR)/Production"
	rm -rf $(BASE_RELEASE_DIR)/Production > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/Production > /dev/null 2>&1 || true 
	
	echo "Creating directory: $(BASE_RELEASE_DIR)/DIA"
	rm -rf $(BASE_RELEASE_DIR)/DIA > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/DIA > /dev/null 2>&1 || true 
	
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	echo "Creating directory: $(BASE_RELEASE_DIR)/ERH"
	rm -rf $(BASE_RELEASE_DIR)/ERH > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/ERH > /dev/null 2>&1 || true 
endif
	echo "Creating directory: $(BASE_RELEASE_DIR)/NVP"
	rm -rf $(BASE_RELEASE_DIR)/NVP > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/NVP > /dev/null 2>&1 || true 

	echo "Creating directory: $(BASE_RELEASE_DIR)/SAP"
	rm -rf $(BASE_RELEASE_DIR)/SAP > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/SAP > /dev/null 2>&1 || true 

ifeq ($(REPORT_GENERATION),TRUE)
	echo "Creating directory: $(BASE_RELEASE_DIR)/Release_log"
	rm -rf $(BASE_RELEASE_DIR)/Release_log > /dev/null 2>&1 || true 
	mkdir -p $(BASE_RELEASE_DIR)/Release_log > /dev/null 2>&1 || true 
endif

	cp -f $(FULL_MEMORY_FILE) $(BASE_RELEASE_DIR)/Production/$(APPL_VERSION_REV2)
	$(eval CURRENT_DATE:=$(shell date +"%Y_%m_%d"))		
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(BASE_RELEASE_DIR)/Production/$(APPL_VERSION_REV2) /XI:32 -o $(BASE_RELEASE_DIR)/Production/UnifiedSW_$(lastword $(subst .,$(space),$(APPL_VERSION_REV2)))_$(CURRENT_DATE).hex /G /s

	cp -f $(SOURCES_DIR)/Autoliv/DIA/Implementation/src/DIA_ReadDataByIdentifier.c $(BASE_RELEASE_DIR)/DIA
	
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	tar -xvf $(SOURCES_DIR)/Autoliv/ERH/Config/Workspace_AEC_Configurator.tar -C $(CURRENT_DIR)/$(SOURCES_DIR)/ERH/Config > /dev/null 2>&1 || true
	cp -f $(SOURCES_DIR)/Autoliv/ERH/Config/Workspace_AECConfigurator/AEC_Configurator/ERH_cfg_private.h $(BASE_RELEASE_DIR)/ERH
	cp -f $(SOURCES_DIR)/Autoliv/ERH/Config/Workspace_AECConfigurator/AEC_Configurator/ERH_cfg_public.h $(BASE_RELEASE_DIR)/ERH
	cp -f $(SOURCES_DIR)/Autoliv/ERH/Config/Workspace_AECConfigurator/AEC_Configurator/ErhDataDictionnary.arxml $(BASE_RELEASE_DIR)/ERH
endif

	if [ -f $(SOURCES_DIR)/Autoliv/NVP/Config/SBE_4G_NVP_layout.xls ]
	then
		cp -f $(SOURCES_DIR)/Autoliv/NVP/Config/SBE_4G_NVP_layout.xls $(BASE_RELEASE_DIR)/NVP
	fi

	if [ -f $(SOURCES_DIR)/Autoliv/NVP/Config/NVP_Layout/GlobalConfiguration.xml ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/NVP/NVP_Layout"
		rm -rf $(BASE_RELEASE_DIR)/NVP/NVP_Layout > /dev/null 2>&1 || true 
		mkdir -p $(BASE_RELEASE_DIR)/NVP/NVP_Layout > /dev/null 2>&1 || true 
		cp -f $(SOURCES_DIR)/Autoliv/NVP/Config/NVP_Layout/* $(BASE_RELEASE_DIR)/NVP/NVP_Layout
	fi
	
ifeq ($(FAB_FILE_SUPPORT),TRUE)
	if [ -f $(SOURCES_DIR)/Autoliv/NVP/Config/SBE_4G_NVP_layout.xls ]
	then
		cp -f $(SOURCES_DIR)/Autoliv/NVP/Config/SBE_4G_NVP_layout.xls $(BASE_RELEASE_DIR)/Production/$(APPL_FAB_VERSION).xls
		cp -f $(FAB_FILE) $(BASE_RELEASE_DIR)/Production/$(APPL_FAB_VERSION)
	fi
endif
	cp -f $(SOURCES_DIR)/Autoliv/NVP/Implementation/inc/* $(BASE_RELEASE_DIR)/NVP
	cp -f $(SOURCES_DIR)/Autoliv/NVP/Implementation/src/* $(BASE_RELEASE_DIR)/NVP

ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
	rm -rf $(SOURCES_DIR)/Autoliv/ERH/Config/Workspace_AECConfigurator/ > /dev/null 2>&1 || true 
endif

	echo Creating SAP image with $(IMAGE_CREATOR)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_$(SAP_NAME).SAP) imagecontent UNI_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))"  
ifeq ($(CYCLONE_UNIV_NVP_SAP_GENERATION),TRUE)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_NVP_$(SAP_NAME).SAP) imagecontent UNI_NVP_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE_NO_EEP))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))" "/param2=$(call getWinDir,$(E2P_STUDY_FILE))"
ifeq ($(FAB_FILE_SUPPORT),TRUE)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_FAB_NVP_$(SAP_NAME).SAP) imagecontent UNI_FAB_NVP_$(SAP_NAME).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM))" "/param2=$(call getWinDir,$(FAB_FILE))"
endif
endif
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_$(SAP_NAME_VARIANT).SAP) imagecontent UNI_$(SAP_NAME_VARIANT).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM_VARIANT))"  
ifeq ($(CYCLONE_UNIV_NVP_SAP_GENERATION),TRUE)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_NVP_$(SAP_NAME_VARIANT).SAP) imagecontent UNI_NVP_$(SAP_NAME_VARIANT).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE_NO_EEP))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM_VARIANT))" "/param2=$(call getWinDir,$(E2P_STUDY_FILE))"
ifeq ($(FAB_FILE_SUPPORT),TRUE)
	$(call getWinDir,$(CYCLONE_INSTALLATION_DIR))/ImageCreationSupportFiles/$(IMAGE_CREATOR) ! $(call getWinDir,$(CYCLONE_UNIV_CONFIG_DIR)/$(PROJECT_STEM)_CycloneConfig_NVP.cfg) hideapp /imagefile $(call getWinDir,$(BASE_RELEASE_DIR)/SAP/UNI_FAB_NVP_$(SAP_NAME_VARIANT).SAP) imagecontent UNI_FAB_NVP_$(SAP_NAME_VARIANT).SAP INTERFACE=CYCLONE RESET_DELAY 0 "/param1=$(call getWinDir,$(FULL_MEMORY_FILE))" "/param0=$(call getWinDir,$(CYCLONE_UNIV_FLASH_ALGORITHM_VARIANT))" "/param2=$(call getWinDir,$(FAB_FILE))"
endif
endif

ifeq ($(REPORT_GENERATION),TRUE) 
	echo "Copying build logs to delivery"
	cp -f $(CURRENT_DIR)/Report/* $(BASE_RELEASE_DIR)/Release_log
endif

ifeq ($(COPY_TO_DELIVERIES_DIR),TRUE)
	echo Mirroring Deliveries folder to Release folder
	rm -rf $(DELIVERIES_DIR)/*  
	
	if [ ! -d $(DELIVERIES_DIR) ]
	then
		echo "Creating the Deliveries directory"
		mkdir -p $(DELIVERIES_DIR) > /dev/null 2>&1 || true 
	fi

	cp -rf $(BASE_RELEASE_DIR)/* $(DELIVERIES_DIR)
endif
endif
endif

ifneq (,$(findstring Application,$(TARGET_KEY)))
$(UNIFIED_CALIBRATION_FILE): $(SREC_FILE) $(BINARY_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE))
	$(call srec_cat,$(AEC_CALIBRATION_FILE) $(CALIBRATION_FLASH_FILE) -o $@)

$(FULL_MEMORY_FILE): $(SREC_FILE) $(BINARY_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE))
	echo "Generating: [$(notdir $@)]"
	$(call srec_cat,$(call buildBinaryName,$(SREC_FILE),$(SREC_SUFFIX)) $(DEFAULT_FILE)	$(if $(call seq,$(AEC_CALIBRATION_SUPPORT),TRUE),$(AEC_CALIBRATION_FILE)) $(CALIBRATION_FLASH_FILE) $(if $(call seq,$(BOOTMANAGER_SUPPORT),TRUE),$(BOOTMANAGER_FILE)) $(if $(call seq,$(BOOTLOADER_SUPPORT),TRUE),$(BOOTLOADER_FILE)) $(if $(call seq,$(E2P_STUDY_SUPPORT),TRUE),$(E2P_STUDY_FILE)) -o $@)
ifeq ($(BOOTLOADER_SUPPORT),TRUE)
	echo "Process Bootloader file (e.g. add magic pattern in flash)"
	$(call srec_cat,$@ -exclude $(FLASH_VALIDATION_START_ADDR_FBL) $(FLASH_VALIDATION_END_ADDR_FBL) -generate $(FLASH_VALIDATION_START_ADDR_FBL) $(FLASH_VALIDATION_END_ADDR_FBL) -repeat-data $(FLASH_VALIDATION_FLAG_FBL) -o $@)
endif
ifeq ($(BOLO_FLASH_VALIDATION),TRUE)
	echo "Process Application and Calibration files (e.g. add magic pattern in flash)"
	$(call srec_cat,$@ -exclude $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -generate $(FLASH_VALIDATION_START_ADDR_APPL) $(FLASH_VALIDATION_END_ADDR_APPL) -repeat-data $(FLASH_VALIDATION_FLAG_APPL) -o $@)
	$(call srec_cat,$@ -exclude $(FLASH_VALIDATION_START_ADDR_DEFAULT) $(FLASH_VALIDATION_END_ADDR_DEFAULT) -generate $(FLASH_VALIDATION_START_ADDR_DEFAULT) $(FLASH_VALIDATION_END_ADDR_DEFAULT) -repeat-data $(FLASH_VALIDATION_FLAG_DEFAULT) -o $@)
endif
	$(call srec_cat,$@ -fill 0xFF $(FULL_FLASH_FILL_RANGE) -o $@)
endif

ifeq ($(ELF_FILE_GENERATION),TRUE)
$(ELF_FILE): $(BINARY_FILE)
	echo "Generating: [$(notdir $(basename $@)).$(SYMBOL_SUFFIX)]"
	$(CELF) -o $@ $(BINARY_FILE)
	$(CPRD) -s -o $(subst .$(BINARY_SUFFIX),.$(SYM_SUFFIX),$(BINARY_FILE)) $(BINARY_FILE)
endif

$(SREC_FILE): $(BINARY_FILE)
	echo "Generating: [$(notdir $(basename $@)).$(SREC_SUFFIX)]"
	
	"$(CHEX)" $(CHEX_PRE_OPT) "$(BINARY_FILE)" $(CHEX_POST_OPT)
	
ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(S19_CRC_CALCULATION),TRUE)
ifeq ($(HEXVIEW_CRC_SUPPORTED),TRUE)
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $@ "/FR:$(strip $(APPL_FILL_RANGE_INTV)):$(strip $(APPL_FILL_RANGE_BSW))" /FP:0xFF "/CS0:@$(APPL_CRC_ADDR);$(APPL_CRC_RANGES)" /XS:32 -o $(subst .s19,_crc.s19,$@) /G /s
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $(subst .s19,_crc.s19,$@) /CR:$(APPL_EXCLUSION_RANGE) /XS:32 -o $(subst .s19,_crc.s19,$@) /G /s
else
ifeq ($(ALV_CRC_SUPPORTED),TRUE)
	cksum -f="$(call getWinDir,$@)" -c="$(APPL_CRC_RANGES)" -a="$(APPL_CRC_ADDR)"
endif
endif
else
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $@ "/FR:$(strip $(APPL_FILL_RANGE_INTV)):$(strip $(APPL_FILL_RANGE_BSW))" /FP:0xFF /XS:32 -o $@ /G /s
	$(subst \,/,$(HEXVIEW_INSTALLATION_DIR))/hexview.exe $@ /CR:$(APPL_EXCLUSION_RANGE) /XS:32 -o $@ /G /s
endif
endif

$(BINARY_FILE): $(ALL_OBJ_SOURCES) $(LINKER_FILE) | $(NECESSARY_OUTPUT_PATHS)
	echo "Linking: [$(notdir $(basename $@)).$(BINARY_SUFFIX)]"
ifeq ($(GENERATE_LINKER_CMD),TRUE)
	find $(OBJ_DIR)/*.o | sort > "$(LINK_CMD_XCL)"
	echo $(LINK_CMD_OPT) >> "$(LINK_CMD_XCL)"
endif
ifeq ($(PARSE_LINKER_FILE),TRUE)	
	cp -f $(LINKER_FILE) $(basename $(LINKER_FILE))_bkup.lnk
	chmod 777 $(basename $(LINKER_FILE))_bkup.lnk
	chmod 777 $(LINKER_FILE)

	cat $(LINKER_FILE) | sed 's|+startup-objects|$(ALL_OBJ_ASM_SOURCES)|g' |\
	                     sed 's|+source-objects|$(sort $(ALL_OBJ_C_SOURCES))|g' |\
	                     sed 's|+library-objects|$(LINK_LIB_OBJ)|g' > $(LINKER_FILE)
endif

	if ! "$(LINK)" $(LINK_OPT) >> $(ERR_DIR)/$(basename $(notdir $@))_linker.$(WARN_SUFFIX) 2>&1; then
		mv -f $(ERR_DIR)/$(basename $(notdir $@))_linker.$(WARN_SUFFIX) $(ERR_DIR)/$(basename $(notdir $@))_linker.$(ERR_SUFFIX);
		cat $(ERR_DIR)/$(basename $(notdir $@))_linker.$(ERR_SUFFIX);
ifeq ($(PARSE_LINKER_FILE),TRUE)	
		mv -f $(LINKER_FILE) $(ERR_DIR)/$(notdir $(LINKER_FILE));
		mv -f $(basename $(LINKER_FILE))_bkup.lnk $(LINKER_FILE);
endif
		exit 1;
ifeq ($(PARSE_LINKER_FILE),TRUE)	
	else
		mv -f $(LINKER_FILE) $(ERR_DIR)/$(notdir $(LINKER_FILE));
		mv -f $(basename $(LINKER_FILE))_bkup.lnk $(LINKER_FILE);
endif
	fi
		
$(ALL_OBJ_ASM_SOURCES):  | $(NECESSARY_OUTPUT_PATHS)
	$(eval COMP_GROUP:=$(strip $(foreach COMPONENT,$(COMPONENTS_LIST),$(if $(call getSourceFile,ASM,$(COMPONENT)),$(COMPONENT)))))
	$(eval SOURCE_FILE:=$(strip $(call getSourceFile,ASM,$(COMP_GROUP))))
	$(eval PREPROCESS_AS:=$(PREPROCESS_AS_IGNORE_$(COMP_GROUP)))
ifeq ($(PREPROCESS_AS_SUPPORT),TRUE)
	if [ ! -z $(PREPROCESS_AS) ] 
	then
		echo "Preprocessing: [$(notdir $(basename $@)).$(ASM_SUFFIX)]"
		cp $(SOURCE_FILE) $(call getWinDir,$(strip $(dir $@)))/$(strip $(notdir $(SOURCE_FILE)))
	else
		echo "Preprocessing: [$(notdir $(basename $@)).$(ASM_SUFFIX)]"
		echo "Preprocessor command line: $(CPP)$(CPP_OPT_$(COMP_GROUP)) c "$(call getWinDir,$(SOURCE_FILE))" -P -o $(call getWinDir,$(strip $(dir $@)))/$(strip $(notdir $(SOURCE_FILE))) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1	" > $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
		echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
		$(CPP)$(CPP_OPT_$(COMP_GROUP)) c "$(call getWinDir,$(SOURCE_FILE))" -P -o $(call getWinDir,$(strip $(dir $@)))/$(strip $(notdir $(SOURCE_FILE))) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
		$(eval SOURCE_FILE:=$(dir $@)/$(notdir $(SOURCE_FILE)))
	fi
endif
	echo "Assembling: [$(notdir $(basename $@)).$(ASM_SUFFIX)]"
	echo "Assembler command line: '$(AS)' $(ASM_OPT_$(COMP_GROUP)) $(call getWinDir,$(dir $@)/$(notdir $(SOURCE_FILE))) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	'$(AS)' $(ASM_OPT_$(COMP_GROUP)) $(call getWinDir,$(SOURCE_FILE)) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1

$(ALL_OBJ_C_SOURCES):  | $(NECESSARY_OUTPUT_PATHS)
	$(eval COMP_GROUP:=$(strip $(foreach COMPONENT,$(COMPONENTS_LIST),$(if $(call getSourceFile,C,$(COMPONENT)),$(COMPONENT)))))
	$(eval SOURCE_FILE:=$(strip $(call getSourceFile,C,$(COMP_GROUP))))
	echo "Compiling: [$(basename $(notdir $@)).$(C_SUFFIX)]"
	echo "Compiler command line: '$(COMP)' $(COMP_OPT_$(COMP_GROUP)) $(call getWinDir,$(SOURCE_FILE)) >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1" > $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1
	if ! '$(COMP)' $(COMP_OPT_$(COMP_GROUP)) $(call getWinDir,$(SOURCE_FILE))  >> $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) 2>&1 ; then
		cat $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) | sed -n '/$(notdir $(basename $(AS)))\|$(notdir $(basename $(COMP)))\|$(notdir $(basename $(PARSER)))\|$(notdir $(basename $(DEP)))\|$(notdir $(basename $(CODE_OPTIMIZER)))\|$(notdir $(basename $(CODE_GEN)))/!p';
		cat $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) | sed -n '/Error\[\|Warning\[\|#error\|Fatal error\[/p';
		cat $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) | sed -n '/$(LICENSE_SERVER)/p';
		mv -f $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) $(ERR_DIR)/$(basename $(notdir $@)).$(ERR_SUFFIX);
		exit 1;
	fi
ifeq ($(PRINT_WARNINGS),TRUE)
	cat $(ERR_DIR)/$(basename $(notdir $@)).$(WARN_SUFFIX) | sed -n '/Warning\[/p';	
endif
ifeq ($(PRINT_QAC_WARNINGS),TRUE)
	print_qac_warnings -i=$(call getWinDir,$(SOURCE_FILE))
	echo $(call getWinDir,$(SOURCE_FILE))
endif

$(DEP_FILES): | $(GEN_FILES) $(AEC_CALIBRATION_FILE) $(CALIBRATION_FLASH_FILE)  $(ALL_COMPONENT_C_SOURCES) $(NECESSARY_OUTPUT_PATHS)
	$(eval COMP_GROUP:=$(strip $(foreach COMPONENT,$(COMPONENTS_LIST),$(if $(call getSourceFile,C,$(COMPONENT)),$(COMPONENT)))))
	$(eval SOURCE_FILE:=$(strip $(call getSourceFile,C,$(COMP_GROUP))))
	echo "Creating dependency for: [$(notdir $@)]"
	echo "Dependency command line: '$(DEP)' $(DEP_PRE_OPT) $(SOURCE_FILE) $(DEP_POST_OPT) $(DEP_OUT_OPT)" > $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) 2>&1
	echo "$(EMPTY_VAR)" >> $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) 2>&1
	if ! '$(DEP)' $(DEP_PRE_OPT) $(SOURCE_FILE) $(DEP_POST_OPT) $(DEP_OUT_OPT) >> $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) 2>&1 ; then
		cat $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) | sed -n '/Error\[\|Warning\[\|#error\|Fatal error\[/p';
		cat $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) | sed -n '/$(LICENSE_SERVER)/p';
		exit 1;
	fi
	
ifneq (,$(findstring Application,$(TARGET_KEY)))
ifeq ($(AEC_CALIBRATION_SUPPORT),TRUE)
$(AEC_CALIBRATION_FILE): | $(NECESSARY_OUTPUT_PATHS)
	echo Generating AEC Calibration
	if [ ! -d $(dir $@) ]
	then
		echo "Creating directory: $(dir $@)"
		mkdir -p $(dir $@) > /dev/null 2>&1 || true 
	fi
	cd $(SOURCES_DIR)/ERH/Config
	java -jar AEC_Configurator.jar 1
	cd $(CURRENT_DIR)
endif

$(CALIBRATION_FLASH_FILE) $(DEFAULT_FILE) $(DYNAMIC_E2P_FILE) $(E2P_STUDY_FILE): | $(NECESSARY_OUTPUT_PATHS)
	echo Generating NVP binary files
	if [ ! -d $(dir $(CALIBRATION_FLASH_FILE)) ]
	then
		echo "Creating directory: $(dir $(CALIBRATION_FLASH_FILE))"
		mkdir -p $(dir $(CALIBRATION_FLASH_FILE)) > /dev/null 2>&1 || true 
	fi

	generate_nvp_files "-f=$(call getWinDir,$(SOURCES_DIR)/NVP/Config/SBE_4G_NVP_layout.xls)"
endif

$(NECESSARY_OUTPUT_PATHS) $(RELEASE_DIR):
	if [ ! -d $@ ]
	then
		echo "Creating directory: $@"
		mkdir -p $@ > /dev/null 2>&1 || true 
	fi

ifneq ($(TARGET),help)
ifneq ($(MAKECMDGOALS),callCheckInIARLicense)
ifneq ($(MAKECMDGOALS),$(TARGET)-clean)
ifneq ($(MAKECMDGOALS),$(TARGET)-eclipse)
$(TARGET): callCheckOutIARLicense updateGliwa .WAIT updateSwVersion $(GEN_FILES) $(DEP_FILES) $(ALL_OBJ_SOURCES) $(BINARY_FILE) $(SREC_FILE) \
           $(RELEASE_DIR)/$(notdir $(SREC_FILE)) pdfReport \
           $(FULL_MEMORY_FILE) $(AEC_CALIBRATION_FILE) $(CALIBRATION_FLASH_FILE) $(UNIFIED_CALIBRATION_FILE) $(if $(call seq,$(ELF_FILE_GENERATION),TRUE),$(ELF_FILE)) | $(NECESSARY_OUTPUT_PATHS)
endif
endif
endif
endif

%-clean:
	if [ -d $(OUTPUT_DIR)/$(TARGET) ]
	then
		echo "Removing directory: $(OUTPUT_DIR)/$(TARGET)"
		rm -rf $(OUTPUT_DIR)/$(TARGET)
	fi

updateGliwa:
ifneq ($(BUILD_MODE),RELEASE)
ifneq (,$(findstring Application,$(TARGET_KEY)))
	echo "Updating T1 Gliwa project"
	../../../../../Components/Application/Supplier/T1/make/T1_TresosAutoCoreOS/T1_projGen.bat
endif
endif

updateSwVersion:
ifeq ($(BUILD_MODE),RELEASE)
ifneq (,$(findstring Application,$(TARGET_KEY)))
	change_sw_version "-f=$(call getWinDir,$(SOURCES_DIR)/Autoliv/DIA/Implementation/src/DIA_ReadDataByIdentifier.c)" "-s=$(APPL_VERSION_REV2)"
endif
endif

callCheckOutIARLicense: 
	echo "Checking-out IAR compiler license"
	"$(COMPILER_LICENSE_MANAGER_BIN)/LightLicenseManager.exe" checkout $(COMPILER_LICENSE_MANAGER_PRODUCT) -v -y 1

callCheckInIARLicense:
	echo "Checking-in IAR compiler license"
	"$(COMPILER_LICENSE_MANAGER_BIN)/LightLicenseManager.exe" checkin -v


.PHONY: $(TARGET) updateSwVersion updateGliwa callCheckOutIARLicense callCheckInIARLicense
.ONESHELL:
.SUFFIXES:
.SILENT:

# filename    : Makefile.main
# description : Makefile that defines the target linkage and source file packages
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
