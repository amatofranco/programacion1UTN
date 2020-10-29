################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/alquileres.c \
../src/armadura.c \
../src/clientes.c \
../src/juegos.c \
../src/utn.c 

OBJS += \
./src/alquileres.o \
./src/armadura.o \
./src/clientes.o \
./src/juegos.o \
./src/utn.o 

C_DEPS += \
./src/alquileres.d \
./src/armadura.d \
./src/clientes.d \
./src/juegos.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


