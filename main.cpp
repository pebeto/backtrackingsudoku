#include "funcionesSudoku.h"
#include <chrono>

int main() {
  // Este algoritmo resuelve cualquier tabla resoluble de SUDOKU.
  // Los ejemplos asignados demuestran que es capaz de resolver
  // cualquier tipo de tabla fijada por dificultad.
  int sudokuFacil[9][9] = {
      {0, 8, 2, 0, 0, 0, 5, 6, 1}, {0, 0, 0, 1, 6, 8, 0, 9, 3},
      {0, 1, 0, 2, 0, 0, 0, 0, 0}, {0, 2, 0, 0, 0, 1, 0, 7, 9},
      {0, 0, 0, 6, 3, 2, 0, 0, 0}, {8, 3, 0, 9, 0, 0, 0, 2, 0},
      {0, 0, 0, 0, 0, 7, 0, 1, 0}, {2, 4, 0, 5, 1, 9, 0, 0, 0},
      {5, 9, 1, 0, 0, 0, 7, 4, 0}};

  int sudokuMedio[9][9] = {
      {5, 0, 0, 2, 0, 1, 0, 0, 0}, {9, 0, 0, 0, 6, 0, 0, 0, 0},
      {0, 0, 2, 8, 0, 0, 0, 9, 6}, {4, 1, 0, 0, 0, 0, 9, 0, 0},
      {8, 9, 0, 4, 1, 2, 0, 6, 5}, {0, 0, 6, 0, 0, 0, 0, 1, 4},
      {1, 8, 0, 0, 0, 9, 3, 0, 0}, {0, 0, 0, 0, 5, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 3, 0, 0, 9}};

  int sudokuDificil[9][9] = {
      {0, 0, 3, 0, 0, 0, 0, 5, 9}, {0, 0, 0, 4, 0, 0, 0, 0, 0},
      {0, 0, 9, 1, 6, 0, 8, 0, 0}, {0, 1, 0, 8, 0, 0, 0, 0, 5},
      {2, 0, 0, 0, 0, 0, 0, 0, 8}, {9, 0, 0, 0, 0, 4, 0, 7, 0},
      {0, 0, 1, 0, 8, 9, 2, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0},
      {4, 7, 0, 0, 0, 0, 3, 0, 0}};

  int elMasDificil[9][9] = {
      {8, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 3, 6, 0, 0, 0, 0, 0},
      {0, 7, 0, 0, 9, 0, 2, 0, 0}, {0, 5, 0, 0, 0, 7, 0, 0, 0},
      {0, 0, 0, 0, 4, 5, 7, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 3, 0},
      {0, 0, 1, 0, 0, 0, 0, 6, 8}, {0, 0, 8, 5, 0, 0, 0, 1, 0},
      {0, 9, 0, 0, 0, 0, 4, 0, 0}};

  resolverSudoku("Sudoku Facil", sudokuFacil);
  resolverSudoku("Sudoku Facil", sudokuFacil, 1);
  resolverSudoku("Sudoku Facil", sudokuFacil, 2);

  resolverSudoku("Sudoku Medio", sudokuMedio);
  resolverSudoku("Sudoku Medio", sudokuMedio, 1);
  resolverSudoku("Sudoku Medio", sudokuMedio, 2);

  resolverSudoku("Sudoku Dificil", sudokuDificil);
  resolverSudoku("Sudoku Dificil", sudokuDificil, 1);
  resolverSudoku("Sudoku Dificil", sudokuDificil, 2);

  resolverSudoku("El sudoku más difícil", elMasDificil);
  resolverSudoku("El sudoku más difícil", elMasDificil, 1);
  resolverSudoku("El sudoku más difícil", elMasDificil, 2);

  return 0;
}
