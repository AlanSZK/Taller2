CXX=g++
CXXFLAGS=-Wall -g3
LDFAGS=-lm

main: main.cpp funciones.o venta.o 
	$(CXX) $(CXXFLAGS) -o main main.cpp funciones.o venta.o $(LDFAGS)

funciones.o: funciones.h funciones.cpp	
	$(CXX) $(CXXFLAGS) -c funciones.cpp

venta.o: venta.h venta.cpp
	$(CXX) $(CXXFLAGS) -c venta.cpp


clean: 
		rm -fr bin/
		rm -fr *.o main 

.PHONY: dist

dist: clean main
	mkdir -p bin 
	cp -r main bin/
	rm -fr *.main 
