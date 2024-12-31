#EB_Automotive_Makefile

McalExt_CORE_PATH      ?= $(PLUGINS_BASE)/McalExt_$(McalExt_VARIANT)
McalExt_OUTPUT_PATH    := $(AUTOSAR_BASE_OUTPUT_PATH)

McalExt_GEN_FILES      += $(McalExt_OUTPUT_PATH)/include/Platforms_Modules.h

ifeq ($(McalExt_Adc_USED),true)
ifeq ($(Adc_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Adc/Adc_defs.mak
endif
endif

ifeq ($(McalExt_BaseNXP_USED),true)
ifeq ($(BaseNXP_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_BaseNXP/BaseNXP_defs.mak
endif
endif

ifeq ($(McalExt_Can_USED),true)
ifeq ($(Can_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Can/Can_defs.mak
endif
endif

ifeq ($(McalExt_Crc_USED),true)
ifeq ($(Crc_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Crc/Crc_defs.mak
endif
endif

ifeq ($(McalExt_Crypto_USED),true)
ifeq ($(Crypto_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Crypto/Crypto_defs.mak
endif
endif

ifeq ($(McalExt_Dio_USED),true)
ifeq ($(Dio_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Dio/Dio_defs.mak
endif
endif

ifeq ($(McalExt_Eep_USED),true)
ifeq ($(Eep_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Eep/Eep_defs.mak
endif
endif

ifeq ($(McalExt_Eth_USED),true)
ifeq ($(Eth_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Eth/Eth_defs.mak
endif
endif

ifeq ($(McalExt_Fee_USED),true)
ifeq ($(Fee_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Fee/Fee_defs.mak
endif
endif

ifeq ($(McalExt_Fls_USED),true)
ifeq ($(Fls_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Fls/Fls_defs.mak
endif
endif

ifeq ($(McalExt_Gpt_USED),true)
ifeq ($(Gpt_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Gpt/Gpt_defs.mak
endif
endif

ifeq ($(McalExt_I2c_USED),true)
ifeq ($(I2c_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_I2c/I2c_defs.mak
endif
endif

ifeq ($(McalExt_I2s_USED),true)
ifeq ($(I2s_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_I2s/I2s_defs.mak
endif
endif

ifeq ($(McalExt_Icu_USED),true)
ifeq ($(Icu_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Icu/Icu_defs.mak
endif
endif

ifeq ($(McalExt_Lin_USED),true)
ifeq ($(Lin_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Lin/Lin_defs.mak
endif
endif

ifeq ($(McalExt_Mcl_USED),true)
ifeq ($(Mcl_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Mcl/Mcl_defs.mak
endif
endif

ifeq ($(McalExt_Mcu_USED),true)
ifeq ($(Mcu_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Mcu/Mcu_defs.mak
endif
endif

ifeq ($(McalExt_Ocu_USED),true)
ifeq ($(Ocu_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Ocu/Ocu_defs.mak
endif
endif

ifeq ($(McalExt_Port_USED),true)
ifeq ($(Port_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Port/Port_defs.mak
endif
endif

ifeq ($(McalExt_Pwm_USED),true)
ifeq ($(Pwm_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Pwm/Pwm_defs.mak
endif
endif

ifeq ($(McalExt_Qdec_USED),true)
ifeq ($(Qdec_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Qdec/Qdec_defs.mak
endif
endif

ifeq ($(McalExt_Rm_USED),true)
ifeq ($(Rm_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Rm/Rm_defs.mak
endif
endif

ifeq ($(McalExt_Spi_USED),true)
ifeq ($(Spi_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Spi/Spi_defs.mak
endif
endif

ifeq ($(McalExt_Uart_USED),true)
ifeq ($(Uart_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Uart/Uart_defs.mak
endif
endif

ifeq ($(McalExt_Wdg_USED),true)
ifeq ($(Wdg_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Wdg_43_Instance0/Wdg_43_Instance0_defs.mak
endif
endif

ifeq ($(McalExt_Wdg_43_Instance1_USED),true)
ifeq ($(Wdg_43_Instance1_VARIANT),TS_T40D2M10I1R0)
include  $(McalExt_CORE_PATH)/make/make_Wdg_43_Instance1/Wdg_43_Instance1_defs.mak
endif
endif

TRESOS_GEN_FILES   += $(McalExt_GEN_FILES)

CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/include
CC_INCLUDE_PATH    += $(McalExt_OUTPUT_PATH)/include


