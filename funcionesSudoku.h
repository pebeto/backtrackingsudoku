#ifndef FUNCIONESSUDOKU_H_INCLUDED
#define FUNCIONESSUDOKU_H_INCLUDED
using namespace std;

void imprimir(int x[9][9]){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout<<x[i][j];
			if((j+1)%3==0)
				cout<<" | ";
			cout<<" ";
		}
		cout<<endl;
        if((i+1)%3==0)
			cout<<"-------------------------"<<endl;
	}
}

bool encontrarVacio(int &x, int &y, int sudoku[9][9]){
    for(x=0; x<9; x++)                                // Busca una posición de la matriz que contenga un "0".
        for(y=0; y<9; y++)                            // Se manda por referencia la posición en donde se encuentra
            if(sudoku[x][y]==0)                       // para que el algoritmo opere sobre el cuadro en el que pertenece.
                return true;
    return false;
}


bool buscarMinMatriz(int i, int x, int y, int sudoku[9][9]){
    if(x%3==0 && y%3==0)                                    // Algoritmo más eficiente de búsqueda en cuadro 3x3 local.
        for(int p=1; p<3; p++)
            for(int q=1; q<3; q++)
                if(sudoku[x+p][y+q]==i)
                    return true;
    if(x%3==0 && y%3==1)                                    // La forma más eficiente de encontrar la posición
        for(int p=1; p<3; p++)                              // donde se encuentra un número en la celda de
            for(int q=0; q<3; q=q+2)                        // una matriz, es calculando el módulo de su posición.
                if(sudoku[x+p][y-1+q]==i)                   //        _____________________________
                    return true;                            //       | i%3==0  | i%3==0  | i%3==0  |
    if(x%3==0 && y%3==2)                                    // i=0   | j%3==0  | j%3==1  | j%3==2  |
        for(int p=1; p<3; p++)                              //       |_________|_________|_________|
            for(int q=0; q<2; q++)                          //       | i%3==1  | i%3==1  | i%3==1  |
                if(sudoku[x+p][y-2+q]==i)                   // i=1   | j%3==0  | j%3==1  | j%3==2  |
                    return true;                            //       |_________|_________|_________|
    if(x%3==1 && y%3==0)                                    //       | i%3==2  | i%3==2  | i%3==2  |
        for(int p=0; p<3; p=p+2)                            // i=2   | j%3==0  | j%3==1  | j%3==2  |
            for(int q=1; q<3; q++)                          //       |_________|_________|_________|
                if(sudoku[x-1+p][y+q]==i)                   //
                    return true;                            //           j=0       j=1       j=2
    if(x%3==1 && y%3==1)                                    //
        for(int p=0; p<3; p=p+2)                            // Tal como se aprecia en el gráfico mostrado, la
            for(int q=0; q<3; q=q+2)                        // posicion de una celda puede ser definida por módulo.
                if(sudoku[x-1+p][y-1+q]==i)                 // Esto significa que cual sea la posición donde se
                    return true;                            // encuentre marcando el algoritmo, se sabrá cuál es
    if(x%3==1 && y%3==2)                                    // su posición en el cuadro 3x3 local. Ejemplo:
        for(int p=0; p<3; p=p+2)                            // - Sabiendo que i y j son contadores que empiezan en 0:
            for(int q=0; q<2; q++)                          //   Si sudoku[i][j], donde i= 6 y j= 7,
                if(sudoku[x-1+p][y-2+q]==i)                 //   i%3= 6%3= 0 y j%3= 7%3= 1, entonces su posición
                    return true;                            //   es (0,1) en su cuadro local.
    if(x%3==2 && y%3==0)                                    //
        for(int p=0; p<2; p++)                              // Este método facilita el acceso rápido a las posiciones
            for(int q=1; q<3; q++)                          // para no tener que almacenar una variable más, ocupando
                if(sudoku[x-2+p][y+q]==i)                   // menos espacio en la memoria.
                    return true;                            //
    if(x%3==2 && y%3==1)                                    // El algoritmo que se ve al lado izquierdo lo denomino como
        for(int p=0; p<2; p++)                              // "método de sustracción obvia".
            for(int q=0; q<3; q=q+2)                        //
                if(sudoku[x-2+p][y-1+q]==i)                 // La lógica a llevar, a diferencia del método de búsqueda
                    return true;                            // lineal clásico, es que no es necesaria la búsqueda de los valores
    if(x%3==2 && y%3==2)                                    // horizontales y verticales, puesto que ya han sido buscados.
        for(int p=0; p<2; p++)                              // Esto significa que en el peor de los casos, el algoritmo
            for(int q=0; q<2; q++)                          // solo busca en 4 celdas, a diferencia del otro método que
                if(sudoku[x-2+p][y-2+q]==i)                 // busca en todas las celdas posibles.
                    return true;

    /*
    // Algoritmo de búsqueda lineal clásico
    for(int p=0; p<3; p++)
        for (int q=0; q< 3; q++)
            if (sudoku[p+x-x%3][q+y-y%3]==i)
                return true;

    // Algoritmo menos eficiente de búsqueda en cuadro 3x3 local.
	if(x%3==0 && y%3==0 && (sudoku[x+1][y+1]==i || sudoku[x+1][y+2]==i || sudoku[x+2][y+1]==i || sudoku[x+2][y+2]==i))
        return true;
	if(x%3==0 && y%3==1 && (sudoku[x+1][y-1]==i || sudoku[x+2][y-1]==i || sudoku[x+1][y+1]==i || sudoku[x+2][y+1]==i))
        return true;
 	if(x%3==0 && y%3==2 && (sudoku[x+1][y-2]==i || sudoku[x+1][y-1]==i || sudoku[x+2][y-2]==i || sudoku[x+2][y-1]==i))
        return true;
	if(x%3==1 && y%3==0 && (sudoku[x-1][y+1]==i || sudoku[x-1][y+2]==i || sudoku[x+1][y+1]==i || sudoku[x+1][y+2]==i))
        return true;
    if(x%3==1 && y%3==1 && (sudoku[x-1][y-1]==i || sudoku[x-1][y+1]==i || sudoku[x+1][y-1]==i || sudoku[x+1][y+1]==i))
        return true;
    if(x%3==1 && y%3==2 && (sudoku[x-1][y-2]==i || sudoku[x-1][y-1]==i || sudoku[x+1][y-2]==i || sudoku[x+1][y-1]==i))
        return true;
	if(x%3==2 && y%3==0 && (sudoku[x-2][y+1]==i || sudoku[x-2][y+2]==i || sudoku[x-1][y+1]==i || sudoku[x-1][y+2]==i))
        return true;
    if(x%3==2 && y%3==1 && (sudoku[x-2][y-1]==i || sudoku[x-1][y-1]==i || sudoku[x-2][y+1]==i || sudoku[x-1][y+1]==i))
        return true;
    if(x%3==2 && y%3==2 && (sudoku[x-2][y-2]==i || sudoku[x-2][y-1]==i || sudoku[x-2][y-1]==i || sudoku[x-1][y-1]==i))
        return true;
    */
    return false;
}

bool seEncuentra(int i, int x, int y, int sudoku[9][9]){
	for(int k=0; k<9; k++)                              // Se utiliza un solo contador que recorre las filas
		if(k!=y || k!=x)                                // y columnas exceptuando el cuadro en donde se encuentra.
            if(sudoku[x][k]==i || sudoku[k][y]==i)
                return true;
    if(buscarMinMatriz(i, x, y, sudoku))                // Se utiliza el método de substracción obvia para buscar
        return true;                                    // dentro de la matriz local del número i alguna igualdad.
    return false;
}

bool resolverSudoku(string nombre,int sudoku[9][9]){
    int x, y;                                       // Índices de búsqueda
	if(!encontrarVacio(x, y, sudoku))
		return true;
    for(int i=1; i<=9; i++){                        // Se itera buscando la estructura numérica que cumpla las restricciones.
        if(!seEncuentra(i, x, y, sudoku)){
            //usleep(100000);
            sudoku[x][y]= i;
            system("clear");
            cout<<nombre<<endl;
            imprimir(sudoku);
            if(resolverSudoku(nombre, sudoku))      // El algoritmo, de manera recursiva, prueba las siguientes estructuras
                return true;                        // con el fin de encontrar el mejor resultado (Backtracking). Si en alguna
            sudoku[x][y]= 0;                        // estructura es imposible cumplir, regresa a la anterior para seguir iterando
        }                                           // hasta encontrar una solución.
    }
	return false;
}

#endif // FUNCIONESSUDOKU_H_INCLUDED
