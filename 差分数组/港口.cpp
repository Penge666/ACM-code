/*
我们求出差分数组dif的话，根据题意，我们就是要让dif都为0，此时就是大家都一样了。

而一段区间[l,r]内加上一个数a的话，便是在差分数组上的体现就是dif[l]+a,dif[r+1]-a。

所以，我们要最少操作次数的话，每次肯定是选取dif[l]跟dif[r]一正一负的来进行一个操作。

而多次来的那些正的或者是负的dif，则让每次操作l=0,或者r=n+1，也就是从开始到这个位置，或者这个位置到结尾的区间都加上a即可。

这题里a是1，所以答案就是max(所有正的dif和，所有负的dif的绝对值和）。

而多说一点，相同的种数的话便是所有dif的总和的绝对值+1,因为1个是最终相同的，而它可以更改的范围就是多出来的dif进行搭配，由此不改变方案数。


*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
#define inf  999999999999999
int a[N];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s1=0,s2=0,ans=0;
    for(int i=2;i<=n;i++){
        int D=a[i]-a[i-1];
        if(D>0) s1+=D;else s2+=abs(D);
    }
    ans=max(s1,s2);cout<<ans;
    return 0;
}
/*
2 3 2 3

*/
