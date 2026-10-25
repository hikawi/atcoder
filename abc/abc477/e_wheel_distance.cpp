#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> A(n), B(n); // A[i] = dist(i+1,i+2), B[i] = dist(i+1,n+1)
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];

    // build adjacency list?
    // oh god, is this too much memory?
    unordered_map<int, unordered_map<int, ll>> adj; // A -> adjlist of neighbors of A, B where B -> weight
    for (int i = 1; i <= n; i++) {
        adj[i][(i % n) + 1] = A[i - 1]; // forward
        adj[(i % n) + 1][i] = A[i - 1]; // backward
        adj[n + 1][i] = B[i - 1];       // mid forward
        adj[i][n + 1] = B[i - 1];       // mid backward
    }

    // putting the graph.
    // dijkstra from middle node (n+1) to ALL other nodes
    vector<ll> dist(n + 1, LONG_MAX);
    {
        dist[n] = 0;
        deque<pair<int, ll>> q;
        q.push_back(pair(n + 1, 0));

        while (!q.empty()) {
            auto cur = q.front();
            q.pop_front();

            // cout << ">> checking " << cur.first << " of dist " << cur.second << endl;
            for (const auto &[neighbor, cost] : adj[cur.first]) {
                ll alt = cur.second + cost;
                // cout << "neighbor=" << neighbor << ",alt=" << alt << ",cur=" << dist[neighbor - 1] << endl;
                if (alt < dist[neighbor - 1]) {
                    dist[neighbor - 1] = alt;
                    q.push_back(pair(neighbor, alt));
                }
            }
        }

        // show all the dist
        // for (auto l : dist)
        //     cout << l << " ";
        // cout << endl;
    }

    // n+1!!! AHHHHHHHHHHHH
    vector<ll> P(n + 1);
    for (int i = 1; i <= n; i++)
        P[i] = P[i - 1] + A[i - 1];

    // we have dist from middle to all other nodes now.
    // we can try doing queries.
    rep(i, q) {
        int a, b;
        cin >> a >> b;

        if (a == n + 1) {
            cout << dist[b - 1] << endl;
            continue;
        }
        if (b == n + 1) {
            cout << dist[a - 1] << endl;
            continue;
        }

        // path1 = min(a to mid) + min(mid to b)
        // path2 = a to b directly forwards
        // path3 = a to b directly backwards (or total - path2, ITS A FUCKING RING!!)
        ll path1 = dist[a - 1] + dist[b - 1];
        ll path2 = abs(P[a - 1] - P[b - 1]);

        cout << min(path1, min(path2, P[n] - path2)) << endl;
    }

    return 0;
}
