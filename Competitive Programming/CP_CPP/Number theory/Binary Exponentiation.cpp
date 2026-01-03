#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, const ll mod) {
  ll result = 1;
  while (b > 0) {
    if (b % 2) result = (result * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return result;
}


ll powerRecursive(ll a, ll b, const ll mod) {
  if (b == 0) return 1;
  ll temp = powerRecursive(a, b/2, 1e9 + 7);
  ll result = (temp * temp) % mod;
  if (b % 2) result = (result * a) % mod; 
  return result;
}

//================actual code starts from here===========================================
void solve() {
  cout << power(100, 3, 1e9 + 7);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}