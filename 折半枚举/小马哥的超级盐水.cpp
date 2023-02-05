/*
���⣺��n����ˮ��ÿһ��ˮ��a��λ�Σ�b��λˮ������һ��x��y�����ж����ַ��������x��y����ˮ��

��Ϊnֻ��35��û��ö��ȫ����������nֻ��һ�����ô���ǿ���ö�����������

���ǿ��԰�n��Ϊ�����֣�ö��һ���ֵ����������Ȼ�����Ƿ��ܺ���һ���ֹ��ɽ⡣

����(a1,b1)��(a2,b2)���������ϡ�

�׵�(a1+a2)/(b1+b2)=x/y��

����õ�(y*a1-x*b1)=(x*b2-y*a2)������ö��ǰ���Ȼ���Һ���ľ����ˡ�


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
