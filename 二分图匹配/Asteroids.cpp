/*
���⣺

��һ��N*N�ľ���һЩ����λ��һЩ���ϣ�Ҫ��������������ÿ�β���������һ�л�һ�е�����������Ҫ���Ρ�

��С�㸲�Ƕ��壺����ͼ�У�ѡȡ���ٵĵ�����ʹ��Щ������еı߶��й����������еıߵĸ��ǣ���������С�㸲�ǡ�

���ۣ���С�㸲���� = ���ƥ����

˼·���Ѻ�������Ϊ����X����������Ϊ����Y�����ڵ�(x,y)����X�е�x����Y�е�y������ÿ���ߣ�ֻҪx��y����һ����ɾ�����ɣ����Ե���С�㸲��ģ�͡�


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
int dfs(int u){  //�������㷨ģ��
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
