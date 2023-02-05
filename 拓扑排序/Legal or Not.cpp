#include<bits/stdc++.h>
using namespace std;
#define N 666
int n,m;
vector<int> v[N];
int vis[N][N];
queue<int> q;
int in[N];


void topoSort(){
//    cout<<q.size()<<'\n';
    int sum=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
    //    ans.push_back(t);
        sum++;
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(in[to]==0) q.push(to);
        }
    }
//    cout<<sum<<'\n';
    //cout<<ans.size()<<'\n';
    if(sum==n) printf("YES\n");
    else printf("NO\n");
}
void init(){
    for(int i=0;i<n;i++){
        in[i]=0;
        v[i].clear();
    }

}
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n+m==0) break;
        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            in[b]++;
            v[a].push_back(b);
        }
        while(!q.empty()) q.pop();
        for(int i=0;i<n;i++){
            if(!in[i])
                q.push(i);
        }
        topoSort();
        init();
    }
    return 0;
}
