#include <bits/stdc++.h>
#define endl '\n'
#define uul __int128 // 输入输出需自定义
#define int long long int
#define ull unsigned long long int
#define ld long double
#define inf -1000000000000000000LL
#define Y cout << "YES" << endl
#define O cout << "NO" << endl
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (!s.empty() && a[s.top()] < a[i])
        {
            b[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}