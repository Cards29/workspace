#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()

// -----------------Soln-----------------
void solve() {
  ll n, cnt = 0;
  cin >> n;

  vi v(n);
  map<ll, ll> m;
  for (auto &i : v) {
    cin >> i;
  }

  for (int l = 0, r = 0; r < n; r++) {
    while (m[v[r]]) {
      m[v[l]] = 0;
      l++;
    }
    m[v[r]]++;
    cnt += r - l + 1;
  }
  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}
