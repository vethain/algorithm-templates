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

int now, cnt, pos;
int sum;
string s;
struct node
{
    int len, siz, fail, son[26];
    void init(int x)
    {
        fl(son, 0LL);
        len = x;
        siz = fail = 0;
    }
} tree[N];
void init()
{
    tree[0].init(0);
    tree[1].init(-1);
    now = 0;
    cnt = 1;
    pos = 0;
    sum = 0;
    tree[0].fail = 1;
}
int get_fail(int p)
{
    while (now - tree[p].len - 1 < 0 || s[now - tree[p].len - 1] != s[now])
    {
        p = tree[p].fail;
    }
    return p;
}
void insert(int c)
{
    int fa = get_fail(pos);
    int so = tree[fa].son[c];
    if (!so)
    {
        so = ++cnt;
        tree[so].init(tree[fa].len + 2);
        tree[so].fail = tree[get_fail(tree[fa].fail)].son[c];
        tree[so].siz = tree[tree[so].fail].siz + 1;
        tree[fa].son[c] = so;
    }
    pos = so;
}
void solve()
{
    cin >> s;
    int n = s.size();
    init();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            insert(s[i] - 'a');
            cout << tree[pos].siz << " ";
        }
        else
        {
            int pr = tree[pos].siz;
            s[i] = ((int)s[i] - 97 + pr) % 26 + 'a';
            insert(s[i] - 'a');
            cout << tree[pos].siz << " ";
        }
        sum += tree[pos].siz;
        now++;
    }
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