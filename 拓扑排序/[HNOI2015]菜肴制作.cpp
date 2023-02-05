#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
#define int long long
#define N 666666
int n,m;
vector<int> ans;
vector<int> v[N];
int in[N];
priority_queue<int,vector<int>,less<int> >q;
int topoSort(){
    while(!q.empty()){
        int t=q.top();
        q.pop();
        ans.push_back(t);
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(!in[to]) q.push(to);
        }
    }
}
void slove(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        v[b].push_back(a);
        in[a]++;
    }
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
        }
    }
    topoSort();
    if(ans.size()==n){
        for(int i=ans.size()-1;i>=0;i--){
            if(i==ans.size()-1) printf("%lld",ans[i]);
            else printf(" %lld",ans[i]);
        }
        printf("\n");
    }else{
        printf("Impossible!\n");
    }

}
void init(){
    while(!q.empty()) q.pop();
    ans.clear();
    for(int i=0;i<=n;i++) v[i].clear(),in[i]=0;

}
signed main(){
    int T;
    scanf("%lld",&T);
    while(T--){
        init();
        slove();
    }
    return 0;
}
