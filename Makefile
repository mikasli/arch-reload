CC = g++
CFLAGS = -g

ArchReload: src/main.cpp
	$(CC) $(CFLAGS) -o ArchReload src/main.cpp

test: ArchReload
	./ArchReload

clean:
	rm -f ./ArchReload
