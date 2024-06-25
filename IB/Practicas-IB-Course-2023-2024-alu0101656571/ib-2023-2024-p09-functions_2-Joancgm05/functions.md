# Práctica 09. Funciones. CMake. Expresiones constantes.

# Factor de ponderación: 8

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Sea capaz de resolver problemas sencillos en C++ usando todos los conocimientos adquiridos hasta ahora, 
  y en particular utilizando funciones
* Diseñe, desarrolle y utilice funciones en sus programas haciendo que sus programas sean modulares
* Conozca la herramienta CMake y sea capaz de usarla a nivel básico para construir sus programas ejecutables

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica.
Se comprobará que el alumnado:
* Conoce los conceptos expuestos en el material de referencia de esta práctica.
* Ha realizado todos los ejercicios propuestos en este enunciado
* Es capaz de escribir programas simples en C++ que resuelvan problemas de complejidad similar a los que se proponen en este documento
* Es capaz de escribir un fichero `CMakeLists.txt` para automatizar el proceso de compilación de sus programas con `cmake` y `make`
* Ha automatizado la compilación de sus programas usando un fichero `Makefile` para cada uno de los programas que desarrolle 
* Hace que sus programas se estructuren en torno a diferentes funciones (sean modulares)
* Todos sus programas se estructuran en directorios diferentes para cada "proyecto" haciendo que cada uno de ellos contenga un fichero `CMakeLists.txt` con la configuración de despliegue del proyecto.
* Utiliza en todos sus programas comentarios adecuados en el formato requerido por [Doxygen](https://www.doxygen.nl/index.html)
* Acredita que todas las prácticas realizadas hasta la fecha se encuentran alojadas en repositorios privados de [GitHub](https://github.com/).
* Acredita que es capaz de subir programas a la plataforma [Jutge](https://jutge.org/) para su evaluación
* Ha incluido un comentario prólogo en todos los ficheros (`*.cc`, `*.h`) de sus ejercicios
* Que todos los programas que desarrolla, antes de su ejecución imprimen en pantalla un mensaje indicando la finalidad del programa así como la información que precisará del usuario para su correcta ejecución.
* Hace que todos los programas que se presentan para su evaluación cumplan con los estándares definidos en la [Guía de estilo de Google para C++](https://google.github.io/styleguide/cppguide.html) 
* Utiliza siempre identificadores significativos en su programa (para constantes, variables, etc.) y no utiliza nunca identificadores de una única letra, tal vez con la excepción de las variables que utilice para iterar en un bucle.
* Acredita que es capaz de editar ficheros remotos en su VM usando vi
* Ha realizado todos sus ejercicios en la máquina virtual Ubuntu de la asignatura.
* Demuestra que es capaz de ejecutar comandos Linux en su VM

### Programas con múltiples ficheros de código
Conforme los programas se hacen más grandes, es habitual descomponer el programa en varios ficheros (módulos) con fines organizativos o de reutilización
del código.
En un proyecto real de desarrollo de software es común que los programas estén compuestos por cientos o miles
de ficheros de código fuente.
Estudie en el tutorial de referencia los apartados:
* [2.7 — Forward declarations and definitions](https://www.learncpp.com/cpp-tutorial/forward-declarations/)
* [A multi-file example](https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/) de la sección 2.8 del tutorial (omita la parte introductoria relativa a los IDEs).
* [2.11 — Header files](https://www.learncpp.com/cpp-tutorial/header-files/)

Considere a continuación, como un ejemplo adicional el programa que hallará en el directorio [headerSourceSeparation](https://github.com/IB-2023-2024/IB-class-code-examples/tree/master/Tools/cmake/headerSourceSeparation) de los ejemplos de código de la asignatura.

Ese programa se compone de tres ficheros: `main.cc`, `tools.cc` y `tools.h`.
El fichero `Makefile` en ese directorio permite compilar el programa. 
Ejecute `make` y observe los comandos que se ejecutan para la compilación.
Examine a continuación el código de todos esos ficheros.
El programa principal simplemente invoca las funcionas *MakeItRain()* y *MakeItSunny()*.
Esas funciones se encuentran definidas en el fichero `tools.cc` y sus declaraciones (también llamadas
prototipos) se incluyen en el fichero `tools.h`.
Cualquier módulo (fichero `*.cc` con código) que precisara utilizar estas funciones deberá incluir (como se
hace en `main.cc`) el fichero `tools.h` donde se declaran dichas funciones.

Esto no es ni más ni menos que lo que se ha venido haciendo con otros ficheros de cabecera, *header*:
Cualquier programa C++ que precise utilizar funciones matemáticas como *sin()*, *cos()*, *fabs()*, *exp()*,
etc. ha de incluir el fichero de cabecera `cmath` (`#include <cmath>`) que es donde se hallan las
declaraciones de esas funciones.
Análogamente en el fichero de cabecera `iostream` se hallan declaradas las clases y  funciones necesarias para
realizar operaciones básicas de entrada/salida.
En el caso de funciones de librería de C++ las definiciones no se encuentran en ficheros de código fuente
(`*.cc`) sino que su código binario, que se encuentra en una librería, es añadido al programa final por 
el enlazador (*linker*), como ya se ha estudiado.

La separación en diferentes ficheros de código que presenta este ejemplo académico es muy frecuente en
proyectos reales de programación, en los que como ya se ha dicho, suelen intervenir cientos o miles de
ficheros.
Utilizar herramientas como `make` para la compilación de este tipo de proyectos es fundamental para optimizar
el proceso de desarrollo.

### La herramienta `cmake`
[CMake](https://es.wikipedia.org/wiki/CMake)
es lo que se conoce como un sistema de *metaconstrucción*. 
No se utiliza para construir (generar, *build* en inglés) el programa ejecutable de una aplicación sino
que produce ficheros de proyecto nativos para la plataforma de destino. 
Por ejemplo, CMake en Linux generará un fichero Makefile; 
en Windows generará una solución para Visual Studio; 
en macOS generará un proyecto para XCode y así sucesivamente. 
Eso es lo que la palabra *meta* indica: CMake construye sistemas de construcción (*builders*). 
La herramienta `make` que ya se ha estudiado, es un sistema de construcción, posiblemente el más común, y así
en *Informática Básica* se utilizará CMake para construir un fichero Makefile con el que se compilará cada uno
de los proyectos (programas) que se desarrollen.

Un proyecto basado en CMake siempre contiene un fichero `CMakeLists.txt`
que describe cómo se estructura el proyecto, la lista de ficheros 
de código fuente que se ha de compilar, lo que CMake debe generar a partir de él y así sucesivamente. 
Se trata en definitiva de un fichero de configuración para la herramienta CMake.
CMake leerá las instrucciones de ese fichero y producirá el resultado deseado. 

Una característica positiva de CMake es el llamado "*out-of-source build*". 
Cualquier fichero requerido para la construcción final, incluyendo los ejecutables, 
será almacenado en un directorio de construcción separado, habitualmente llamado `build/`. 
Esto evita que el directorio de origen que contiene el código fuente contenga
ficheros no deseados y hace que sea fácil volver a empezar: sólo hay que eliminar 
el directorio destino de la compilación (el directorio `build/`) y listo.

CMake es una herramienta muy potente que admite multitud de opciones.
En [la documentación](https://cmake.org/cmake/help/latest/index.html) 
de la herramienta se pueden estudiar en profundidad estas opciones, pero para la utilización que se propone
realizar en *Informática Básica* bastará con que estudie detenidamente 
[este breve tutorial](https://www.internalpointers.com/post/modern-cmake-beginner-introduction).

En el directorio raíz del repositorio de esta práctica hallará un subdirectorio `fibonacci_sum` con el
siguiente contenido:
```
  fibonacci_sum
  ├── CMakeLists.txt             // Fichero de configuración para CMake
  ├── CMakeLists.txt.simpler     // Otro fichero de configuración más simple
  ├── doc                        // Documentación
  ├── fibonacci.Doxyfile         // Fichero de configuración para Doxygen
  ├── LEE_ME.txt
  └── src                        // Código fuente de la aplicación
      ├── fibonacci_main.cc
      ├── fibonacci_sum.cc
      ├── fibonacci_sum.h
      ├── tools.cc
      └── tools.h
```
Esa estructura de directorios (a la que se añadirán los directorios `build/` -y opcionalmente `lib/`-)
es habitual en proyectos de desarrollo de software.
En este ejemplo se ha tomado la aplicación `fibonacci_sum` que calcula la suma de términos pares de la serie
de Fibonacci y se ha fragmentado la aplicación en 5 ficheros de código (`*.cc` y `*.h`).
El fichero de configuración `CMakeLists.txt` contiene la configuración que se utiliza para el despliegue de la
aplicación.
Al efecto de ilustrar este proceso, se crea una librería `libtools.a` que se aloja en el directorio `lib`. 
El programa binario (`fibonacci_sum`) se construye enlazando esta librería con el resto del código objeto
producto de la compilación.

> Observe que el directorio `fibonacci_sum/doc` no está presente en el repositorio, debe incluirse manualmente con `mkdir` antes de efectuar la construcción del programa.

Para construir la aplicación, siga los siguientes pasos (que son los habituales):
```
$ cd fibonacci_sum
$ mkdir build
$ cd build
$ cmake ..
$ make
```

El cuarto de esos comandos, `cmake`, usando el fichero de configuración `CMakeLists.txt`, creará en el 
directorio `build` el fichero `Makefile` que utiliza el comando `make` para construir la aplicación, 
cuyo programa binario `fibonacci_sum` se crea asimismo en el directorio `build`.

Experimente con este fichero de configuración entregado, `CMakeLists.txt` para adaptarlo a cada uno
de sus propios proyectos (ejercicios de prácticas).
No es necesario en principio, que construya librerías propias para sus programas.
La construcción de una librería se ha incluído en este ejemplo con la finalidad de ilustrar ese proceso.

El fichero `CMakeLists.txt.simpler` que se incluye es más simple que el anterior y en ese caso no genera la
documentación (Doxygen) del proyecto ni construye ninguna librería que se enlace con el programa final.
Puede utilizar este fichero (renombrándolo a `CMakeLists.txt`) como "plantilla" adaptándolo de ahora en 
adelante a cada uno de sus proyectos de programación en C++.

### Expresiones constantes

Cuando se declara una constante usando la etiqueta `const`, el compilador comprobará implícitamente si es una constante *en tiempo de compilación* o *en tiempo de ejecución*. En la mayoría de los casos, esto sólo es relevante para la optimización del código, pero hay casos en los que C++ requiere una expresión constante que sólo use valores definidos en tiempo de compilación. Como este tipo de constantes permiten una mejor optimización, en general siempre intentaremos que las constantes sean evaluables en tiempo de compilación.

Que una constante sea evaluable en tiempo de compilación o en tiempo de ejecución depende si su inicialización se pueda realizar durante la compilación. En algunos casos, esto puede ser difícil de determinar. Por ejemplo:

```
int variable{5};               // no es constante
const int my_var1{x};          // constante en ejecución, su inicializador no es constante
const int my_var2{5};          // constante en compilación, su inicializador es una expresión constante
const int result{getValue()};  // no está claro, depende de cómo se haya definido getValue()
```

Afortunadamente, se puede indicar al compilador cuándo necesitamos que una constante sea evaluable en tiempo de compilación. Para ello, se usa la etiqueta `constexpr` en lugar de `const`. Una `constexpr` ("expresión constante") sólo puede ser evaluada en tiempo de compilación. Si su inicializador no es una expresión constante, el compilador dará un error.

```
#include <iostream>

int Five() {
  return 5;
}

int main() {
  constexpr double gravity{9.8};  // correcto: 9.8 es una expresión constante
  constexpr int sum{4 + 5};       // correcto: 4 + 5 es una expresión constante
  constexpr int something{sum};   // correcto: sum es una expresión constante

  int age;
  std::cin >> age;
  constexpr int myAge{age};      // error: age no es una expresión constante
  constexpr int young{Five()};   // error: el valor de retorno de five() no es una expresión constante
  return 0;
}
```

Como buena práctica, todo valor que no deba ser modificado tras su inicialización debería declararse:

- como `constexpr`, si su valor se conoce en tiempo de compilación
- como `const`, si su valor no se conoce en tiempo de compilación

Téngase en cuenta que algunos tipos de datos que reservan memoria dinámicamente, tales como `std::string` y `std::vector`, no son compatibles con `constexpr`; para constantes de estos tipos, se debe usar `const`. Asimismo, los parámetros de las funciones siempre se evalúan en tiempo de ejecución y, por tanto, no pueden ser declaradas como `constexpr`.

En algunos contextos, el compilador puede decidir que no es necesario evaluar una expresión en tiempo de compilación.

```
constexpr int variable{3 + 4};  // 3 + 4 siempre se evaluará en tiempo de compilación
const int my_var{3 + 4};        // 3 + 4 siempre se evaluará en tiempo de compilación
int result{3 + 4};              // 3 + 4 puede que se evalúe en tiempo de compilación o en tiempo de ejecución
```

Considere el siguiente ejemplo:

```
#include <iostream>

int main() {
  constexpr int x { 3 + 4 }; // 3 + 4 es una expresión constante
  std::cout << x;            // Se evalúa en tiempo de ejecución
  return 0;
}
```

`3 + 4` es una expresión constante, así que el compilador la evaluará en tiempo de compilación y la sustituirá por el valor `7`. Pero como `x` es también una constante en tiempo de compilación, el compilador probablemente optimizará el programa sustituyendo `std::cout << x` por `std::cout << 7`, que se ejecutará en tiempo de ejecución. Sin embargo, como `x` sólo se usa una vez, es más probable que el compilador optimice el programa eliminando `x` antes de evaluar `3 + 4`:

```
#include <iostream>

int main() {
  std::cout << 3 + 4;  // Se evalúa en tiempo de ejecución
  return 0;
}
```

La expresión `std::cout << 3 + 4` ya no es constante, así que surge la duda de si la subexpresión `3 + 4` se evaluaría en tiempo de compilación o no. En general sí se optimizará, ya que los compiladores son capaces de detectar subexpresiones constantes incluso si son parte de expresiones en tiempo de ejecución. A este proceso de optimización se le conoce como *"constant folding"* ("plegado de constantes"). Etiquetar las expresiones constantes como `constexpr` asegura que dichos valores sean reconocidos por el plegado de constantes siempre que estas se usen en una expresión en tiempo de ejecución.

### Material de estudio complementario
Estudie todo lo que se indica en el epígrafe 
[Functions](https://google.github.io/styleguide/cppguide.html#Functions)
de la Guía de Estilo de Google y ponga en práctica todo lo que en ella se propone.
Es normal si encuentra en ese epígrafe algún contenido que aún no ha estudiado: no se preocupe. 
Centre su atención en aquellos aspectos que ya conozca, para consolidarlos.

Estudie del
[tutorial de referencia](https://www.learncpp.com/)
en la asignatura los siguientes apartados:
* [Local variables](https://www.learncpp.com/cpp-tutorial/local-variables/)
* [Introduction to global variables](https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/)
* [Variable shadowing (name hiding)](https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/)
* [Scope, duration, and linkage summary](https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/)
* [Command line arguments](https://www.learncpp.com/cpp-tutorial/command-line-arguments/)
* [Constant expressions](https://www.learncpp.com/cpp-tutorial/constexpr-variables/)

### Ejercicios
* Al realizar los ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
para cada uno de los ejercicios.
Asigne a cada uno de esos directorios nombres significativos. 
* Automatice la compilación del programa correspondiente a cada ejercicio con un fichero `Makefile`
independiente para cada programa e inclúyalo en el correspondiente directorio.
* Haga que todos los programas tomen su entrada por la línea de comandos y en caso de que se ejecuten sin
  pasarles el número adecuado de parámetros impriman en pantalla un mensaje indicando el modo correcto de
  ejecutar el programa.
* El código de cada uno de los programas deberá organizarse de forma modular, es decir haciendo uso de funciones 
* Cada función deberá realizar una única tarea y hacerlo correctamente 
* El identificador de una función debe reflejar claramente lo que la función hace 


1. Escriba un programa `scalar_product.cc` que utilice una función que tome como parámetros dos vectores de números
reales y devuelva su producto escalar, calculado como el sumatorio del producto de sus elementos en igual posición

$$[a1, a2, a3] \cdot [b1, b2, b3] = a1 * b1 + a2 * b2 + a3 * b3$$

  Si la función detecta que los vectores no tienen la misma longitud, debe mostrar un mensaje de error y devolver 0.

2. Escriba un programa `capitalize_vowels.cc`que incluya una función que tome como parámetro una cadena de caracteres sin
espacios y la modifuque de forma que queden las consonantes en minúscula y las vocales en mayúscula.
Los caracteres que no sean letras mayúsculas ni minúsculas deberán permanecer inalterados.

```
Public test cases
Input           Output
Abecedario      AbEcEdArIO
PyThon          pythOn
AlFa2022        AlfA2022
```

3. Escriba un programa `polynomial.cc` que incluya una función C++ que reciba como parámetros un vector de coeficientes
reales `coefficients` y un valor real `value` y calcule el valor del polinomio correspondiente en el valor dado, usando
el siguiente esquema:

$$(...(((coef_0 * value + coef_1) * value + coef_2) * value + coef_3) * value + coef_4) * value + ...) * value + coef_{N-1}$$

```
Public test cases
Coefficients    Value    Output
2 4 6 8         0        8
1 3 5           2        15
1 1 1 1 1       4        341
```

4. Desarrolle un programa `approximate_root.cc` que incluya una función que tome como parámetro un número real mayor que
cero `number` y devuelva su raíz cuadrada con un error de ±`EPSILON` (donde `EPSILON` es una constante real
suficientemente pequeña - por ejemplo, `1e-4`). La función debe usar internamente dos valores reales `root` y `delta`
con cualesquiera valores iniciales (se recomienda 1.0 para ambos) y seguir el siguiente procedimiento:

    - Mientras que la diferencia entre `root`² y `number` sea mayor que `EPSILON`:
      - si `delta` es positivo: mientras que `root`² sea __menor__ que `number`, sume `delta` a `root`.
      - en caso contrario: mientras que `root`² sea __mayor__ que `number`, sume `delta` a `root`.
      - multiplique `delta` por -0.5.
    - Devuelva el valor `root`.

5. Desarrolle un programa `hypotenuse.cc` que utilice incluya una función que tome como parámetros los catetos de un
triángulo rectángulo, como valores reales, y devuelva su hipotenusa, haciendo uso de la función implementada en el
ejercicio 4 para calcularla.

$$hipotenusa = \sqrt{cateto1^2 + cateto2^2}$$

```
Public test cases
Input     Output
3 4       5
7 9       10.4018
10 12     15.6205
```
