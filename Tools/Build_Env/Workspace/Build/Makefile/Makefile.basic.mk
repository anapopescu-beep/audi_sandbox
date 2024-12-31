include $(TARGET_KEY)/Makefile.config.mk

ifneq ($(MAKECMDGOALS),$(TARGET)-clean)
ifneq ($(TARGET),help)
include Makefile.utilities.mk
endif 
endif

#SHELL += -x

$(NECESSARY_OUTPUT_PATHS) $(RELEASE_DIR):
	if [ ! -d $@ ]
	then
		echo "Creating directory: $@"
		mkdir -p $@ > /dev/null 2>&1 || true 
	fi

$(TARGET):

	if [ ! -d $(BASE_RELEASE_DIR)/$(TARGET_KEY) ]
	then
		echo "Creating directory: $(BASE_RELEASE_DIR)/$(TARGET_KEY)"
		mkdir -p $(BASE_RELEASE_DIR)/$(TARGET_KEY) > /dev/null 2>&1 || true 
	fi
	
	echo "Copying executable file to: $(BASE_RELEASE_DIR)/$(TARGET_KEY)"
	
	cp -f $(BASIC_EXECUTABLE_FILE) $(BASE_RELEASE_DIR)/$(TARGET_KEY)

%-clean:
	if [ -d $(BASE_RELEASE_DIR)/$(TARGET_KEY) ]
	then
		echo "Removing directory: $(BASE_RELEASE_DIR)/$(TARGET_KEY)"
		rm -rf $(BASE_RELEASE_DIR)/$(TARGET_KEY)
	fi

.PHONY: $(TARGET) 
.ONESHELL:
.SUFFIXES:
.SILENT:

# filename    : Makefile.basic.mk
# description : Makefile that compiles a certain Application via external batch file
# author      : Andrei Anca
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : andrei.anca@autoliv.com
# status      : Released
