int tin[mxn], tout[mxn], up[mxn][20], T;

void dfs(int v, int p) {
    tin [v] = ++T;
    up[v][0] = p;
    for (int i = 1; i <= 19; ++i) 
        up[v][i] = up[up[v][i-1]][i-1];

    for (const int x : adj[v]) {
        if (x != p) {
            dfs(x, v);
        }
    }

    tout[v] = ++T;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;

    if (is_ancestor(v, u))
        return v;

    for (int i = 16; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
