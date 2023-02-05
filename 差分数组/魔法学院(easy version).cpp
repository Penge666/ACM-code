//https://ac.nowcoder.com/acm/problem/229099
//同样也是差分的思想。维护add【】del【】两个数字。
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
const int N = 4e5+100 ,maxn=4e5+100;
int n,m;
char SS[maxn];
int arr[maxn];
struct str{
    int l,r,num;
}st[maxn];
vector<int> add[N],del[N];
set<int> s;
map<int,int> mp;
signed main(){
    cin>>n>>m>>(SS+1);
    for(int i=1;i<=n;i++) arr[i]=(int)(SS[i]);
    for(int i=1;i<=m;i++){
        char ch;
        cin>>st[i].l>>st[i].r>>ch;
        st[i].num=(int)(ch);
        add[st[i].l].pb(st[i].num);
        del[st[i].r+1].pb(st[i].num);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(auto j:add[i]){
            if(!mp[j])
                s.insert(j);
            mp[j]++;
        }
        for(auto j:del[i]){
            if(mp[j]==1)
                s.erase(j);
            mp[j]--;
        }
        if(s.size())
            ans=ans+max(arr[i],*s.rbegin());
        else
            ans+=arr[i];
    }
    cout<<ans;
    return 0;
}
