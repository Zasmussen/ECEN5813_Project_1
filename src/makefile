# @file makefile
# @brief Makefile for creating project1.elf executable
#
# @author Zachary Asmussen
# @date January 30th, 2018
#
# "$ make build" Creates project1.elf file running on HOST as default
# "$ make build PLATFORM=HOST" Currently same as previous command, but more specific
# "$ make build PLTFORM=BBB" Runs cross compiler to run on Beaglebone Black
# "$ make build PLATFORM=KL25Z" Compiles files into project1.elf to run on MKL25Z
# "$ make clean" Deletes all output and executable files
# "$ make compile-all" Generates all ouput files, but does not link anything
#

include sources.mk

# Generic default settings
PLATFORM = HOST
CC = gcc
LD = $(CC)
VERB = -DVERBOSE

# MKL25Z specific settings including loading flags and CPU information
ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
	CPU=cortex-m0plus
	ARCH=armv6-m
	SPECS = nosys.specs
	VERB =

	LDFILE= ../platform/MKL25Z128xxx4_flash.ld
	LDFLAGS = -T$(LDFILE)
	LD=$(CC)

	ARMFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=soft -mfpu=fpv4-sp-d16

# HOST platform setting, same as default setting
else ifeq ($(PLATFORM),HOST)
	CC = gcc
	VERB = -DVERBOSE
	LD = $(CC)

# Cross compiling of Beaglebone Black system
else ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc
	VERB = -DVERBOSE
	LD = $(CC)
endif

# Sets all flags and compiler settings for build
CSTD=c99
COMMONFLAGS = -std=$(CSTD) -Wall -Werror -g -O0
CPPFLAGS = $(VERB) -DPROJECT1
LDFLAGS += -Wl,-Map=main.map
CFLAGS += $(COMMONFLAGS) $(ARMFLAGS)


TARGET = project1.elf


INCLUDES = -I../inc/common -I../inc/kl25z -I../inc/CMSIS -I../inc/ -I../platform

# Create object variable for every source and assembly file
OBJS := $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

# Create object for every C file
%.o : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c -o $@

# Creates assembly file for every C file
%.asm : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) -S -o $@

# Creates object file for every user create .S file
%.o : %.S
	$(CC) $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c  -o $@

# Creates pre-processed output files of every C file
%.i : %.c
	$(CC) $(CPPFLAGS) -E $< -o $@

# Create main object file
.PHONY: build
build: $(TARGET)

# Deletes object and output files
.PHONY: clean
clean:
		rm -f *.o $(TARGET) *.i *.asm main.map

# Only compiles files into objects
.PHONY: compile-all
compile-all: $(OBJS)

# Final link to create .elf file
$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
