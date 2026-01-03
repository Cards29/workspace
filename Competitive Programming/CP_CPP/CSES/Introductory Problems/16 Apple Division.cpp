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
ll n;
ll v[21];
ll mn = LLONG_MAX;

void f(int i, ll x, ll y) {
  if (i == n) {
    mn = min(mn, abs(x - y));
    return;
  }

  f(i + 1, x + v[i], y);
  f(i + 1, x, y + v[i]);
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) cin >> v[i];

  f(0, 0, 0);
  cout << mn << endl;

  // This is a bitmask approach
  // for (int mask = 0; mask < (1 << n); mask++) {
  //   ll diff = 0;
  //   for (int i = 0; i < n; i++) {
  //     if (mask & (1 << i)) {
  //       diff += v[i];
  //     }
  //     else {
  //       diff -= v[i];
  //     }
  //   }
  //   mn = min(mn, abs(diff));
  // }

  // cout << mn;
  
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