/*
���⣺����������n������Ҫ������ȥ̽�գ���m������·������������Ҫ���������˲��ܱ��������еĵ㣬һ������Ա���������˾���������Ǻ͵�������С·�����ǵ����𣩡�
˼·�����Ǹ���С·���������⣬������Ϊ�еĵ�����ظ����ʣ�������С·���ǿ����ཻ�ģ����Ǿ��ô��ݱհ�������ͼ��G������ת��Ϊһ���·�����ǣ�Ȼ����Ǹ� poj1422 һ���ˡ�
��������С·������ = ͼ�Ķ����� �C ���ƥ����������ֻҪ���������㷨������ƥ������Ȼ���ö�����һ���ͳ����ˡ�

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
