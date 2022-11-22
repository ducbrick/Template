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

  bool many_children = false;

  for (int v : adj[u]) {
    if (v == p[u][0])
      continue;

    d[v] = d[u] + 1;
    p[v][0] = u;

    if (many_children) {
      lim++;
    }

    dfs(v);
    many_children = true;
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