# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica 2023-2024
# 
# @author Joan Carlos García Méndez alu0101656571@ull.edu.es
# @date oct 22th 2023
# @brief a makefile for optimice the process of compilation
# @bug 0bugs
 
CXX = g++
CXXFLAGS = -std=c++17 -Wall
 
max-of-three: max-of-three.o
	$(CXX) $(CXXFLAGS) -o $@ $^  
 
max-of-three.o: max-of-three.cc
	$(CXX) $(CXXFLAGS) -c $< 
 
clean:
	rm *.o
	rm max-of-three
