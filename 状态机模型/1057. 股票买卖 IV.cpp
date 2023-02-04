/*
初始化
f[i][0][0]
因为有入口的存在，所以i要从0开始枚举，枚举到n，表示前0天，前1天，...，前n天的情况。也可以理解为前1天的状态是从前0天转移过来的。前0天什么都没有买，最大收益是0，是合法的状态。

f[n][i][0]
最后，枚举k笔交易的最大值，在这个n天内，是可以一笔交易都不买的，所以k要从0开始枚举，枚举到k笔交易。


*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, K = 110;

int n, k;
int a[N], f[N][K][2];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i ++ ) f[i][0][0] = 0;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= k; j ++ )
        {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + a[i - 1]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - a[i - 1]);
        }

    int res = 0;
    for (int i = 0; i <= k; i ++ ) res = max(res, f[n][i][0]);

    cout << res << endl;

    return 0;
}
