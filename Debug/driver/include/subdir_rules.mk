################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
driver/include/mpu6050.obj: ../driver/include/mpu6050.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/__Workspace/TI/18_430F5529_Quad_Attempt_2" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --include_path="D:/__Workspace/TI/18_430F5529_Quad_Attempt_2/user/include" --include_path="D:/__Workspace/TI/18_430F5529_Quad_Attempt_2/driver/include" --include_path="D:/__Workspace/TI/18_430F5529_Quad_Attempt_2/F5xx_F6xx_Core_Lib" --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=full --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driver/include/mpu6050.d" --obj_directory="driver/include" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


