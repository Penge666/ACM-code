/*
���⣺��n��ѧ����ÿ��ѧ������һЩ���ֹ�ϵ���ҳ�����û��ϵ������һȺ�ˡ�

˼·������һ������ͼ��������ģ���⡾��������= ���� - ���ƥ������ע�⣺���ƥ������Ҫ����2

���ο����͡�

����֮��Ϳ��Է��֣�����һ���ǳ����Ե��������������⣬����ת��Ϊ����ͼ�������������Ĳ�㽨ͼ��Ȼ����ݶ�����������=������-��С�㸲������  �������������˵�����ǿ��Է������������ϵ���໥�ġ�

�����ǵĽ�ͼ�У�������˵Ӧ����һ�����еĵ㣬һ����Ů�ĵ��������ߣ�������Ŀ��û˵�Ա�����⡣

ֻ�ܽ�ÿ�����������㣬һ���������еĵ㣬һ��������Ů�ĵ��ˣ�Ȼ�����ߡ����ڹ�ϵ���໥�ģ�����������˱ߵ��ظ���Ҳ���Ǳ߼��ǸղŵĶ������Ӷ����������ƥ�����˶�����

��ô ����������=������-���ƥ��/2���������մ𰸾ͺ�֮�����ˡ�


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
