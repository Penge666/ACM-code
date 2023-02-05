/*
题意：给n杯盐水，每一杯水有a单位盐，b单位水。给你一个x和y，问有多少种方法能配成x比y的盐水。

因为n只有35，没法枚举全部情况，如果n只有一般大，那么我们可以枚举所有情况。

我们可以把n分为两部分，枚举一部分的所有情况，然后找是否能和另一部分构成解。

对于(a1,b1)和(a2,b2)这两个集合。

易得(a1+a2)/(b1+b2)=x/y。

化简得到(y*a1-x*b1)=(x*b2-y*a2)。所以枚举前面的然后找后面的就行了。


*/
#include <iostream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll ai,bi;
}a[105];
ll b[1<<19];
map<int,int> VIS;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n;
        VIS.clear();
        ll x,y;cin>>n>>x>>y;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].ai>>a[i].bi;
        }
        int p=0;
        ll n1=n/2;
        ll n2=n-n1;
        ll m1=(1<<n1);
        ll m2=(1<<n2);
        for(int i=0;i<(m2);i++)
        {
            ll sum=0;
            for(int j=0;j<n2;j++)
            {
                if((i>>j)&1)
                {
                    sum+=a[j+n1].bi*x-a[j+n1].ai*y;
                }
            }
            VIS[sum]++;
            //cout<<ans-1<<endl;
        }

        sort(b,b+p);
        ll ans=0;
        for(int i=0;i<m1;i++)
        {
            ll sum=0;
            for(int j=0;j<n1;j++)
            {
                if((i>>j)&1)
                {
                    sum+=a[j].ai*y-a[j].bi*x;
                }
            }
           ans+=VIS[sum];
        }
        cout<<ans-1<<endl;
    }

    return 0;
}
