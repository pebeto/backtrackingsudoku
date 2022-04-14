#include <chrono>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void imprimir(int x[9][9]) {
  for (int i = 0, j; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      cout << x[i][j];
      if ((j + 1) % 3 == 0)
        cout << " | ";
      cout << " ";
    }
    cout << endl;
    if ((i + 1) % 3 == 0)
      cout << "-------------------------" << endl;
  }
}

bool encontrarVacio(int &x, int &y, int sudoku[9][9]) {
  for (x = 0; x < 9;
       x++) // Busca una posición de la matriz que contenga un "0".
    for (y = 0; y < 9;
         y++) // Se manda por referencia la posición en donde se encuentra
      if (sudoku[x][y] ==
          0) // para que el algoritmo opere sobre el cuadro en el que pertenece.
        return true;
  return false;
}

bool buscarMinMatrizSubstraccionObvia(int i, int x, int y, int sudoku[9][9]) {
  // Algoritmo más eficiente de búsqueda en cuadro 3x3 local.

  // La forma más eficiente de encontrar la posición
  // donde se encuentra un número en la celda de
  // una matriz, es calculando el módulo de su posición.
  //        _____________________________
  //       | i%3==0  | i%3==0  | i%3==0  |
  // i=0   | j%3==0  | j%3==1  | j%3==2  |
  //       |_________|_________|_________|
  //       | i%3==1  | i%3==1  | i%3==1  |
  // i=1   | j%3==0  | j%3==1  | j%3==2  |
  //       |_________|_________|_________|
  //       | i%3==2  | i%3==2  | i%3==2  |
  // i=2   | j%3==0  | j%3==1  | j%3==2  |
  //       |_________|_________|_________|
  //
  //           j=0       j=1       j=2

  // Tal como se aprecia en el gráfico mostrado, la
  // posicion de una celda puede ser definida por módulo.
  // Esto significa que cual sea la posición donde se
  // encuentre marcando el algoritmo, se sabrá cuál es
  // su posición en el cuadro 3x3 local. Ejemplo:
  // - Sabiendo que i y j son contadores que empiezan en 0:
  //   Si sudoku[i][j], donde i= 6 y j= 7,
  //   i%3= 6%3= 0 y j%3= 7%3= 1, entonces su posición
  //   es (0,1) en su cuadro local.

  // Este método facilita el acceso rápido a las posiciones
  // para no tener que almacenar una variable más, ocupando
  // menos espacio en la memoria.

  // El algoritmo que se ve al lado izquierdo lo denomino como
  // "método de sustracción obvia".

  // La lógica a llevar, a diferencia del método de búsqueda
  // lineal clásico, es que no es necesaria la búsqueda de los valores
  // horizontales y verticales, puesto que ya han sido buscados.
  // Esto significa que en el peor de los casos, el algoritmo
  // solo busca en 4 celdas, a diferencia del otro método que
  // busca en todas las celdas posibles.

  if (x % 3 == 0) {
    if (y % 3 == 0) {
      for (int p = 1, q; p < 3; p++)
        for (q = 1; q < 3; q++)
          if (sudoku[x + p][y + q] == i)
            return true;
    }
    if (y % 3 == 1) {
      for (int p = 1, q; p < 3; p++)
        for (q = 0; q < 3; q = q + 2)
          if (sudoku[x + p][y - 1 + q] == i)
            return true;
    }
    if (y % 3 == 2) {
      for (int p = 1, q; p < 3; p++)
        for (q = 0; q < 2; q++)
          if (sudoku[x + p][y - 2 + q] == i)
            return true;
    }
  }
  if (x % 3 == 1) {
    if (y % 3 == 0) {
      for (int p = 0, q; p < 3; p = p + 2)
        for (q = 1; q < 3; q++)
          if (sudoku[x - 1 + p][y + q] == i)
            return true;
    }
    if (y % 3 == 1) {
      for (int p = 0, q; p < 3; p = p + 2)
        for (q = 0; q < 3; q = q + 2)
          if (sudoku[x - 1 + p][y - 1 + q] == i)
            return true;
    }
    if (y % 3 == 2) {
      for (int p = 0, q; p < 3; p = p + 2)
        for (q = 0; q < 2; q++)
          if (sudoku[x - 1 + p][y - 2 + q] == i)
            return true;
    }
  }
  if (x % 3 == 2) {
    if (y % 3 == 0) {
      for (int p = 0, q; p < 2; p++)
        for (q = 1; q < 3; q++)
          if (sudoku[x - 2 + p][y + q] == i)
            return true;
    }
    if (y % 3 == 1) {
      for (int p = 0, q; p < 2; p++)
        for (q = 0; q < 3; q = q + 2)
          if (sudoku[x - 2 + p][y - 1 + q] == i)
            return true;
    }
    if (y % 3 == 2) {
      for (int p = 0, q; p < 2; p++)
        for (q = 0; q < 2; q++)
          if (sudoku[x - 2 + p][y - 2 + q] == i)
            return true;
    }
  }
  return false;
}

bool buscarMinMatrizLinealClasico(int i, int x, int y, int sudoku[9][9]) {
  for (int p = 0; p < 3; p++)
    for (int q = 0; q < 3; q++)
      if (sudoku[p + x - x % 3][q + y - y % 3] == i)
        return true;
  return false;
}

bool buscarMinMatrizMenosEficiente(int i, int x, int y, int sudoku[9][9]) {
  if (x % 3 == 0 && y % 3 == 0 &&
      (sudoku[x + 1][y + 1] == i || sudoku[x + 1][y + 2] == i ||
       sudoku[x + 2][y + 1] == i || sudoku[x + 2][y + 2] == i))
    return true;
  if (x % 3 == 0 && y % 3 == 1 &&
      (sudoku[x + 1][y - 1] == i || sudoku[x + 2][y - 1] == i ||
       sudoku[x + 1][y + 1] == i || sudoku[x + 2][y + 1] == i))
    return true;
  if (x % 3 == 0 && y % 3 == 2 &&
      (sudoku[x + 1][y - 2] == i || sudoku[x + 1][y - 1] == i ||
       sudoku[x + 2][y - 2] == i || sudoku[x + 2][y - 1] == i))
    return true;
  if (x % 3 == 1 && y % 3 == 0 &&
      (sudoku[x - 1][y + 1] == i || sudoku[x - 1][y + 2] == i ||
       sudoku[x + 1][y + 1] == i || sudoku[x + 1][y + 2] == i))
    return true;
  if (x % 3 == 1 && y % 3 == 1 &&
      (sudoku[x - 1][y - 1] == i || sudoku[x - 1][y + 1] == i ||
       sudoku[x + 1][y - 1] == i || sudoku[x + 1][y + 1] == i))
    return true;
  if (x % 3 == 1 && y % 3 == 2 &&
      (sudoku[x - 1][y - 2] == i || sudoku[x - 1][y - 1] == i ||
       sudoku[x + 1][y - 2] == i || sudoku[x + 1][y - 1] == i))
    return true;
  if (x % 3 == 2 && y % 3 == 0 &&
      (sudoku[x - 2][y + 1] == i || sudoku[x - 2][y + 2] == i ||
       sudoku[x - 1][y + 1] == i || sudoku[x - 1][y + 2] == i))
    return true;
  if (x % 3 == 2 && y % 3 == 1 &&
      (sudoku[x - 2][y - 1] == i || sudoku[x - 1][y - 1] == i ||
       sudoku[x - 2][y + 1] == i || sudoku[x - 1][y + 1] == i))
    return true;
  if (x % 3 == 2 && y % 3 == 2 &&
      (sudoku[x - 2][y - 2] == i || sudoku[x - 2][y - 1] == i ||
       sudoku[x - 2][y - 1] == i || sudoku[x - 1][y - 1] == i))
    return true;
  return false;
}

bool buscarMinMatriz(int i, int x, int y, int sudoku[9][9], int metodo) {
  if (metodo == 0) {
    return buscarMinMatrizSubstraccionObvia(i, x, y, sudoku);
  }
  if (metodo == 1) {
    return buscarMinMatrizLinealClasico(i, x, y, sudoku);
  }
  if (metodo == 2) {
    return buscarMinMatrizMenosEficiente(i, x, y, sudoku);
  }
  return false;
}

bool seEncuentra(int i, int x, int y, int sudoku[9][9], int metodo) {
  for (int k = 0; k < 9;
       k++) // Se utiliza un solo contador que recorre las filas
    if (k != y ||
        k != x) // y columnas exceptuando el cuadro en donde se encuentra.
      if (sudoku[x][k] == i || sudoku[k][y] == i)
        return true;
  if (buscarMinMatriz(
          i, x, y, sudoku,
          metodo)) // Se utiliza el método de substracción obvia para buscar
    return true;   // dentro de la matriz local del número i alguna igualdad.
  return false;
}

string obtenerNombreMetodo(int metodo) {
  if (metodo == 0) {
    return "Substracción obvia";
  }
  if (metodo == 1) {
    return "Lineal clásico";
  }
  if (metodo == 2) {
    return "Menos eficiente";
  }
  return "No existe";
}

bool logicaSudoku(string nombre, int sudoku[9][9], int metodo, bool print) {
  int x, y; // Índices de búsqueda
  if (!encontrarVacio(x, y, sudoku))
    return true;
  for (int i = 1; i <= 9; i++) { // Se itera buscando la estructura numérica que
                                 // cumpla las restricciones.
    if (!seEncuentra(i, x, y, sudoku, metodo)) {
      sudoku[x][y] = i;
      if (print) {
        system("clear");
        imprimir(sudoku);
      }
      if (logicaSudoku(nombre, sudoku, metodo,
                       print)) // El algoritmo, de manera recursiva,
                               // prueba las siguientes estructuras
        return true;           // con el fin de encontrar el mejor resultado
                               // (Backtracking). Si en alguna
      sudoku[x][y] = 0;        // estructura es imposible cumplir, regresa a la
                               // anterior para seguir iterando
    }                          // hasta encontrar una solución.
  }
  return false;
}

void copiarSudoku(int sudoku[9][9], int nuevoSudoku[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      nuevoSudoku[i][j] = sudoku[i][j];
    }
  }
}

void resolverSudoku(string nombre, int sudoku[9][9], int metodo = 0,
                    bool print = false) {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  int nuevoSudoku[9][9];
  copiarSudoku(sudoku, nuevoSudoku);
  auto t1 = high_resolution_clock::now();
  logicaSudoku(nombre, nuevoSudoku, metodo, print);
  auto t2 = high_resolution_clock::now();
  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  cout << nombre << " (" << obtenerNombreMetodo(metodo)
       << "):" << ms_int.count() << "ms\n";

  cin.ignore();
  system("clear");
}
