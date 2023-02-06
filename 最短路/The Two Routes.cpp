/*
���⣺��n�����У�����֮����m����·��ʣ�µĶ��ǹ�·����������һ����ȫͼ����Ϊ��ȫ�����⣬������������һ����վ������n������Ҫ��һ��ʱ�䣬һ�������û𳵻�������ͬʱ��1����n��ʱ��
˼·���էһ���ŵ��±ƣ������������·���й�·��������ͼ���Ǿͼ򵥺ܶ��ˣ�����һ�����·����Ϊ��ĸ������٣����Ը������¾Ϳ��Ը㶨�������·���߹�·��һ�����ܵ���Ǿ����-1������������ֵ

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
