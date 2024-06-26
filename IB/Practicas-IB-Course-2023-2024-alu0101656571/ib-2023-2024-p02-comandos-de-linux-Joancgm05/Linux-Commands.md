# Práctica 02. Comandos básicos en el Sistema Operativo Linux

# Factor de ponderación: 4

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Sea capaz de conectarse a la máquina virtual (VM) disponible a través de la infraestructura [IaaS](https://es.wikipedia.org/wiki/Infraestructura_como_servicio_(IaaS)) empleada en la asignatura
* Sepa ejecutar comandos básicos de Linux, así como obtener información sobre los mismos
* Sepa editar ficheros remotos en la VM de la asignatura usanso el editor [vim](https://missing.csail.mit.edu/2020/editors/)

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica:
* Ha de acreditarse que se es capaz de conectarse a la máquina virtual de la asignatura y ejecutar comandos básicos de Linux para al menos: copiar, borrar y editar ficheros, crear directorios y compilar un programa en C++
* El alumnado ha de acreditar que conoce el funcionamiento de los comandos básicos de Linux estudiados
* Ha de acreditar que es capaz de editar ficheros remotos en la VM de la asignautra usando vi

### Introducción
El propósito de esta práctica es estudiar algunos comandos básicos de Linux. 
Con la prevalencia en la actualidad de los sistemas operativos basados en Interfaces Gráficas de Usuario (GUIs), la necesidad de 
interaccionar con el sistema a través de comandos ha disminuído su importancia. 
No obstante, hay muchas tareas que son mucho más fáciles de realizar en un entorno Unix usando comandos y el trabajo mediante 
comandos también es casi obligatorio en entornos cliente/servidor. 
Por otra parte, la familiaridad con Unix mejorará la empleabilidad de cualquier ingeniero en informática.

Si ya está familiarizado con Linux, esta práctica será muy corta. En cambio, si usted es nueva/o en Linux le tomará más tiempo, así que prepárese en consecuencia.

En esta práctica no se va a programar comandos sino que los ejercicios están orientados a conocer los fundamentos del uso de Unix. Este conocimiento básico será necesario para completar sus tareas de programación en otras prácticas futuras de la asignatura.

### Conexión con su VM de la asignatura
En la práctica anterior se estudió cómo realizar la conexión con la máquina virtual que utilizará usted en la asignatura. Recuerde que para ello necesita un cliente `ssh`.
* Si se conecta Ud. desde un sistema Linux, abra un terminal y ejecute
`ssh usuario@<dirección IP de su máquina>`
Recuerde que la dirección IP de su máquina tiene un formato similar a `10.6.129.147`
* Si se conecta desde un sistema Windows, un cliente `ssh` recomendado es [putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
* Si se conecta desde un sistema Mac, abra una ventana de terminal (en 'Aplicaciones/utilidades') y ejecute
`ssh usuario@<dirección IP de su máquina>`
Recuerde también que si se conecta Ud. desde fuera del campus ULL ha de instalar e iniciar sesión usando un [cliente VPN](https://www.ull.es/servicios/stic/2016/05/10/servicio-de-vpn-de-la-ull/).

### Comandos Linux
Estudie en [este tutorial](http://linuxcommand.org/index.php) al menos hasta el final de la sección 7
(*"I/O Redirection"*) en el capítulo *"Learning the Shell"* aunque puede Ud. estudiar más allá de ese punto, si lo desea.

Pruebe en su máquina virtual los comandos que estudie en el tutorial.

### Ejercicios
En este documento, el primer carácter `$` en los ejemplos de comandos no debe escribirse, sino que denota el
símbolo del sistema (**prompt**).
Algunas líneas de comandos son demasiado largas para caber en una sola línea impresa. 
Estos se indican con una barra invertida `\` al final de la línea. 
No debe incluirse al escribir el comando. 
Por ejemplo

``` .bash
$ example command \
continues \
and continues
```

Debe escribirse como:

``` .bash
$ example command continues and continues
```

#### Ejercicio 1. 
Si no ha sido creado anteriormente, cree un subdirectorio `practicas` en su directorio `home` (`~`) y clone (haga una copia) 
dentro de él del repositorio de esta práctica en el (sub) directorio `IB-p02-LinuxCommands`. 
A este último directorio nos referiremos como 'directorio de trabajo'. Para ello ejecute:
```
$ cd ~
$ mkdir practicas
$ cd practicas
$ git clone git@github.com:IB-2023-2024/P02-LinuxCommands.git IB-p02-LinuxCommands
```

#### Ejercicio 2. 
acceda al directorio de trabajo. 
Encontrará en él el fichero `ProgrammingJoke.txt`. 
¿Cuál es el chiste? 
Busque cualquier otro chiste famoso de programadores y utilice el editor vi para añadir el texto del nuevo chiste a continuación del que ya existe.

#### Ejercicio 3. 
En su directorio de trabajo hallará el fichero `linux-exercise.tar.gz`.
Se trata de un fichero *tar* (conjunto de ficheros) que a su vez está comprimido (nótese la extensión `.gz`).

Descomprima ese fichero:

``` .bash
$ tar xvfz linux-exercise.tar.gz 
``` 

Utilice [explainshell](https://explainshell.com/) para estudiar el significado de las diferentes opciones que
ha utilizado en el comando anterior.
Para ello, escriba el comando en [explainshell](https://explainshell.com/explain?cmd=tar+xzvf+linux-exercise.tar.gz+) tal como acaba de escribirlo


La opción `v` (*verbose*) en el comando `tar` muestra los ficheros con la ruta conforme son descomprimidos y
extraídos. 
Como resultado de la ejecución del comando obtendrá una serie de ficheros en un subdirectorio llamado `linux-exercises`. 
Vaya a ese directorio con el comando `cd`.
Visualice el árbol de directorios con el comando `tree`.
Pruebe a visualizar tanto los ficheros como solamente los directorios del árbol.

#### Ejercicio 4. Desplazarse por el árbol de directorios 
Comandos en este ejercicio: `cd`, `mkdir`, `ls`, `mv`, `more`, `less`, `cat`, `tar`.
El objetivo de este ejercicio es aprender a moverse con `cd`, ver el contenido de los ficheros,
crear directorios, mover y copiar ficheros.

Colóquese en el directorio `moving-around` y descomprima el fichero `dirs.tar.gz`:

``` .bash
$ cd moving-around
$ tar xvfz dirs.tar.gz
``` 

Averigüe qué directorios y ficheros se crearon:
``` .bash
$ ls
$ ls -l
$ cd inputs
$ ls -l
$ cd ..
``` 
Y así sucesivamente...

#### Ejercicio 5. ¿Qué fichero de salida trata sobre la cafeína?
Acceda al subdirectorio de resultados (que a su vez contiene subdirectorios). 
Los ficheros `pdb` tienen una línea con con el texto *"TITLE AlgúnNombre"*. 

A continuación se muestran algunos comandos que puede probar para averiguar qué fichero trata sobre la cafeína. 

``` .bash
$ grep caffeine *.pdb
$ grep caffeine */*.pdb
$ grep title */*.pdb
$ grep TITLE */*.pdb
``` 
¿Sobre qué trata la información del resto de ficheros?
Puede mostrar el contenido completo de un fichero usando los comandos `more`, `less` o `cat`.

#### Ejercicio 6. Crear subdirectorios
Solo hay tres directorios `result*`. 
Cree directorios nuevos: `result4` y `result5` para los ficheros de salida 4 y 5 y mueva los ficheros de salida (`out_4.pdb`, `out_5.pdb`) a esos directorios.
* `cd` al directorio `outputs`
* Cree un nuevo subdirectorio con `mkdir result4`
* Mueva el fichero `out_4.pdb` con el comando `mv result3/out_4.pdb result4`
* Repita para `result5` y `out_5.pdb`

#### Ejercicio 7. Cree un nuevo fichero tar comprimido de la nueva jerarquía de directorios
Colóquese en el directorio `moving-around` donde se encuentra el fichero `tar` original (`dirs.tar.gz`) usando
el comando `cd`.

``` .bash
$ tar cvfz dirs-new.tar.gz inputs outputs
```
Observe en el comando anterior la opción `c` para **C**rear el fichero *dirs-new.tar.gz*


Confirme el contenido del fichero tar:
``` .bash
$ tar tvf dirs-new.tar.gz
``` 
Para visualizar página a página el contenido del fichero *tar* comprimido puede usar un *pipe* encadenando la
ejecución del comando anterior con `more`:
``` .bash
$ tar tvf dirs-new.tar.gz | more
``` 



#### Ejercicio 8. Use el comando `man` (*manual*) para encontrar opciones para el comando `ls`
Comandos en este ejercicio: `man`, `ls`.
En este ejercicio aprenderá cómo encontrar información detallada sobre las opciones y sobre cómo ordenar la salida del comando `ls`.

Abra la página de manual de `ls`
``` .bash
$ man ls
``` 

Ese comando abre la página del manual para `ls`. 
Como hay muchas opciones para el comando, resulta útil consultarlas en la página de manual.
La búsqueda se activa presionando `/` y luego escribiendo un (comienzo de) una palabra clave. 
Al presionar *enter* se activa la búsqueda y presionando `n` (*next*) se pasa a la siguiente ocurrencia de la
palabra clave.

También puede desplazarse por la pantalla con las teclas de flecha cuando sea necesario. 
Salga de la página del manual presionando la tecla `q` (*quit*).

Practique estas búsquedas localizando una opción para ordenar la salida del comando `ls`.
Para ello en la página de manual escriba `/sort` (*sort* sería la palabra clave) y presione *enter*.


##### Encuentre la opción que ordena la salida por tamaño de fichero
Presione `n` tantas veces como sea necesario hasta que encuentre la opción para ordenar por tamaño de fichero. 
También puede usar alguna otra palabra clave para encontrar eso, por ejemplo, tamaño (*size*).

##### Ordenar el contenido del directorio por tamaño de fichero
Vaya al directorio `moving-around/inputs` y ordene los ficheros por tamaño:

``` .bash
$ ls -S
``` 

##### Opciones adicionales
Busque la opción que invierta el orden de clasificación (es decir, imprima el fichero más grande al final). 
Puede dar las opcións al comando `ls` juntas (por ejemplo, `ls -la` en lugar de `ls -l -a`).

Busque la opción que mostrará el tamaño del fichero en "formato legible por humanos", es decir, kB/MB/GB en lugar de bytes (el valor predeterminado).

Sugerencia: también puede buscar el significado de las opciones directamente por `/-S` (que buscará la aparición de `-S` (o incluso mejor `-S ` (con un espacio final)) si quiere saber qué hace esa opción.


##### Ordenar el contenido del directorio por fecha de creación de los ficheros
El comando:
``` .bash
$ ls -ltr
``` 
Muestra los ficheros en formato largo (`l`) ordenados en orden inverso (`r`, *reverse*) por fecha de creación (`t`, *time*).
De este modo aparecerán los últimos en la lista los últimos ficheros que se hayan creado.

El comando 
``` .bash
$ touch nombre-fichero
``` 
modifica la fecha del fichero que se le pasa como parámetro (*nombre-fichero*).

#### Ejercicio 9. Uso de comodines (*wildcards*)
Comandos en este ejercicio: `ls`, `cp`.
En este ejercicio aprenderá a actuar sobre múltiples ficheros usando comodines.

Linux habilita comodines o expresiones regulares para hacer coincidir ficheros o cadenas que difieren solo en algunas formas controladas.

#### Limite los ficheros de listado con comodines
Colóquese en el directorio `moving-around/outputs`.
Revise todos los contenidos.

``` .bash
$ ls
```

Enumere solo aquellos ficheros que tienen una "a" en el nombre y terminan en ".pdb"

``` .bash
$ ls *a*.pdb
```

Enumere aquellos ficheros que tienen un nombre con siete caracteres y terminan en ".pdb"

``` .bash
$ ls ???????.pdb
```
Colóquese en el directorio `moving-around/outputs`.
Liste todos los ficheros pdb en los subdirectorios.

``` .bash
$ ls */*.pdb
```

En el comando anterior, el primer asterisco indica que se revisen todos los subdirectorios en el directorio actual, y el segundo todas las cadenas. 
Ahora limite la lista solo a aquellos ficheros de salida que tienen un número 2-5 en su nombre:

``` .bash
$ ls */out_[2-5].pdb
```
¿Cuál es la diferencia con el siguiente comando?

``` .bash
$ ls */*[2-5].pdb
```

#### Ejercicio 10. 
Localice entre los ficheros de esta práctica uno llamado `square.cc`.
Se trata de un fichero que contiene el código fuente de un programa escrito en C++.
En clases de teoría estudiará qué es el código fuente.
Utilice el comando

`g++ -o square square.cc`

para compilar ese programa.
Compilar un programa es traducir el programa fuente a un fichero ejecutable que será posible ejecutar en el
ordenador.

Una vez compilado, liste los ficheros que se encuentran en el directorio de trabajo. 
¿Observa algún cambio en esos ficheros?

Identifique entre los ficheros del directorio de trabajo, alguno que sea ejecutable y ejecútelo.
Para ello basta que escriba el comando

`./nombre-fichero-ejecutable`

(sustuyendo, obviamente *nombre-fichero-ejecutable* por el nombre de su fichero).
Estudie el contenido del fichero que contiene el código fuente y trate de comprender cómo funciona el
programa.

#### Ejercicio 11. 
Elimine el fichero `square` resultado de la compilación en el paso anterior.
Tenga en cuenta que en Linux (Unix) una vez un fichero se borra, lo perderá para siempre.
#### Ejercicio 12. 
Cambie el nombre de `square.cc` a `square_numbers.cc`.
#### Ejercicio 13. 
¿Cómo se muestra un fichero de texto largo para que se detenga en cada pantalla?
Practique mostrando en pantalla el contenido del fichero `/proc/cpuinfo` (observe la ruta absoluta en el nombre de ese fichero) que contiene información sobre las CPUs de su máquina.
#### Ejercicio 14. 
¿Qué contiene el fichero de texto `long-text-file.txt` que se encuentra en su directorio de trabajo?
#### Ejercicio 15. 
¿Qué hacen las teclas de flechas arriba y flecha abajo cuando está ejecutándose la shell de Linux (bash)?
#### Ejercicio 16. 
En la shell, escriba el carácter `!` seguido de una letra como la `g` o la `l`, como en `!g` o `!l`.
Experimente con otras letras después del símbolo de exclamación. ¿Qué hace la exclamación?
#### Ejercicio 17. 
Experimente con el comando `grep`. `grep` es un programa que permite buscar texto usando expresiones regulares (estudiará Ud. expresiones regulares más adelante en 2º curso). 
Por ahora, puede usarlo para buscar un patrón de texto. Un uso básico del comando es:
  `grep string target-file`
  Ese comando localiza todas las apariciones de la cadena de texto `string` en el fichero `target-file` El fichero `long-text-file.txt` contiene 187018 palabras. Use grep para encontrar todas las palabras que contengan "aula" en ese fichero. ¿Cuáles son esas las palabras?
#### Ejercicio 18. 
Use un *pipe* (encadenamiento de comandos). El comando `wc` (de *Word Count*) indica cuántas líneas, palabras y caracteres hay en un fichero. Utilice el comando `man` para conocer el funcionamiento de `wc`, así como información detallada del comando. Utilizando `wc` averigüe cuantas líneas, palabras y caracteres contiene el fichero `long-text-file.txt`
  Utilice un *pipe* (usando el caracter `|`) para vincular los dos comandos anteriores (`grep` y `wc`) entre sí, para averiguar cuántas veces aparecen en el fichero `long-text-file.txt` cada una de las palabras que contienen la subpalabra "aula". Escriba un fichero de texto `aula.txt` en el que figure cada una de estas palabras y el número de veces que aparece en el fichero `long-text-file.txt`.
