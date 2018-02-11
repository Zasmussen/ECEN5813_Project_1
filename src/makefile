PLATFORM =
CC =

ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
endif
ifeq ($(PLATFORM),HOST)
	CC = gcc
endif
ifeq ($(PLATFORM),BBB)
	CC = gcc
endif
# KL25Z Variables
CPU=cortex-m0plus
ARCH=thumb
SPECS = nosys.specs

# Compiler variables
CSTD=c99
LD=arm-none-eabi-ld
ARMTARGET = project1arm.elf
TARGET = project1.elf
LDFILE= ../platform/MKL25Z128xxx4_flash.ld

INCLUDES = -I../inc/common -I../inc/kl25z -I../inc/CMSIS -I../inc/ -I../platform
SRCS := main.c memory.c data.c conversion.c debug.c project1.c \


# C Flag constants, Gives debug info, Sets C to CSTD version variable, Sets target ARM processor to CPU variable, Sets ARM instruction set to mthumb
CFLAGS = -std=$(CSTD) -Wall -Werror -g -O0
ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) -march= --specs=$(SPECS)
CPPFLAGS =
LDFLAGS = -T=$(LDFILE)# -Wl,-Map=main.map

# Create object variable for every source
OBJS =$(SRCS:.c=.o)

%.o : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) -c -o $@

# Create main object file

.PHONY: build
ifeq ($(PLATFORM),KL25Z)
build: $(ARMTARGET)
endif
ifeq ($(PLATFORM),HOST)
build: $(TARGET)
endif
ifeq ($(PLATFORM),BBB)
build: $(TARGET)
endif


$(ARMTARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@


.PHONY: clean
clean:
		rm -f $(OBJS) $(TARGET) main.map
