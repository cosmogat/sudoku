// 05-02-2013
// billy
// programa.c++
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "sudoku.h++"
using namespace std;


int main (int num_arg, char * vec_arg[]) {
  bool verbose = false;
  if ((num_arg > 3) || (num_arg < 2)) {
    cerr << "El programa s'utilitza així:" << endl;
    cerr << vec_arg[0] << " [|-v] sud.txt" << endl;
    cerr << "On:" << endl;
    cerr << "\t-v:\tserveix per a mostrar certa informació del sudoku." << endl;
    cerr << "\tsud.txt\tes un fitxer de text amb el sudoku.\nEl fitxer 'sud.txt' tindra els nombres tots seguits en una mateixa fila i els zeros seran les caselles sense resoldre." << endl;
    exit(-1);
  }
  if (strcmp(vec_arg[1], "-v") == 0)
    verbose = true;
  int dif = 0;
  Sudoku prova = verbose ? vec_arg[2] : vec_arg[1];
  dif = prova.Resoldre();
  if (dif == -1) {
    cerr << "Sudoku no resoluble. Com a minim 16 caselles" << endl;
    exit(-2);
  } 
  cout << prova << endl;
  if (verbose)
    cout << "Dificultat: " << dif << endl;
  return 0;
}

