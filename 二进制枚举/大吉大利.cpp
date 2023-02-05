// 对每一位算贡献


#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 19999999999999999
#define N 666666
int arr[N];
signed main(){
    int n;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for(int i=30;i>=0;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(arr[j]&(1<<i)){
                sum++;
            }
        }
        ans+=sum*sum*(1<<i);
    }
    printf("%lld",ans);
    return 0;
}
/*
6
2 5 8 9 6 7
*/
