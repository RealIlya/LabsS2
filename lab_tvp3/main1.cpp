#include <iostream>

void theTuringMachine(char *number);

int main() {
  std::string n;
  std::cout << "input an octal number >> ";
  std::cin >> n;
  char number[n.length() + 2];
  number[0] = 48;
  for (size_t i = 0; i <= n.length(); i++) {
    number[i + 1] = n[i];
    if (!(n[i] > 47 && n[i] < 56) && n[i] != '\0') {
      std::cout << "incorrect number format in the octal number system";
      exit(EXIT_FAILURE);
    }
  }
  std::cout << number << std::endl;
  theTuringMachine(number);
  std::cout << number << std::endl;
  return 0;
}

void theTuringMachine(char *number) {
  size_t len = 0;
  // инвариант: len >= 0
  // предусловие: в числе есть цифры
  for (; number[len] != '\0'; len++)
    ;  // программа: len = len + 1;
       // постусловие: number[len] == '\0' (len-1 - кол-о цифр в числе)
  int count = 0;
  // инвариант: count >= 0
  // предусловие: последня цифра = 7
  for (int i = len - 1; number[i] - 48 == 7; i--) count++;
  // программа: если цифра = 7, то count увеличивается на 1
  //  постусловие: текущая цифра не равна 7
  int k = 1;
  // инвариант: число = цифра1, ..., цифраi, ..., цифра(len-1),
  // где i = len-count-1,
  // цифраi = (цифра меньше 7) + !k, а цифра(i+1), ..., цифра(len+1) равны 7 * k
  // предусловие: счетчик не на цифре 7
  for (size_t i = len - count - 1; i < len; i++) {
    // текущая цифра = цифра*k + k
    // программа: если текущая цифра не равна семи, то
    // k = 0;
    number[i] = (number[i] - 48) * k + k + 48;
    if (number[i] - 48 != 7) k = 0;
  }
  // постусловие: счетчик вышел за пределы цифр числа
}
