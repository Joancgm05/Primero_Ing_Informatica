// modificación
  int cont_pair(); 
  double media();
  int suma_pares();

  //Modificación calcula el número de pares

template<class T> int stack_l_t<T>::cont_pair(){
  int par = 0;
  while(!empty()){
    int numeros = top();
    if(numeros % 2 == 0){
      par++;
    }
    pop();
  }
  cout<<endl;
  return par;
}

//Modificación calcula la media de los elementos de la pila

template<class T> double stack_l_t<T>::media(){
  int suma = 0;
  int media = 0;
  int cont = 0;
  while(!empty()){
    int numeros = top();
    suma = suma + numeros;
    cont++;
    pop();
  }
  media = suma / cont;
  cout<<endl;
  return media;
}

// Suma de los pares de una pila
template<class T> int stack_l_t<T>::suma_pares(){
  int suma = 0;
  while(!empty()){
    int numeros = top();
    if(numeros % 2 == 0){
      suma = suma + numeros;
    }
    pop();
  }
  cout<<endl;
  return suma;
}

#endif  // STACKL_H_