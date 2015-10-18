################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maze.cpp \
../Menu.cpp \
../Node.cpp \
../Project3.cpp 

OBJS += \
./Maze.o \
./Menu.o \
./Node.o \
./Project3.o 

CPP_DEPS += \
./Maze.d \
./Menu.d \
./Node.d \
./Project3.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


