################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F5xx_F6xx_Core_Lib/HAL_FLASH.obj" \
"./F5xx_F6xx_Core_Lib/HAL_PMAP.obj" \
"./F5xx_F6xx_Core_Lib/HAL_PMM.obj" \
"./F5xx_F6xx_Core_Lib/HAL_TLV.obj" \
"./F5xx_F6xx_Core_Lib/HAL_UCS.obj" \
"./driver/i2c.obj" \
"./driver/inv_mpu.obj" \
"./driver/inv_mpu_dmp_motion_driver.obj" \
"./driver/motor.obj" \
"./driver/mpu6050.obj" \
"./driver/oled.obj" \
"./driver/ppm.obj" \
"./driver/ultrasonic.obj" \
"./driver/usart.obj" \
"./flight_ctrl/AttitudePID.obj" \
"./flight_ctrl/PID.obj" \
"./flight_ctrl/camera.obj" \
"./flight_ctrl/control.obj" \
"./flight_ctrl/control_acro.obj" \
"./modules/filter.obj" \
"./modules/imu.obj" \
"./user/main.obj" \
"./user/msp430_clock.obj" \
"../lnk_msp430f5529.cmd" \
$(GEN_CMDS__FLAG) \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include F5xx_F6xx_Core_Lib/subdir_vars.mk
-include driver/subdir_vars.mk
-include flight_ctrl/subdir_vars.mk
-include modules/subdir_vars.mk
-include user/subdir_vars.mk
-include subdir_rules.mk
-include F5xx_F6xx_Core_Lib/subdir_rules.mk
-include driver/subdir_rules.mk
-include flight_ctrl/subdir_rules.mk
-include modules/subdir_rules.mk
-include user/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
FlightController_RabbitLab.out \

EXE_OUTPUTS__QUOTED += \
"FlightController_RabbitLab.out" \

BIN_OUTPUTS += \
FlightController_RabbitLab.hex \

BIN_OUTPUTS__QUOTED += \
"FlightController_RabbitLab.hex" \


# All Target
all: FlightController_RabbitLab.out

# Tool invocations
FlightController_RabbitLab.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -O2 --opt_for_speed=3 --use_hw_mpy=F5 --advice:power="all" --define=__MSP430F5529__ --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 -z -m"FlightController_RabbitLab.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/ti/ccsv8/ccs_base/msp430/include" -i"C:/ti/ccsv8/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/lib" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="FlightController_RabbitLab_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "FlightController_RabbitLab.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

FlightController_RabbitLab.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/hex430" --memwidth=8 --romwidth=8 -o "FlightController_RabbitLab.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "F5xx_F6xx_Core_Lib\HAL_FLASH.obj" "F5xx_F6xx_Core_Lib\HAL_PMAP.obj" "F5xx_F6xx_Core_Lib\HAL_PMM.obj" "F5xx_F6xx_Core_Lib\HAL_TLV.obj" "F5xx_F6xx_Core_Lib\HAL_UCS.obj" "driver\i2c.obj" "driver\inv_mpu.obj" "driver\inv_mpu_dmp_motion_driver.obj" "driver\motor.obj" "driver\mpu6050.obj" "driver\oled.obj" "driver\ppm.obj" "driver\ultrasonic.obj" "driver\usart.obj" "flight_ctrl\AttitudePID.obj" "flight_ctrl\PID.obj" "flight_ctrl\camera.obj" "flight_ctrl\control.obj" "flight_ctrl\control_acro.obj" "modules\filter.obj" "modules\imu.obj" "user\main.obj" "user\msp430_clock.obj" 
	-$(RM) "F5xx_F6xx_Core_Lib\HAL_FLASH.d" "F5xx_F6xx_Core_Lib\HAL_PMAP.d" "F5xx_F6xx_Core_Lib\HAL_PMM.d" "F5xx_F6xx_Core_Lib\HAL_TLV.d" "F5xx_F6xx_Core_Lib\HAL_UCS.d" "driver\i2c.d" "driver\inv_mpu.d" "driver\inv_mpu_dmp_motion_driver.d" "driver\motor.d" "driver\mpu6050.d" "driver\oled.d" "driver\ppm.d" "driver\ultrasonic.d" "driver\usart.d" "flight_ctrl\AttitudePID.d" "flight_ctrl\PID.d" "flight_ctrl\camera.d" "flight_ctrl\control.d" "flight_ctrl\control_acro.d" "modules\filter.d" "modules\imu.d" "user\main.d" "user\msp430_clock.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

