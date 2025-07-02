/*
  Alhamdulillah
  I solved this problem without any help except from Allah,
  this is my first time solving a problem of this level.
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define cy cout << "Yes\n"
#define cn cout << "No\n"

const int MOD = 1e9 + 7;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

//================actual code starts from here================

void solve() {
  ll n, k, cnt = 0, input, mx = 0;
  bool b = 1;
  cin >> n;

  set<ll> s;
  vi freq(n + 1, 0), ans;
  for (int i = 0; i < n; i++) {
    cin >> input;
    freq[input]++;
    s.insert(input);
    mx = (mx >= input) * mx + (mx < input) * input;
  }

  ll mex = 0;
  for (int i = 0; i <= n; i++) {
    if (freq[i] == 0) {
      mex = i;
      break;
    }
  }

  vi ulta_pref(n + 1, 0), extra(n + 1, 0);

  ulta_pref[n] = freq[n];
  for (int i = n - 1; i >= 0; i--) {
    ulta_pref[i] = ulta_pref[i + 1] + freq[i];
  }

  extra[0] = (freq[0] > 1) ? (freq[0] - 1) : 0;
  for (int i = 1; i <= n; i++) {
    extra[i] = extra[i - 1] + ((freq[i] > 1) ? (freq[i] - 1) : 0);
  }


  ans.push_back(1);
  for (int k = 1; k < n; k++) {
    cnt = 0;
    b = 1;
    if (mex == n) {
      ans.push_back(n - k + 1);
      continue;
    }
    for (int i = 0; i < mex; i++) {
      if (freq[i] - k > 0) continue;
      else if (i < mex && freq[i] - k == 0){
        cnt++;
      }
      else if (freq[i] - k < 0) {
        if (i < mex && ulta_pref[i] - k >= 0) cnt++;
        else if (i == 0);
        else if (i < mex && extra[i - 1] + ulta_pref[i] - k >= 0) cnt++;
      }
    }
    if ((mex < mx && n - k >= mex)|| extra[n] - k >= 0) cnt++;
    ans.push_back(cnt);
  }
  ans.push_back(1);

  for (auto i : ans) cout << i << ' ';
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}