################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x/device" --include_path="C:/ti/C2000Ware_5_05_00_00/driverlib/f280013x/driverlib" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=CPU1 --define=USE_ADC_REFERENCE_INTERNAL --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-647866239: ../lab_sci_controlcard.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x/lab_sci_controlcard.syscfg" -o "syscfg" -s "C:/ti/C2000Ware_5_05_00_00/.metadata/sdk.json" -b "/boards/TMDSCNCD2800137" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-647866239 ../lab_sci_controlcard.syscfg
syscfg/board.h: build-647866239
syscfg/board.cmd.genlibs: build-647866239
syscfg/board.opt: build-647866239
syscfg/board.json: build-647866239
syscfg/pinmux.csv: build-647866239
syscfg/c2000ware_libraries.cmd.genlibs: build-647866239
syscfg/c2000ware_libraries.opt: build-647866239
syscfg/c2000ware_libraries.c: build-647866239
syscfg/c2000ware_libraries.h: build-647866239
syscfg/clocktree.h: build-647866239
syscfg: build-647866239

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x/device" --include_path="C:/ti/C2000Ware_5_05_00_00/driverlib/f280013x/driverlib" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=CPU1 --define=USE_ADC_REFERENCE_INTERNAL --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/sci_cc_f280013x/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


