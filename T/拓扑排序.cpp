#include <bits/stdc++.h>
#define endl '\n'
#define i128 __int128
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf 1000000000000000000LL
#define gcd __gcd
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

const int N = 5e5 + 5;
const double eps = 1e-9;
int mod = 1e9 + 7;

// cnt 是排序完的层数
vector<int> g[26], ind(26, 0), id(26, 0);
set<int> s;
int cnt = 0;
vector<int> topo()
{
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (ind[i] == 0 && s.find(i) != s.end())
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        cnt++;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int now = q.front();
            ans.push_back(now);
            q.pop();
            for (auto xx : g[now])
            {
                ind[xx]--;
                if (ind[xx] == 0)
                {
                    q.push(xx);
                }
            }
        }
    }
    return ans;
}
void solve()
{
    const auto topo = [&]() -> vector<pair<int, int>>
    {
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (ind[i] == 0 && s.find(i) != s.end())
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            cnt++;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int now = q.front();
                ans.push_back(now);
                q.pop();
                for (auto xx : g[now])
                {
                    ind[xx]--;
                    if (ind[xx] == 0)
                    {
                        q.push(xx);
                    }
                }
            }
        }
        return ans;
    };
    topo();
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