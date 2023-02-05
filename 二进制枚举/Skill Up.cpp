/*
 题意：有N本书，M种算法，每种书的价格是Ci，第i书对第j种算法能提升Ai,j点，输出最少的钱满足每种算法的点数超过X。+

由于数据较小，直接枚举所有状态【二进制枚举】
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 999999999999999999
#define N 666666
int arr[N];
int n,m,x;
int c[N];
int mp[666][666];
int t[N];
signed main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=1;j<=m;j++) cin>>mp[i][j];
    }
    int ans=inf;
    for(int i=0;i<(1<<n);i++){
        int s=0;
        for(int j=0;j<=400;j++) t[j]=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                s+=c[j];
                for(int k=1;k<=m;k++) t[k]+=mp[j][k];
            }
        }
        int f=1;
        for(int j=1;j<=m;j++){
            if(t[j]<x){
                 f=0;
                break;
            }
        }
        if(f) ans=min(ans,s);
    }
    if(ans==inf) cout<<"-1";else cout<<ans;
    return 0;
}
