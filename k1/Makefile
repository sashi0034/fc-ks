CC = C:/SDK/gbdk/bin/lcc.exe -mmos6502:nes -Wm-yoA -Wl-j

OUTDIR = build

BINS = $(OUTDIR)/k1.nes

all: $(OUTDIR) $(BINS)

ASRC = $(wildcard *.s)
CSRC = $(wildcard *.c)

OBJS = $(CSRC:%.c=$(OUTDIR)/%.o) $(ASRC:%.s=$(OUTDIR)/%.o)

# Compile and link single file in one pass

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%.o: %.c
	$(CC) -c -o $@ $<

$(OUTDIR)/%.o: %.s
	$(CC) -c -o $@ $<

$(BINS): $(OBJS)
	$(CC) -Wm-yS -o $@ $^
	rm -f $(OUTDIR)/*.map $(OUTDIR)/*.noi $(OUTDIR)/*.ihx $(OUTDIR)/*.lst

run: $(BINS)
	F:\Downloads\punes-0.110-x86_64-win-d3d9\punes64.exe $(BINS)
	echo

clean:
	rm -f $(OUTDIR)/*.*
