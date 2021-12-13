#include <bits/stdc++.h>
using namespace std;

struct Dsu{
  vector <int> p;

  Dsu(int n){
    p.resize(n + 1, -1);
  }

  int size(int u){
    if(p[u] > 0)
      return -1;

    return -p[u];
  }

  int findP(int u){
    if(p[u] < 0)
      return u;

    return p[u] = findP(p[u]);
  }

  bool merge(int u, int v){
    u = findP(u);
    v = findP(v);

    if(u == v)
      return false;

    if(p[u] > p[v])
      swap(u, v);

    p[u] += p[v];
    p[v] = u;
  }
}