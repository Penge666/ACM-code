 /*

����������ȶ�����������õ����ǣ�3 5 6 4 1 7 8 9 2 0

������ȷ��Ϊ 6 4 1 3 9 2 5 7 8 0 ����ʹ��С�ģ�1��������ǰ�档

�������ǿ��Եõ� ǰ���С�Ĳ�һ������ǰ�棬������һ�������һ�����ں��档

���ǿ� 6��3��һ��3����ǰ�棬��Ϊ6��������һ����С������1��ʹ��6����ǰ�š�

�ڿ� 2�� 8��8һ�����ں��棬��Ϊ8�����Ѿ�û�ж�����ʹ������ǰ�ţ�����0����

����������ǵ��������� ����һ����ͼ����һ���ֵ�������������������ٰ�������򵹹������Ǵ���

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
