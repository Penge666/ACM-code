#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef unsigned long long ll;
const int MAXN=2e5+5;
int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}
int n,k;
string s;
ll Hash[MAXN],p[MAXN];
bool check(int x)
{
    map<ll,pair<int,int> >mp;
    for(int i=x;i<=n;i++)
    {
        ll val=Hash[i]-Hash[i-x]*p[x];
        if(i-mp[val].first>=x)
        {
            mp[val].first=i;
            mp[val].second++;
        }
        if(mp[val].second>=k)return true;
    }
    return false;
}
int main()
{
    cin>>n>>k;
    cin>>s;
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*233;
        Hash[i]=Hash[i-1]*233+s[i-1];
    }
    int l=1;int r=n/k;
    int res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))
        {
            res=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<res<<endl;
    return 0;
}
