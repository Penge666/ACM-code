/*
T1 Treepath
观察到路径 x->y 的长度的奇偶性只与 x 到根的长度的奇偶性以及 y 到根的 长度的奇偶性有关（令 dist[x]表示 x 到根的距离，x 到 y 的距离为dist[x]+dist[y]-2dist[lca]，最后一项对奇偶性没影响，所以真正有用的信息包含 在 dist[x]和 dist[y]里，不难想到当这两个数奇偶性相同时路径长度为偶数）。复杂度O(n)。

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
