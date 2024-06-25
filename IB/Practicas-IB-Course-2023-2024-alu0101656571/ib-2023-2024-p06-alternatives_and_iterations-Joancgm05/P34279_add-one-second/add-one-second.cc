/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2023-2024
 *  
 * @author Joan Carlos García Méndez alu0101656571@ull.edu.es
 * @date oct 22th 2023
 * @brief this program adds one second to a clock time, given 
          its hours, minutes and seconds
 * @bug 0 bugs
 * @see https://jutge.org/problems/P34279_en
 */
 
#include<iostream>

int main() {
  int hours, minutes, seconds;
  std::cin >> hours >> minutes >> seconds;
  
  seconds++;

  if (seconds > 59) {
  minutes++;
	seconds = 0;
  }
  if (minutes > 59) {
  hours++;
  minutes = 0;
  }
  if (hours > 23) {
  hours = 0;
  minutes = 0;
  seconds = 0;
  }	
  if (hours < 10) {
  std::cout << "0";
  }
  std::cout << hours << ":";
  if (minutes < 10) {
  std::cout << "0";
  }
  std::cout << minutes << ":";
  if (seconds < 10) {
  std::cout << "0";  
  }
  std::cout << seconds << '\n';

  return 0;
 }
