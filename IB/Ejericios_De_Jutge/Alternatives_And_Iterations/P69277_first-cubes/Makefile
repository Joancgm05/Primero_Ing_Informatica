# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Joan Carlos García Méndez
# @date
# @brief A Makefile for the execition of the program first-cubes.
#

CXX = g++ 
CXXFLAGS = -std=c++17 -Wall 
LDFLAGS = 

all: first-cubes

first-cubes: first-cubes.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o
	rm -rf first-cubes
 
