#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define all(v) v.begin(), v.end()

// -----------------Soln-----------------

void solve() {
  ll n, q;
  cin >> n >> q;

  vi v(n), b(2 * n);
  for (auto &i : v)
    cin >> i;

  for (int i = 0; i < 2 * n; i++) {
    b[i] = v[i % n];
  }

  for (int i = 2 * n - 2; i >= 0; i--) {
    b[i] += b[i + 1];
  }

  ll t, rui_c = 0, c, l, r;
  while (q-- > 0) {
    cin >> t;

    if (t == 1) {
      cin >> c;
      rui_c = (rui_c + c) % n;
    } else {
      cin >> l >> r;
      ll l0 = l - 1;
      ll r0 = r;

      cout << b[l0 + rui_c] - b[r0 + rui_c] << endl;
    }
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
