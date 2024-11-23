#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int nums[1010], sum[1010];
int query;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    sort(nums + 1, nums + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + nums[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> query;
        if (query > sum[n]) {
            cout << n << ' ';
            continue;
        }
        for (int j = 0; j <= n; j++)
        {
            if (sum[j] > query)
            {
                cout << j - 1 << ' ';
                break;
            }
        }
    }
    return 0;
}