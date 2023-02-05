/*
题意：有一个没有游标的天平，和n个秤砣，m个询问， 每次一个k，问可否秤出k这个重量。 秤砣可以放两边。

思路：我们可以二进制枚举每一个子集，还要注意一点就是，比如我我们有两个秤砣：2、8；我们不仅记录2、8、2+8、还要记录8-2这种情况，所以每次再跑一遍， 减去每个的重量标记即可。


*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define N 2666
int arr[N];
int vis[N];
signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<=2000;i++) vis[i]=0;
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    //    sort(arr+1,arr+1+n);
        for(int i=0;i<(1<<n);i++){
            int s=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    s+=arr[j];
                }
            }
            vis[s]=1;
            for(int j=0;j<n;j++){
                if(s-arr[j]>=0) vis[s-arr[j]]=1;

            }
        }
        int m;
        scanf("%d",&m);
        while(m--){
            int q;
            scanf("%d",&q);
            if(vis[q]) printf("YES");
            else printf("NO");
            printf("\n");
        }
    }
    return 0;
}
