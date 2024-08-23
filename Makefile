CXX = g++
CXXFLAGS = -g

ArchReload: src/main.cpp
	$(CXX) $(CXXFLAGS) -o ArchReload src/main.cpp

test: ArchReload
	./ArchReload

clean:
	rm -f ./ArchReload
