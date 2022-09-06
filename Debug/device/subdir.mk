################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MKL43Z4.c 

OBJS += \
./device/system_MKL43Z4.o 

C_DEPS += \
./device/system_MKL43Z4.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\board" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\source" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\drivers" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\component\uart" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\component\serial_manager" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\utilities" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\component\lists" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\device" -I"C:\Users\franc\Documents\MCUXpressoIDE_11.5.0_7232\workspace\TP3_FINAL_KL43\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


