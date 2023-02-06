/*
题意：

给一个N*N的矩阵，一些星球位于一些点上，要求消除所有星球，每次操作可消除一行或一列的星球，求最少要几次。

最小点覆盖定义：二分图中，选取最少的点数，使这些点和所有的边都有关联（把所有的边的覆盖），叫做最小点覆盖。

结论：最小点覆盖数 = 最大匹配数

思路：把横坐标作为集合X，纵坐标作为集合Y，对于点(x,y)，由X中的x连向Y中的y。对于每条边，只要x和y中有一个被删除即可，明显的最小点覆盖模型。


*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 5555
int vis[maxn];
int match[maxn];
int e[maxn][maxn];
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        e[x][y]=1;
    }
    memset(match,0,sizeof(match));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
