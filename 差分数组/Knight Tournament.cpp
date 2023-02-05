//利用差分的思想，逆向思考
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
const int N = 4e5+100 ;
int n,m;
int l[N],r[N],x[N];
vector<pair<int,int> > add[N],del[N];
int ans[N];
set<pair<int,int> > s;
signed main(){
//    s.insert({1,2});
//    s.insert({2,2});
//    s.erase({1,2});
//    cout<<s.size();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>l[i]>>r[i]>>x[i];
    for(int i=n;i>=1;i--){
        if(x[i]==l[i]){
            add[l[i]+1].pb({i,x[i]});
            del[r[i]+1].pb({i,x[i]});
        }else if(x[i]==r[i]){
            add[l[i]].pb({i,x[i]});
            del[r[i]].pb({i,x[i]});
        }else{
            add[l[i]].pb({i,x[i]});
            del[x[i]].pb({i,x[i]});

            add[x[i]+1].pb({i,x[i]});
            del[r[i]+1].pb({i,x[i]});
        }
        //cout<<"fuck"<<i<<endl;
    }

    for(int i=1;i<=n;i++){
        for(auto p:add[i]){
            s.insert(p);
        }
        for(auto p:del[i]){
            s.erase(p);
        }
        if(s.size()){
            auto p=*s.begin();
            ans[i]=p.second;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
