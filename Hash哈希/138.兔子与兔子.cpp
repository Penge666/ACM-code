#include<bits/stdc++.h>
using namespace std;
#define int long long
#define base 131
#define N 1666666
#define mod 1000000007
int sum[N];
char str[N];
int Hash[N];
int f[N];
signed main(){
    scanf("%s",str+1);
    int len=strlen(str+1);
    f[0]=1;
    for(int i=1;i<=len;i++){
        Hash[i]=base*(Hash[i-1])+str[i]-'a'+1;
        f[i]=(f[i-1]*base);
    }
    int m;
    cin>>m;
    while(m--){
        int l1,l2,r1,r2;
        scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
        if((Hash[r1]-Hash[l1-1]*f[r1-l1+1])==(Hash[r2]-Hash[l2-1]*f[r2-l2+1]))
            cout<<"Yes"<<'\n';
        else
            cout<<"No"<<'\n';
    }
    return 0;
}
