#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
struct str{
    int pos;
    int val;
};
deque<str> q;
int arr[N];
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    for(int i=1;i<=k;i++){
        while(!q.empty()&&arr[i]>q.front().val) q.pop_front();
        q.push_front((str){i,arr[i]});
    }
    printf("%lld\n",q.back().val);
    for(int i=k+1;i<=n;i++){
        while(!q.empty()&&arr[i]>q.front().val) q.pop_front();
        q.push_front((str){i,arr[i]});
        while(!q.empty()&&q.back().pos<=i-k) q.pop_back();
        printf("%lld\n",q.back().val);
    }
    return 0;
}
