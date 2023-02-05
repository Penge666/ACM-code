#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
vector<int> v[N];
int in[N];int n,m;
vector<int> ans;
priority_queue<int> q;
void init(){
    while(!q.empty()) q.pop();
    ans.clear();
    for(int i=1;i<=n;i++){
        in[i]=0;
        v[i].clear();
    }
}
signed main(){
    int T;
    cin>>T;
    while(T--){

        scanf("%lld%lld",&n,&m);
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%lld%lld",&a,&b);
            in[b]++;
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(!in[i]) q.push(i);
        }
        while(!q.empty()){
            int t=q.top();
            q.pop();
            ans.push_back(t);
            for(int i=0;i<v[t].size();i++){
                int to=v[t][i];
                in[to]--;
                if(!in[to]){
                    q.push(to);
                }
            }
        }
        int sum=0;
        int minx=9999999999;
        for(int i=0;i<ans.size();i++){
            minx=min(minx,ans[i]);
            sum+=minx;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
