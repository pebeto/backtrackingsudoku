# Backtracking sudoku
## Algoritmo vuelta atrás que soluciona tableros de sudoku resolubles

El Backtracking es un tipo de algoritmo que busca encontrar la mejor solución posible o todas las que se puedan presentar. 
Esta técnica de programación es muy utilizada en muchísimos programas que requieren una forma de evaluar cientos de
resultados en muy poco tiempo.
El siguiente algoritmo es otro de los más que existen dentro de la red sobre la solución de un tablero de sudoku resoluble.
Entenderse por *tablero resoluble* al cual pueda ser resuelto colocando sus respectivos dígitos de una manera en la que el 
programa no entre en un bucle infinito (Ejemplo: Si se colocan en el tablero inicial dos números iguales en la misma fila,
entonces el tablero ya no es *resoluble*).
Lo especial de este algoritmo es su manera de buscar la repetición de un número en una respectiva celda `[i][j]`. En el 
caso de la búsqueda horizontal y vertical, el algoritmo hace uso de un solo `for` para recorrer las celdas superiores e
inferiores del tablero. En de la posición en donde se encuentra el número, se calcula el módulo (%) para encontrar la
posición exacta en el cuadro local y se evalúa solamente las casillas que no han sido buscadas de manera horizontal y vertical.
A este método lo he denominado como "de substracción obvia", puesto que se ignoran las casillas buscadas de la forma anteriormente
mencionada. Gracias a esto, se pueden disminuir las nueve operaciones que realiza el algoritmo clásico de búsqueda en solamente
cuatro.
