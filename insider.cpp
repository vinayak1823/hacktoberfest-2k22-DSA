#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const int inf = (int) 1.01e9;
    vector<int> m(n + 1, inf);
    vector<int> M(n + 1, -inf);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      if (a[i] != a[j]) {
        return a[i] < a[j];
      }
      return i < j;
    });
    int cnt = 0;
    vector<int> val(n, 0);
    vector<int> save(n, -1);
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && a[order[end + 1]] == a[order[beg]]) {
        ++end;
      }
      int L = -2;
      int lst = -2;
      for (int i = beg; i <= end; i++) {
        if (lst != order[i] - 1) {
          L = order[i] - 1;
        }
        save[i] = L;
        if (L >= 0 && val[L] != val[order[i]]) {
          cnt -= 1;
        }
        if (order[i] < n - 1 && val[order[i]] != val[order[i] + 1]) {
          cnt -= 1;
        }
        if (L >= 0 && order[i] < n - 1 && val[L] != val[order[i] + 1]) {
          cnt += 1;
        }
        lst = order[i];
      }
      m[cnt + 1] = min(m[cnt + 1], a[order[beg]]);
      M[cnt + 1] = max(M[cnt + 1], a[order[beg]]);
      for (int i = end; i >= beg; i--) {
        L = save[i];
        val[order[i]] = 1;
        if (L >= 0 && val[L] != val[order[i]]) {
          cnt += 1;
        }
        if (order[i] < n - 1 && val[order[i]] != val[order[i] + 1]) {
          cnt += 1;
        }
        if (L >= 0 && order[i] < n - 1 && val[L] != val[order[i] + 1]) {
          cnt -= 1;
        }
      }
      if (end < n - 1 && a[order[end]] + 1 < a[order[end + 1]]) {
        m[cnt + 1] = min(m[cnt + 1], a[order[beg]] + 1);
        M[cnt + 1] = max(M[cnt + 1], a[order[end + 1]] - 1);
      }
      beg = end + 1;
    }
    for (int i = n; i > 2; i--) {
      m[i - 1] = min(m[i - 1], m[i]);
      M[i - 1] = max(M[i - 1], M[i]);
    }
    for (int i = 2; i <= n; i++) {
      if (i > 2) {
        cout << " ";
      }
      cout << (m[i] == inf ? -1 : m[i]);
    }
    cout << '\n';
    for (int i = 2; i <= n; i++) {
      if (i > 2) {
        cout << " ";
      }
      cout << (M[i] == -inf ? -1 : M[i]);
    }
    cout << '\n';
  }
  return 0;
}
