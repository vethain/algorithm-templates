#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <climits>
#include <cstdlib>

#define ll long long int
#define ull unsigned long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        p[a[i]] = i;
    }
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        c.push_back(p[b[i]]);
    }
    vector<int> f;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(f.begin(), f.end(), c[i]);
        if (it == f.end())
        {
            f.push_back(c[i]);
        }
        else
        {
            *it = c[i];
        }
    }
    cout << f.size() << endl;
    return 0;
}