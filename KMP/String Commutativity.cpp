// KMP判断长度为n的字符串是否存在循环节。

#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 9999999967;
using namespace std;
namespace fastIO {
    inline void input(int& res) {
        char c = getchar();res = 0;int f = 1;
        while (!isdigit(c)) { f ^= c == '-'; c = getchar(); }
        while (isdigit(c)) { res = (res << 3) + (res << 1) + (c ^ 48);c = getchar(); }
        res = f ? res : -res;
    }
    inline ll qpow(ll a, ll b) {
        ll ans = 1, base = a;
        while (b) {
            if (b & 1) ans = (ans * base % mod +mod )%mod;
            base = (base * base % mod + mod)%mod;
            b >>= 1;
        }
        return ans;
    }
}
using namespace fastIO;
const int N = 1e6 + 5;

int Case,n,len;
string s;
int nxt[N];

void solve(){
    map<string,int> vis;
    ll res = 0;
    for(int i=1;i<=n;i++){
        cin>>s;
        len =s.size();
        int t = len;
        int j=0,ans,k=-1;
        len=s.size();
        nxt[0]=-1;
        while(j<=len){
            if(k==-1||s[j]==s[k])
                nxt[++j]=++k;
            else
                k=nxt[k];
        }
        ans = len%(len-nxt[len])?1:len/(len-nxt[len]);
        s=s.substr(0,len/ans);
        res += vis[s];
        vis[s]++;
    }
    printf("%lld\n",res);
}

int main(){
    //init();javascript:void(0);
    Case=1;
    //scanf("%d",&Case);
    while(~scanf("%d",&n)){
        solve();
     }
    return 0;
}
