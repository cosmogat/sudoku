// 05-02-2013
// billy
// casella.c++
#include <iostream>
#include <cstdlib>
#include "casella.h++"
using namespace std;

Casella::Casella() {
  nums.resize(9);
  for (int i = 0; i < 9; i++)
    nums[i] = true;
  cont = 0;
}

Casella::Casella(const Casella & ori) {
  nums.resize(9);
  cont = ori.cont;
  for (int i = 0; i < 9; i++)
    nums[i] = ori.nums[i];
}

Casella::Casella(const int a) {
  nums.resize(9);
  cont = 8;
  for (int i = 0; i < 9; i++)
    nums[i] = false;
  nums[a - 1] = true;
}

Casella & Casella::operator=(const Casella & ori) {
  cont = ori.cont;
  for (int i = 0; i < 9; i++)
    nums[i] = ori.nums[i];
  return (*this);
}

Casella & Casella::operator=(const int a) {
  if (a >= 0 && a <= 9) {
    if (a == 0) {
      cont = 0;
      for (int i = 0; i < 9; i++)
	nums[i] = true;
    }
    else {
      cont = 8;
      for (int i = 0; i < 9; i++)
	nums[i] = false;
      nums[a - 1] = true;
    }
  }
  else{
    cerr << "Valors incorrectes per a la casella." << endl;
    exit(-1);
  }
  return (*this);
}

bool Casella::operator!=(const Casella & cas) const {
  if (cont != cas.cont)
    return true;
  for (int i = 0; i < 9; i++)
    if (nums[i] != cas.nums[i])
      return true;
  return false;
}

bool Casella::operator==(const Casella & cas) const {
  return (!operator!=(cas));
}

void Casella::MarcarFals(const int a) {
  if (nums[a - 1])
    cont++;
  nums[a - 1] = false;
}

bool Casella::Resolta() const {
  return (cont == 8);
}

int Casella::Numero() const {
  for (int i = 0; i < 9; i++)
    if (nums[i])
      return (i + 1);
  return -1;
}

bool Casella::EsPosible(int num) const {
  return nums[num - 1];
}

void Casella::Imprimir(ostream & eix) const {
  if (this->Resolta())
    eix << this->Numero();
  else
    eix << "X";
}

void Casella::Llegir (istream & ent) {
  int aux;
  ent >> aux;
  operator=(aux);
}

ostream & operator<< (ostream & eix, const Casella & cas) {
  cas.Imprimir(eix);
  return eix;
}

istream & operator>> (istream & ent, Casella & cas) {
  cas.Llegir(ent);
  return ent;
}
