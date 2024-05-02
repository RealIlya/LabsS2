#include <iostream>

void func(char *n, int len, int k) {
  if (len) {
    if (*n > 47 && *n < 56) {
      if (k) {
        if (*n != 55) {
          k = 0;
          *n += 1;
          func(n - 1, len - 1, k);
        } else {
          *n = 48;
          func(n - 1, len - 1, k);
        }
      }
    } else {
      std::cout << "incorrect number format in the octal number system";
      exit(0);
    }
  }
}

int main() {
  std::string n;
  std::cout << "input an octal number >> ";
  std::cin >> n;
  int len = n.length() + 2;
  char *x = new char(len);
  x[0] = 48;
  for (int i = 1; i < len - 1; i++) x[i] = n[i - 1];
  x[len - 1] = 0;
  if (x) {
    func(&x[len - 2], len - 1, 1);
    std::cout << x;
    delete x;
  }
}