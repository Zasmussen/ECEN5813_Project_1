PLATFORM =
CC =
INCLUDES =

ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
	CPU=cortex-m0plus
	ARCH=armv6-m
	SPECS = nosys.specs

	LDFILE= ../platform/MKL25Z128xxx4_flash.ld
	LDFLAGS = -T$(LDFILE)
	LD=arm-none-eabi-ld

	ARMFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=soft -mfpu=fpv4-sp-d16
else ifeq ($(PLATFORM),HOST)
	CC = gcc
	VERB = -DVERBOSE
	LD = $(CC)
else ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc
	VERB = -DVERBOSE
	LD = $(CC)
endif

CSTD=c99
COMMONFLAGS = -std=$(CSTD) -Wall -Werror -g -O0
CPPFLAGS = $(VERB) -DPROJECT1
LDFLAGS += -Wl,-Map=main.map
CFLAGS += $(COMMONFLAGS) $(ARMFLAGS)

TARGET = project1.elf


INCLUDES = -I../inc/common -I../inc/kl25z -I../inc/CMSIS -I../inc/ -I../platform
SRCS := main.c memory.c data.c conversion.c debug.c project1.c \


# C Flag constants, Gives debug info, Sets C to CSTD version variable, Sets target ARM processor to CPU variable, Sets ARM instruction set to mthumb





# Create object variable for every source
OBJS := $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

%.o : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) $(CPPFLAGS) -c -o $@

%.asm : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) -S -o $@

%.o : %.S
	$(CC) $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

%.i : %.c
	$(CC) $(CPPFLAGS) -E $< -o $@

# Create main object file
.PHONY: build
build: $(TARGET)

.PHONY: clean
clean:
		rm -f $(OBJS) $(TARGET) main.map

.PHONY: compile-all



$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
