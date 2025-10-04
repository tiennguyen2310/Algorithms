#include <bits/stdc++.h>

using namespace std;

int n, m;
const int Sz = 1e4 + 2;
vector <int> adj[Sz + 1];
vector <int> r_adj[Sz + 1];
bool vis[Sz + 1];
vector <int> vec; // visiting order 1st dfs

void dfs1(int u){
    vis[u] = true;
    for(int v : r_adj[u]){
        if(!vis[v]) dfs1(v);
    }
    vec.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs2(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        r_adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs1(i);
    }

    for(int i = 1; i <= n; i++) vis[i] = false;
    int res = 0;

    for(int i = (int)vec.size() - 1; i >= 0; i--){
        if(!vis[vec[i]]){
            res++;
            dfs2(vec[i]);
        }
    }

    cout << res;
    return 0;
}
