/*
״̬���ı߽���������һ����ڵĸ����������ֻ������0״̬����������1״̬��һ��ʼ���߷���0������˵f[0][0] = 0��һ��ʼ���߲���״̬1�ģ�����f[0][1] = -0x3f3f3f3f��֮���Ը��ɸ������Ϊ��������ֵ��


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
