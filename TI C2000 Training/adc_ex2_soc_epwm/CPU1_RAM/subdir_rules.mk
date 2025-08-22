################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm" --include_path="C:/ti/C2000Ware_6_00_00_00" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm/device" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280013x/driverlib/" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1627764449: ../adc_ex2_soc_epwm.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm/adc_ex2_soc_epwm.syscfg" -o "syscfg" -s "C:/ti/C2000Ware_6_00_00_00/.metadata/sdk.json" -d "F280013x" -p "64PM" -r "F280013x_64PM" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1627764449 ../adc_ex2_soc_epwm.syscfg
syscfg/board.h: build-1627764449
syscfg/board.cmd.genlibs: build-1627764449
syscfg/board.opt: build-1627764449
syscfg/board.json: build-1627764449
syscfg/pinmux.csv: build-1627764449
syscfg/epwm.dot: build-1627764449
syscfg/adc.dot: build-1627764449
syscfg/c2000ware_libraries.cmd.genlibs: build-1627764449
syscfg/c2000ware_libraries.opt: build-1627764449
syscfg/c2000ware_libraries.c: build-1627764449
syscfg/c2000ware_libraries.h: build-1627764449
syscfg/clocktree.h: build-1627764449
syscfg: build-1627764449

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm" --include_path="C:/ti/C2000Ware_6_00_00_00" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm/device" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280013x/driverlib/" --include_path="C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="U:/1. Projects/000 Selbst Lernen/Resources/TI C2000 Training/adc_ex2_soc_epwm/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


