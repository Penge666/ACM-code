/*
本质上，我们最后的答案只需要考虑f[n][1]就可以了，但是由于存在一些边界数据，比如股票狂跌这种情况，那么最好的就是一次都不买，那么就处于f[n][2]这种情况，所以最后的输出还是要考虑下f[n][2]和f[n][1]之间的最大值。
要记得，入口和出口都要考虑并进行初始化。


*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
int a[N], f[N][3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    memset(f,-0x3f,sizeof(f));
    f[0][2] = 0;

    for (int i = 1; i <= n; i ++ )
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - a[i - 1]);
        f[i][1] = f[i - 1][0] + a[i - 1];
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }

    cout << max(f[n][1], f[n][2]) << endl;

    return 0;
}
