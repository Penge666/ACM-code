//认真审题，题目求的是不同本质的循环数。学一下Exkmp就会了。利用Z[数组]跑个后缀就??
#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 3e6+100 ;
char str[N];
int Next[N];
int cur[N],ans[N];

void pre_EKMP(char x[],int m){
    Next[0] = m;
    int j = 0;
    while( j+1 < m && x[j] == x[j+1] )j++;
    Next[1] = j;
    int k = 1;
    for(int i = 2; i < m; i++){
        int p = Next[k]+k-1;
        int L = Next[i-k];
        if( i+L < p+1 ) Next[i] = L;
        else{
            j = max(0ll,p-i+1);
            while( i+j < m && x[i+j] == x[j])j++;
            Next[i] = j;
            k = i;
        }
    }
}
signed main(){
    cin>>str;
    int n=strlen(str);
    pre_EKMP(str,n);
    for(int i=n-1;i>0;i--){
        cur[i]=cur[i+1];
        int len=n-i;
        if(len==Next[i]){
            cur[i]=cur[i+1]+1;
        }
    }
    ans[0]=0;
    for(int i=1;i<n;i++){
        int t=min(i,n-i-1);
        ans[i]=cur[n-t];
    }
    ans[n-1]=0;
    int Q=1;
    cin>>Q;
    while(Q--){
        int x;
        scanf("%lld",&x);
        printf("%lld\n",ans[x-1]);
    }
    return 0;
}
