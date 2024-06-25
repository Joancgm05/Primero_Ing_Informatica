# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Joan Carlos García Méndez
# @date
# @brief A Makefile for the execition of the program sum-of-squares.
#

CXX = g++ 
CXXFLAGS = -std=c++17 -Wall 
LDFLAGS = 

all: sum-of-squares

sum-of-squares: sum-of-squares.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o
	rm -rf sum-of-squares
 
