#include <iostream>

int main() {
  unsigned long n = 0;
  std::cout << "Введите натуральное число ";
  std::cin >> n;
  size_t i = 1;
  int count = n & 1;
  // инвариант: count = a1 + a2 + ... + ai,
  // где ai = i-ый бит числа n
  // предусловие: i != 64
  for (; i < sizeof(long) * 8; i++) {
    count += ((n >> i) & 0b1);
  }  // постусловие: i == 64
  std::cout << "Является степенью двойки: ";
  (count == 1) ? std::cout << "YES" : std::cout << "NO";
}