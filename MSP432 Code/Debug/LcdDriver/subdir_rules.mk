################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
LcdDriver/%.obj: ../LcdDriver/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
<<<<<<< HEAD
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/dmmil/Google Drive/BYUI Drive/_ECEN361/Ecen361-UFPA/MSP432 Code" --include_path="C:/ti/simplelink_msp432p4_sdk_2_30_00_14/source" --include_path="C:/ti/simplelink_msp432p4_sdk_2_30_00_14/source/third_party/CMSIS/Include" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="LcdDriver/$(basename $(<F)).d_raw" --obj_directory="LcdDriver" $(GEN_OPTS__FLAG) "$<"
=======
	"/Applications/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Users/LuisDavidRuiz/ti/simplelink_msp432p4_sdk_1_60_00_12/source/ti/grlib" --include_path="/Users/LuisDavidRuiz/Desktop/Ecen361-UFPA/MSP432 Code" --include_path="/Users/LuisDavidRuiz/ti/simplelink_msp432p4_sdk_2_30_00_14/source" --include_path="/Users/LuisDavidRuiz/ti/simplelink_msp432p4_sdk_2_30_00_14/source/third_party/CMSIS/Include" --include_path="/Applications/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS/include" --advice:power=none --define=__MSP432P401R__ --define=DeviceFamily_MSP432P401x -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="LcdDriver/$(basename $(<F)).d_raw" --obj_directory="LcdDriver" $(GEN_OPTS__FLAG) "$<"
>>>>>>> 66b35d49145b1437d1bb127a87bfb3919dfdec3d
	@echo 'Finished building: "$<"'
	@echo ' '


