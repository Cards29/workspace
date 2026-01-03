#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

/* ================ actual code starts here ================ */

void bfs(const vvi& adj, ll start) {
    vector<bool> visited(adj.size(), false);
    queue<ll> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        cout << node << " ";

        for (ll neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(const vvi& adj, ll node, vector<bool>& visited) {
    if (visited[node]) return;

    visited[node] = true;
    cout << node << " ";

    for (ll neighbor : adj[node]) {
        dfs(adj, neighbor, visited);
    }
}

void bfsMatrix(const vvi& adj, ll start) {
    ll n = adj.size();
    vector<bool> visited(n, false);
    queue<ll> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        cout << node << " ";

        for (ll i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfsMatrix(const vvi& adj, ll node, vector<bool>& visited) {
    if (visited[node]) return;

    visited[node] = true;
    cout << node << " ";

    for (ll i = 0; i < adj.size(); i++) {
        if (adj[node][i] == 1) {
            dfsMatrix(adj, i, visited);
        }
    }
}
