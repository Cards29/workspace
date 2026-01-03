#include <vector>

std::vector<long long> primeFactors(long long n) {
  std::vector <long long> fact;

  if (n % 2 == 0) fact.push_back(2);
  while (n % 2 == 0) n /= 2;

  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0){
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  }

  if (n > 1) fact.push_back(n);

  return fact;
}