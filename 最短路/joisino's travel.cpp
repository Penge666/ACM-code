/*

题意就是给一个带权无向图，然后给出一个人的路线，经过的点的顺序不固定，求出走的最短距离。
先用Floyd求出任意i到j的最短路长度，然后用next_permutation枚举经过的点的顺序即可。

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 9999999999
#define N 6666
int arr[N];int f[N];
int e[N][N];
int a[N];
struct str{
    int x,y,z;
}st[666666];

signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
        }
    }
    for(int i=1;i<=k;i++)
        scanf("%lld",&arr[i]);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        e[a][b]=e[b][a]=c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    int ans=inf;
    for(int i=1;i<=k;i++) a[i]=i;
    do{
        int sum=0;
        for(int i=2;i<=k;i++){
            sum+=e[arr[a[i]]][arr[a[i-1]]];
        }
        ans=min(ans,sum);
    }while(next_permutation(a+1,a+1+k));
    cout<<ans;
    return 0;
}
/*

*/
