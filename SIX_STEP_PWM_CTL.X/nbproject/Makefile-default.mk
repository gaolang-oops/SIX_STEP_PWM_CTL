#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../HARDWARE/Led.c ../HARDWARE/HardWare.c ../HARDWARE/Key.c ../HARDWARE/Timer.c ../HARDWARE/Pwm.c ../HARDWARE/Adc.c ../HARDWARE/Spi.c ../HARDWARE/Ic.c ../SOC/Config.c ../SOC/Startup.s ../SYSTEM/Delay.s ../SYSTEM/Kernel.c ../SYSTEM/Error.c ../SYSTEM/Moto.c ../SYSTEM/Rotor.c ../USER/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/343451991/Led.o ${OBJECTDIR}/_ext/343451991/HardWare.o ${OBJECTDIR}/_ext/343451991/Key.o ${OBJECTDIR}/_ext/343451991/Timer.o ${OBJECTDIR}/_ext/343451991/Pwm.o ${OBJECTDIR}/_ext/343451991/Adc.o ${OBJECTDIR}/_ext/343451991/Spi.o ${OBJECTDIR}/_ext/343451991/Ic.o ${OBJECTDIR}/_ext/1360905368/Config.o ${OBJECTDIR}/_ext/1360905368/Startup.o ${OBJECTDIR}/_ext/1749661346/Delay.o ${OBJECTDIR}/_ext/1749661346/Kernel.o ${OBJECTDIR}/_ext/1749661346/Error.o ${OBJECTDIR}/_ext/1749661346/Moto.o ${OBJECTDIR}/_ext/1749661346/Rotor.o ${OBJECTDIR}/_ext/761542982/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/343451991/Led.o.d ${OBJECTDIR}/_ext/343451991/HardWare.o.d ${OBJECTDIR}/_ext/343451991/Key.o.d ${OBJECTDIR}/_ext/343451991/Timer.o.d ${OBJECTDIR}/_ext/343451991/Pwm.o.d ${OBJECTDIR}/_ext/343451991/Adc.o.d ${OBJECTDIR}/_ext/343451991/Spi.o.d ${OBJECTDIR}/_ext/343451991/Ic.o.d ${OBJECTDIR}/_ext/1360905368/Config.o.d ${OBJECTDIR}/_ext/1360905368/Startup.o.d ${OBJECTDIR}/_ext/1749661346/Delay.o.d ${OBJECTDIR}/_ext/1749661346/Kernel.o.d ${OBJECTDIR}/_ext/1749661346/Error.o.d ${OBJECTDIR}/_ext/1749661346/Moto.o.d ${OBJECTDIR}/_ext/1749661346/Rotor.o.d ${OBJECTDIR}/_ext/761542982/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/343451991/Led.o ${OBJECTDIR}/_ext/343451991/HardWare.o ${OBJECTDIR}/_ext/343451991/Key.o ${OBJECTDIR}/_ext/343451991/Timer.o ${OBJECTDIR}/_ext/343451991/Pwm.o ${OBJECTDIR}/_ext/343451991/Adc.o ${OBJECTDIR}/_ext/343451991/Spi.o ${OBJECTDIR}/_ext/343451991/Ic.o ${OBJECTDIR}/_ext/1360905368/Config.o ${OBJECTDIR}/_ext/1360905368/Startup.o ${OBJECTDIR}/_ext/1749661346/Delay.o ${OBJECTDIR}/_ext/1749661346/Kernel.o ${OBJECTDIR}/_ext/1749661346/Error.o ${OBJECTDIR}/_ext/1749661346/Moto.o ${OBJECTDIR}/_ext/1749661346/Rotor.o ${OBJECTDIR}/_ext/761542982/main.o

# Source Files
SOURCEFILES=../HARDWARE/Led.c ../HARDWARE/HardWare.c ../HARDWARE/Key.c ../HARDWARE/Timer.c ../HARDWARE/Pwm.c ../HARDWARE/Adc.c ../HARDWARE/Spi.c ../HARDWARE/Ic.c ../SOC/Config.c ../SOC/Startup.s ../SYSTEM/Delay.s ../SYSTEM/Kernel.c ../SYSTEM/Error.c ../SYSTEM/Moto.c ../SYSTEM/Rotor.c ../USER/main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128MC506
MP_LINKER_FILE_OPTION=,--script="..\Linker\p33EP128MC506.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/343451991/Led.o: ../HARDWARE/Led.c  .generated_files/flags/default/bfe7679253d747eb3a2d1012a5dee3114b31076b .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Led.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Led.c  -o ${OBJECTDIR}/_ext/343451991/Led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Led.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/HardWare.o: ../HARDWARE/HardWare.c  .generated_files/flags/default/ec055898bfcfd7f9655ca69c8d4885939c46cd31 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/HardWare.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/HardWare.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/HardWare.c  -o ${OBJECTDIR}/_ext/343451991/HardWare.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/HardWare.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Key.o: ../HARDWARE/Key.c  .generated_files/flags/default/6721dafbb86d88ebb4498dd777889f6044f07589 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Key.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Key.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Key.c  -o ${OBJECTDIR}/_ext/343451991/Key.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Key.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Timer.o: ../HARDWARE/Timer.c  .generated_files/flags/default/af91bcd7bfb67db9635994a970bbd89fd6c6a022 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Timer.c  -o ${OBJECTDIR}/_ext/343451991/Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Pwm.o: ../HARDWARE/Pwm.c  .generated_files/flags/default/f62d9d567f4159b2c1002b8a25cbedda62f67c3d .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Pwm.c  -o ${OBJECTDIR}/_ext/343451991/Pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Pwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Adc.o: ../HARDWARE/Adc.c  .generated_files/flags/default/d502ed01ed0dbeb0314667efeb95c631f03fedcc .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Adc.c  -o ${OBJECTDIR}/_ext/343451991/Adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Spi.o: ../HARDWARE/Spi.c  .generated_files/flags/default/88306fd005c67b88fab0f9518c23fa9ed5dd9261 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Spi.c  -o ${OBJECTDIR}/_ext/343451991/Spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Ic.o: ../HARDWARE/Ic.c  .generated_files/flags/default/1faaefb4597f979f7e5ea2c2acf90d3afc570ee5 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Ic.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Ic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Ic.c  -o ${OBJECTDIR}/_ext/343451991/Ic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Ic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360905368/Config.o: ../SOC/Config.c  .generated_files/flags/default/d48c1d1b3430216add5ba01c84cfb9c7923a29d4 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1360905368" 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SOC/Config.c  -o ${OBJECTDIR}/_ext/1360905368/Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360905368/Config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Kernel.o: ../SYSTEM/Kernel.c  .generated_files/flags/default/faf1d9ea4fc87fddbc3f1f07c7ffc50940826916 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Kernel.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Kernel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Kernel.c  -o ${OBJECTDIR}/_ext/1749661346/Kernel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Kernel.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Error.o: ../SYSTEM/Error.c  .generated_files/flags/default/973d04ac287163140eb6790fd64bf1afcf3793ad .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Error.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Error.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Error.c  -o ${OBJECTDIR}/_ext/1749661346/Error.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Error.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Moto.o: ../SYSTEM/Moto.c  .generated_files/flags/default/f7321b6f493976fe4466e3fef401b23c7385d1c3 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Moto.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Moto.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Moto.c  -o ${OBJECTDIR}/_ext/1749661346/Moto.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Moto.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Rotor.o: ../SYSTEM/Rotor.c  .generated_files/flags/default/bc5254406a202089df512c2f65ae277573f8765a .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Rotor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Rotor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Rotor.c  -o ${OBJECTDIR}/_ext/1749661346/Rotor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Rotor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/761542982/main.o: ../USER/main.c  .generated_files/flags/default/d0520bba3a6f99f5f33592745420b735de057130 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/761542982" 
	@${RM} ${OBJECTDIR}/_ext/761542982/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/761542982/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../USER/main.c  -o ${OBJECTDIR}/_ext/761542982/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/761542982/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/343451991/Led.o: ../HARDWARE/Led.c  .generated_files/flags/default/9523fa3a7f6990797fc1b5842b69e38800cc90d0 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Led.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Led.c  -o ${OBJECTDIR}/_ext/343451991/Led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Led.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/HardWare.o: ../HARDWARE/HardWare.c  .generated_files/flags/default/8e8ba9017a62dea521ec7555fedd3645bbec6db1 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/HardWare.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/HardWare.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/HardWare.c  -o ${OBJECTDIR}/_ext/343451991/HardWare.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/HardWare.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Key.o: ../HARDWARE/Key.c  .generated_files/flags/default/431d8878f368d5f80f42a5b7631a6bac89bce4ec .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Key.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Key.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Key.c  -o ${OBJECTDIR}/_ext/343451991/Key.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Key.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Timer.o: ../HARDWARE/Timer.c  .generated_files/flags/default/af8d77e76087bbe4bdd298e445df1f31afe864c0 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Timer.c  -o ${OBJECTDIR}/_ext/343451991/Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Pwm.o: ../HARDWARE/Pwm.c  .generated_files/flags/default/452d5d57d4dc25e958334d0ded84da8a9a38abea .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Pwm.c  -o ${OBJECTDIR}/_ext/343451991/Pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Adc.o: ../HARDWARE/Adc.c  .generated_files/flags/default/128e3bb2577c1360ec47fcccc67fff60738f319c .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Adc.c  -o ${OBJECTDIR}/_ext/343451991/Adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Spi.o: ../HARDWARE/Spi.c  .generated_files/flags/default/dd0a7ddb8c50efc0de26ae9ef4d4bb0aae5d2d48 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Spi.c  -o ${OBJECTDIR}/_ext/343451991/Spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/343451991/Ic.o: ../HARDWARE/Ic.c  .generated_files/flags/default/772b634e52ff223d5dc96e8e26a30fa32437a4c9 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/343451991" 
	@${RM} ${OBJECTDIR}/_ext/343451991/Ic.o.d 
	@${RM} ${OBJECTDIR}/_ext/343451991/Ic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HARDWARE/Ic.c  -o ${OBJECTDIR}/_ext/343451991/Ic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/343451991/Ic.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360905368/Config.o: ../SOC/Config.c  .generated_files/flags/default/ec77ee14221492b5ebf40ada83e7402f80a18799 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1360905368" 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SOC/Config.c  -o ${OBJECTDIR}/_ext/1360905368/Config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360905368/Config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Kernel.o: ../SYSTEM/Kernel.c  .generated_files/flags/default/372df5a9a870f34d9a490bfd4a0ef6d6fb7b8ba8 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Kernel.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Kernel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Kernel.c  -o ${OBJECTDIR}/_ext/1749661346/Kernel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Kernel.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Error.o: ../SYSTEM/Error.c  .generated_files/flags/default/4d46d9cf3754ee59f5576a830130ccd9ad2bdcf5 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Error.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Error.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Error.c  -o ${OBJECTDIR}/_ext/1749661346/Error.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Error.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Moto.o: ../SYSTEM/Moto.c  .generated_files/flags/default/32453de41d7ac30d04689d4da811c2a6729f5323 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Moto.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Moto.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Moto.c  -o ${OBJECTDIR}/_ext/1749661346/Moto.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Moto.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Rotor.o: ../SYSTEM/Rotor.c  .generated_files/flags/default/a36592b693bf6a395c39c463434eefcb7efa1ca6 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Rotor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Rotor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SYSTEM/Rotor.c  -o ${OBJECTDIR}/_ext/1749661346/Rotor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1749661346/Rotor.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/761542982/main.o: ../USER/main.c  .generated_files/flags/default/130f9bbeb407efb1b7bda303f9463696819f72be .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/761542982" 
	@${RM} ${OBJECTDIR}/_ext/761542982/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/761542982/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../USER/main.c  -o ${OBJECTDIR}/_ext/761542982/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/761542982/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../HARDWARE" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360905368/Startup.o: ../SOC/Startup.s  .generated_files/flags/default/c90991143d00ea62229679ecef797532fe6f7938 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1360905368" 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Startup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Startup.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../SOC/Startup.s  -o ${OBJECTDIR}/_ext/1360905368/Startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1360905368/Startup.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Delay.o: ../SYSTEM/Delay.s  .generated_files/flags/default/64886c3b62774547b85e58b50645612134dbffa2 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Delay.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../SYSTEM/Delay.s  -o ${OBJECTDIR}/_ext/1749661346/Delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1749661346/Delay.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1360905368/Startup.o: ../SOC/Startup.s  .generated_files/flags/default/824617beac948d58a9e26a1628f2eabe1b454ed4 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1360905368" 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Startup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360905368/Startup.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../SOC/Startup.s  -o ${OBJECTDIR}/_ext/1360905368/Startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1360905368/Startup.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1749661346/Delay.o: ../SYSTEM/Delay.s  .generated_files/flags/default/3c9cb77e4e716316887c399a739494d59ab03f11 .generated_files/flags/default/ee71d62e67581db8c10a5a3b203d13aea51f1f0
	@${MKDIR} "${OBJECTDIR}/_ext/1749661346" 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1749661346/Delay.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../SYSTEM/Delay.s  -o ${OBJECTDIR}/_ext/1749661346/Delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1749661346/Delay.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../Linker/p33EP128MC506.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../Linker/p33EP128MC506.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/SIX_STEP_PWM_CTL.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
