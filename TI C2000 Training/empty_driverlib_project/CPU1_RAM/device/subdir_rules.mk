################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
device/%.obj: ../device/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/empty_driverlib_project" --include_path="C:/ti/C2000Ware_5_05_00_00" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/empty_driverlib_project/device" --include_path="C:/ti/C2000Ware_5_05_00_00/driverlib/f280013x/driverlib/" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/empty_driverlib_project/CPU1_RAM/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

device/%.obj: ../device/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/empty_driverlib_project" --include_path="C:/ti/C2000Ware_5_05_00_00" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/empty_driverlib_project/device" --include_path="C:/ti/C2000Ware_5_05_00_00/driverlib/f280013x/driverlib/" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/empty_driverlib_project/CPU1_RAM/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


