// 05-02-2013
// billy
// casella.h++
#ifndef _CASELLA_HH
#define _CASELLA_HH
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Casella {
private:
  vector<bool> nums;
  int cont;
public:
  Casella();
  Casella(const Casella &);
  Casella(const int);
  Casella & operator=(const Casella &);
  Casella & operator=(const int);
  bool operator!=(const Casella &) const;
  bool operator==(const Casella &) const;
  void MarcarFals(const int);
  bool Resolta() const;
  int Numero() const;
  bool EsPosible(int) const;
  void Imprimir(ostream &) const;
  void Llegir (istream &);
};
ostream & operator<< (ostream &, const Casella &);
istream & operator>> (istream &, Casella &);
#endif
