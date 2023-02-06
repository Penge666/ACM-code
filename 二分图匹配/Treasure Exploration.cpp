/*
题意：在外星上有n个点需要机器人去探险，有m条单向路径。问至少需要几个机器人才能遍历完所有的点，一个点可以被多个机器人经过（这就是和单纯的最小路径覆盖的区别）。
思路：这是个最小路径覆盖问题，但是因为有的点可以重复访问，所以最小路径是可以相交的，我们就用传递闭包建立新图（G’），转化为一般的路径覆盖，然后就是跟 poj1422 一样了。
　　　最小路径覆盖 = 图的顶点数 – 最大匹配数，所以只要用匈牙利算法求出最大匹配数，然后用顶点数一减就出来了。

*/
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 666
int match[maxn];
int vis[maxn];
int e[maxn][maxn];
int n,m;
int dfs(int u){
    for(int i=1;i<=n;i++){
        if(!vis[i]&&e[u][i]){
            vis[i]=1;
            if(match[i]==0||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(e[i][k]&&e[k][j])
                    e[i][j]=1;
}
int main(){
        while(~scanf("%d%d",&n,&m)&&(n+m)){
            int x,y;
            memset(match,0,sizeof(match));

            for(int i=1;i<=m;i++){
                scanf("%d%d",&x,&y);
                e[x][y]=1;
            }
            floyd();
            int ans=0;
            for(int i=1;i<=n;i++){
                memset(vis,0,sizeof(vis));
                if(dfs(i))
                    ans++;
            }
            int res=n-ans;
            printf("%d\n",res);
            for(int i=0;i<=maxn;i++)
                for(int j=0;j<=maxn;j++)
                    e[i][j]=0;
        }
    return 0;
}
