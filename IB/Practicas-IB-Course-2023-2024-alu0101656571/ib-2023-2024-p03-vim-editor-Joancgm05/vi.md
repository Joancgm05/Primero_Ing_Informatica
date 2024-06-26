# Práctica 03. Edición de ficheros de texto con vi

# Factor de ponderación: 4

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Aprenda a utilizar el editor [vim](https://www.vim.org/)
  conociendo al menos los comandos básicos de edición
* Sepa editar ficheros remotos en la VM de la asignatura usando vi
* Ampliar sus conocimientos sobre comandos de Linux

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica:
* Ha de acreditarse que se es capaz de conectarse a su máquina virtual (VM) de la asignatura 
* Ha de acreditar que es capaz de editar ficheros remotos en su VM usando vi
* Ha de demostrar que es capaz de ejecutar comandos Linux en su VM

### Introducción
Todo usuario de Linux que se precie debiera saber utilizar el editor vi.
Son varias las áreas en las que necesitará usar un editor de texto: la programación o la edición de ficheros de configuración del sistema son dos de las más relevantes.
Hay varios editores de texto notables disponibles para sistemas operativos basados en Linux.
Los usuarios de terminal gráfica utilizarán el editor por defecto de su distribución, pero si se accede al fichero desde la terminal, 
o a través de 
[`ssh`](https://ss64.com/bash/ssh.html)
en otro servidor, con frecuencia tendrá que editar el texto utilizando uno de los conocidos editores en terminal.
Existen otros editores más sencillos de utilizar, pero puede que Ud. acceda a una máquina que no disponga de ellos y que no le permita 
instalar su propio editor, de modo que conocer vi podrá sacarle de más de un apuro.

Vi fue el primer editor de texto orientado al terminal creado para Unix. 
Fue diseñado para ser simple pero potente en cuanto a la manipulación de texto.
Vim (Vi IMproved), como su nombre indica, es un clon de Vi y ofrece aún más funciones que éste. 
Es gratuito y de código abierto, y está diseñado para ser utilizado tanto desde una interfaz de línea de comandos 
como en forma de aplicación independiente en una interfaz gráfica de usuario (GUI).
Es altamente configurable y dispone de características notables como resaltado de sintaxis, soporte para ratón, versiones gráficas, modo visual, 
muchos comandos de edición nuevos y una gran cantidad de extensiones.
A modo de resumen, se indican a continuación algunas de las características por las que utilizaremos vi en
*Informática Básica*:

1. Es gratuito y de código abierto
2. Está disponible en la mayoría, si no en todas las distribuciones de Linux existentes
3. Está bien documentado. Es muy fácil hallar información sobre cualquier duda sobre su uso
5. Es muy personalizable y extensible
6. Tiene configuraciones portátiles
7. Utiliza menos recursos del sistema
8. Es compatible con todos los lenguajes de programación y formatos de archivo
9. Es muy popular en el mundo de Linux

### Tutoriales
En la Práctica 1 de la asignatura ya se indicaron algunas referencias para un primer contacto con vi.
El [tutorial interactivo on-line](https://www.openvim.com/) 
enseña el uso del editor de forma interactiva.
[Este otro tutorial](https://github.com/Izaird/Vim-primeros-pasos) explica lo básico del editor a través de ejemplos concretos con ficheros de texto.
Utilice el comando 
```.bash
git clone git@github.com:Izaird/Vim-primeros-pasos.git
```
para realizar una copia del repositorio y luego edite y estudie usando vim los diferentes ficheros del tutorial.

`vimtutor` es un tutorial que estará instalado en su sistema Linux siempre que vi lo esté.
Ejecute el comando `vimtutor` accederá a un fichero de texto que contiene el contenido del tutorial y en el
que puede practicar los comandos de vi.

Tanto
[este tutorial](https://web.stanford.edu/class/cs107/resources/vim.html) 
de una asignatura de la Universidad de Stanford,  
[The Missing Semester of Your CS Education](https://missing.csail.mit.edu/2020/editors/) 
del MIT o el tutorial en español
[Aprende Vim](https://victorhck.gitbook.io/aprende-vim/)
de Victorhk también son buenos tutoriales de iniciación.

Por último la 
[Vim Quick Reference Card](http://www.cheat-sheets.org/saved-copy/vimqrc.pdf)
que tiene también disponible a través del aula virtual de la asignatura es una hoja que merece la pena
imprimir y tener disponible en sus primeras sesiones de edición.
Recuerde imprimirla y llevarla consigo a la evaluación de esta práctica.

Elija de los anteriores el tutorial que prefiera, y no se conforme con estudiar solo uno de ellos.

### Funciones de edición de ficheros de texto
Asegúrese de saber cómo realizar en vim cada una de las tareas que se exponen a continuación.
Si no obtiene la información necesaria en alguno de los tutoriales, también es un buen recurso
consultar
[Stackoverflow](https://stackoverflow.com/questions/tagged/vim)
donde podrá hallar multitud de preguntas/respuestas sobre el editor.

Estas son algunas de las tareas que debe ser capaz de realizar en vim.
Subraye o marque de algún modo cada una de ellas en su copia de la 
[Vim Quick Reference Card](http://www.cheat-sheets.org/saved-copy/vimqrc.pdf)

* Comenzar la edición de un fichero de texto en vi usando la ruta (path) absoluta del fichero
* Desplazarse dentro del fichero en todas las direcciones (líneas arriba/abajo y derecha/izquierda dentro de
  cada línea
* Desplazarse al final/principio (primera/última línea) del fichero
* Desplazarse al principio/final de una determinada línea
* Desplazarse en una línea de texto a la izquierda/derecha avanzando de palabra en palabra
* Desplazarse una página arriba/abajo dentro del fichero
* Reemplazar un carácter por otro en una determinada línea del fichero
* Borrar una línea del fichero
* Borrar un rango de líneas (desde la línea N a la N+M)
* Copiar una línea de texto (o un rango de líneas) en el buffer para luego insertar esas mismas líneas en una
  posición diferente
* Buscar una determinada palabra dentro del fichero
* Reemplazar todas las apariciones de una determinada palabra por otra diferente
* Mostrar/ocultar los números de línea en el fichero
* Deshacer la acción realizada por el último comando ejecutado en el editor
* Rehacer la última acción desechada
* Abandonar la edición del fichero de diferentes modos: habiendo grabado (escrito) la sesión o sin grabar

### Comandos Linux útiles a la hora de procesar ficheros de texto
Por último, estudie también aquellos comandos de linux que tienen relación con la gestión de ficheros.
En particular estudie (con sus páginas de manual) y practique los comandos 
[file](https://ss64.com/bash/file.html),
[grep](https://ss64.com/bash/grep.html),
[wc](https://ss64.com/bash/wc.html) y
[find](https://ss64.com/bash/find.html)
