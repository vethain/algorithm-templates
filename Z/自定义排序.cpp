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
#include <numeric>

#define endl '\n'
#define ll long long int
#define ull unsigned long long int
using namespace std;

const int mod = 1e9;
const int N = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(4), x;
    a = {1, 3, 5, 4};

    // 1.sort函数自定义排序
    sort(a.begin(), a.end(), [&](int i, int j)
         { return x[i] < x[j]; }); //[]中有&，排序还依赖于外部数组x

    sort(a.begin(), a.end(), [](int i, int j)
         { return i < j; }); //[]中无&，排序仅依赖于内部变量i，j(从小到大)

    // 2.
    return 0;
}