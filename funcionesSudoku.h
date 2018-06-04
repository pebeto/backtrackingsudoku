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
    for(x=0; x<9; x++)
        for(y=0; y<9; y++)
            if(sudoku[x][y]==0)
                return true;
    return false;
}

bool buscarMinMatriz(int i, int x, int y, int sudoku[9][9]){
	if(x%3==0 && y%3==0 && (sudoku[x+1][y+1]==i || sudoku[x+1][y+2]==i || sudoku[x+2][y+1]==i || sudoku[x+2][y+2]==i))
        return true;
	if(x%3==1 && y%3==0 && (sudoku[x-1][y+1]==i || sudoku[x-1][y+2]==i || sudoku[x+1][y+1]==i || sudoku[x+1][y+2]==i))
        return true;
	if(x%3==2 && y%3==0 && (sudoku[x-2][y+1]==i || sudoku[x-2][y+2]==i || sudoku[x-1][y+1]==i || sudoku[x-1][y+2]==i))
        return true;
	if(x%3==0 && y%3==1 && (sudoku[x+1][y-1]==i || sudoku[x+2][y-1]==i || sudoku[x+1][y+1]==i || sudoku[x+2][y+1]==i))
        return true;
 	if(x%3==0 && y%3==2 && (sudoku[x+1][y-2]==i || sudoku[x+1][y-1]==i || sudoku[x+2][y-2]==i || sudoku[x+2][y-1]==i))
        return true;
    if(x%3==1 && y%3==1 && (sudoku[x-1][y-1]==i || sudoku[x-1][y+1]==i || sudoku[x+1][y-1]==i || sudoku[x+1][y+1]==i))
        return true;
    if(x%3==1 && y%3==2 && (sudoku[x-1][y-2]==i || sudoku[x-1][y-1]==i || sudoku[x+1][y-2]==i || sudoku[x+1][y-1]==i))
        return true;
    if(x%3==2 && y%3==1 && (sudoku[x-2][y-1]==i || sudoku[x-1][y-1]==i || sudoku[x-2][y+1]==i || sudoku[x-1][y+1]==i))
        return true;
    if(x%3==2 && y%3==2 && (sudoku[x-2][y-2]==i || sudoku[x-2][y-1]==i || sudoku[x-2][y-1]==i || sudoku[x-1][y-1]==i))
        return true;
    return false;
}

bool seEncuentra(int i, int x, int y, int sudoku[9][9]){
	for(int k=0; k<9; k++)
		if(k!=y || k!=x)
            if(sudoku[x][k]==i || sudoku[k][y]==i)
                return true;
    if(buscarMinMatriz(i, x, y, sudoku))
        return true;
    return false;
}

bool resolverSudoku(string nombre,int sudoku[9][9]){
    int x, y; //Se inicializan los índices para saber por dónde empezar.
	if(!encontrarVacio(x, y, sudoku))
		return true;
    for(int i=1; i<=9; i++){
        if(!seEncuentra(i, x, y, sudoku)){
            //usleep(1000000);
            sudoku[x][y]= i;
            system("clear");
            cout<<nombre<<endl;
            imprimir(sudoku);
            if(resolverSudoku(nombre, sudoku))
                return true;
            sudoku[x][y]= 0;
        }
    }
	return false;
}

#endif // FUNCIONESSUDOKU_H_INCLUDED