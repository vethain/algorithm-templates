// 无向图

int ans = 0, n, a1, a2;
vector<int> g[N], fa(N), a(N), vis(N), ind(N);
int dp[N][2];

void dfs(int u, int fa)
{
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (auto v : g[u])
    {
        if ((u == a2 && v == a1) || (u == a1 && v == a2) || v == fa)
        {
            continue;
        }
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
void get(int i)
{

    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (ind[i] == 1)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int now = q.front();
            ind[now]--;
            q.pop();
            for (auto v : g[now])
            {
                ind[v]--;
                if (ind[v] == 1)
                    q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] > 1)
        {
            a1 = i;
            for (auto v : g[i])
            {
                if (ind[v] > 1 && v != a1)
                {
                    a2 = v;
                    goto th;
                }
            }
        }
    }
th:
    dfs(a1, 0);
    ans = max(ans, dp[a1][0]);
    dfs(a2, 0);
    ans = max(ans, dp[a2][0]);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        ind[u]++;
        ind[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ld k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            get(i);
        }
    }
    printf("%.1Lf", (ans + 0.0) * k);
}

// 有向图

int ans = 0, rt = 0;
vector<int> g[N], fa(N), a(N), vis(N);
int dp[N][2];

void dfs(int u)
{
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (auto v : g[u])
    {
        if (v == rt)
        {
            continue;
        }
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int f(int i)
{
    vis[i] = 1;
    if (vis[fa[i]])
    {
        return fa[i];
    }
    return f(fa[i]);
}
void get(int i)
{
    rt = f(i);
    dfs(rt);
    ans = max(ans, dp[rt][0]);
    rt = fa[rt];
    dfs(rt);
    ans = max(ans, dp[rt][0]);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> a[i] >> u;
        g[u].push_back(i);
        fa[i] = u;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans = 0;
            get(i);
            sum += ans;
        }
    }
    cout << sum << endl;
}