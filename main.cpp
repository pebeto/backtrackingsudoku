#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "funcionesSudoku.h"
using namespace std;

int main() {

    // Este algoritmo resuelve cualquier tabla resoluble de SUDOKU.
    // Los ejemplos asignados demuestran que es capaz de resolver
    // cualquier tipo de tabla fijada por dificultad.

    int sudokuFacil[9][9]={
		{0, 8, 2, 0, 0, 0, 5, 6, 1},
		{0, 0, 0, 1, 6, 8, 0, 9, 3},
		{0, 1, 0, 2, 0, 0, 0, 0, 0},
		{0, 2, 0, 0, 0, 1, 0, 7, 9},
		{0, 0, 0, 6, 3, 2, 0, 0, 0},
		{8, 3, 0, 9, 0, 0, 0, 2, 0},
		{0, 0, 0, 0, 0, 7, 0, 1, 0},
		{2, 4, 0, 5, 1, 9, 0, 0, 0},
		{5, 9 ,1, 0, 0, 0, 7, 4, 0}};

	int sudokuMedio[9][9]={
		{5, 0, 0, 2, 0, 1, 0, 0, 0},
		{9, 0, 0, 0, 6, 0, 0, 0, 0},
		{0, 0, 2, 8, 0, 0, 0, 9, 6},
		{4, 1, 0, 0, 0, 0, 9, 0, 0},
		{8, 9, 0, 4, 1, 2, 0, 6, 5},
		{0, 0, 6, 0, 0, 0, 0, 1, 4},
		{1, 8, 0, 0, 0, 9, 3, 0, 0},
		{0, 0, 0, 0, 5, 0, 0, 0, 1},
		{0, 0 ,0, 1, 0, 3, 0, 0, 9}};

	int sudokuDificil[9][9]={
		{0, 0, 3, 0, 0, 0, 0, 5, 9},
		{0, 0, 0, 4, 0, 0, 0, 0, 0},
		{0, 0, 9, 1, 6, 0, 8, 0, 0},
		{0, 1, 0, 8, 0, 0, 0, 0, 5},
		{2, 0, 0, 0, 0, 0, 0, 0, 8},
		{9, 0, 0, 0, 0, 4, 0, 7, 0},
		{0, 0, 1, 0, 8, 9, 2, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0},
		{4, 7 ,0, 0, 0, 0, 3, 0, 0}};

	int elMasDificil[9][9]={
		{8, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 3, 6, 0, 0, 0, 0, 0},
		{0, 7, 0, 0, 9, 0, 2, 0, 0},
		{0, 5, 0, 0, 0, 7, 0, 0, 0},
		{0, 0, 0, 0, 4, 5, 7, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 3, 0},
		{0, 0, 1, 0, 0, 0, 0, 6, 8},
		{0, 0, 8, 5, 0, 0, 0, 1, 0},
		{0, 9 ,0, 0, 0, 0, 4, 0, 0}};

    resolverSudoku("Sudoku Facil:", sudokuFacil);
    cin.ignore();
    system("clear");
    resolverSudoku("Sudoku Medio:", sudokuMedio);
    cin.ignore();
    system("clear");
    resolverSudoku("Sudoku Dificil:", sudokuDificil);
    cin.ignore();
    system("clear");
    resolverSudoku("El sudoku más difícil:", elMasDificil);

	return 0;
}
