################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Friends.cpp \
../Menu.cpp \
../SystemMain.cpp \
../User.cpp \
../Wall.cpp \
../main.cpp 

OBJS += \
./Friends.o \
./Menu.o \
./SystemMain.o \
./User.o \
./Wall.o \
./main.o 

CPP_DEPS += \
./Friends.d \
./Menu.d \
./SystemMain.d \
./User.d \
./Wall.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


