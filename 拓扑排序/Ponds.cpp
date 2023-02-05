/*
���⣺

���⣺��n��������m���ܵ���ÿ�������ļ�ֵ��v�� ����Ҫɾ��������ɾ���ĳ������������ֻ����һ���ܵ�������ᱬը������������ĳ������������ļ�ֵ�ܺ��Ƕ��١�

˼·��

��������ɾ��������ͨ���ж�С��2�Ľڵ㣬Ȼ�����ò��鼯ά������ɾ��֮�����ͨ���Ȩֵ������

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int arr[N],in[N];
int n,m;
int f[N],num[N],sum[N];
map<int,int> vis;
vector<int> v[N];
int getf(int v){
    if(v==f[v]){
        return f[v];
    }else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
void merge(int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2){
        /*f[t1]=t2;
        sum[t2]+=t1;
        num[max(t1,t2)]++;
        */
        f[max(t1,t2)]=min(t1,t2);
        sum[min(t1,t2)]+=sum[max(t1,t2)];
        num[min(t1,t2)]+=num[max(t1,t2)];
    }
}

void toposort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]<=1){
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(!vis[to]&&in[to]<=1){
                q.push(to);
                vis[to]=1;
            }
        }
    }
}

void init(){
    for(int i=1;i<=n;i++){

        sum[i]=arr[i];
        f[i]=i;
        v[i].clear();
        num[i]=1;
        in[i]=0;
    }
    vis.clear();
}
signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);

        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            //sum[i]=arr[i];
        }
        init();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%lld%lld",&a,&b);
            in[a]++;
            in[b]++;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        toposort();
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            for(int j=0;j<v[i].size();j++){
                if(!vis[v[i][j]]){
                    merge(i,v[i][j]);
                }
            }
        }
        int Ans=0;
        for(int i=1;i<=n;i++){
            if(i==getf(i)&&num[i]%2&&(!vis[i])){
                Ans+=sum[i];
            }
        }
        printf("%lld\n",Ans);
    }
    return 0;
}
