struct Dsu{
  vector <int> p;

  void init (int n) {
    p.resize(n, -1);
  }

  int size(int u){
    if(p[u] > 0)
      return -1;

    return -p[u];
  }

  int find(int u){
    if(p[u] < 0)
      return u;

    return p[u] = find(p[u]);
  }

  bool merge(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v)
      return false;

    if(p[u] > p[v])
      swap(u, v);

    p[u] += p[v];
    p[v] = u;

    return true;
  }
};