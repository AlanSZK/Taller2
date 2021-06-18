CXX=g++
CXXFLAGS=-Wall -g3
LDFAGS=-lm

main: main.cpp funciones.o 
	$(CXX) $(CXXFLAGS) -o main main.cpp funciones.o $(LDFAGS)

funciones.o: funciones.h funciones.cpp	
	$(CXX) $(CXXFLAGS) -c funciones.cpp


clean: 
		rm -fr bin/
		rm -fr *.o main 

.PHONY: dist
dist: clean main
	mkdir -p bin 
	cp -r main bin/
	rm -fr *.main 
