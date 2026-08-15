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

int deg(int num, int deg)
{
    return num & (1ull << deg);
}
pair<vector<int>, bool> gsxor(vector<int> nums) // bool返回原数组是否可以通过多个数组合使得异或为0
{
    int n = nums.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = nums[i];
    }
    int row = 0;
    for (int col = 63; col >= 0 && row < n; --col)
    {
        bool found = false;
        for (int i = row; i < n; ++i)
        {
            if (deg(a[i], col))
            {
                swap(a[row], a[i]);
                found = true;
                break;
            }
        }
        if (!found)
            continue;
        for (int i = 0; i < n; ++i)
        {
            if (i == row)
                continue;
            if (deg(a[i], col))
            {
                a[i] ^= a[row];
            }
        }
        ++row;
    }
    bool hasZero = (row < n);
    vector<int> basis;
    for (int i = 0; i < row; ++i)
    {
        if (a[i] != 0)
        {
            basis.push_back(a[i]);
        }
    }
    sort(basis.begin(), basis.end(), greater<int>());
    return {basis, hasZero};
}
void solve()
{
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // EgoMundi
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}