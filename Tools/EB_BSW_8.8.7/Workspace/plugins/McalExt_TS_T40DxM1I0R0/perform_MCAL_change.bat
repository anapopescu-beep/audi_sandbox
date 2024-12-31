@echo off
:: --------{ EB Automotive Batch File }--------
::
:: script to update MCAL module with EB content
:: or reset it to vendor content

if [%1]==[EB_update] goto usage
if [%1]==[origin] goto usage
echo Usage: %0 [OPTION]
echo(
echo   EB_update
echo		Update files of the plug-in with content of Elektrobit Automotive GmbH.
echo   origin
echo		Reset the files of the plug-in with vendor content.
echo(
goto copy_end

:usage
cd %~d0 >NUL
cd %~p0
:: if exist an *.origin_version delete the current file:
if exist .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm
del .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c )
if exist .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm
del .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm
del .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm
del .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm
del .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm
del .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm
del .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm
del .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h
del .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm
del .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c
del .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm
del .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c
del .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c )
if exist .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm
del .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm
del .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm
del .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h
del .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c
del .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c )
if exist .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm
del .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm (
echo delete %~d0%~p0MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm
del .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm )
if exist .\MCAL_Delivery\Origin_files\Can\Can_PBcfg.c (
echo delete %~d0%~p0MCAL_Delivery\Origin_files\Can\Can_PBcfg.c
del .\MCAL_Delivery\Origin_files\Can\Can_PBcfg.c )
if exist .\MCAL_Delivery\Origin_files\Lin\Lin_Defines.h (
echo delete %~d0%~p0MCAL_Delivery\Origin_files\Lin\Lin_Defines.h
del .\MCAL_Delivery\Origin_files\Lin\Lin_Defines.h )
if exist .\include\BaseNXP\OsIf.h (
echo delete %~d0%~p0include\BaseNXP\OsIf.h
del .\include\BaseNXP\OsIf.h )
if exist .\include\BaseNXP\OsIf_Interrupts.h (
echo delete %~d0%~p0include\BaseNXP\OsIf_Interrupts.h
del .\include\BaseNXP\OsIf_Interrupts.h )
if exist .\include\BaseNXP\OsIf_Timer_Custom.h (
echo delete %~d0%~p0include\BaseNXP\OsIf_Timer_Custom.h
del .\include\BaseNXP\OsIf_Timer_Custom.h )
if exist .\include\BaseNXP\OsIf_Timer_System.h (
echo delete %~d0%~p0include\BaseNXP\OsIf_Timer_System.h
del .\include\BaseNXP\OsIf_Timer_System.h )
if exist .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h (
echo delete %~d0%~p0include\BaseNXP\OsIf_Timer_System_Internal_Systick.h
del .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h )
if exist .\include\BaseNXP\PlatformTypes.h (
echo delete %~d0%~p0include\BaseNXP\PlatformTypes.h
del .\include\BaseNXP\PlatformTypes.h )
:: if exist an *.EB_update file delete the current file:
if exist .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm
del .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c
del .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c )
if exist .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm
del .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c
del .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c )
if exist .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm
del .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm
del .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm
del .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm
del .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm
del .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm
del .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h
del .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm
del .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c
del .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm
del .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h
del .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c
del .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c )
if exist .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm
del .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm
del .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm
del .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h
del .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c
del .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c )
if exist .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm
del .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm )
if exist .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm
del .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm )
if exist .\include\BaseNXP\OsIf.h (
echo 	remove %~d0%~p0include\BaseNXP\OsIf.h
del .\include\BaseNXP\OsIf.h )
if exist .\include\BaseNXP\OsIf_Interrupts.h (
echo 	remove %~d0%~p0include\BaseNXP\OsIf_Interrupts.h
del .\include\BaseNXP\OsIf_Interrupts.h )
if exist .\include\BaseNXP\OsIf_Timer_Custom.h (
echo 	remove %~d0%~p0include\BaseNXP\OsIf_Timer_Custom.h
del .\include\BaseNXP\OsIf_Timer_Custom.h )
if exist .\include\BaseNXP\OsIf_Timer_System.h (
echo 	remove %~d0%~p0include\BaseNXP\OsIf_Timer_System.h
del .\include\BaseNXP\OsIf_Timer_System.h )
if exist .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h (
echo 	remove %~d0%~p0include\BaseNXP\OsIf_Timer_System_Internal_Systick.h
del .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h )
if exist .\include\BaseNXP\PlatformTypes.h (
echo 	remove %~d0%~p0include\BaseNXP\PlatformTypes.h
del .\include\BaseNXP\PlatformTypes.h )
if exist .\include\CDD_I2c\I2c.h (
echo 	remove %~d0%~p0include\CDD_I2c\I2c.h
del .\include\CDD_I2c\I2c.h )
if exist .\include\CDD_I2s\I2s.h (
echo 	remove %~d0%~p0include\CDD_I2s\I2s.h
del .\include\CDD_I2s\I2s.h )
if exist .\include\CDD_Rm\Rm.h (
echo 	remove %~d0%~p0include\CDD_Rm\Rm.h
del .\include\CDD_Rm\Rm.h )

:: perform origin
if [%1]==[EB_update] goto copy_EB
:: if exist an *.origin_version file make it to the current file:
if exist .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c.origin_version .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c.origin_version .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c.origin_version .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c.origin_version .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h.origin_version .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c.origin_version .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c.origin_version .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h.origin_version .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c.origin_version .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm.origin_version 
copy .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm.origin_version .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm >NUL )
if exist .\MCAL_Delivery\Origin_files\Can\Can_PBcfg.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\Origin_files\Can\Can_PBcfg.c.origin_version 
copy .\MCAL_Delivery\Origin_files\Can\Can_PBcfg.c.origin_version .\MCAL_Delivery\Origin_files\Can\Can_PBcfg.c >NUL )
if exist .\MCAL_Delivery\Origin_files\Lin\Lin_Defines.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\Origin_files\Lin\Lin_Defines.h.origin_version 
copy .\MCAL_Delivery\Origin_files\Lin\Lin_Defines.h.origin_version .\MCAL_Delivery\Origin_files\Lin\Lin_Defines.h >NUL )
if exist include\BaseNXP\OsIf.h.origin_version (
echo 	use %~d0%~p0.include\BaseNXP\OsIf.h.origin_version 
copy .\include\BaseNXP\OsIf.h.origin_version .\include\BaseNXP\OsIf.h >NUL )
if exist include\BaseNXP\OsIf_Interrupts.h.origin_version (
echo 	use %~d0%~p0.include\BaseNXP\OsIf_Interrupts.h.origin_version 
copy .\include\BaseNXP\OsIf_Interrupts.h.origin_version .\include\BaseNXP\OsIf_Interrupts.h >NUL )
if exist include\BaseNXP\OsIf_Timer_Custom.h.origin_version (
echo 	use %~d0%~p0.include\BaseNXP\OsIf_Timer_Custom.h.origin_version 
copy .\include\BaseNXP\OsIf_Timer_Custom.h.origin_version .\include\BaseNXP\OsIf_Timer_Custom.h >NUL )
if exist include\BaseNXP\OsIf_Timer_System.h.origin_version (
echo 	use %~d0%~p0.include\BaseNXP\OsIf_Timer_System.h.origin_version 
copy .\include\BaseNXP\OsIf_Timer_System.h.origin_version .\include\BaseNXP\OsIf_Timer_System.h >NUL )
if exist include\BaseNXP\OsIf_Timer_System_Internal_Systick.h.origin_version (
echo 	use %~d0%~p0.include\BaseNXP\OsIf_Timer_System_Internal_Systick.h.origin_version 
copy .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h.origin_version .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h >NUL )
if exist include\BaseNXP\PlatformTypes.h.origin_version (
echo 	use %~d0%~p0.include\BaseNXP\PlatformTypes.h.origin_version 
copy .\include\BaseNXP\PlatformTypes.h.origin_version .\include\BaseNXP\PlatformTypes.h >NUL )
goto copy_end

:: perform EB update
:copy_EB
:: if exist an *.EB_update file make it to the current file:
if exist .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Adc_TS_T40D2M10I1R0\config\Adc.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\config\BaseNXP.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c.EB_update .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\generate_PC\src\OsIf_Cfg.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c.EB_update .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c.EB_update .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c.EB_update .\MCAL_Delivery\eclipse\plugins\Base_TS_T40D2M10I1R0\src\OsIf_Timer_System_Internal_Systick.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\config\Can.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c.EB_update .\MCAL_Delivery\eclipse\plugins\Can_TS_T40D2M10I1R0\generate_PB\src\Can_PBcfg.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Crypto_TS_T40D2M10I1R0\config\Crypto.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Dio_TS_T40D2M10I1R0\config\Dio.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Eth_TS_T40D2M10I1R0\config\Eth.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Fls_TS_T40D2M10I1R0\config\Fls.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Gpt_TS_T40D2M10I1R0\config\Gpt.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\config\I2c.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h.EB_update
copy .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h.EB_update .\MCAL_Delivery\eclipse\plugins\I2c_TS_T40D2M10I1R0\include\Lpi2c_Ip_Irq.h >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\config\I2s.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c.EB_update .\MCAL_Delivery\eclipse\plugins\I2s_TS_T40D2M10I1R0\src\Flexio_I2s_Ip.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\config\Lin.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h.EB_update .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\generate_PC\include\Lin_Defines.h >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c.EB_update .\MCAL_Delivery\eclipse\plugins\Lin_TS_T40D2M10I1R0\src\Lin_Ipw.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Mcl_TS_T40D2M10I1R0\config\Mcl.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Mcu_TS_T40D2M10I1R0\config\Mcu.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\config\Spi.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h.EB_update .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\include\Spi.h >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c.EB_update .\MCAL_Delivery\eclipse\plugins\Spi_TS_T40D2M10I1R0\src\Spi.c >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Uart_TS_T40D2M10I1R0\config\Uart.xdm >NUL )
if exist .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm.EB_update
copy .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm.EB_update .\MCAL_Delivery\eclipse\plugins\Wdg_TS_T40D2M10I1R0\config\Wdg.xdm >NUL )
if exist .\include\BaseNXP\OsIf.h.EB_update (
echo 	use %~d0%~p0include\BaseNXP\OsIf.h.EB_update
copy .\include\BaseNXP\OsIf.h.EB_update .\include\BaseNXP\OsIf.h >NUL )
if exist .\include\BaseNXP\OsIf_Interrupts.h.EB_update (
echo 	use %~d0%~p0include\BaseNXP\OsIf_Interrupts.h.EB_update
copy .\include\BaseNXP\OsIf_Interrupts.h.EB_update .\include\BaseNXP\OsIf_Interrupts.h >NUL )
if exist .\include\BaseNXP\OsIf_Timer_Custom.h.EB_update (
echo 	use %~d0%~p0include\BaseNXP\OsIf_Timer_Custom.h.EB_update
copy .\include\BaseNXP\OsIf_Timer_Custom.h.EB_update .\include\BaseNXP\OsIf_Timer_Custom.h >NUL )
if exist .\include\BaseNXP\OsIf_Timer_System.h.EB_update (
echo 	use %~d0%~p0include\BaseNXP\OsIf_Timer_System.h.EB_update
copy .\include\BaseNXP\OsIf_Timer_System.h.EB_update .\include\BaseNXP\OsIf_Timer_System.h >NUL )
if exist .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h.EB_update (
echo 	use %~d0%~p0include\BaseNXP\OsIf_Timer_System_Internal_Systick.h.EB_update
copy .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h.EB_update .\include\BaseNXP\OsIf_Timer_System_Internal_Systick.h >NUL )
if exist .\include\BaseNXP\PlatformTypes.h.EB_update (
echo 	use %~d0%~p0include\BaseNXP\PlatformTypes.h.EB_update
copy .\include\BaseNXP\PlatformTypes.h.EB_update .\include\BaseNXP\PlatformTypes.h >NUL )
if exist .\include\CDD_I2c\I2c.h.EB_update (
echo 	use %~d0%~p0include\CDD_I2c\I2c.h.EB_update
copy .\include\CDD_I2c\I2c.h.EB_update .\include\CDD_I2c\I2c.h >NUL )
if exist .\include\CDD_I2s\I2s.h.EB_update (
echo 	use %~d0%~p0include\CDD_I2s\I2s.h.EB_update
copy .\include\CDD_I2s\I2s.h.EB_update .\include\CDD_I2s\I2s.h >NUL )
if exist .\include\CDD_Rm\Rm.h.EB_update (
echo 	use %~d0%~p0include\CDD_Rm\Rm.h.EB_update
copy .\include\CDD_Rm\Rm.h.EB_update .\include\CDD_Rm\Rm.h >NUL )
:copy_end
