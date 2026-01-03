#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++) 
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == INF) continue;    
            ll dik = dist[i][k];
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == INF) continue;
                ll nd = dik + dist[k][j];
                if (nd < dist[i][j]) 
                    dist[i][j] = nd;
            }
        }
    }

    bool hasNegCycle = false;
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            hasNegCycle = true;
            break;
        }
    }

    if (hasNegCycle) {
        cout << "Graph contains a negative-weight cycle\n";
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) 
                    cout << "INF ";
                else 
                    cout << dist[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
