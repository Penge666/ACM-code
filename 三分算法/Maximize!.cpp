/*
有两种操作，1.往集合里面加一个数，这个数比集合里所有元素都大
2.在该集合取一子集使得子集的价值最大，并输出价值
价值是该子集中最大的值-这个子集的平均值

下列有t组操作，请你根据按照操作输出

解析：
这道题想一下，每一次2操作，绝对是从现在的集合里取最大的元素，然后从左到右延伸（这个集合有序），找使得价值最大的子集
这是贪心。
这样又因为这个找的过程，这个价值曲线随下标增大是一个向上突的曲线，所以就需要三分查找
这样最后输出10位小数的答案就可以了

推荐三分博客：https://blog.csdn.net/u011787119/article/details/44598871

三分可用于查找极值问题


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int sum[N],arr[N];
int cnt;
double check(int x){
    double ans=(x*arr[cnt]-sum[x])*1.0/(x+1);
    return ans;
}
int slove(int l,int r){
    while(l+1<r){
        int midl=(l+r)/2;
        int midr=(midl+r)/2;
        if(check(midl)>=check(midr)){
            r=midr;
        }else{
            l=midl;
        }
    }
    if(check(l)>check(r)) return l;
    else return r;
}
signed main(){
    cnt=0;
    int _;
    cin>>_;
    while(_--){

        sum[0]=0;
        int op;
        cin>>op;
        if(op==1){
            cnt++;
            cin>>arr[cnt];
            sum[cnt]=sum[cnt-1]+arr[cnt];

        }else{
            int ans=slove(1,cnt-1);

            printf("%.10f\n",check(ans));
        }
    }
    return 0;
}
