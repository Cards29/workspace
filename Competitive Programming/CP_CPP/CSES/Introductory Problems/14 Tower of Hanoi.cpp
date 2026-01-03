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

ll power(ll a, ll b){
  ll result = 1;
  while (b > 0) {
    if (b % 2) result *= a;
    a *= a;
    b /= 2;
  }

  return result;
}

void soln(ll left, ll middle, ll right, ll n) {
  if (n == 0) {
    return;
  }

  vector<pair<ll, ll>> ans, ans1;
  soln(left, right, middle, n - 1);

  ans.push_back({left, right});
  cout << left << ' ' << right << '\n';

  soln(middle, left, right, n - 1);
}

void solve() {
  ll n;
  cin >> n;

  cout << (1 << n) - 1 << endl;

  soln(1, 2, 3, n);
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