EXECUTABLE=crc32
PLATFORM=$(shell uname)

all: $(EXECUTABLE)

$(EXECUTABLE): crc32.c
	gcc -O0 -I. crc32.c -DCRC32TOOL_STANDALONE -o $(EXECUTABLE) -lz

run: $(EXECUTABLE)
	./$(EXECUTABLE) crc32.c

clean:
	rm -f $(EXECUTABLE)
	rm -f $(EXECUTABLE).exe
