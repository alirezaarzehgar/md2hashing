CC = cc
BUILD_OPT = -c
INSTALL_OPT = -o
SOURCES = main.c src/calc_md2.c src/chartohex.c
OUT_RESOURCES = out/*
OUTPUT = bin/md2

all: compile

compile:
	mkdir -p out

	$(CC) $(BUILD_OPT) $(SOURCES)
	mv *.o out

install:
	mkdir -p bin

	$(CC) $(OUT_RESOURCES) $(INSTALL_OPT) $(OUTPUT)

clean:
	rm -rf $(OUT_RESOURCES)

