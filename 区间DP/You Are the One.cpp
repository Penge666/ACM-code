/*
题意：一队人排队上台表演，每个人有个值a[i]，他第k个上场就会有a[i]*(k-1)
的不愉快度，现在有个栈可以调整上台顺序，对于每个人可以选择进栈或者
直接上台，在栈中的人可以随时上台，问不愉快度的最小总和

dp(i,j):区间[i,j]能获得的最小愤怒值
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
int d[MAXN][MAXN]; //区间[i, j]第i个前面没有人的情况下的最小代价

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
            scanf("%d", &a[i]), s[i] = s[i - 1] + a[i]; //前缀和
        memset(d, 0x3f, sizeof(d));
        for (int i = 1; i <= n; i++) d[i][i] = 0; //单个人为0
        for (int l = 1; l < n; l++)
            for (int i = 1; i + l <= n; i++)
            {
                int j = i + l;
                d[i][j] = min(d[i][j], d[i + 1][j] + a[i] * (j - i)); //尝试把第i个人进栈先让[i+1, j]上场
                for (int k = i; k < j; k++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + (k - i + 1) * (s[j] - s[k]));
            }
        printf("Case #%d: ", ti);
        cout << d[1][n] << endl;
    }

    return 0;
}
