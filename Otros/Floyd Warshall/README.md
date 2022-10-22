## Floyd Warshall
El algoritmo de Floyd-Warshall, descrito en 1959 por Bernard Roy, 
es un algoritmo de análisis sobre grafos para encontrar el camino 
mínimo en grafos dirigidos ponderados. El algoritmo encuentra el 
camino entre todos los pares de vértices en una única ejecución. 
El algoritmo de Floyd-Warshall es un ejemplo de programación dinámica.

El algoritmo de Warshall es un ejemplo de algoritmo booleano. 
A partir de una tabla inicial compuesta de 0`s (no hay correspondencia 
inicial en el grafo) y 1`s (hay una correspondencia, llamase “flecha”, 
entre nodos), obtiene una nueva matriz denominada “Matriz de Clausura 
Transitiva” en la que se muestran todas las posibles uniones entre nodos, 
directa o indirectamente. Es decir, si de “A” a “B” no hay una “flecha”, 
es posible que si haya de “A” a “C” y luego de “C” a “B”. Luego, este 
resultado se verá volcado en la matriz final.

El algoritmo de Floyd es muy similar, pero trabaja con grafos ponderados. 
Es decir, el valor de la “flecha” que representamos en la matriz puede ser 
cualquier número real o infinito. Infinito marca que no existe unión entre 
los nodos. Esta vez, el resultado será una matriz donde estarán representadas 
las distancias mínimas entre nodos, seleccionando los caminos más convenientes 
según su ponderación (“peso”). Por ejemplo, si de “A” a “B” hay 36 (km), pero 
de “A” a “C” hay 2(km) y de “C” a “B” hay 10 (km), el algoritmo nos devolverá 
finalmente que de “A” a “B” hay 12 (km).

Los pasos a dar en la aplicación del algoritmo de Floyd son los siguientes:

* Formar las matrices iniciales C y D, donde C es la matriz de adyacencia, y D 
es una matriz del mismo tamaño cargada con valores iniciales Dij = i.

* Se toma k=1.

* Se selecciona la fila y la columna k de la matriz C y entonces, para i y j, 
con i≠k, j≠k e i≠j, hacemos:

Si (Cik + Ckj) < Cij → Dij = Dkj y Cij = Cik + Ckj

En caso contrario, dejamos las matrices como están.

* Si k ≤ n, aumentamos k en una unidad y repetimos el paso anterior, en caso contrario paramos las iteraciones.

* La matriz final C contiene los costes óptimos para ir de un vértice a otro, mientras 
que la matriz D contiene los penúltimos vértices de los caminos óptimos que unen dos vértices, 
lo cual permite reconstruir cualquier camino óptimo para ir de un vértice a otro.

El algoritmo de Floyd-Warshall compara todos los posibles caminos a través del grafo entre 
cada par de vértices. El algoritmo es capaz de hacer esto con sólo 
V^3 (esto es notable considerando que puede haber hasta V^2 aristas en el grafo, y 
que cada combinación de aristas se prueba). Lo hace 
mejorando paulatinamente una estimación del camino más corto entre dos vértices, 
hasta que se sabe que la estimación es óptima.


