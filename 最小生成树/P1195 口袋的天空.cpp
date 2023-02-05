//n���� m���� ����k��������С����
//
//��kΪ1 ������һ��MST ��һ��kruskal n-1������
//
//�� kΪ2 Ϊ����ͼ����Ϊ ����MST n-2������
//
//ͬ�� ����k��mst ���� n-k������ ��������n-k�β����� û���˱� ����cpp�е� h<m) ֱ����� No Answer
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int mp[6666][6666];
int f[N];
int n,m,k;
struct str{
    int u,v,w;
}st[N];
int getf(int v){
    if(v==f[v]){
        return f[v];
    }else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
int merge(int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2){
        f[t2]=t1;
        return 1;
    }
    return 0;
}
bool cmp(str a,str b){
    return a.w<b.w;
}
signed main(){
    int cnt=0;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&st[i].u,&st[i].v,&st[i].w);
    int ans=0;
    sort(st+1,st+m+1,cmp);int j=1;
    for(int i=1;i<=m&&j<=n-k;i++){
        if(merge(st[i].u,st[i].v)){
            ans+=st[i].w;
            j++;
        }
    }
    if(j<n-k) cout<<"No Answer";
    else
        cout<<ans;
    return 0;
}
