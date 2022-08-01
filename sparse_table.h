struct Sparse_Table {
  typedef long long Type;

  inline Type f(Type a, Type b) {
    return min(a, b);
  }

  vector <vector <Type>> st;

  void build(Type *a, int n) {
    int k = log2(n);

    st.resize(n + 1, vector <Type> (k + 1));

    for (int i = 0; i <= n; i++)
      st[i][0] = a[i];

    for (int k = 1; k <= log2(n); k++)
      for (int i = 0; i + (1 << k) - 1 <= n; i++) {
        int j = i + (1 << (k - 1));
        st[i][k] = f(st[i][k - 1], st[j][k - 1]);
      }
  }

  Type query(int l, int r) {
    int k = log2(r - l + 1);
    r = r - (1 << k) + 1;
    return f(st[l][k], st[r][k]);
  }
};