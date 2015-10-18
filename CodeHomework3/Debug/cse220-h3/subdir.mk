################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cse220-h3/main.c \
../cse220-h3/options.c 

OBJS += \
./cse220-h3/main.o \
./cse220-h3/options.o 

C_DEPS += \
./cse220-h3/main.d \
./cse220-h3/options.d 


# Each subdirectory must supply rules for building sources it contributes
cse220-h3/%.o: ../cse220-h3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


