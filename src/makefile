
# Make override variables
CPU=cortex-m0plus
ARCH=thumb
SPECS = nosys.specs

# Compiler variables
CSTD=c11
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
TARGET = main.elf
LDFILE=MKL25Z128xxx4_flash.ld

INCLUDES = -Iinc
SRCS := src/main.c \


# C Flag constants, Gives debug info, Sets C to CSTD version variable, Sets target ARM processor to CPU variable, Sets ARM instruction set to mthumb
CFLAGS = -std=$(CSTD) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall

LDFLAGS = -T=$(LDFILE)# -Wl,-Map=main.map 

# Create object variable for every source
OBJS =$(SRCS:.c=.o)

%.o : %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) -c -o $@

# Create main object file

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
		rm -f $(OBJS) $(TARGET) main.map
