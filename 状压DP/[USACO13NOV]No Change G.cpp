//��⣺dp[i]�У�i��ʾ��ǰʹ�õĻ���״̬��dp[i]��ʾʹ����Щ���ҿ��Ե������Ʒλ��
//����ô����ö�����еĿ�ѡ״̬������ÿһ��״̬ö�ٵ�ǰѡ��Ļ��ң� ����״̬pi����������ö�ٵ�ǰѡ��Ļ���ci����dp[pi]=max(dp[pi],find(sum[dp[pi^(1<<ci)]]+coin[ci]));
//���У�sum[i]��ʾ�ӵ�һ����Ʒ����i����Ʒ��ǰ׺�ͣ�������һ������򵥼���һ��


#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 17 ,  M = 1<<17 , inf = 0x3f3f3f3f;
int dp[M];//dp[s]:����״̬s���ܵ���������Ʒ
int n,k,a[M],b[M],sum[M];
int slove(int tmp,int money){
    int l=tmp,r=n,idx=tmp;
    while(l<=r){
        int mid=(l+r)/2;
        int num=sum[mid]-sum[tmp];
        if(num<=money){
            idx=max(idx,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return idx;
}
signed main(){
    cin>>k>>n;
    for(int i=0;i<k;i++)  cin>>a[i];
    sum[0]=0;
    for(int i=1;i<=n;i++) cin>>b[i],sum[i]=sum[i-1]+b[i];
    //for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
    //cout<<slove(1,9)<<'\n';
    for(int s=0;s<(1<<k);s++){
        for(int i=0;i<k;i++){
            if((s&(1<<i))){
                dp[s]=max(dp[s],slove(dp[s^(1<<i)],a[i]));
            }
        }
    }
    int ans=-1;
    for(int i=0;i<(1<<k);i++){
        if(dp[i]>=n){
            int sum=0;
            for(int j=0;j<k;j++){
                if(!((1<<j)&i)){
                    sum+=a[j];
                }
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans;
    return 0;
}
