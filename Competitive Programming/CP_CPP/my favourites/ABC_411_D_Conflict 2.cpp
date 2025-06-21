#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define yes cout << "Yes\n"
#define no cout << "No\n"

const ll MOD = 1e9 + 7;
const ll N = 1e6 + 10;

// =========================actual code starts here=========================

void solve(ll tc) {
  ll n, q;
  cin >> n >> q;

  vector<vector<string>> queries;

  string t, p, s;
  for (int i = 0; i < q; i++) {
    cin >> t >> p;
    if (t == "1" || t == "3") queries.push_back({t, p});
    else {
      cin >> s;
      queries.push_back({t, p, s});
    }
  }

  ll index = 0, qq, pc;
  s = "";
  string ans = "";
  for (int i = q - 1; i >= 0; i--) {
    qq = stoll(queries[i][0]);
    pc = stoll(queries[i][1]);
    if (qq == 2) {
      s = queries[i][2];
      reverse(s.begin(), s.end());
    }
    else s = "";
    
    if (qq == 1 && index == pc) index = 0;
    else if (qq == 3 && index == 0) index = pc;
    else if (qq == 2 && index == pc) {
      ans += s;
    }
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;

}  

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    // cout << "Case " << i << ": ";
    solve(i);    
  }

  return 0;
}