#include <iostream>
using namespace std; // Using the entire std namespace

int main() {
  int x = 42; // Example value
  int i = 3;  // Example bit position
  int j = 1;  // Another example bit position
  // Arithmetic operations
  cout << "1 << i (pow(2, i)): " << (1 << i) << endl;
  cout << "x << i (x * pow(2, i)): " << (x << i) << endl;
  cout << "x >> i (floor(x / pow(2, i))): " << (x >> i) << endl;
  cout << "x & ((1 << i) - 1) (x % pow(2, i)): " << (x & ((1 << i) - 1)) << endl;
  // Bitmask construction
  cout << "(1 << i) (bitmask with only i-th bit on): " << (1 << i) << endl;
  cout << "(1 << i) | (1 << j) (bitmask with only i-th and j-th bits on): " << ((1 << i) | (1 << j)) << endl;
  cout << "~0 (bitmask with all bits on): " << (~0) << endl;
  cout << "~(1 << i) (bitmask with all bits on except i-th bit off): " << (~(1 << i)) << endl;
  cout << "-1 ^ (1 << i) (same as above): " << (-1 ^ (1 << i)) << endl;
  // Bit operations on variable x
  cout << "Original x: " << x << endl;
  cout << "x | (1 << i) (turn on the i-th bit of x): " << (x | (1 << i)) << endl;
  cout << "x & ~(1 << i) (turn off the i-th bit of x): " << (x & ~(1 << i)) << endl;
  cout << "x ^ (1 << i) (toggle (flip) the i-th bit of x): " << (x ^ (1 << i)) << endl;
  cout << "(x >> i) & 1 (check if the i-th bit of x is on): " << ((x >> i) & 1) << endl;
  // Tricks and built-in functions
  long long x_ll = 10; // Example for __builtin_popcountll
  cout << "x & -x (isolate the lowest bit that is on (LSB)): " << (x & -x) << endl;
  cout << "__builtin_popcountll(" << x_ll << ") (count number of bits that are on): " << __builtin_popcountll(x_ll) << endl;
  return 0;
}