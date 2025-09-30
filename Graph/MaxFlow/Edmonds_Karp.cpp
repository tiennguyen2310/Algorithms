/*
Max-Flow Implementation: Edmonds-Karp Algorithm using BFS
Run-time: O(|E|^2 |V|)
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair <int, int>

int n, m, s, t;
const int Sz = 1002;
vector <int> adj[Sz];
int capacity[Sz][Sz];
int used[Sz][Sz];
int trace[Sz];

void bfs(){
    for(int i = 1; i <= n; i++) trace[i] = 0;

    trace[s] = -1;
    queue <int> q;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(trace[v]) continue;
            
            // if there's still a positive flow able to pass by
            assert(capacity[u][v] >= used[u][v]);
            if(capacity[u][v] > used[u][v]){
                trace[v] = u;
                q.push(v);
            }
        }
    }
}

int increaseFlow(){
    int res = 1e9;
    int v = t;
    while(v != s){
        int u = trace[v];
        res = min(res, capacity[u][v] - used[u][v]);
        v = u;
    }
    
    v = t;
    while(v != s){
        int u = trace[v];
        used[u][v] += res;
        used[v][u] -= res;
        v = u;
    }

    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;
    for(int i = 1, u, v, c; i <= m; i++){
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u); // reverse edge
        capacity[u][v] = c;
    }

    int maxFlow = 0;

    do{
        // increase flow
        bfs();
        if(trace[t]) maxFlow += increaseFlow();
    } while(trace[t]);

    cout << maxFlow;
    return 0;
}
