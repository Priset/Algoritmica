## Union Find
Un conjunto disjunto es una estructura de datos que realiza un 
seguimiento de un conjunto de elementos divididos en varios 
subconjuntos disjuntos (que no se superponen). En otras palabras, 
un conjunto disjunto es un grupo de conjuntos donde ningún elemento 
puede estar en más de un conjunto. También se denomina estructura 
de datos de búsqueda de unión, ya que admite la operación de unión 
y búsqueda en subconjuntos. Empecemos por definirlos:

Find: Determina en qué subconjunto se encuentra un elemento en particular 
y devuelve el representante de ese conjunto en particular. Un elemento de 
este conjunto normalmente actúa como un "representante" del conjunto.

Union: Fusiona dos subconjuntos diferentes en un solo subconjunto, y el 
representante de un conjunto se convierte en representante de otro.

El conjunto disjunto también admite otra operación importante llamada 
MakeSet, que crea un conjunto que contiene solo un elemento dado.

Podemos determinar si dos elementos están en el mismo subconjunto 
comparando el resultado de dos Encontrar operaciones. Si los dos 
elementos están en el mismo conjunto, tienen la misma representación; 
de lo contrario, pertenecen a conjuntos diferentes. Si se llama a la 
unión de dos elementos, fusione los dos subconjuntos a los que pertenecen los dos elementos.

![imagen](https://user-images.githubusercontent.com/90929324/193980373-5a1831da-9e23-4f88-9ead-fbb8beb2dfbc.png)
