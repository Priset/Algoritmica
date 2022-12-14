## BIT

El Binary Indexed Tree (BIT) o Fenwick Tree (por Peter Fenwick) es una 
estructura de datos que permite modificaciones y consultas en O(logn), 
siendo n la cantidad de elementos de referencia en la estructura (sea a 
el arreglo con todos esos elementos). Toma como referencia una función 
asociativa f y calcula respuestas parciales para optimizar el tiempo de 
consulta y de modificación.
Consideraremos que las respuestas parciales de la estructura serán 
almacenadas en un arreglo ft. La cantidad de memoria que necesita el 
BIT es O(n), siendo más específicos, necesitaría una cantidad cercada a 
n+1 estructuras del mismo tipo que los elementos de a, lo cual probaremos a continuación.

![imagen](https://user-images.githubusercontent.com/90929324/193981801-051ad08d-2b66-487a-8e28-1e61b57b4902.png)
