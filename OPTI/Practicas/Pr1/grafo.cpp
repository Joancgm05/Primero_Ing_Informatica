 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

void GRAFO::destroy() {
  for (unsigned i=0; i< n; i++) {
	LS[i].clear();
	A[i].clear();
	if (dirigido == 1) {
      LP[i].clear();
    };
  }
  LS.clear();
  LP.clear();
  A.clear();
}

void GRAFO::build (char nombrefichero[85], int &errorapertura) {
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if (textfile.is_open()) {
    unsigned i, j, k;
	// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
	textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
	// los nodos internamente se numeran desde 0 a n-1
	// creamos las n listas de sucesores
	LS.resize(n); 
    A.resize(n);
    if (dirigido == 1) { // Con n nodos, la primera dimensión de LS y LP tiene que tener n espacios
      LP.resize(n);
    }
    // leemos los m arcos
    for (k = 0; k < m; k++) {
      textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
	  //damos los valores a dummy.j y dummy.c
      //situamos en la posición del nodo i a dummy mediante push_back
      //pendiente de hacer un segundo push_back si es no dirigido. O no.
	  //pendiente la construcción de LP, si es dirigido
      //pendiente del valor a devolver en errorapertura
      //...
      dummy.j = j - 1; // restamos 1 para que los nodos estén en la posición correcta
      if (dirigido == 0) { // Si el grafo no es dirigido, solo trabajamos con LS
        LS[i - 1].emplace_back(dummy); // Colocamos el nodo al que apunta y el coste del arco de cada nodo
        dummy.j = i - 1; // Asignamos el nodo predecesor
        if (i - 1 != j - 1) { // Si el nodo no apunta a sí mismo
          LS[j - 1].emplace_back(dummy); // Colocamos el nodo al que apunta y el coste del arco de cada nodo
        } // Dado que es un grafo no dirigido
      } 
      if (dirigido == 1) {
        LS[i - 1].emplace_back(dummy); // Colocamos el nodo al que apunta y el coste del arco de cada nodo
        dummy.j = i - 1; // Asignamos el nodo predecesor
        LP[j - 1].emplace_back(dummy); // Colocamos el nodo al que apunta y el coste del arco de cada nodo
      } 
    }
  }
    textfile.close();
}

GRAFO::~GRAFO() { destroy(); }

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
  build (nombrefichero, errorapertura);
}

void GRAFO::actualizar (char nombrefichero[85], int &errorapertura) {
  //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
  destroy();
  //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() { return dirigido; }

void GRAFO::Info_Grafo() {
  cout << "El grafo tiene las siguientes caracteristicas: " << '\n';
  cout << "Num. nodos: " << n << '\n';
  cout << "Num. arcos: " << m << '\n';
  cout << "¿Dirigido? " << (dirigido == 1 ? "Sí" : "No") << '\n';
  cout << '\n';
}

void Mostrar_Lista(vector<LA_nodo> L, unsigned& nodo) {
  for (int i{0}; i < nodo; ++i ) {
    cout << "[" << i + 1 << "]";
    if (L[i].size() == 0) {
      cout << "vacío";
    }
    for (int k{0}; k < L[i].size(); ++k) {
      cout << " : " << L[i][k].j + 1 << " [" << L[i][k].c << "] ";
    }
    cout << '\n';
  }
  cout << L[0][0].j << '\n';
}

void GRAFO :: Mostrar_Listas (int l) {
  if (l == 0 || l == 1) {
    Mostrar_Lista(LS, n); // Para los grafos dirigidos y no dirigidos
  } else if ( l == -1) {
      Mostrar_Lista(LP, n); // Para los grafos dirigidos
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
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad() {
  vector<bool> visitado;
  visitado.resize(n, false);
  unsigned nodo_inicial;
  vector<unsigned> prenum, postnum;
  unsigned prenum_ind = 0, postnum_ind = 0;
  cout << "Introduce el nodo inicial [1 - " << n << "]:" << '\n';
  cin >> (unsigned &) nodo_inicial;
  while (nodo_inicial < 1 || nodo_inicial > n) {
    cout << "Introduce un nodo válido: [1 - " << n << "]: ";
    cin >> (unsigned &) nodo_inicial;
  }
  prenum.resize(n, 0);
  postnum.resize(n, 0);

  dfs_num(nodo_inicial, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
  if ((LS[nodo_inicial - 1].size() != 0) || (LP[nodo_inicial - 1].size() != 0)) { // Si el nodo tiene arcos
    cout << "EL preorden es: ";
    bool Se_manifiesta_uno = false;
    for (int i{0}; i < prenum.size(); ++i) {
      if ((!Se_manifiesta_uno) || prenum[i] != 0) {
        if (i != 0) {
            cout << " --> ";
        }
        cout << "[" << prenum[i] << "]";
      }
      if (prenum[i] == 0) {
        Se_manifiesta_uno = true;
      }
    }
    cout << '\n';

    cout << "El postorden es: ";
    bool Se_manifiesta_dos = false;
    for (int i{0}; i < postnum.size(); ++i) {
      if ((!Se_manifiesta_dos) || postnum[i] != 0) {
        if (i != 0) {
            cout << " --> ";
        }
        cout << "[" << postnum[i] + 1 << "]";
      }
      if (postnum[i] == 0) {
        Se_manifiesta_dos = true;
    }
  }
  cout << '\n';
  } else {
    cout << "Este nodo no tiene arcos" << '\n';
  }
}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construccion de pred y d: usamos la cola
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

    while (!cola.empty()) // Mientras la cola no esté vacía
    {   unsigned k = cola.front(); // Extraemos el primer nodo de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j = 0;j < L[k].size();++j)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no esta visitado
            {
            //Lo visitamos
            if(visitado[L[k][j].j] == false) {
              visitado[L[k][j].j] = true;
              cola.push(L[k][j].j); //Lo metemos en la cola
              pred[L[k][j].j] = k; //le asignamos el predecesor
              d[L[k][j].j] = d[k] + 1; //le calculamos su etiqueta distancia
            }
            };
        //Hemos terminado pues la cola est� vac�a
    };
}

void GRAFO::RecorridoAmplitud() {//Construye un recorrido en amplitud desde un nodo inicial
  vector<unsigned> pred;    // Declaramos el vector de nodos predecesores, la posición es el vector actual, y el número que contiene es su predecesor
  vector<unsigned> d;       // Declaramos el vector de etiquetas distancia, la posición es el nodo, y el número que contenga, es la distancia del nodo elegido por el usuario
  int nodo_inicial{0};

  cout << "Introduce el nodo inicial [1 - " << n << "]:" << '\n';
  cin >> nodo_inicial;

  while (nodo_inicial < 1 || nodo_inicial > n){
    cout << "Introduce un nodo válido: [1 - " << n << "]:" << '\n';
    cin >> nodo_inicial;
  }
  
  cout << "Tu nodo inicial es: [" << nodo_inicial << "]" << endl << endl;

  bfs_num(nodo_inicial - 1, LS, pred, d);
  cout << "Distancia entre el nodo inicial y el resto, expresado en el número de arcos" << endl << endl;

  for(int i{0}; i < d.size(); ++i) { // Recorremos el vector de distancias para mostrar los nodos a distancia i
    cout << "[" << i + 1 << "] : " << d[i] << endl;
  }

  // Mostramos los predecesores
  cout << endl << "Predecesores de cada nodo" << endl << endl;
  for(int i{0}; i < pred.size(); ++i) {
    cout << "Predecesor de " << i + 1 << " : ";
      cout << pred[i] + 1 << endl;
  }
  cout << endl;
}

void GRAFO::MostrarCamino(int s, int i, vector<unsigned>& pred) {
    if (s != i) {
        MostrarCamino(s, pred[i], pred);
        std::cout << " - " << i + 1;
    } else {
        std::cout << s + 1;
    }
}

void GRAFO::Kruskal() {
  vector<AristaPesada> Aristas; // creamos un vector de tipo AristaPesada
  AristaPesada dummy; // objeto dummy
  for (unsigned i = 0; i < n; ++i) { // cargamos las aristas de la lista de adyacencia
    for (unsigned j = 0; j < LS[i].size(); ++j) {
      if (i < LS[i][j].j) {
        dummy.extremo1 = i; // sus extremos
        dummy.extremo2 = LS[i][j].j; 
        dummy.peso = LS[i][j].c; // su coste o peso 
        Aristas.emplace_back(dummy); // añadimos dummy al vector Aristas
      }
    }
  }
  // Ordenamos el vector Aristas según el peso de las aristas
  AristaPesada actual{};
  for (unsigned i = 0; i < Aristas.size(); ++i) { // recorremos el vector
    actual = Aristas[i]; // denominamos actual a la posicion de Aristas en i
    for (unsigned j = i; j < Aristas.size(); ++j) { // iniciamos j en i, por lo que vamos cogiendo los siguientes
      if (Aristas[j].peso < actual.peso) { // si el peso de la posicion j es menor que en la i
        actual = Aristas[j]; // adquirimos el valor de este coste
        Aristas[j] = Aristas[i]; // posicionamos este coste donde estaba el anterior
        Aristas[i] = actual; // intercambiamos, obteniendo un valor menor.
        // Al final el vector Aristas quedara ordenado de minimo coste
      }
    }
  }

  // Registro de componentes conexas
  vector<unsigned> Raiz; // creamos el vector raiz
  Raiz.resize(n); // lo redimensionamos con el numero de aristas
  for (unsigned q = 0; q < n; ++q) {
    Raiz[q] = q; // llenamos el vector raiz con el numero de aristas
  }

  // Kruskal completo
  vector<AristaPesada> MST; // construimos el vector arbol generador de minimo coste  
  unsigned l{0}, coste_total{0}; // iterador y coste total
  while (MST.size() < n - 1) { // mientras MST no llegue al final
    if (Raiz[Aristas[l].extremo1] != Raiz[Aristas[l].extremo2]) { // Si raiz[i] <> raiz[j]
      unsigned kill = Raiz[Aristas[l].extremo1]; // kill = raiz[i]
      for (int i = 0; i < Raiz.size(); ++i) { // recorremos el vector Raiz
        if (Raiz[i] == kill) { // si coincide la posicion del vector con el valor
          Raiz[i] = Raiz[Aristas[l].extremo2]; // posicion raiz adquiere el valor del extremo2
        }
      }
      MST.emplace_back(Aristas[l]); // añadimos al vector MST las aristas completas
      coste_total += Aristas[l].peso; // a estas aristas le vamos sumando el peso e imrpimimos
      cout << "Arista numero " << MST.size() << " incorporada (" << Aristas[l].extremo1 + 1 << ", " << Aristas[l].extremo2 + 1 << "), con peso " << Aristas[l].peso << endl;
    }
    ++l; // sumamos al iterador
  }
  cout << "El peso del arbol generador de minimo coste es " << coste_total << endl;
  cout << endl;
}





