#include <iostream>
#include <string>
#include <vector>

struct Equipo {
  std::string nombre_equipo;
  int partidos_jugados;
  int partidos_ganados;
  int partidos_empatados;
};

struct Clasificación {
  std::string nombre_equipo;
  int puntos;
};

void Clasificación(struct Equipo liga[N_EQUIPOS], struct Equipo_Clasificación Clasificación[N_EQUIPOS]) {
  for (int i{0}; i < N_EQUIPOS; ++i){
    Clasificación[i].nombre_equipo = liga[i].nombre_equipo;
    Clasificación[i].puntuacion = liga[i].partidos_ganados* 3 + liga[i].partidos_empatados;
  }
}

int main() {
  struct Equipo Liga[22];
  return 0;
}