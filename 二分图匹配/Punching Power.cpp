/*
思路：首先，只要不是一个点在距离它4个单位的点的位置，那么距离就超过了1.3.我们希望能找到尽可能多的距离超过1.3的机器数，我们可以反向思考，找到距离<1.3的最多的·匹配数就行。那么我们就能用匈牙利算法求出最大匹配。
还有一个非常重要的问题，如何划分点集。因为不符合题目的坐标都是相邻的。所以，坐标之和(xi+yi)的奇偶性不同，利用奇偶性划分。
*/
#include<bits/stdc++.h>
using namespace std;
const int  maxn = 2555 ,N = maxn;
int vis[maxn];
int match[maxn];
int e[maxn][maxn];
int x[N],y[N];
int n,m;
int dfs(int u){  //匈牙利算法模板
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&e[u][i]==1){
            vis[i]=1;
            if(match[i]==0||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        memset(e,0,sizeof(e));
        for(int i=1;i<=n;i++){
            for(int j=1+i;j<=n;j++){
                 if(abs(x[i]-x[j])+abs(y[i]-y[j])==1){
//                     cout<<i<<" "<<j<<" "<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<endl;

                    e[i][j]=1;e[j][i]=1;
                }
            }
        }
        memset(match,0,sizeof(match));
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            if((x[i]+y[i])%2){
                if(dfs(i)){
                    ans++;
                }
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
/*
4
0 0
0 1
1 0
1 1
6
0 1
1 0
1 1
1 2
1 3
2 2
*/
