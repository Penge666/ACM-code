/*����
��n�������ˣ�Ȼ�����m������

m������������:A�����B

���A���B��B���C����ôA���ܴ��C�����д�����

�������㣬����ֻ��Ҫǰ���ٳ��������ܹ�֪��˳���ˡ�

����˵������ζ�����֪�������-1

 

��⣺
���֣�Ȼ��check��ʱ�����Ǽ�������������Ƿ���һ��ֱ�߾ͺ���

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
struct str{
    int x,y;
}st[N];
int n,m;
vector<int> v[N];
int in[N];
int check(int num){
    queue<int> q;
    for(int i=1;i<=n;i++){
        v[i].clear();in[i]=0;
    }
    for(int i=1;i<=num;i++){
        in[st[i].y]++;
        v[st[i].x].push_back(st[i].y);
    }
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i);
    }
    int sum=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(q.size()) return 0;
        sum++;
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(!in[to]){
                q.push(to);
            }
        }
    }
    if(sum==n) return 1;
    else return 0;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>st[i].x>>st[i].y;
    int l=1;
    int r=m;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
