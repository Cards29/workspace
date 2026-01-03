#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, const ll MOD) {
  ll result = 1;
  while (b > 0) {
    if (b % 2) result = (result * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return result;
}

// only when p is prime
ll inverse(ll a, ll p) {
  return power(a, p - 2, p);
}
