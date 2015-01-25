################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bst.c \
../expression_tree.c \
../permutation.c \
../tree.c \
../tree_basics.c 

OBJS += \
./bst.o \
./expression_tree.o \
./permutation.o \
./tree.o \
./tree_basics.o 

C_DEPS += \
./bst.d \
./expression_tree.d \
./permutation.d \
./tree.d \
./tree_basics.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


