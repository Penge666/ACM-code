/*
˼·�����ȣ�ֻҪ����һ�����ھ�����4����λ�ĵ��λ�ã���ô����ͳ�����1.3.����ϣ�����ҵ������ܶ�ľ��볬��1.3�Ļ����������ǿ��Է���˼�����ҵ�����<1.3�����ġ�ƥ�������С���ô���Ǿ������������㷨������ƥ�䡣
����һ���ǳ���Ҫ�����⣬��λ��ֵ㼯����Ϊ��������Ŀ�����궼�����ڵġ����ԣ�����֮��(xi+yi)����ż�Բ�ͬ��������ż�Ի��֡�
*/
#include<bits/stdc++.h>
using namespace std;
const int  maxn = 2555 ,N = maxn;
int vis[maxn];
int match[maxn];
int e[maxn][maxn];
int x[N],y[N];
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
    while(cin>>n){
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        memset(e,0,sizeof(e));
        for(int i=1;i<=n;i++){
            for(int j=1+i;j<=n;j++){
                 if(abs(x[i]-x[j])+abs(y[i]-y[j])==1){
//                     cout<<i<<" "<<j<<" "<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<endl;

                    e[i][j]=1;e[j][i]=1;
                }
            }
        }
        memset(match,0,sizeof(match));
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            if((x[i]+y[i])%2){
                if(dfs(i)){
                    ans++;
                }
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
/*
4
0 0
0 1
1 0
1 1
6
0 1
1 0
1 1
1 2
1 3
2 2
*/
