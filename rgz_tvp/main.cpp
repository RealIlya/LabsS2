#include <iostream>
#include <vector>

#define _TN_ 4
#define _PN_ 3

void initPetri(int **Dm, int **Dp, int *P) {
  // заполнение сети
  Dm[0][0] = 1;
  Dm[1][1] = 2;
  Dm[2][1] = 1;
  Dm[2][2] = 1;
  Dp[0][1] = 2;
  Dp[1][0] = 1;
  Dp[2][2] = 1;
  Dp[3][0] = 1;
  P[0] = 0;
  P[1] = 2;
  P[2] = 1;
}

void removePetri(int **Dm, int **Dp, int *R) {
  for (int i = 0; i < _TN_; i++) {
    delete Dm[i];
    delete Dp[i];
  }
  delete Dm;
  delete Dp;
  delete R;
}

bool isAviable(int **Dm, int *P, int T) {
  int key = 0;
  for (int i = 0; i < _PN_; i++)
    if (Dm[T][i] <= P[i] || P[i] == -1) key++;
  return key == _PN_;
}

void step(int **Dm, int **Dp, int *P, int T) {
  if (isAviable(Dm, P, T)) {
    std::cout << "(" << P[0] << ", " << P[1] << ", " << P[2] << ") -T" << T
              << "> (";
    for (int i = 0; i < _PN_; i++)
      P[i] = ((-Dm[T][i] + Dp[T][i] > 0 &&
               (Dm[T][0] > 0 || Dm[T][1] > 0 || Dm[T][2] > 0)) ||
              P[i] == -1)
                 ? -1
                 : P[i] - Dm[T][i] + Dp[T][i];
    std::cout << P[0] << ", " << P[1] << ", " << P[2] << ")\n";
  }
}

void Reachabilty(int **Dm, int **Dp, int *P) {
  int T;
  std::cout << "Введите переход который необходимо достигнуть: ";
  std::cin >> T;
  std::cout << "\n";
  int opt = 0;
  while (!isAviable(Dm, P, T)) {
    for (int i = 0; i < _TN_; i++) step(Dm, Dp, P, i);
    // попытка убрать зацикливание
    if (opt == 3) {
      step(Dm, Dp, P, 4);
      opt = 0;
    } else
      opt++;
  }
  if (isAviable(Dm, P, T)) step(Dm, Dp, P, T);
}

void printMatrixes(int **Dm, int **Dp) {
  std::cout << "\nD-:\n";
  for (int i = 0; i < _TN_; i++) {
    for (int j = 0; j < _PN_; j++) std::cout << Dm[i][j] << " ";
    std::cout << "\n";
  }
  std::cout << "\nD+:\n";
  for (int i = 0; i < _TN_; i++) {
    for (int j = 0; j < _PN_; j++) std::cout << Dp[i][j] << " ";
    std::cout << "\n";
  }
  std::cout << "\nD:\n";
  for (int i = 0; i < _TN_; i++) {
    for (int j = 0; j < _PN_; j++) std::cout << Dp[i][j] - Dm[i][j] << " ";
    std::cout << "\n";
  }
}

bool isPassed(int *P, std::vector<int *> *passed) {
  bool res = 0;
  int key = 0;
  for (size_t i = 0; i < passed->size(); i++) {
    key = 0;
    for (int j = 0; j < _PN_; j++)
      if (passed->at(i)[j] == P[j]) key++;
    if (key == _PN_) res = 1;
  }
  return res;
}

void removePt(int **Pt) {
  for (size_t j = 0; j < _TN_; j++) delete Pt[j];
  delete Pt;
}

void Tree(int **Dm, int **Dp, int *P, std::vector<int *> *passed) {
  int **Pt;
  Pt = new int *[_TN_];
  for (int j = 0; j < _TN_; j++) {
    Pt[j] = new int(_PN_);
    for (int i = 0; i < _PN_; i++) Pt[j][i] = 0;
  }
  for (int i = 0; i < _TN_ * 2; i++) {
    int n = i;
    i %= _TN_;
    if (isAviable(Dm, P, i)) {
      if (i == 3) P[0] = -1;
      for (int j = 0; j < _PN_; j++) {
        Pt[i][j] = P[j];
      }
      if (!isPassed(P, passed)) passed->push_back(P);
      step(Dm, Dp, Pt[i], i);
      if (!isPassed(Pt[i], passed)) Tree(Dm, Dp, Pt[i], passed);
    }
    i = n;
  }
}

int main() {
  int **Dm, **Dp, *P;
  Dm = new int *[_TN_];
  Dp = new int *[_TN_];
  P = new int[_PN_];
  for (int i = 0; i < _TN_; i++) {
    Dm[i] = new int[_PN_];
    Dp[i] = new int[_PN_];
    for (int j = 0; j < _PN_; j++) {
      Dm[i][j] = 0;
      Dp[i][j] = 0;
    }
  }
  initPetri(Dm, Dp, P);
  Reachabilty(Dm, Dp, P);
  initPetri(Dm, Dp, P);
  printMatrixes(Dm, Dp);
  std::vector<int *> *passed = new std::vector<int *>;
  std::cout << "\nДерево достижимости: \n";
  Tree(Dm, Dp, P, passed);
  removePetri(Dm, Dp, P);
  return 0;
}