//分奇数偶数输出就行
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define maxn 2009
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,a[maxn];
signed main(){
    int T=1;
    cin>>T;
    while(T--){
        vector<int> v1,v2;
        cin>>n;
        for(int i=1;i<=n;i++){
             a[i]=read();
             if(a[i]%2) v1.pb(a[i]);else v2.pb(a[i]);
        }
        for(auto p:v1) cout<<p<<" ";
        for(auto p:v2) cout<<p<<" ";
        cout<<endl;
    }

    return 0;
}