//����a��һ��װ�������ŵģ�����һ��1��װ�������ֻ��������1������װ����
//����һ��a��װ����������Ҫ���ٶ������װ������������Ŵ����߶��ǵݼ���
//
//��Ŀ���ӣ�https://ac.nowcoder.com/acm/contest/4743/C

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
int x,y;
int cal(int tmp){
    return (tmp+max(min((x-2*tmp)/4,y-3*tmp),0));
}
int solve(int l,int r){
    while(r - l > 10){
        int m1 = l+(r-l)/3,m2 = r - (r-l)/3;
        if(cal(m1) > cal(m2)) r = m2;
        else l = m1;
    }
    int ans = 0;
    for(int i = l;i <= r;i++)
        ans = max(ans,cal(i));
    return ans;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        cin>>x>>y;
        int l = 0,r = min(x/2,y/3);
        printf("%d\n",solve(l,r));
    }
    return 0;
}
