/*
状态机的边界条件，有一个入口的概念，这里的入口只能走向0状态，不能走向1状态。一开始的走法是0，所以说f[0][0] = 0，一开始是走不到状态1的，所以f[0][1] = -0x3f3f3f3f，之所以给成负无穷，因为求的是最大值。


*/
#include <iostream>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int T, n;
int a[N], f[N][2];

int main()
{
    cin >> T;
    while (T --)
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];

        for (int i = 1; i <= n; i ++ )
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + a[i - 1];
        }

        cout << max(f[n][0], f[n][1]) << endl;
    }

    return 0;
}
