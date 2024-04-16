/*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */


#include "grafo.h"

void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
}

void GRAFO :: build (char nombrefichero[85], int &errorapertura) //
{
  ElementoLista dummy; // cremaos un objeto de tipo elemento lista
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open()) {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n); // reconstruimos
    LP.resize(n);
	  // leemos los m arcos
		for (k=0;k<m;k++) {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
      if(Es_dirigido()){ 
        dummy.j = j -1; // cuardamos los nodos como -1 para que el programa lo lea bien (nodo 1 en realidad es 0 para el programa)
			  LS[i-1].push_back(dummy); // añadimos en la lista de sucesores
        dummy.j = i -1; 
        LP[j-1].push_back(dummy); // añadimos en la lista de predecesores
      }else { // si no es dirigido
        if(i == j){ // si es un bucle, simple push_back
          dummy.j = j-1;
          LS[i-1].push_back(dummy);
        }else{ // si no es bucle, hacemos igual que dirigido
          dummy.j = j-1;
          LS[i-1].push_back(dummy);
          dummy.j = i-1;
          LS[j-1].push_back(dummy);
        }
      }
      errorapertura = 0; // se crea correctamente
    }
  } else {
    errorapertura = 1; // da fallo al abrir
  }
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

unsigned GRAFO::Es_dirigido()
{
  if (dirigido){ // si es dirigido, devuelve un 1
    return 1;
  } else { // si no, un 0
    return 0;
  }
}

void GRAFO::Info_Grafo()
{
   if(Es_dirigido()){ // si es dirigido
     cout << "\nGrafo dirigido";
     cout << " | nodos: " << n << " | aristas: " << m << endl;
  }else{ // si no es dirigido
    cout << "\nGrafo no dirigido";
    cout << " | nodos: " << n << " | aristas: " << m << endl;
  }
}

void Mostrar_Lista(vector<LA_nodo> L)
{
  for (int i = 0; i < L.size(); i++) { // recorremos L, que es un vector de vectores
    cout << "[" << i+1 << "] : "; // imprimimos posicion + 1 para que muestre el valor verdadero
      for (int j = 0; j < L[i].size(); j++) { // en la posicion i, mostramos el nodo y el coste
        cout << L[i][j].j + 1 << " : (" << L[i][j].c << ") ";
      }
      if (!L[i].size()) { // si el nodo esta vacio imprimimos null
        cout << "null";
      }
      cout << endl;
  }
}

void GRAFO ::Mostrar_Listas (int l) //Al ya tener Mostrar_Lista hecho lo usamos con las LS y las LP
{
  if (l==0 || l==1) { // si es 0 o 1, mostramos las listas de sucesores
    Mostrar_Lista(LS);
  }else{ // si es otro (como -1), mostramos predecesores
    Mostrar_Lista(LP);
  }
}

//Recorrido en profundidad recursivo con recorridos enum y postnum
void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
  visitado[i] = true;
  prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
  for (unsigned j = 0; j < L[i].size(); j++)
    if (!visitado[L[i][j].j]) {
      dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
    };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad()
{
  unsigned i;
  vector<bool> visitado;
  vector<LA_nodo>  L;
  vector<unsigned> prenum;
  unsigned prenum_ind=0;
  vector<unsigned> postnum;
  unsigned postnum_ind=0;
  visitado.resize(n);
  prenum.resize(n);
  postnum.resize(n);

  cout << "Elija el nodo de partida? [1-" << n << "]: ";
  cin >> i;
  dfs_num(i-1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
  cout << "Orden de visita de los nodos en preorden\n";
  for (int i = 0; i < postnum_ind; i++) { 
    if (i < postnum_ind-1) { // final del vector de prenum
      cout << "[" << prenum[i]+1 << "] ->";
    } else {
      cout << "[" << prenum[i]+1 << "]";
    }
  }
  cout << "\nOrden de visita de los nodos en preorden\n";
  for (int i = 0; i < postnum_ind; i++) {
    if (i < postnum_ind-1) { // final del vector de postnum
      cout << "[" << postnum[i]+1 << "] ->";
    }else{
      cout << "[" << postnum[i]+1 << "]";
    }
  }
  cout << "\n\n"; 
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
    {   
      unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
      cola.pop(); //lo sacamos de la cola
      //Hacemos el recorrido sobre L desde el nodo k+1
      for (unsigned j=0;j<L[k].size();j++)
        //Recorremos todos los nodos u adyacentes al nodo k+1
        //Si el nodo u no est� visitado
        {
        if(!visitado[LS[k][j].j]){
          visitado[LS[k][j].j] = true; //Lo visitamos
          cola.push(LS[k][j].j); //Lo metemos en la cola
          pred[LS[k][j].j] = k; //le asignamos el predecesor
          d[LS[k][j].j] = d[k] +1;  //le calculamos su etiqueta distancia
        //Hemos terminado pues la cola est� vac�a
    };
  }
  }
}

void GRAFO::RecorridoAmplitud() //Construye un recorrido en amplitud desde un nodo inicial
{
 
  int nodo;
  vector<bool> visitado;
  vector<unsigned> d;
  int distancia_maxima = d.size();
  vector<unsigned> pred;    
  cout << "Vamos a construir un recorrido en amplitud\n";
  cout << "Elija el nodo de partida? [" << 1 << "-" << n << "] ";
  cin >> nodo;
  cout << "Nodo incial: " << nodo << endl;
  nodo--; // restamos uno para que el programa lo lea correctamente

  bfs_num(nodo, LS, pred, d);
  cout << "Nodos segun distancia al nodo inicial en numero de aristas: " << endl;
    for(int i = 0; i < pred.size(); i++){ // calcular la distancia del grafo
      if(d[i] > distancia_maxima ){ 
        distancia_maxima = d[i]; // si distancia es menor que el acumulado entonces vamos reiniciando el valor hasta llegar a la ultima distancia
      }
    }
    distancia_maxima++; // para lectura por pantalla
    for(int i = 0; i < distancia_maxima; i++){
      cout << "Distancia " << i << " aristas"; // muestra distancias
      if(i != 0){ // si es distinto de cero
        for(int j = 0; j < n; j++){ // recorremos hasta llegar al valor de la cantidad de nodos
          if(d[j] == i){
            cout << " : " << nodo + 1; // si son iguales muestra el nodo
          }
          nodo++;
        }
        nodo = 0; // se reinicia para la siguiente 
      }
      else{
        cout << " : " << nodo +1; // como el if no recoge la primera distancia se muestra por pantalla
        nodo = 0;
      }
    cout << endl;
  }
  cout << endl << "Ramas de conexion en el recorrido" << endl;
  for (int j = 0; j < n; ++j) { // recorremos los nodos
    if (d[j] == 0 && j != nodo - 1) { // si no es sucesor
      cout <<" ";
    } else { // si lo es
      cout << pred[j] + 1 << " - " << j + 1;
    }
    cout << endl;
  }
}

void GRAFO::Kruskal() { 

  // Creamos un vector de aristas 
  vector<AristaPesada> Aristas; // vector de aristas pesadas
  AristaPesada dummy; // creamos un objeto de tipo arista pesada
  for (unsigned i = 0; i < n; ++i) { // Cargamos las aristas de la lista de adyacencia
    for (unsigned j = 0; j < LS[i].size(); ++j) { 
      if (i < LS[i][j].j) { 
        dummy.extremo1 = i; 
        dummy.extremo2 = LS[i][j].j; 
        dummy.peso = LS[i][j].c; // asignamos el peso
        Aristas.emplace_back(dummy); // añadimos al vector de aristas
      }
    }
  }

  // Ordenamos el vector Aristas según el peso de las aristas
  AristaPesada posicion_primera{}; // creamos un objeto de tipo arista pesada
  for (unsigned i = 0; i < Aristas.size(); ++i) { // recorremos el vector
    posicion_primera = Aristas[i]; // denominamos actual a la posicion de Aristas en i
    for (unsigned j = i; j < Aristas.size(); ++j) { // iniciamos j en i, por lo que vamos cogiendo los siguientes
      if (Aristas[j].peso < posicion_primera.peso) { // si el peso de la posicion j es menor que en la i
        posicion_primera = Aristas[j]; // adquirimos el valor de este coste
        Aristas[j] = Aristas[i]; // posicionamos este coste donde estaba el anterior
        Aristas[i] = posicion_primera; // intercambiamos, obteniendo un valor menor.
        // Al final el vector Aristas quedara ordenado de minimo coste
      }
    }
  }

  // Registro de componentes conexas
  vector<unsigned> Raiz; // creamos un vector de tipo unsigned
  Raiz.resize(n); // lo redimensionamos con el numero de aristas
  for (unsigned q = 0; q < n; ++q) {
    Raiz[q] = q; // llenamos el vector raiz con el numero de aristas
  }

vector<AristaPesada> MST; //construimos el árbol de mínimo coste
  unsigned z{0}, j{0}, coste_arbol{0}; //inicializamos el coste del árbol y el iterador
  //j es un iterador para que en caso de que no se llene MST del todo pero se hayan recorrido todos las aristas, pueda salir del bucle
  while (MST.size() < n - 1) { //mientras el tamaño del árbol sea menor que el de los nodos - 1 porque el camino óptimo de aristas siempre será el número de nodos menos 1
    if (Raiz[Aristas[z].extremo1] != Raiz[Aristas[z].extremo2]) { //comparamos que las raices son distintas para no unir elementos de la misma componente conexa ya que provocaría un ciclo
      unsigned kill = Raiz[Aristas[z].extremo1]; // kill = raiz[i]
      for (int i{0}; i < Raiz.size(); i++) { //recorremos las raices y aquellas que sean iguales a kill las sustituimos por la del otro extremo, formando una componente conexa mayor
        if (Raiz[i] == kill) {
            Raiz[i] = Raiz[Aristas[z].extremo2];
        }
      }
      MST.emplace_back(Aristas[z]); //guardamos la arista en el árbol
      coste_arbol += Aristas[z].peso; //aumentamos el peso/coste en base al costo/peso de la arista
      cout << "Arista número " << MST.size() << " incorporada (" << Aristas[z].extremo1 + 1 << ", " << Aristas[z].extremo2 + 1 << "), con peso " << Aristas[z].peso << endl;
    }
    z++;
    j++;
    if (j == Aristas.size()) {
        break;
    }
  }

  if (MST.size() == n - 1) { //si el tamaño del árbol es igual al número de nodos - 1, el grafo es conexo
     cout << "El grafo es conexo." << endl;
    cout << "El peso del Árbol generador de mínimo coste es " << coste_arbol << endl;
  } else { //si no, no es conexo
        cout << "El grafo es no conexo." << endl;
  }
    cout << endl;
}