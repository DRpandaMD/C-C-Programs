################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InClassPrograms.cpp \
../src/Scope.cpp \
../src/nameSpace.cpp \
../src/referenceVariables.cpp 

OBJS += \
./src/InClassPrograms.o \
./src/Scope.o \
./src/nameSpace.o \
./src/referenceVariables.o 

CPP_DEPS += \
./src/InClassPrograms.d \
./src/Scope.d \
./src/nameSpace.d \
./src/referenceVariables.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


