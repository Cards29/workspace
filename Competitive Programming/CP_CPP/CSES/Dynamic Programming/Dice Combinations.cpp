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

const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
ll dp[N];

ll rec(ll n) {
  if (dp[n] > 0)
    return dp[n] % mod;

  for (int i = 1; i <= 6; i++) {
    if (n - i >= 0) {
      if (dp[n - i] == 0)
        dp[n - i] = rec(n - i) % mod;

      dp[n] += (dp[n - i] + dp[i]) % mod;
    }
  }

  return dp[n] % mod;
}

void solve() {
  ll n;
  cin >> n;
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        dp[i] = (dp[i - j] + dp[i]) % mod;
      }
    }
  }

  cout << dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}
