int h[MAX_N + 1];

void precalc(int u, int p = -1) {
  for (int v : adj[u])
    if (v != p) {
      precalc(v, u);
      h[u] = max(h[u], h[v] + 1);
    }
}

int d[MAX_N + 1],
    p[MAX_N + 1][MAX_K + 1];

int lim,
    id[MAX_N + 1];
vector <int> node[MAX_N + 1];

void dfs(int u) {
  for (int k = 1; k <= __lg(d[u]); k++) {
    int parent = p[u][k - 1];
    p[u][k] = p[parent][k - 1]; 
  }

  id[u] = lim;
  node[lim].push_back(u);

  int nxt = -1,
      nxt_h = -1;

  for (int v : adj[u]) {
    if (v == p[u][0])
      continue;

    if (h[v] > nxt_h) {
      nxt = v,
      nxt_h = h[v];
    }
  }

  if (nxt == -1)
    return;

  d[nxt] = d[u] + 1;
  p[nxt][0] = u;
  dfs(nxt);

  for (int v : adj[u]) {
    if (v == p[u][0] || v == nxt)
      continue;

    d[v] = d[u] + 1;
    p[v][0] = u;

    lim++;

    dfs(v);
  }
}

int get_lca(int u, int v) {
  if (d[u] < d[v]) {
    swap(u, v);
  }

  while (d[u] > d[v]) {
    int k = __lg(d[u] - d[v]);
    u = p[u][k];
  }

  if (u == v)
    return u;

  for (int k = __lg(d[u]); k >= 0; k--) 
    if (p[u][k] != p[v][k]) {
      u = p[u][k];
      v = p[v][k];
    }

  return p[u][0];
}
