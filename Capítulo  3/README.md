## Programación Dinámica 
* El método de programación dinámica sirve para resolver problemas combinando
las soluciones de subproblemas.
* Normalmente es usada para resolver problemas de optimización.
* Al construir un algoritmo usando la estrategia de programación dinámica es
necesario:
1. Caracterizar la estructura de una solución optima.
2. Definir recursivamente el valor de una solución óptima.
3. Computar el valor de una solución en forma bottom-up.
4. [Opcional] Construir una solución óptima a partir de la información computada.

Hay dos condiciones que se deben cumplir antes de comenzar a pensar en una
solución a un problema de optimización usando programación dinámica.
* Sub-estructura óptima. Un problema tiene sub-estructura óptima cuando la
solución óptima a un problema se puede componer a partir de soluciones óptimas
de sus sub-problemas.
* Superposición de Problemas. El cálculo de la solución óptima implica resolver 
muchas veces un mismo sub-problemas. La cantidad de sub-problema es
“pequeña”.

![imagen](https://user-images.githubusercontent.com/90929324/196309065-c3d8b917-d47a-46b6-a750-dbd15f66183c.png)

