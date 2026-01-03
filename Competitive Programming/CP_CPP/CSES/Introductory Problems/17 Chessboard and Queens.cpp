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

// O(N! * N), but way faster in practice because of the diagonals

ll cnt;
char grid[8][8];
vector<bool> rowAttacked(8, 0); 
vector<bool> diag1 (15, 0); 
vector<bool> diag2 (15, 0);

// normal solution
// void f(int col) {
//   if (col == 8) {
//     cnt++;
//     return;
//   }

//   for (int row = 0; row < 8; row++) {
//     if (grid[row][col] == '.') {
//       bool attacked = false;

//       for (int c = 0; c < col; c++) {
//         if (grid[row][c] == 'Q') {
//           attacked = true;
//           break;
//         }
//       }

//       for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
//         if (grid[r][c] == 'Q') {
//           attacked = true;
//           break;
//         }
//       }

//       for (int r = row + 1, c = col - 1; r < 8 && c >= 0; r++, c--) {
//         if (grid[r][c] == 'Q') {
//           attacked = true;
//           break;
//         }
//       }

//       if (!attacked) {
//         grid[row][col] = 'Q';
//         f(col + 1);
//         grid[row][col] = '.';
//       }
//     }
//   }
// }

// the optimized version
void f(int col) {
  if (col == 8) {
    cnt++;
    return;
  }

  for (int row = 0; row < 8; row++) {
    if (grid[row][col] == '.' && !rowAttacked[row] && !diag1[row + col] && !diag2[row - col + 7]) {
      
      grid[row][col] = 'Q';
      rowAttacked[row] = diag1[row + col] = diag2[row - col + 7] = true;

      f(col + 1);
      
      grid[row][col] = '.';
      rowAttacked[row] = diag1[row + col] = diag2[row - col + 7] = false;

    }
  }
}

void solve() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> grid[i][j];
    }
  }

  f(0);

  cout << cnt << endl;

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