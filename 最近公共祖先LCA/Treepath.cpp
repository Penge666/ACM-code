/*
T1 Treepath
�۲쵽·�� x->y �ĳ��ȵ���ż��ֻ�� x �����ĳ��ȵ���ż���Լ� y ������ ���ȵ���ż���йأ��� dist[x]��ʾ x �����ľ��룬x �� y �ľ���Ϊdist[x]+dist[y]-2dist[lca]�����һ�����ż��ûӰ�죬�����������õ���Ϣ���� �� dist[x]�� dist[y]������뵽������������ż����ͬʱ·������Ϊż���������Ӷ�O(n)��

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
vector<int> v[N];
int sum0,sum1;
void dfs(int u,int h,int fa){
    if(h%2) sum1++;else sum0++;
    for(int i=0;i<v[u].size();i++){
        int to=v[u][i];
        if(to==fa) continue;
        dfs(to,h+1,u);
    }
}
signed main(){
    int n;
    cin>>n;
    sum1=0,sum0=0;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,1,0);
    cout<<sum0*(sum0-1)/2+sum1*(sum1-1)/2;
    return 0;
}
