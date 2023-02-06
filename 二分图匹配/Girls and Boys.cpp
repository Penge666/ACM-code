/*
题意：有n个学生，每个学生都和一些人又关系，找出互相没关系的最多的一群人。

思路：这是一道二分图最大独立集模板题【最大独立集= 点数 - 最大匹配数】注意：最大匹配数需要除以2

【参考博客】

看到之后就可以发现，这是一道非常明显的最大独立集的问题，可以转化为二分图来做，还是最经典的拆点建图，然后根据定理，最大独立集=顶点数-最小点覆盖数。  而对于这道题来说，我们可以发现这个浪漫关系是相互的。

而我们的建图中，按理来说应该是一边是男的点，一边是女的点这样连边，但是题目中没说性别的问题。

只能将每个点拆成两个点，一个当作是男的点，一个当作是女的点了，然后连边。由于关系是相互的，这样就造成了边的重复。也就是边集是刚才的二倍，从而导致了最大匹配变成了二倍。

那么 ，最大独立集=顶点数-最大匹配/2，所以最终答案就呼之欲出了。


*/
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxn 666
vector<int> v[maxn];
int vis[maxn];
int match[maxn];
int n;
int dfs(int u){
    for(int i=0;i<v[u].size();i++){
        int temp=v[u][i];
        if(vis[temp]==0){
            vis[temp]=1;
            if(match[temp]==0||dfs(match[temp])){
                match[temp]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            v[i].clear();
        int x,m,y;
        for(int i=1;i<=n;i++){
            scanf("%d: (%d)",&x,&m);
            for(int j=0;j<m;j++){
                scanf("%d",&y);
                v[x].push_back(y);
                //v[y].push_back(x);
            }
        }
        memset(match,0,sizeof(match));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++)
                vis[j]=0;
            if(dfs(i))
                ans++;
        }
        printf("%d\n",n-ans/2);
    }
    return 0;
}
