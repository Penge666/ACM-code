/*
�����ֲ�����1.�����������һ������������ȼ���������Ԫ�ض���
2.�ڸü���ȡһ�Ӽ�ʹ���Ӽ��ļ�ֵ��󣬲������ֵ
��ֵ�Ǹ��Ӽ�������ֵ-����Ӽ���ƽ��ֵ

������t�������������ݰ��ղ������

������
�������һ�£�ÿһ��2�����������Ǵ����ڵļ�����ȡ����Ԫ�أ�Ȼ����������죨����������򣩣���ʹ�ü�ֵ�����Ӽ�
����̰�ġ�
��������Ϊ����ҵĹ��̣������ֵ�������±�������һ������ͻ�����ߣ����Ծ���Ҫ���ֲ���
����������10λС���Ĵ𰸾Ϳ�����

�Ƽ����ֲ��ͣ�https://blog.csdn.net/u011787119/article/details/44598871

���ֿ����ڲ��Ҽ�ֵ����


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
