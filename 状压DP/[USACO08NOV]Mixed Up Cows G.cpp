/**
约翰家有N头奶牛，第i头奶牛的编号是Si，每头奶牛的编号都是唯一的。这些奶牛最近 在闹脾
气，为表达不满的情绪，她们在挤奶的时候一定要排成混乱的队伍。在一只混乱的队 伍中，相
邻奶牛的编号之差均超过K。比如当K = 1时，1, 3, 5, 2, 6, 4就是一支混乱的队伍， 而1, 3,
 6, 5, 2, 4不是，因为6和5只差1。请数一数，有多少种队形是混乱的呢？

（4<=N<=16,1<=si<=25000）

数据范围这么小很明显就算是状压DP（一般不大于20），

定义dp[ i ] [ j ]表示状态为i时以j为末尾时的方案数

当状态s不包含第i只牛时，第j只牛与第i只牛编号之差大于k时，s再加上i的状态下以第i只牛为

末尾的方案就等于状态s下以j为末尾的方案的和（所有满足的j）

所以状态转移方程：f [ s|(1<<(i-1)) ][ i ]+= f [ s ][ j ];
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N = 17 , M = 1<<17 , inf = 0x3f3f3f3f;

int dp[M][N];//dp[s,i]:在状态s下(也就是说，已经用了状态i的数)，以i结尾的方案数
int n,m,arr[N];

signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) dp[1<<i][i]=1;
    for(int s=0;s<(1<<n);s++){
        for(int i=0;i<n;i++){
            if((1<<i)&s){
                for(int j=0;j<n;j++){
                    if(abs(arr[j]-arr[i])>m&&(!((1<<j)&s))){
                        dp[s|(1<<j)][j]+=dp[s][i];
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=dp[(1<<n)-1][i];
    cout<<ans;
    return 0;
}
