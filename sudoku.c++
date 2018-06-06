// 05-02-2013
// billy
// sudoku.c++
#include <iostream>
#include <cstdlib>
#include "sudoku.h++"
using namespace std;

// Mètodes privats

void Sudoku::MarcarFila(int fil, int num) {
  for (int i = 0; i < 9; i++)
    if (!sud[fil][i].Resolta())
      sud[fil][i].MarcarFals(num);
}

void Sudoku::MarcarColumna(int col, int num) {
  for (int i = 0; i < 9; i++)
    if (!sud[i][col].Resolta())
      sud[i][col].MarcarFals(num);
}

void Sudoku::MarcarQuadrat(int fil, int col, int num) {
  int x = col / 3;
  int y = fil / 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (!sud[i + (3 * y)][j + (3 * x)].Resolta())
	sud[i + (3 * y)][j + (3 * x)].MarcarFals(num);
}

void Sudoku::NetejarFiles() {
  int cnt, tmp;
  bool resolt;
  for (int fil = 0; fil < 9; fil++) {
    for (int num = 1; num < 10; num++) {
      cnt = 0;
      resolt = false;
      for (int i = 0; i < 9; i++) {
	if (!sud[fil][i].Resolta()) {
	  if (sud[fil][i].EsPosible(num)) {
	    cnt++;
	    tmp = i;
	  }
	}
	else {
	  if (num == sud[fil][i].Numero())
	    resolt = true;
	}
      }
      if (cnt == 1 && !resolt) {
	sud[fil][tmp] = num;
	MarcarFila(fil, num);
	MarcarColumna(tmp, num);
	MarcarQuadrat(fil, tmp, num);
      }
    }
  }
}

void Sudoku::NetejarColumnes() {
  int cnt, tmp;
  bool resolt;
  for (int col = 0; col < 9; col++) {
    for (int num = 1; num < 10; num++) {
      cnt = 0;
      resolt = false;
      for (int i = 0; i < 9; i++) {
	if (!sud[i][col].Resolta()) {
	  if (sud[i][col].EsPosible(num)) {
	    cnt++;
	    tmp = i;
	  }
	}
	else {
	  if (num == sud[i][col].Numero())
	    resolt = true;
	}
      }
      if (cnt == 1 && !resolt) {
	sud[tmp][col] = num;
	MarcarColumna(col, num);
	MarcarFila(tmp, num);
	MarcarQuadrat(tmp, col, num);
      }
    }
  }
}

void Sudoku::NetejarQuadrats() {
  int cnt, tmp_fil, tmp_col, x, y;
  bool resolt;
  for (int fil = 0; fil < 9; fil++)
    for (int col = 0; col < 9; col++) {
      x = col / 3;
      y = fil / 3;
      for (int num = 1; num < 10; num++) {
	cnt = 0;
	resolt = false;
	for (int i = 0; i < 3; i++)
	  for (int j = 0; j < 3; j++) {
	    if (!sud[i + (3 * y)][j + (3 * x)].Resolta()) {
	      if (sud[i + (3 * y)][j + (3 * x)].EsPosible(num)) {
		cnt++;
		tmp_fil = i;
		tmp_col = j;
	      }
	    }
	    else {
	      if (num == sud[i + (3 * y)][j + (3 * x)].Numero())
		resolt = true;
	    }
	  }
	if (cnt == 1 && !resolt) {
	  sud[tmp_fil + (3 * y)][tmp_col + (3 * x)] = num;
	  MarcarQuadrat(fil, col, num);
	  MarcarFila(tmp_fil + (3 * y), num);
	  MarcarColumna(tmp_col + (3 * x), num);
	}
      }
    }
}

void Sudoku::ParellesFiles() {
  int cnt, tmp1, tmp2;
  vector <int> vectoret;
  bool trobat;
  for (int fil = 0; fil < 9; fil++) {
    cnt = 0;
    vectoret.resize(0);
    tmp1 = tmp2 = -1;
    trobat = false;
    for (int i = 0; i < 9 && !trobat; i++)
      if (!sud[fil][i].Resolta())
	for (int j = (i + 1); j < 9 && !trobat; j++)
	  if (sud[fil][i] == sud[fil][j]) {
	    trobat = true;
	    tmp1 = i;
	    tmp2 = j;
	  }
    if (trobat) {
      for (int num = 1; num < 10; num++) {
	if (sud[fil][tmp1].EsPosible(num)) {
	  vectoret.push_back(num);
	  cnt++;
	}
      }
    }
    if (cnt == 2) {
      for (int i = 0; i < 9; i++)
	if ((!sud[fil][i].Resolta()) && (i != tmp1) && (i != tmp2)) {
	  sud[fil][i].MarcarFals(vectoret[0]);
	  sud[fil][i].MarcarFals(vectoret[1]);
	}
    }
  }
}

void Sudoku::ParellesColumnes() {
  int cnt, tmp1, tmp2;
  vector <int> vectoret;
  bool trobat;
  for (int col = 0; col < 9; col++) {
    cnt = 0;
    vectoret.resize(0);
    tmp1 = tmp2 = -1;
    trobat = false;
    for (int i = 0; i < 9 && !trobat; i++)
      if (!sud[i][col].Resolta())
	for (int j = (i + 1); j < 9 && !trobat; j++)
	  if (sud[i][col] == sud[j][col]) {
	    trobat = true;
	    tmp1 = i;
	    tmp2 = j;
	  }
    if (trobat) {
      for (int num = 1; num < 10; num++) {
	if (sud[tmp1][col].EsPosible(num)) {
	  vectoret.push_back(num);
	  cnt++;
	}
      }
    }
    if (cnt == 2) {
      for (int i = 0; i < 9; i++)
	if ((!sud[i][col].Resolta()) && (i != tmp1) && (i != tmp2)) {
	  sud[i][col].MarcarFals(vectoret[0]);
	  sud[i][col].MarcarFals(vectoret[1]);
	}
    }
  }
}

void Sudoku::ParellesQuadrats() {
  int i_ini, j_ini, cnt, tmp1, tmp2, tmp3, tmp4;
  vector <int> vectoret;
  bool trobat;
  for (int qua = 0; qua < 9; qua++) {
    i_ini = (qua / 3) * 3;
    j_ini = (qua % 3) * 3;
    cnt = 0;
    vectoret.resize(0);
    tmp1 = tmp2 = tmp3 = tmp4 = -1;
    trobat = false;
    for (int i = i_ini; ((i < 3 + i_ini) && (!trobat)); i++)
      for (int j = j_ini; ((j < 3 + j_ini) && (!trobat)); j++)
	if (!sud[i][j].Resolta()) 
	  for (int k = i; ((k < 3 + i_ini) && (!trobat)); k++)
	    for (int l = j; ((l < 3 + j_ini) && (!trobat)); l++)
	      if ((!((k == i) && (l == j))) && (sud[i][j] == sud[k][l])) {
		trobat = true;
		tmp1 = i;
		tmp2 = j;
		tmp3 = k;
		tmp4 = l;
	      }
    if (trobat)
      for (int num = 1; num < 10; num++)
	if (sud[tmp1][tmp2].EsPosible(num)) {
	  vectoret.push_back(num);
	  cnt++;
	}
    if (cnt == 2)
      for (int m = i_ini; m < 3 + i_ini; m++)
	for (int n = j_ini; n < 3 + j_ini; n++)
	  if ((!sud[m][n].Resolta()) && (!((m == tmp1) && (n == tmp2))) && (!((m == tmp3) && (n == tmp4)))) {
	    sud[m][n].MarcarFals(vectoret[0]);
	    sud[m][n].MarcarFals(vectoret[1]);
	  }
  }
}

void Sudoku::Agranar() {
  int i_ini, j_ini;
  vector <int> vec1, vec2;
  for (int qua = 0; qua < 9; qua++) {
    i_ini = (qua / 3) * 3;
    j_ini = (qua % 3) * 3;
    vec1.resize(0);
    vec2.resize(0);
    for (int k = 0; k < 9; k++)
      vec1.push_back(k + 1);
    for (int i = i_ini; i < 3 + i_ini; i++)
      for (int j = j_ini; j < 3 + j_ini; j++)
	if (sud[i][j].Resolta()) 
	  vec1[sud[i][j].Numero() - 1] = 0;
    for (int k = 0; k < 9; k++)
      if (vec1[k] != 0)
	vec2.push_back(vec1[k]);
    for (unsigned int h = 0; h < vec2.size(); h++) {
      vector <int> fil, col;
      fil.resize(0);
      col.resize(0);
      for (int i = i_ini; i < 3 + i_ini; i++)
	for (int j = j_ini; j < 3 + j_ini; j++)
	  if ((!sud[i][j].Resolta()) && (sud[i][j].EsPosible(vec2[h]))) {
	    fil.push_back(i);
	    col.push_back(j);
	  }
      bool filSi = true, colSi = true;
      for (unsigned int m = 1; m < fil.size(); m++)
	filSi = filSi && (fil[0] == fil[m]);
      for (unsigned int m = 1; m < col.size(); m++)
	colSi = colSi && (col[0] == col[m]);
      if (filSi) {
	for (int n = 0; n < 9; n++) {
	  bool tmp = false;
	  for (unsigned int o = 0; o < col.size(); o++)
	    tmp = tmp || (n == col[o]);
	  if ((fil.size() > 0) && (!sud[fil[0]][n].Resolta()) && (!tmp))
	    sud[fil[0]][n].MarcarFals(vec2[h]);
	}
      }
      if (colSi) {
	for (int n = 0; n < 9; n++) {
	  bool tmp = false;
	  for (unsigned int o = 0; o < fil.size(); o++)
	    tmp = tmp || (n == fil[o]);
	  if ((col.size() > 0) && (!sud[n][col[0]].Resolta()) && (!tmp))
	    sud[n][col[0]].MarcarFals(vec2[h]);
	}      
      }
    }
  }
}

void Sudoku::MinimesPosibilitats(int & fil, int & col) const {
  int min = 10, cont = 0;
  fil = col = -1;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (!sud[i][j].Resolta()) {
	cont = 0;
	for (int num = 1; num < 10; num++)
	  if (sud[i][j].EsPosible(num)) {
	      cont++;
	    }
	if (cont < min) {
	  fil = i;
	  col = j;
	  min = cont;
	}
      }
}

// Mètodes públics

Sudoku::Sudoku() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      sud[i][j] = 0;
}

Sudoku::Sudoku(const Sudoku & ori) {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      sud[i][j] = ori.sud[i][j];
}

Sudoku::Sudoku(const char *fit) {
  ifstream f;
  f.open(fit);
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      sud[i][j] = ((int) f.get()) - 48;
  f.close();
}

Sudoku & Sudoku::operator=(const Sudoku & ori) {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      sud[i][j] = ori.sud[i][j];
  return (*this);
}

Sudoku & Sudoku::operator=(const char * fit) {
  ifstream f;
  f.open(fit);
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      sud[i][j] = ((int) f.get()) - 48;
  f.close();
  return (*this);
}

bool Sudoku::operator!=(const Sudoku & sudo) const {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if ((*this).sud[i][j] != sudo.sud[i][j])
	return true;
  return false;
}

bool Sudoku::operator==(const Sudoku & sud) const {
  return !(operator!=(sud));
}

void Sudoku::Imprimir(ostream & eix) const {
  for (int i = 0; i < 9; i++) {
    if (i == 0 || i == 3 || i == 6)
      eix << "+-----------------------+" << endl;
    for (int j = 0; j < 9; j++) {
      if (j == 0)
	eix << "| " ;
      eix << sud[i][j];
      if (j == 2 || j == 5 || j == 8)
	eix << " | ";
      else
	eix << " ";
    }
    eix << endl;
  }
  eix << "+-----------------------+" << endl;
}

void Sudoku::ImprimirPosibles(int fil, int col) const {
  vector <int> posibles;
  for (int num = 1; num < 10; num++)
    if (sud[fil][col].EsPosible(num))
      posibles.push_back(num);
  cout << "(" << fil << ", " << col << ") ->";
  for (unsigned int i = 0; i < posibles.size() - 1; i++)
    cout << " " << posibles[i] << ",";
  cout << " " << posibles[posibles.size() - 1]<< endl;

}

bool Sudoku::Resolt() const {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (!sud[i][j].Resolta())
	return false;
  return true;
}


int Sudoku::Resoldre() {
  int num, ret = 0;
  Sudoku aux1;
  if(!Resoluble())
    return -1;
  if (!Resolt()) {
    while ((*this) != aux1) {
      aux1 = (*this);
      for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
	  if (sud[i][j].Resolta()) {
	    num = sud[i][j].Numero();
	    MarcarFila(i, num);
	    MarcarColumna(j, num);
	    MarcarQuadrat(i, j, num);
	  }
    }
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      NetejarFiles();
    } while ((*this) != aux1);
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      NetejarColumnes();
    } while ((*this) != aux1);  
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      NetejarQuadrats();
    } while ((*this) != aux1);  
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      ParellesFiles();
    } while ((*this) != aux1);  
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      ParellesColumnes();
    } while ((*this) != aux1);  
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      ParellesQuadrats();
    } while ((*this) != aux1);
  }
  if (!Resolt()) {
    do {
      aux1 = (*this);
      Agranar();
    } while ((*this) != aux1);
  }
  if (!Resolt()) {
    ret++;
    int fil, col;
    vector <int> posibles;
    MinimesPosibilitats(fil, col);
    for (int nom = 1; nom < 10; nom++)
      if (sud[fil][col].EsPosible(nom))
	posibles.push_back(nom);
    vector <Sudoku> random;
    random.resize(posibles.size());
    for (unsigned int ind = 0; ind < posibles.size(); ind++) {
      random[ind] = (*this);
      random[ind].sud[fil][col] = posibles[ind];
      ret += random[ind].Resoldre();
      if (random[ind].Correcte())
      	(*this) = random[ind];
    }
    random.resize(0);
  }
  return ret;
}

bool Sudoku::Resoluble() const {
  int cont = 0;
  for (int i = 0; ((i < 9) && (cont < 16)); i++)
    for (int j = 0; ((j < 9) && (cont < 16)); j++)
      if (sud[i][j].Resolta())
	cont++;
  if (cont < 16)
    return false;
  return true;
}

bool Sudoku::Correcte() const {
  if (!Resolt())
    return false;
  int cont_fil, cont_col = 0;
  for (int i = 0; i < 9; i++) {
    cont_fil = cont_col = 0;
    for (int j = 0; j < 9; j++) {
      cont_fil += sud[i][j].Numero();
      cont_col += sud[j][i].Numero();
    }
    if ((cont_fil != 45) || (cont_col != 45))
      return false;
  }
  return true;
}

ostream & operator<< (ostream & eix, const Sudoku & sudo) {
  sudo.Imprimir(eix);
  return eix;
}
