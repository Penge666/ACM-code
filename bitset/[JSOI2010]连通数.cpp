#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 6666
char mp[N][N];
int n;
bitset<N> s[N];
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",mp[i]);
        for(int j=0;j<n;j++){
            if(i==j){
                s[i][j]=1;
            }else{
                s[i][j]=mp[i][j]-'0';
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if(s[i][j])
            s[i]|=s[j];

    int ans=0;
    for(int i=0;i<n;i++) ans+=s[i].count();
    cout<<ans;
    return 0;
}
