CC65_PATH := C:/SDK/cc65
CC65 := $(CC65_PATH)/bin/cc65
CA65 := $(CC65_PATH)/bin/ca65
LD65 := $(CC65_PATH)/bin/ld65
OUTDIR := build

SOURCES := $(wildcard *.c)
ASSEMBLIES := $(SOURCES:%.c=$(OUTDIR)/%.s)
OBJECTS := $(SOURCES:%.c=$(OUTDIR)/%.o)
TARGET := $(OUTDIR)/k2.nes

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
$(OUTDIR)/%.s: %.c | $(OUTDIR)
	$(CC65) -t nes --include-dir $(CC65_INC) $< -o $@

# Assemble to object file
$(OUTDIR)/%.o: $(OUTDIR)/%.s
	$(CA65) -t nes --include-dir $(CA65_INC) $< -o $@

# Link object files to create NES file
$(TARGET): $(OBJECTS)
	$(LD65) -C $(LD65_CFG)/nes.cfg -o $@ $^ $(LD65_LIB)/nes.lib

all: $(TARGET)

run: $(TARGET)
	F:\Downloads\punes-0.110-x86_64-win-d3d9\punes64.exe $(TARGET)
	echo Finished

clean:
	rm -f $(ASSEMBLIES) $(OBJECTS) $(TARGET)

.PHONY: all run clean

.PRECIOUS: $(OUTDIR)/%.s
