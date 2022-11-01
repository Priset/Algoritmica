## Edmonds Karp
En ciencias de la computación y teoría de grafos, el Algoritmo 
de Edmonds-Karp es una implementación del método de Ford-Fulkerson 
para calcular el flujo maximo en una red de flujo con complejidad O(V E^2). 
Es asintóticamente más lento que el algoritmo de Push-relabel, que 
tiene complejidad O(V^3), pero es habitualmente más rápido en la 
práctica para grafos ralos. El algoritmo fue publicado por primera vez por 
un científico soviético, Yefim (Chaim) Dinic, en 1970, e independientemente 
por Jack Edmonds y Richard Karp en 1972. El Algoritmo de Dinic incluye 
técnicas adicionales para reducir la complejidad a O(V^2E). 


El algoritmo es idéntico al algoritmo de Ford-Fulkerson, excepto porque 
el orden para ir buscando los caminos aumentantes está definido. El camino 
encontrado debe ser el camino más corto que tiene capacidad disponible. 
Esto se puede encontrar mediante una búsqueda en anchura, ya que dejamos 
que los bordes tengan unidad de longitud. La complejidad O(V E^2) se 
fundamenta mostrando que cada camino aumentante puede ser encontrado con O(E), 
cada vez que al menos uno de los lados E se satura, la distancia desde el lado 
saturado hasta el origen a través del camino aumentante deberá ser más largo 
que la última vez que este estuvo saturado, y ese largo es a lo sumo V. Otra 
propiedad de este algoritmo es que el largo del camino aumentante más corto 
se incrementa monotonamente.

![imagen](https://user-images.githubusercontent.com/90929324/199142678-5a993cdc-3a88-4b91-bc5a-065ac31c3453.png)
