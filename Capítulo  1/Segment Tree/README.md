## Segment Tree

El ST es una estructura de datos muy versátil que sirve para 
responder varias consultas de agregación tipo máximo, mínimo, 
sumas, promedio, multiplicaciones y otras menos estándar, en 
tiempo log N para un universo de N elementos. Típicamente el 
ST se construye para responder consultas sobre un arreglo (como 
"entrégame el mínimo valor entre los índices i y j del arreglo"). 
También se pueden hacer actualizaciones de elementos de ese arreglo 
que tardan tiempo log N. Si tenemos entonces un problema donde hay Q 
consultas (preguntas por rango y actualizaciones de elementos) sobre 
un arreglo de largo N, el tiempo total de la solución con ST será 
Ο(Q log N) más el tiempo de construcción inicial del ST (que se puede lograr en Ο(N log N)). 

![imagen](https://user-images.githubusercontent.com/90929324/193980832-93944ae9-e461-4c27-9c1d-2ad3e6e1a5a4.png)
