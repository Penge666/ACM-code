#include<bits/stdc++.h>
using namespace std;

#define N 666666

int arr[N];
int a[N],b[N];
int sum[N];
int n,m;

signed main(){
    int _;
    cin>>_;
    while(_--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            int minx=2000;
            int s=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){

                    sum+=arr[j];
                    s++;
                    minx=min(minx,arr[j]);
                }
            }
            if(sum>=m&&(sum-minx)<m){
                ans=max(ans,s);
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}

/*
2
5 9
4 1 3 5 4
7 37
7 5 8 8 5 10 4

*/


/*
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/
