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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> f;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(f.begin(), f.end(), a[i]);
        if (it == f.end())
        {
            f.push_back(a[i]);
        }
        else
        {
            *it = a[i];
        }
    }
    cout << f.size() << endl;
    return 0;
}