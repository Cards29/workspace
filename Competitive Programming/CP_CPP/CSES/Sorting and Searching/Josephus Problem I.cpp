#include <bits/stdc++.h>
#include <queue>
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
  ll n;
  cin >> n;

  queue<ll> q;
  for (int i = 1; i <= n; i++)
    q.push(i);

  while (q.size() > 1) {
    ll t = q.front();
    q.pop();

    cout << q.front() << ' ';
    q.pop();

    q.push(t);
  }

  cout << q.front();
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
