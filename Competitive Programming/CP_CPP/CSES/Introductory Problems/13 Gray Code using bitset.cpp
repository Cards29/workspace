#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define yes cout << "YES\n"
#define no cout << "NO\n"

//================actual code starts from here================

ll power(ll a, ll b) {
  ll result = 1;
  while (b > 0) {
    if (b % 2) result *= a;
    a *= a;
    b /= 2;
  }

  return result;
}


void solve() {
  ll n;
  cin >> n;

  ll b = power(2, n), temp;
  vi v;

  for (ll a = 0; a < b; a++) {
    temp = a;
    v.push_back((temp ^ (temp >> 1)));
  }

  bitset<16> b1;
  string ans = "";
  // ll diz = power(10, n);
  temp = n;
  for (auto j : v) {
    b1 = j;

    for (int i = 0; i < n; i++) cout << b1[i];
    cout << endl;
  }


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  ll t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    // cout << "Case " << i << ": ";
    solve();
  }

  return 0;
}