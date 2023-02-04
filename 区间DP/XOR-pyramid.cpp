/*
通过以上图片及题目，可以知道某个区间内的值的递推式为f[l,r]=f[l+1,r] xor f[l,r?1]
（通过这个递推式可以进行区间dp，首先输入的是dp[i][i]为区间长度为1的值，然后通
过枚举长度以及左端点来更新区间f值，另外开一个ans[i][j]来记录[i, j]区间的答案，在
询问的时候O(1)回答。
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5555;
int n,q;
int arr[N];
int dp[N][N];
int f[N][N];
/*
dp(i,j):表示区间[i,j]所表示的最大值
*/
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i][i]=arr[i];
        f[i][i]=arr[i];
    }

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            f[l][r]=f[l][r-1]^f[l+1][r];
            dp[l][r]=max(max(dp[l][r],f[l][r]),max(dp[l][r-1],dp[l+1][r]));
        }
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        cout<<dp[L][R]<<'\n';
    }
    return 0;
}
