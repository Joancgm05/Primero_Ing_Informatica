 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"
using namespace std;

void menu (unsigned dirigido, char& opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{ 
    cout << "Optimizacion en Grafos, 2023-2024 Joan Carlos García Méndez" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    if (dirigido == 0) { //Grafo no dirigido
            cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
            cout << "r.  Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
    } else {
            cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
            cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
            cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
            cout << "k. Mostrar arbol generador de minimo coste, [k]ruskal" << endl;
    }
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {
    int error_apertura;
    char nombrefichero[85];
    char opcion;
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
        system("cls");
        cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
        system("pause");
        system("cls");
    } else {
        cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
        //pressanykey();
        //clrscr();
        system("pause");
        system("cls");
        
        do {
            menu(G.Es_dirigido(), opcion);
            switch (opcion) {
                case 'q' :
                    break;
                case 'c' :
                    system("cls");
         	        cout << "Introduce el nombre completo del fichero de datos" << endl;
                    cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1) {
                        system("cls");
                        cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
                    } else {
                        system("cls");
                        cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
                    };
                    //pressanykey();
                    //clrscr();
                    system("pause");
                    system("cls");
                    break;

                case 'i' :
                    //clrscr();
                    system("cls");
		            cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    //pressanykey();
                    //clrscr();
                    system("pause");
                    system("cls");
                    break;
                
                case 'y' :
                    system("cls");
                    cout << "Opción no disponible actualmente" << endl;
                    system("pause");
                    system("cls");
                    break;

                case 'm' : //recorrido amplitud
                    system("cls");
                    G.RecorridoAmplitud();
                    system("pause");
                    system("cls");
                    break;

                case 'r' : //recorrido profundidad
                    system("cls");
                    G.RecorridoProfundidad();
                    system("pause");
                    system("cls");
                    break;

                if (G.Es_dirigido() == 0) { //no dirigido
                    case 'a' :
                        system("cls");
                        cout << "Esta es la lista de adyacencia de " << nombrefichero << endl;
                        G.Mostrar_Listas(0);
                        system("pause");
                        system("cls");
                        break;
                } else if (G.Es_dirigido() == 1) { //dirigido
                    case 's' :
                        system("cls");
                        cout << "Esta es la lista de sucesores de " << nombrefichero << endl;
                        G.Mostrar_Listas(1);
                        system("pause");
                        system("cls");
                        break;
                    case 'p' :
                        system("cls");
                        cout << "Esta es la lista de predecesores de " << nombrefichero << endl;
                        G.Mostrar_Listas(-1);
                        system("pause");
                        system("cls");
                        break;
                    case 'k' :
                        system("cls");
                        cout << "Mostrar arbol generador de minimo coste" << endl;
                        G.Kruskal();
                        system("pause");
                        system("cls");
                        break;
                }
                
                default:
                    system("cls");
                    cout << "Opción no válida, vuelve a intentarlo" << endl;
                    system("pause");
                    system("cls");
                    break;
            }
        } while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};
