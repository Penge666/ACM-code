//˼·���ǱȽ�������
//�Ȱ�ԭ����Ϊ�����֣�ǰ׺ ��׺ �м�
//����acbba �ֳ�a+cbb+a
//Ȼ����м���������������0��ͷ������len-1��β�Ļ��Ĵ�
//�𰸾���ǰ׺+����Ĵ�+��׺
//
#include<bits/stdc++.h>
#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define mst(a,x) memset(a, x, sizeof(a))
#define rep(i,s,e) for(int i=s; i<e; ++i)
#define dep(i,e,s) for(int i=e; i>=s; --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6 + 5;
string s; int n;
int seed,mod,hs1[maxn],hs2[maxn],bas[maxn]; // hs�������
void init(int* hs){
        s=' '+s;
         bas[0]=1; rep(i,1,n+1){
        bas[i]=1ll*bas[i-1]*seed%mod;
        hs[i]=1ll*hs[i-1]*seed%mod+s[i];
        if(hs[i]>=mod) hs[i]-=mod;
    }
}
int getsum(int *h,int l,int r){
    int res=h[r]-1ll*h[l-1]*bas[r-l+1]%mod;
    if(res<0) res+=mod;
    return res;
}
void hash_init(){
    seed=31,mod=998244353 ; init(hs1);
    reverse(s.begin(),s.end()); init(hs2);
}
void solve(){
    cin>>s; int l=0,r=s.size()-1,p(0),q(0);
    while(s[l]==s[r]&&l<r) l++,r--;
    string t1=s.substr(0,l),t2=s.substr(r+1);
    s=s.substr(l,r-l+1); n=s.size(); hash_init();
    rep(i,1,n+1) if(getsum(hs1,1,i/2)==getsum(hs2,n-i+1,n-(i+1)/2)) p=i;
    rep(i,1,n+1) if(getsum(hs2,1,i/2)==getsum(hs1,n-i+1,n-(i+1)/2)) q=i;
    if(p>q){
        reverse(s.begin(),s.end());
        // ���ڵ�s��' '+s+' ' ����Ҫ��1��ʼ
        cout<<t1+s.substr(1,p)+t2<<'\n';
    } else cout<<t1+s.substr(1,q)+t2<<'\n';
}
int main(){
    int _; sc(_); while(_--) solve();
}
