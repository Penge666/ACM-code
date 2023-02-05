 /*

如果你用优先队列拓扑排序得到的是：3 5 6 4 1 7 8 9 2 0

但是正确答案为 6 4 1 3 9 2 5 7 8 0 这样使得小的（1）尽量在前面。

这里我们可以得到 前面的小的不一定排在前面，但是有一点后面大的一定排在后面。

我们看 6和3不一定3排在前面，因为6后面连了一个更小的数字1能使得6更往前排。

在看 2和 8，8一定排在后面，因为8后面已经没有东西能使它更往前排（除了0）。

所以最后我们的做法就是 建立一个反图，跑一边字典序最大的拓扑排序，最后再把这个排序倒过来就是答案了

*/
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
    for(int i=ans.size()-1;i>=0;i--){
        if(i==ans.size()-1) printf("%lld",ans[i]);
        else printf(" %lld",ans[i]);
    }
    printf("\n");
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
