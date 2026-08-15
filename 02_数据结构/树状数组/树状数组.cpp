#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
using namespace std;

template <typename T, size_t SIZE>
void fl(T (&arr)[SIZE], const T &val)
{
    fill(arr, arr + SIZE, val);
}
template <typename Container>
void fl(Container &container, const typename Container::value_type &val)
{
    fill(container.begin(), container.end(), val);
}

const int mod = 1e9 + 7;
const int N = 5e5 + 5;
const double eps = 1e-9;

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int val) {
        for (; i <= n; i += i & -i)
            tree[i] = max(tree[i], val);
    }
    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res = max(res, tree[i]);
        return res;
    }
};

/*已知所有可能出现元素   修改每个元素出现次数    第k小*/
struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int val) {
        for (; i <= n; i += i & -i)
            tree[i] += val;
    }
    int kth(int k) {
        int idx = 0;
        for (int bit = 1 << 20; bit; bit >>= 1) {
            int nxt = idx + bit;
            if (nxt <= n && tree[nxt] < k) {
                k -= tree[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};

//前缀最大值
int tree[N];
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int d)
{
    while (x < N)
    {
        tree[x] += d;
        x += lowbit(x);
    }
}
int qur(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    fl(tree, 0LL);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, d;
            cin >> x >> d;
            update(x, d);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << qur(r) - qur(l - 1) << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}