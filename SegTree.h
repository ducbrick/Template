#include <bits/stdc++.h>
using namespace std;

struct SegTree {
  typedef long long Type;

  static const Type BASE_VALUE = 0;

  inline Type f(Type a, Type b) {
    return a + b;
  }

  int n;
  vector <Type> st;

  void init(int _n, Type initValue = BASE_VALUE) {
    n = _n;
    st.resize(2 * n, initValue);
  }

  inline void update(int pos, Type value) {
    for (st[pos += n] = value; pos > 1; pos >>= 1)
      st[pos >> 1] = f(st[pos], st[pos ^ 1]);
  }

  inline Type query(int l, int r) {  
    r++;

    Type res = BASE_VALUE;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) 
        res = f(res, st[l++]);
      if (r & 1) 
        res = f(res, st[--r]);
    }

    return res;
  }
};
