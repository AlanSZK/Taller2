CXX=g++
CXXFLAGS=-Wall -g3
LDFAGS=-lm

main: main.cpp funciones.o producto.o 
	$(CXX) $(CXXFLAGS) -o main main.cpp funciones.o producto.o $(LDFAGS)

funciones.o: funciones.h funciones.cpp	
	$(CXX) $(CXXFLAGS) -c funciones.cpp

producto.o: producto.h producto.cpp
	$(CXX) $(CXXFLAGS) -c producto.cpp


clean: 
		rm -fr bin/
		rm -fr *.o main 

.PHONY: dist

dist: clean main
	mkdir -p bin 
	cp -r main bin/
	rm -fr *.main 
