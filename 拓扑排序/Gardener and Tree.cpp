#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5+100 ;
//
int n,k;
int arr[N];
vector<int> g[N],v;
int d[N];
map<int,int> mp;

signed main(){
    int T=1;
    cin>>T;
    while(T--){
        mp.clear();
        v.clear();
        cin>>n>>k;
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<=n;i++){
            g[i].clear();
            d[i]=0;
        }
        int a,b;
        int s=0;
        for(int i=1;i<=n-1;i++){
            cin>>a>>b;
            if(!mp[a]) mp[a]=1,s++;
            if(!mp[b]) mp[b]=1,s++;
            g[a].push_back(b),g[b].push_back(a);
            d[a]++,d[b]++;
        }

        for(int i=1;i<=n;i++){
            if(d[i]==1)
                v.push_back(i);
        }
        int sum=0;
        for(int i=0;i<k;i++){
            if(v.size()<=0) break;
            vector<int> tmp;
            tmp.clear();
            sum+=v.size();
            for(int o=0;o<v.size();o++){
                for(int j=0;j<g[v[o]].size();j++){
                    d[g[v[o]][j]]--;
                    if(d[g[v[o]][j]]==1){
                        tmp.push_back(g[v[o]][j]);
                    }
                }
            }

            v=tmp;
        }

        cout<<n-sum<<endl;
    }
    return 0;
}
/*

*/
