################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/button.c \
../Core/Inc/fsm.c \
../Core/Inc/fsm_manual.c \
../Core/Inc/global.c \
../Core/Inc/software_timer.c 

OBJS += \
./Core/Inc/button.o \
./Core/Inc/fsm.o \
./Core/Inc/fsm_manual.o \
./Core/Inc/global.o \
./Core/Inc/software_timer.o 

C_DEPS += \
./Core/Inc/button.d \
./Core/Inc/fsm.d \
./Core/Inc/fsm_manual.d \
./Core/Inc/global.d \
./Core/Inc/software_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

