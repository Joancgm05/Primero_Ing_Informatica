#include <iostream>
#include <string>
#include <vector>

const int n_equipos{22}; // Declaramos como constante el número de equipos de la liga

/// @brief Declaramos la struct del Equipo para posteriormente crear un array del número de equipos.
struct Equipo {                
  std::string nombre_equipo;
  int partidos_jugados;
  int partidos_ganados;
  int partidos_empatados;
};

/// @brief Lo mismo para esta struct
struct Clasificacion {        
  std::string nombre_equipo;
  int puntos;
};

/// @brief Esta función copia el nombre del array Equipo al Clasificacion para posteriormente medir 
///        a los valores del struct aqui.
/// @param liga 
/// @param clasificacion 
void Clasificación(struct Equipo liga[n_equipos], struct Clasificacion clasificacion[n_equipos]) {
  for (int i{0}; i < n_equipos; ++i){
    clasificacion[i].nombre_equipo = liga[i].nombre_equipo;
    clasificacion[i].puntos = liga[i].partidos_ganados* 3 + liga[i].partidos_empatados;
  }
}

int main() {
  struct Equipo Liga[22];
  return 0;
}