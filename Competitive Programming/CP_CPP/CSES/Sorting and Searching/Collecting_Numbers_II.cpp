#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()

//-----------------Soln-----------------

/*
explaination:

### Reminder: what `ans` means

* `ans` = number of “rounds” needed.
* A “round” is basically caused whenever some number $i$ comes **after** $i+1$ in the array.
* So `ans` = `1 + count of all pairs (i, i+1) where positionOf[i] > positionOf[i+1]`.

---

### The problem after a swap

When you swap two positions in the array:

* Most pairs `(i, i+1)` are completely unaffected.
* Only the pairs that involve the two swapped numbers can change.
  Example: If you swap numbers 3 and 7, only pairs `(2,3)`, `(3,4)`, `(6,7)`, `(7,8)` are in danger of flipping their order.

That’s why the code makes a small set `s` that contains at most **four pairs**:

* `(value_at_l, value_at_l + 1)`
* `(value_at_r, value_at_r + 1)`
* `(value_at_l - 1, value_at_l)`
* `(value_at_r - 1, value_at_r)`
  (ignoring invalid ones like when the number is `1` or `n`).

So, instead of rechecking all $n-1$ pairs after every swap, the program only checks **these 4 possible pairs**.

---

### Step-by-step update process

1. **Before swapping**

   * For each pair `(x, y)` in `s`, check if `positionOf[x] > positionOf[y]`.
   * If yes, that pair is currently a “break” and has contributed `+1` to `ans`.
   * Subtract it now, because you’re about to change the array and the pair’s status may flip.

   👉 This removes the “old influence” of these pairs.

---

2. **Do the swap itself**

   * Swap the elements at positions `l` and `r`.
   * Update their positions in `positionOf`.
     Example: if value `5` is now at index `10`, then `positionOf[5] = 10`.

   👉 Now the array and `positionOf` reflect the new situation.

---

3. **After swapping**

   * For each pair `(x, y)` in `s`, check again: is `positionOf[x] > positionOf[y]` now?
   * If yes, this pair has become a “break,” so add `+1` back to `ans`.

   👉 This adds the “new influence” of these pairs.

---

4. **Print the answer**

   * `ans` now holds the correct updated number of rounds for the new array.
   * Clear the set `s` for the next query.

---

### Why is this fast?

* Each swap only affects at most 4 pairs.
* For each pair, you do **two checks**: once before the swap, once after.
* So per swap you do at most ~8 comparisons.
* That’s $O(1)$ work per swap.
* Since there are $m$ swaps, the whole program runs in $O(n + m)$ time.

---

✅ In short:
Instead of recalculating the entire number of rounds after every swap, the code **surgically removes the old contribution of the affected pairs, does the swap, and then adds back their new contribution**.

rahinur: first we decrement because their position will chane, 
        next, after swaped, we check again, if some numbers' position is still
        > than num + 1, we again increment count, so we get the correct result
*/ 
void solve() {
  ll n, m;
  cin >> n >> m;

  vi values(n + 1, 0), positionOf(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> values[i];
    positionOf[values[i]] = i;
  }

  ll ans = 1;
  for (int i = 1; i < n; i++) {
    ans += positionOf[i] > positionOf[i + 1];
  }

  ll l, r;
  set <pair <ll, ll>> s;
  while (m --> 0) {
    cin >> l >> r;
    if (values[l] < n) 
      s.insert({values[l], values[l] + 1});
    if (values[r] < n) 
      s.insert({values[r], values[r] + 1});
    if (values[l] > 1) 
      s.insert({values[l] - 1, values[l]});
    if (values[r] > 1) 
      s.insert({values[r] - 1, values[r]});

    for (auto [x, y] : s) {
      ans -= positionOf[x] > positionOf[y];
    }

    swap(values[l], values[r]);

    positionOf[values[l]] = l;
    positionOf[values[r]] = r;

    for (auto [x, y] : s) {
      ans += positionOf[x] > positionOf[y];
    }

    cout << ans << endl;
    s.clear();
  }

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
