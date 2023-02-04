/*
���⣺һ�����Ŷ���̨���ݣ�ÿ�����и�ֵa[i]������k���ϳ��ͻ���a[i]*(k-1)
�Ĳ����ȣ������и�ջ���Ե�����̨˳�򣬶���ÿ���˿���ѡ���ջ����
ֱ����̨����ջ�е��˿�����ʱ��̨���ʲ����ȵ���С�ܺ�

dp(i,j):����[i,j]�ܻ�õ���С��ŭֵ
MIN
dp[l][r]=dp[l][k]+dp[k+1][r]+(k-l+1)*(sum[r]-sum[k-1])
*/

#include <stdio.h>
#include <bits/stdc++.h>
#define fst first
#define sed second
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 110;
int a[MAXN], s[MAXN];
int d[MAXN][MAXN]; //����[i, j]��i��ǰ��û���˵�����µ���С����

int main()
{
#ifdef LOCAL
    freopen("C:/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ti++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), s[i] = s[i - 1] + a[i]; //ǰ׺��
        memset(d, 0x3f, sizeof(d));
        for (int i = 1; i <= n; i++) d[i][i] = 0; //������Ϊ0
        for (int l = 1; l < n; l++)
            for (int i = 1; i + l <= n; i++)
            {
                int j = i + l;
                d[i][j] = min(d[i][j], d[i + 1][j] + a[i] * (j - i)); //���԰ѵ�i���˽�ջ����[i+1, j]�ϳ�
                for (int k = i; k < j; k++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + (k - i + 1) * (s[j] - s[k]));
            }
        printf("Case #%d: ", ti);
        cout << d[1][n] << endl;
    }

    return 0;
}
