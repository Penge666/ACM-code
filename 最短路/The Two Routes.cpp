/*
题意：有n个城市，城市之间有m条铁路，剩下的都是公路，加起来是一个完全图，因为安全的问题，火车汽车不能在一个车站，除了n，现在要求一个时间，一个可以让火车还有汽车同时从1到达n的时间
思路：额，乍一看优点懵逼，但是如果把铁路还有公路放在两个图中那就简单很多了，就是一个最短路，因为点的个数很少，所以弗洛伊德就可以搞定，如果铁路或者公路有一个不能到达，那就输出-1，否则输出最大值

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define  N 666
#define inf 999999999999
int mp1[N][N];
int mp2[N][N];
signed main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                mp1[i][j]=mp1[j][i]=0;
            else
                mp1[i][j]=mp1[j][i]=inf;
            if(i==j)
                mp2[i][j]=mp2[j][i]=0;
            else
                mp2[i][j]=mp2[j][i]=1;
        }
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        mp1[a][b]=mp1[b][a]=1;
        mp2[a][b]=mp2[b][a]=inf;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                mp1[j][k]=min(mp1[j][k],mp1[j][i]+mp1[i][k]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                mp2[j][k]=min(mp2[j][k],mp2[j][i]+mp2[i][k]);
    if(mp1[1][n]>=inf||mp2[1][n]>=inf)
        cout<<"-1";
    else
        cout<<max(mp1[1][n],mp2[1][n]);
    return 0;
}
