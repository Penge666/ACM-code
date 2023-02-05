#include <cstdio>
#include <cstring>

using namespace std;
#define int long long
const int MAX_N=1010000;


//****************
int n,m;
int S[MAX_N],T[MAX_N];
int next[MAX_N];

void getNext(){
    int j,k;
    j=0,k=-1;
    next[0]=-1;
    while(j<m){
        if(k==-1||T[j]==T[k]){
            next[++j]=++k;
        }else{
            k=next[k];
        }
    }
    return ;
}
int KMP_index(){
    int i=0,j=0;
    while(i<n&&j<m){
        if(j==-1||S[i]==T[j]){
            j++,i++;
        }else{
            j=next[j];
        }
    }
    if(j==m) return i-m;else return -1;
}

signed main(){
    int _;
    scanf("%lld",&_);
    while(_--){
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<n;i++) scanf("%lld",&S[i]);
        for(int i=0;i<m;i++) scanf("%lld",&T[i]);
        getNext();
        int ans=KMP_index();
        if(ans!=-1) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
