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
  ll n, x;
  cin >> x >> n;

  vi v(n);
  for (auto &i : v)
    cin >> i;

  set<ll> s;
  multiset<ll> m;

  s.insert(0);
  s.insert(x);

  m.insert(x - 0);

  for (int i = 0; i < n; i++) {
    s.insert(v[i]);
    auto it = s.find(v[i]);

    int pre = *prev(it);
    int nex = *next(it);

    m.erase(m.find(nex - pre));

    m.insert(v[i] - pre);
    m.insert(nex - v[i]);

    cout << *m.rbegin() << ' ';
  }
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
