#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1e9 + 9;
const ll N = 1e5 + 10;
/* ================ actual code starts here ================ */

void solve() {
  ll n;
  cin >> n;

  vi v(n);
  for (auto &i : v)
    cin >> i;

  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    if (s.upper_bound(v[i]) == s.end()) {
      s.insert(v[i]);
    } else {
      auto it = s.upper_bound(v[i]);
      s.erase(it);
      s.insert(v[i]);
    }
  }

  cout << s.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}
