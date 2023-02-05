/*
直接暴力二进制枚举即可。QAQ

状压枚举行，复杂度 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
char mp[66][100900];
int lie[N];
int arr[N];
signed main(){
    int T;
    scanf("%lld",&T);
    while(T--){
        int n,m,a,b;
        scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
        for(int i=0;i<=m+1;i++){
            arr[i]=0,lie[i]=0;
        }
        for(int i=1;i<=n;i++){
            scanf("%s",mp[i]+1);
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='*')
                    lie[j]++;
            }
        }
        int F=0;
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            for(int k=1;k<=m;k++) arr[k]=lie[k];
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum++;
                    for(int k=1;k<=m;k++){
                        if(mp[j+1][k]=='*') arr[k]--;
                    }
                }
            }
            if(sum>a) continue;

            int add=0;
            for(int k=1;k<=m;k++){
                if(arr[k]>0) add++;
            }
            if(add<=b){
                printf("yes");
                F=1;
                break;
            }
        }
        if(!F) printf("no");
        printf("\n");
    }

    return 0;
}
