#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

// find_by_order(k): returns an iterator to the k-th element (0-indexed)
// order_of_key(k): returns the number of elements strictly less than k
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

  vector<pair<pair<ll, ll>, ll>> customers(n);

  for (int i = 0; i < n; i++) {
    cin >> customers[i].first.first >> customers[i].first.second;
    customers[i].second = i;
  }
  sort(all(customers));

  vi roomAssigned(n, -1);
  ll roomId = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
      rooms;

  for (int i = 0; i < n; i++) {
    if (rooms.empty()) {
      roomId++;
      roomAssigned[customers[i].second] = roomId;
      rooms.push({customers[i].first.second, roomId});
    } else {
      if (rooms.top().first < customers[i].first.first) {
        auto x = rooms.top();
        rooms.pop();
        roomAssigned[customers[i].second] = x.second;
        rooms.push({customers[i].first.second, x.second});
      } else {
        roomId++;
        roomAssigned[customers[i].second] = roomId;
        rooms.push({customers[i].first.second, roomId});
      }
    }
  }

  cout << roomId << endl;
  for (auto i : roomAssigned)
    cout << i << ' ';
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
