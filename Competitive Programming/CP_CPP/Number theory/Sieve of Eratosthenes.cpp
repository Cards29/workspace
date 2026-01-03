#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll N = 10000003;
bitset <N> mark;
vi primes;

void sieve_of_eratosthenes() {
  primes.push_back(2);
  mark[0] = mark[1] = 1;
  int lim = sqrt(N * 1.0) + 2;

  for (int i = 4; i < N; i += 2) mark[i] = 1;
  for (int i = 3; i < N; i += 2) {
    if (!mark[i]) {
      primes.push_back(i);
      if (i <= lim) {
        for (int j = i * i; j < N; j += i) {
          mark[j] = 1;
        }
      }
    }
  }
}