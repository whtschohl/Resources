################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB" --include_path="C:/ti/C2000Ware_5_05_00_00" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB/device" --include_path="C:/ti/C2000Ware_5_05_00_00/driverlib/f280013x/driverlib/" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1053613681: ../lab_f280013x_controlcard.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB/lab_f280013x_controlcard.syscfg" -o "syscfg" -s "C:/ti/C2000Ware_5_05_00_00/.metadata/sdk.json" -b "/boards/TMDSCNCD2800137" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1053613681 ../lab_f280013x_controlcard.syscfg
syscfg/board.h: build-1053613681
syscfg/board.cmd.genlibs: build-1053613681
syscfg/board.opt: build-1053613681
syscfg/board.json: build-1053613681
syscfg/pinmux.csv: build-1053613681
syscfg/c2000ware_libraries.cmd.genlibs: build-1053613681
syscfg/c2000ware_libraries.opt: build-1053613681
syscfg/c2000ware_libraries.c: build-1053613681
syscfg/c2000ware_libraries.h: build-1053613681
syscfg/clocktree.h: build-1053613681
syscfg: build-1053613681

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB" --include_path="C:/ti/C2000Ware_5_05_00_00" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB/device" --include_path="C:/ti/C2000Ware_5_05_00_00/driverlib/f280013x/driverlib/" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/SCI_LAB/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


