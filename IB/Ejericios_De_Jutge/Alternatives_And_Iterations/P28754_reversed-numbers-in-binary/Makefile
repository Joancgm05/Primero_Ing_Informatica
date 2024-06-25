# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Joan Carlos García Méndez
# @date
# @brief A Makefile for the execition of the program reversed-number-in-binary.
#

CXX = g++ 
CXXFLAGS = -std=c++17 -Wall 
LDFLAGS = 

all: reversed-number-in-binary

reversed-number-in-binary: reversed-number-in-binary.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o
	rm -rf reversed-number-in-binary
 
