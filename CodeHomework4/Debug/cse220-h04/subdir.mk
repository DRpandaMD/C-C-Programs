################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cse220-h04/count.c \
../cse220-h04/main.c 

OBJS += \
./cse220-h04/count.o \
./cse220-h04/main.o 

C_DEPS += \
./cse220-h04/count.d \
./cse220-h04/main.d 


# Each subdirectory must supply rules for building sources it contributes
cse220-h04/%.o: ../cse220-h04/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


