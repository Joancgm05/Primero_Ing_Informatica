# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica 2023_2024
# 
# @author Joan Carlos García Méndez alu0101656571@ull.edu.es
# @date oct 22th 2023
# @brief a makefile for optimice the process of compilation
# @bug 0bugs
 
CXX = g++ 
CXXFLAGS = -std=c++17 -Wall
 
uppercase_lowercase: uppercase_lowercase.o
	$(CXX) $(CXXFLAGS) -o $@ $^  
 
uppercase_lowercase.o: uppercase_lowercase.cc
	$(CXX) $(CXXFLAGS) -c $< 
 
clean:
	rm *.o
	rm uppercase_lowercase.o

