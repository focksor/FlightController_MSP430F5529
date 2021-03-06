################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
flight_ctrl/AttitudePID.obj: ../flight_ctrl/AttitudePID.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="flight_ctrl/AttitudePID.d_raw" --obj_directory="flight_ctrl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

flight_ctrl/PID.obj: ../flight_ctrl/PID.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="flight_ctrl/PID.d_raw" --obj_directory="flight_ctrl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

flight_ctrl/camera.obj: ../flight_ctrl/camera.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="flight_ctrl/camera.d_raw" --obj_directory="flight_ctrl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

flight_ctrl/control.obj: ../flight_ctrl/control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="flight_ctrl/control.d_raw" --obj_directory="flight_ctrl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

flight_ctrl/control_acro.obj: ../flight_ctrl/control_acro.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted -Ooff --opt_for_speed=3 --use_hw_mpy=F5 --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/user/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/driver/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/F5xx_F6xx_Core_Lib" --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/modules/include" --include_path="C:/OneDrive/CrapCode/FlightController_RabbitLab/flight_ctrl/include" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="flight_ctrl/control_acro.d_raw" --obj_directory="flight_ctrl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


