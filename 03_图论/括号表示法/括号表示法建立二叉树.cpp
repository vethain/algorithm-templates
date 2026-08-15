#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
#define ld long double
#define np next_permutation
#define pq priority_queue
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
using namespace std;

const int mod = 1e9;
const int N = 1e5 + 5;
int g[1005][2];

void dfs1(int now)
{
    char kk = 'A' + now;
    cout << kk << " ";
    if (g[now][0] != -1)
    {
        dfs1(g[now][0]);
    }
    if (g[now][1] != -1)
    {
        dfs1(g[now][1]);
    }
}
void dfs2(int now)
{
    char kk = 'A' + now;
    if (g[now][0] != -1)
    {
        dfs2(g[now][0]);
    }
    cout << kk << " ";
    if (g[now][1] != -1)
    {
        dfs2(g[now][1]);
    }
}
void dfs3(int now)
{
    char kk = 'A' + now;
    if (g[now][0] != -1)
    {
        dfs3(g[now][0]);
    }
    if (g[now][1] != -1)
    {
        dfs3(g[now][1]);
    }
    cout << kk << " ";
}
int len(int max_len, int node = 0)
{
    if (g[node][1] == -1 && g[node][0] == -1)
    {
        return max_len;
    }
    int now = max_len;
    for (int child : g[node])
    {
        if (child != -1)
        {
            now = max(now, len(max_len + 1, child));
        }
    }
    return now;
}
vector<pair<int, int>> pei(const string &s)
{
    vector<pair<int, int>> ans;
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (!st.empty())
            {
                int now = st.top();
                st.pop();
                ans.push_back({now, i});
            }
        }
    }
    return ans;
}
void solve()
{
    for (int i = 0; i < 1005; i++)
    {
        g[i][0] = g[i][1] = -1;
    }
    string s;
    cin >> s;
    int n = s.size();
    int du[1005] = {
        0,
    };
    int papa = s[0] - 'A';
    vector<pair<int, int>> p = pei(s);
    sort(p.begin(), p.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return (a.second - a.first) < (b.second - b.first); });
    for (int i = 0; i < p.size(); i++)
    {
        int fa = s[p[i].first - 1] - 'A';
        vector<char> check;
        for (int j = p[i].first; j <= p[i].second; j++)
        {
            if (s[j] >= 'A' && s[j] <= 'Z')
            {
                check.push_back(s[j]);
                du[fa]++;
                du[s[j] - 'A']++;
            }
            if (s[j] == ',')
            {
                check.push_back(s[j]);
            }
            s[j] = '#';
        }
        if (check.size() == 3)
        {
            g[fa][0] = check[0] - 'A';
            g[fa][1] = check[2] - 'A';
        }
        else if (check.size() == 2)
        {
            if (check[0] == ',')
            {
                g[fa][1] = check[1] - 'A';
            }
            else if (check[1] == ',')
            {
                g[fa][0] = check[0] - 'A';
            }
            else
            {
                g[fa][0] = check[0] - 'A';
                g[fa][1] = check[1] - 'A';
            }
        }
        else
        {
            if (check[0] != ',')
            {
                g[fa][0] = check[0] - 'A';
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (du[i])
        {
            cnt1++;
        }
        if (du[i] == 1)
        {
            cnt2++;
        }
    }
    cout << "高度:" << len(1, papa) << endl;
    cout << "结点数:" << cnt1 << endl;
    cout << "叶子结点数:" << cnt2 << endl;
    cout << "先序遍历序列:";
    dfs1(papa);
    cout << endl;
    cout << "中序遍历序列:";
    dfs2(papa);
    cout << endl;
    cout << "后序遍历序列:";
    dfs3(papa);
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}