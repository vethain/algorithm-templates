#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ld long double
#define gcd __gcd
#define inf 0x3f3f3f3f3f3f3f3fLL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

struct trie
{
    int nxt[N][26], cnt;
    bool ed[N];
    void insert(string s, int sz)
    {
        int p = 0;
        for (int i = 0; i < sz; i++)
        {
            int c = s[i] - 'a';
            if (!nxt[p][c])
            {
                nxt[p][c] = ++cnt;
            }
            p = nxt[p][c];
        }
        ed[p] = 1;
    }
    bool find(string s, int sz)
    {
        int p = 0;
        for (int i = 0; i < sz; i++)
        {
            int c = s[i] - 'a';
            if (!nxt[p][c])
            {
                return 0;
            }
            p = nxt[p][c];
        }
        return ed[p];
    }
};
trie t;
// 注意必须定义为全局结构体  否则栈溢出
void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundus
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();

    return 0;
}