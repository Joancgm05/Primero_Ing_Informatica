// Principio de Computadores. Preparación para el Microexamen
// Operaciones con funciones y direccionamiento indirecto
// Autor: Carlos Martín Galán
// Fecha última modificación: 22/4/2024
#include <iostream>

const int n1 = 10;
double v1[n1] = {10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0};
const int n2 = 5;
double v2[n2] = {5.5, 4.5, 4.25, 2.5, 2.5 };
const int n3 = 4;
double v3[n3] = {7.0, 5.0, 2.0, 1.0};


void printvec(double *v, const int n) {
    for (int i = 0; i < n; i++)
        std::cout << v[i] << " ";
    
    std::cout << "\n";
    return;
}

int ordenado(double *v, const int n) {
    int resultado = 1;
    int i = 0;
    while (i < n-1) {
        if (v[i+1] >= v[i]) {
            resultado = 0;
            break;
        }
        i++;
    }
    return(resultado);
}

void merge(double *v1, const int n1,double *v2, const int n2) {
    
    int  o1 = ordenado(v1,n1);
    if (o1 == 0) return;
    int o2 = ordenado(v2,n2);
    if (o2 == 0) return;
    int i = 0; // índice para recorrer el v1
    int j = 0; // índice para recorrer el v2
    while ( ( i < n1) && (j < n2) ) {
        if (v1[i] >= v2[j]) {
            std::cout << v1[i] << " ";
            i++;
        }
        else {
            std::cout << v2[j] << " ";
            j++;
        }
    }
    while ( i < n1) {
        std::cout << v1[i] << " ";
        i++;
    }
    while ( j < n2) {
        std::cout << v2[j] << " ";
        j++;
    }
    std::cout << "\n";
    return;
}

int main(void) {
    std::cout << "\nVector con dimension " << n1 << std::endl;
    printvec(v1,n1);
  
    std::cout << "\nVector con dimension " << n2 << std::endl;
    printvec(v2,n2);
  
    std::cout << "\nVector con dimension " << n3 << std::endl;
    printvec(v3,n3);
  
    std::cout << "\nIntentando mezcla con dos vectores ...\n";
    merge(v1,n1,v2,n2);
    std::cout << "\nIntentando mezcla con dos vectores ...\n";
    merge(v1,n1,v3,n3);

    std::cout << "\nFIN DEL PROGRAMA\n";
    return(0);
}
