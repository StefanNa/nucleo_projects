################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.c 

OBJS += \
./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.o 

C_DEPS += \
./Utilities/STM32F1xx_Nucleo/stm32f1xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F1xx_Nucleo/%.o: ../Utilities/STM32F1xx_Nucleo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DUSE_RTOS_SYSTICK -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/inc" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/CMSIS/core" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/CMSIS/device" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/HAL_Driver/Inc/Legacy" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/HAL_Driver/Inc" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/STM32Toolchain/projects/eclipseOPEN/Tetst/Utilities/STM32F1xx_Nucleo" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


