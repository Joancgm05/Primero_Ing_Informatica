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

/**
   * Modificación
   * Contar el número de pares en una pila
  */

  stack_l_t<int> modi; 

  modi.push(8);
  modi.push(2);
  modi.push(4);
  modi.push(3);
  modi.push(6);
  modi.push(3);
  cout << "El numero de pares es : " << modi.cont_pair() << endl;

  /**
   * Modificación2
   * calcular la media de una pila
  */

  stack_l_t<int> modi2;

  modi2.push(8);
  modi2.push(2);
  modi2.push(4);
  modi2.push(3);
  modi2.push(6);
  modi2.push(3);
  cout << "La media de la pila es : " << modi2.media() << endl;

  /** 
   * Modificación 3
   * Suma de los pares de una pila
  */
  stack_l_t<int> modi3;

  modi3.push(8);
  modi3.push(2);
  modi3.push(4);
  modi3.push(3);
  modi3.push(6);
  modi3.push(3);
  cout << "La suma de los pares de la pila es : " << modi3.suma_pares() << endl;

  return 0;
}