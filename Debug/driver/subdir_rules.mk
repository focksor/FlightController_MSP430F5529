################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
driver/i2c.obj: ../driver/i2c.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/i2c.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/inv_mpu.obj: ../driver/inv_mpu.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/inv_mpu.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/inv_mpu_dmp_motion_driver.obj: ../driver/inv_mpu_dmp_motion_driver.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/inv_mpu_dmp_motion_driver.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/motor.obj: ../driver/motor.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/motor.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/mpu6050.obj: ../driver/mpu6050.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/mpu6050.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/oled.obj: ../driver/oled.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/oled.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/ppm.obj: ../driver/ppm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/ppm.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/ultrasonic.obj: ../driver/ultrasonic.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/ultrasonic.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver/usart.obj: ../driver/usart.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/usart.d_raw" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


