#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define yes cout << "Yes\n"
#define no cout << "No\n"

//================actual code starts from here================

void solve() {
  vi v = {1, 3, 6, 5};

  ll C = 8, n = 4;

  vvi dp(n + 1, vi(C + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int c = 0; c <= C; c++) {
      if (v[i - 1] <= c) 
        dp[i][c] = max(dp[i - 1][c], v[i - 1] + dp[i - 1][c - v[i - 1]]);
      else
        dp[i][c] = dp[i - 1][c];
    }
  }

  cout << "DP table : " << endl;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= C; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }

  vi selected;
  for (int i = n, c = C; i > 0; i--) {
    if (dp[i][c] != dp[i - 1][c]) {
      selected.push_back(v[i - 1]);
      c -= v[i - 1];
    }
  }

  cout << endl;
  cout << "Max possible = " << dp[n][C] << endl
     << "Selected elements = ";
  for (auto i : selected) cout << i << ' ';

  

  
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
