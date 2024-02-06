CC65_PATH := C:/SDK/cc65
CC65 := $(CC65_PATH)/bin/cc65
CA65 := $(CC65_PATH)/bin/ca65
LD65 := $(CC65_PATH)/bin/ld65
OUTDIR := build

SRC := $(wildcard *.c)

ASSEMBLY := $(OUTDIR)/$(SRC:.c=.s)
OBJECT := $(OUTDIR)/$(SRC:.c=.o)
TARGET := $(OUTDIR)/$(SRC:.c=.nes)

CA65_INC := $(CC65_PATH)/include
CC65_INC := $(CC65_PATH)/include
LD65_CFG := $(CC65_PATH)/cfg
LD65_LIB := $(CC65_PATH)/lib
LD65_OBJ := $(CC65_PATH)/obj
CC65_HOME := $(CC65_PATH)

# Ensure the build directory exists
$(OUTDIR):
	mkdir -p $(OUTDIR)

# Compile C to assembly
$(ASSEMBLY): $(SRC) | $(OUTDIR)
	$(CC65) -t nes --include-dir $(CC65_INC) $< -o $@

# Assemble to object file
$(OBJECT): $(ASSEMBLY)
	$(CA65) -t nes --include-dir $(CA65_INC) $< -o $@

# Link object file to create NES file
$(TARGET): $(OBJECT)
	$(LD65) -C $(LD65_CFG)/nes.cfg -o $@ $< $(LD65_LIB)/nes.lib

all: $(TARGET)

run: $(TARGET)
	F:\Downloads\punes-0.110-x86_64-win-d3d9\punes64.exe $(TARGET)
	echo Finishded

clean:
	rm -f $(ASSEMBLY) $(OBJECT) $(TARGET)

.PHONY: all clean
