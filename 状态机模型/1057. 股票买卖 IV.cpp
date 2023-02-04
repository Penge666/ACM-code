/*
��ʼ��
f[i][0][0]
��Ϊ����ڵĴ��ڣ�����iҪ��0��ʼö�٣�ö�ٵ�n����ʾǰ0�죬ǰ1�죬...��ǰn��������Ҳ�������Ϊǰ1���״̬�Ǵ�ǰ0��ת�ƹ����ġ�ǰ0��ʲô��û�������������0���ǺϷ���״̬��

f[n][i][0]
���ö��k�ʽ��׵����ֵ�������n���ڣ��ǿ���һ�ʽ��׶�����ģ�����kҪ��0��ʼö�٣�ö�ٵ�k�ʽ��ס�


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
