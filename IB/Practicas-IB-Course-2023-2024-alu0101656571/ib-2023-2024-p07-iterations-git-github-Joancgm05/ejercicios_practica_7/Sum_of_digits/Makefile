# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Joan Carlos García Méndez
# @date
# @brief A Makefile for the execition of the program sum-of-digits.
# 

CXX = g++                        
CXXFLAGS = -std=c++17 -Wall      
LDFLAGS =                      

all: sum-of-digits

sum-of-digits: sum-of-digits.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o 
	rm -rf sum-of-digits
