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

void solve() {
  string str;
  cin >> str;

  vector<string> ans;

  sort(str.begin(), str.end());
  do{
    ans.push_back(str);
  }while(next_permutation(str.begin(), str.end()));

  cout << ans.size() << endl;
  for (string s : ans) cout << s << endl;

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