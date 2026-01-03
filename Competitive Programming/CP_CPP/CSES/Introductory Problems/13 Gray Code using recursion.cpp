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

vector<string> answer(ll n) {
  if (n == 1) {
    return {"0", "1"};
  }

  vector<string> a = answer(n - 1);
  vector<string> b = a;
  reverse(b.begin(), b.end());

  a.insert(a.end(), b.begin(), b.end());

  return a;
}

void solve() {
  ll n;
  cin >> n;

  vector<string> ans = answer(n);

  for (string& i : ans) cout << i << '\n';



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