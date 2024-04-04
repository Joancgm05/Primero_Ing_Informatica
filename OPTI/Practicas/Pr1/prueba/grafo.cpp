 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"
using namespace std;
void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		A[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
	A.clear();

}

void GRAFO :: build (char nombrefichero[85], int &errorapertura) {
    ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open()) {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);
        if (dirigido == 1) {
            LP.resize(n);
        }
        // leemos los m arcos
		for (k=0;k<m;k++) {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
			//damos los valores a dummy.j y dummy.c
			//situamos en la posici�n del nodo i a dummy mediante push_back
			//pendiente de hacer un segundo push_back si es no dirigido. O no.
			//pendiente la construcci�n de LP, si es dirigido
			//pendiente del valor a devolver en errorapertura
			//...
            dummy.j = j-1;
            if (dirigido == 0) { //si es no dirigido solo trabajamos con LS
                LS[i-1].emplace_back(dummy); //colocamos en el vector en la posición del nodo su info
                if ((i-1) != (j-1)) { 
                    dummy.j = i-1;
                    LS[j-1].emplace_back(dummy);
                } // como es adyacente, colocamos primero el valor del que nos pasa en el fichero ej el nodo 2 con sucesor 3
                // y luego le damos la vuelta para también almacenar esa info en el nodo 3 puesto que al ser adyacente ambos nodos
                // están conectados, por tanto dummy.j pasa a ser de 3 a ser 2 y en vez de almacenar en el nodo 2 ahora lo hacemos en el 3
            } else if (dirigido == 1) {
                LS[i-1].emplace_back(dummy);
                dummy.j = i-1;
                LP[j-1].emplace_back(dummy); //lo  mismo que en el adyacente solo que en este caso almaceno la info
                //en la lista de predecesores puesto que es dirigido

            }
        }
    }
    textfile.close();
}

GRAFO::~GRAFO()
{
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() { return dirigido;}

void GRAFO::Info_Grafo() {
    cout << endl << "Información del grafo: " << endl;
    cout << "Número de nodos: " << n << endl;
    cout << "Número de arcos: " << m << endl;
    cout << "¿Es dirigido? " << (dirigido == 1 ? "Sí, es dirigido" : "No es dirigido");
    cout << endl;
}

void Mostrar_Lista(vector<LA_nodo> L, unsigned& nodo) {
    for (int i{0}; i < nodo; i++) {
        cout << "[" << i + 1 << "]";
        if (L[i].size() == 0) {
            cout << " : NULL";
        } 
        for (int k{0}; k < L[i].size(); k++) {
            cout << " : " << L[i][k].j + 1 << " {" << L[i][k].c << "}"; 
        }

        cout << endl;
    }
    
    cout << endl;
}

void GRAFO :: Mostrar_Listas (int l) {
    if (l == 0 || l == 1) {
        Mostrar_Lista(LS, n);
    } else if (l == -1) {
        Mostrar_Lista(LP, n);
    }
}

void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
{

}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j=0;j<L[i].size();j++)
             if (!visitado[L[i][j].j]) {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad() {
    vector<bool> visitado;
    visitado.resize(n, false);
    unsigned nodo_inicial;
    vector<unsigned> prenum, postnum;
    unsigned prenum_ind{0}, postnum_ind{0};
    cout << "Seleccione el nodo por el que desea empezar: 1-" << n << endl;
    cin >> (unsigned &) nodo_inicial;
    while (nodo_inicial < 1 || nodo_inicial > n){
        cout << "El nodo elegido no está en el rango [1 - " << n << "], elige otro: ";
        cin >> nodo_inicial;
    }
    prenum.resize(n, 0);
    postnum.resize(n, 0);
    
    dfs_num(nodo_inicial - 1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
    
    if ((LS[nodo_inicial - 1].size() != 0) || (LP[nodo_inicial - 1].size() != 0)) {
        cout << "Preorden: ";
        bool aparece_1 = false;      
        for (int i{0}; i < prenum.size(); i++) {    
            if ((!aparece_1) || prenum[i] != 0) {
                if (i != 0) {
                    cout << " --> ";
                }
                cout << "[" << prenum[i] + 1 << "]";  
            }
            if (prenum[i] == 0) {
                aparece_1 = true;
            }
            
        }
        cout << endl;

        cout << "Postorden: ";
        bool aparece_2 = false; //esta varibale sirve para que si el vector prenum o post no se llena del todo no imprima el resto de valores
        //puesto que el resto va a ser cero, comprobamos cuando aparece el 0 alguna vez (nodo 1) y lo marcamos como que aparece, porque si no seguirían apareciendo 1 en el recorrido
        for (int i{0}; i < postnum.size(); i++) {    
            if ((!aparece_2) || postnum[i] != 0) {
                if (i != 0) {
                    cout << " --> ";
                }
                cout << "[" << postnum[i] + 1 << "]";  
            }
            if (postnum[i] == 0) {
                aparece_2 = true;
            }
            
        }
        cout << endl;
    } else {
        cout << "No es posible llevar a cabo el recorrido porque este nodo no dispone de arcos" << endl;
    }
}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
{
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);
    visitado[i] = true;

    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1

    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
    {   unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0;j<L[k].size();j++)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no est� visitado
        {
            //Lo visitamos
            if (visitado[L[k][j].j] == false) {
                visitado[L[k][j].j] = true;
                pred[L[k][j].j] = k;
                d[L[k][j].j] = d[k] + 1;
                cola.push(L[k][j].j);
            }
            //Lo metemos en la cola
            //le asignamos el predecesor
            //le calculamos su etiqueta distancia
        };
        //Hemos terminado pues la cola est� vac�a
    };
}
void GRAFO::MostrarCamino(int s, int i, vector<unsigned>& pred) {
    if (s != i) {
        MostrarCamino(s, pred[i], pred);
        std::cout << " --> " << i + 1;
    } else {
        std::cout << s + 1;
    }
}
void GRAFO::RecorridoAmplitud() {//Construye un recorrido en amplitud desde un nodo inicial
    int nodo_inicial;
    cout << "Seleccione el nodo por el que desea empezar: 1-" << n << ": ";
    cin >> nodo_inicial;
    while (nodo_inicial < 1 || nodo_inicial > n){
        cout << "El nodo elegido no está en el rango [1 - " << n << "], elige otro: ";
        cin >> nodo_inicial;
    }
    vector<unsigned> pred;
    vector<unsigned> d;
    bfs_num(nodo_inicial - 1, LS, pred, d);
    cout << "Nodo inicial: " << "[" << nodo_inicial << "]" << endl;
    if ((LS[nodo_inicial - 1].size() != 0) || (LP[nodo_inicial - 1].size() != 0)) { //compruebo que no sea un nodo suelto
        cout << "Distancia entre el nodo inicial y el resto, según el número de arcos" << endl;
        int max = d[0]; //inicializo la distancia máxima
        for (int i{0}; i < d.size(); i++) {
            if (d[i] > max) {
                max = d[i]; //calculo si hay alguna otra distancia máxima
            }
        }
        for (int i{0}; i <= max; i++) {
            cout << "Distancia " << i << " aristas";
            for (int x{0}; x < d.size(); x++) {
                if ((d[x] == i) && ((LS[x].size() != 0) || (LP[x].size() != 0))) {
                    cout << " : " << x + 1;
                }
            }
            cout << endl;
        }
        cout << endl;
        cout << "Predecesores de cada nodo" << endl;
        for (int i{0}; i < pred.size(); i++) {
            if (((LS[i].size() != 0) || (LP[i].size() != 0)) && (i != nodo_inicial - 1)) { //compruebo que el nodo tenga predecesor y sucesores y que no sea un nodo suelto para representar el recorrido, y que tampoco sea el inicial
                //cout << i + 1;
                //unsigned predecesor_actual = pred[i]; 
                //while (predecesor_actual != nodo_inicial - 1) { //voy imprimiendo el recorrido
                //    cout << " <-- " << predecesor_actual + 1; //imprimo el predecesor
                //    predecesor_actual = pred[predecesor_actual]; //desplazo el predecesor
                //}
                //cout << " <-- " << nodo_inicial << endl; //finalmente imprimo el incial

                MostrarCamino(nodo_inicial - 1, i, pred);
                cout << endl;
            }    
        }
    } else {
        cout << "No es posible llevar a cabo el recorrido porque este nodo no dispone de arcos" << endl;
    }
    cout << endl;
}








