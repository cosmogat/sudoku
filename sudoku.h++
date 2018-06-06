// 05-02-2013
// billy
// sudoku.h++
#ifndef _SUDOKU_HH
#define _SUDOKU_HH
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "casella.h++"
using namespace std;

class Sudoku {
private:
  Casella sud[9][9];
  void MarcarFila(int, int);
  void MarcarColumna(int, int);
  void MarcarQuadrat(int, int, int);
  void NetejarFiles();
  void NetejarColumnes();
  void NetejarQuadrats();
  void ParellesFiles();
  void ParellesColumnes();
  void ParellesQuadrats();
  void Agranar();
  void MinimesPosibilitats(int &, int &) const;
public:
  Sudoku();
  Sudoku(const Sudoku &);
  Sudoku(const char *);
  Sudoku & operator=(const Sudoku &);
  Sudoku & operator=(const char *);
  bool operator!=(const Sudoku &) const;
  bool operator==(const Sudoku &) const;
  void Imprimir(ostream &) const;
  void ImprimirPosibles(int, int) const;
  bool Resolt() const;
  int Resoldre();
  bool Resoluble() const;
  bool Correcte() const;
};
ostream & operator<< (ostream &, const Sudoku &);
#endif
