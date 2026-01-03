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
ll cnt[26];
vector<string> ans;

// O(N! * (N + 26))
void build(string s) {
  if ((int)s.size() == n) {
    ans.push_back(s);
    return;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 0) {
      cnt[i]--;
      build(s + char('a' + i));
      cnt[i]++;
    }
  }
}

void solve() {
  string str;
  cin >> str;

  n = (int)str.size();
  for (char i : str) cnt[i - 'a']++;

  build("");

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