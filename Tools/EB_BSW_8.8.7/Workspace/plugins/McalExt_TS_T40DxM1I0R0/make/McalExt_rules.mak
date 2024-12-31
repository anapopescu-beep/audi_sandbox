#EB_Automotive_Makefile

LIBRARIES_TO_BUILD     += McalExt_src

ifeq ($(McalExt_Adc_USED),true)
ifeq ($(Adc_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Adc_src
include  $(McalExt_CORE_PATH)/make/make_Adc/Adc_rules.mak
endif
endif

ifeq ($(McalExt_BaseNXP_USED),true)
ifeq ($(BaseNXP_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += BaseNXP_src
include  $(McalExt_CORE_PATH)/make/make_BaseNXP/BaseNXP_rules.mak
endif
endif

ifeq ($(McalExt_Can_USED),true)
ifeq ($(Can_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Can_src
include  $(McalExt_CORE_PATH)/make/make_Can/Can_rules.mak
endif
endif

ifeq ($(McalExt_Crc_USED),true)
ifeq ($(Crc_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Crc_src
include  $(McalExt_CORE_PATH)/make/make_Crc/Crc_rules.mak
endif
endif

ifeq ($(McalExt_Crypto_USED),true)
ifeq ($(Crypto_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Crypto_src
include  $(McalExt_CORE_PATH)/make/make_Crypto/Crypto_rules.mak
endif
endif

ifeq ($(McalExt_Dio_USED),true)
ifeq ($(Dio_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Dio_src
include  $(McalExt_CORE_PATH)/make/make_Dio/Dio_rules.mak
endif
endif

ifeq ($(McalExt_Eep_USED),true)
ifeq ($(Eep_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Eep_src
include  $(McalExt_CORE_PATH)/make/make_Eep/Eep_rules.mak
endif
endif

ifeq ($(McalExt_Eth_USED),true)
ifeq ($(Eth_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Eth_src
include  $(McalExt_CORE_PATH)/make/make_Eth/Eth_rules.mak
endif
endif

ifeq ($(McalExt_Fee_USED),true)
ifeq ($(Fee_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Fee_src
include  $(McalExt_CORE_PATH)/make/make_Fee/Fee_rules.mak
endif
endif

ifeq ($(McalExt_Fls_USED),true)
ifeq ($(Fls_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Fls_src
include  $(McalExt_CORE_PATH)/make/make_Fls/Fls_rules.mak
endif
endif

ifeq ($(McalExt_Gpt_USED),true)
ifeq ($(Gpt_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Gpt_src
include  $(McalExt_CORE_PATH)/make/make_Gpt/Gpt_rules.mak
endif
endif

ifeq ($(McalExt_I2c_USED),true)
ifeq ($(I2c_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += I2c_src
include  $(McalExt_CORE_PATH)/make/make_I2c/I2c_rules.mak
endif
endif

ifeq ($(McalExt_I2s_USED),true)
ifeq ($(I2s_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += I2s_src
include  $(McalExt_CORE_PATH)/make/make_I2s/I2s_rules.mak
endif
endif

ifeq ($(McalExt_Icu_USED),true)
ifeq ($(Icu_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Icu_src
include  $(McalExt_CORE_PATH)/make/make_Icu/Icu_rules.mak
endif
endif

ifeq ($(McalExt_Lin_USED),true)
ifeq ($(Lin_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Lin_src
include  $(McalExt_CORE_PATH)/make/make_Lin/Lin_rules.mak
endif
endif

ifeq ($(McalExt_Mcl_USED),true)
ifeq ($(Mcl_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Mcl_src
include  $(McalExt_CORE_PATH)/make/make_Mcl/Mcl_rules.mak
endif
endif

ifeq ($(McalExt_Mcu_USED),true)
ifeq ($(Mcu_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Mcu_src
include  $(McalExt_CORE_PATH)/make/make_Mcu/Mcu_rules.mak
endif
endif

ifeq ($(McalExt_Ocu_USED),true)
ifeq ($(Ocu_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Ocu_src
include  $(McalExt_CORE_PATH)/make/make_Ocu/Ocu_rules.mak
endif
endif

ifeq ($(McalExt_Port_USED),true)
ifeq ($(Port_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Port_src
include  $(McalExt_CORE_PATH)/make/make_Port/Port_rules.mak
endif
endif

ifeq ($(McalExt_Pwm_USED),true)
ifeq ($(Pwm_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Pwm_src
include  $(McalExt_CORE_PATH)/make/make_Pwm/Pwm_rules.mak
endif
endif

ifeq ($(McalExt_Qdec_USED),true)
ifeq ($(Qdec_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Qdec_src
include  $(McalExt_CORE_PATH)/make/make_Qdec/Qdec_rules.mak
endif
endif

ifeq ($(McalExt_Rm_USED),true)
ifeq ($(Rm_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Rm_src
include  $(McalExt_CORE_PATH)/make/make_Rm/Rm_rules.mak
endif
endif

ifeq ($(McalExt_Spi_USED),true)
ifeq ($(Spi_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Spi_src
include  $(McalExt_CORE_PATH)/make/make_Spi/Spi_rules.mak
endif
endif

ifeq ($(McalExt_Uart_USED),true)
ifeq ($(Uart_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Uart_src
include  $(McalExt_CORE_PATH)/make/make_Uart/Uart_rules.mak
endif
endif

ifeq ($(McalExt_Wdg_USED),true)
ifeq ($(Wdg_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Wdg_43_Instance0_src
include  $(McalExt_CORE_PATH)/make/make_Wdg_43_Instance0/Wdg_43_Instance0_rules.mak
endif
endif

ifeq ($(McalExt_Wdg_43_Instance1_USED),true)
ifeq ($(Wdg_43_Instance1_VARIANT),TS_T40D2M10I1R0)
LIBRARIES_TO_BUILD     += Wdg_43_Instance1_src
include  $(McalExt_CORE_PATH)/make/make_Wdg_43_Instance1/Wdg_43_Instance1_rules.mak
endif
endif

McalExt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Interrupts.c
McalExt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Timer.c
McalExt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Timer_System.c
McalExt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Timer_System_Internal_Systick.c
