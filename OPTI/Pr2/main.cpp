 /*
 *  Programa principal.
 *  Autor: Joan Carlos García Méndez
 *
 */

#include <string.h>
#include "grafo.h"


void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{
  cout << "Optimiza!cion en Grafos, 2020-2021 Iván Pérez Rodríguez" << endl;
  cout << "c. [c]argar grafo desde fichero" << endl;
  if (dirigido == 0) { //Grafo no dirigido
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
    cout << "k. Mostrar arbol generador de minimo coste, [k]ruskal" << endl;
	} else { // Grafo dirigido
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
    cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
  };
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char *argv[])
{
  int error_apertura;
  char nombrefichero[85], opcion;
    
  //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) {
	  cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]);
  } else {
      cout << "Introduce el nombre completo del fichero de datos" << endl;
      cin >> nombrefichero;
  };
  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
    cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
  } else {
    cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
    do {
      menu(G.Es_dirigido(), opcion);
      switch (opcion) {
        case 'c' :
          cout << "Introduce el nombre completo del fichero de datos" << endl;
          cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura);
          if (error_apertura == 1) {
            cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
          } else {
            cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
          };
          break;
        case 'i' :
		      cout << "Grafo cargado desde " << nombrefichero << endl;
          G.Info_Grafo();
          break;
        case 's':
          cout << "Mostrar la lista de sucesores del grafo" << endl;
          G.Mostrar_Listas(1);
          break;
        case 'p':
          cout << "Mostrar la lista de predecesores del grafo" << endl;
          G.Mostrar_Listas(-1);
          break;
        case 'r':
          cout << "Realizar un recorrido en profundidad del grafo desde un nodo por sucesores" << endl;
          G.RecorridoProfundidad();
          break;
        case 'm':
          cout << "Realizar un recorrido en amplitud del grafo desde un nodo por sucesores" << endl;
          G.RecorridoAmplitud();
          break;
        case 'a':
          cout << "Lista de adyacencia" << endl;
          G.Mostrar_Listas(0);
          break;
        case 'k':
          cout << "Mostrar arbol generador de minimo coste" << endl;
          G.Kruskal();
          break;
      }
    }
    while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};

