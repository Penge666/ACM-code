// 1.ֱ�ӱ��ѣ����ѽ����С��������

#include<bits/stdc++.h>

using namespace std;
const int N = 22;
int ans,n,m,arr[N];
int g[N];//������

//u:��ǰ���˶��ٸ���  cnt����ǰ�ֳ��˶�����
void dfs(int u,int cnt){
    if(cnt>=ans) return ;
    if(u==n){
        ans = cnt;
        return ;
    }
    for(int i=0;i<cnt;i++){
        if(g[i]+arr[u+1]<=m){
            g[i]+=arr[u+1];
            dfs(u+1,cnt);
            g[i]-=arr[u+1];
        }
    }
    g[cnt]+=arr[u+1];
    dfs(u+1,cnt+1);
    g[cnt]-=arr[u+1];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ans=n;
    dfs(0,0);//���˶��ٸ��������˶�����
    cout<<ans;
    return 0;
}

//״ѹDP


//dp[i]�ʹ���ǰ״̬Ϊiʱ��С�ĳ˵��ݴ���
//dw[i]�ʹ���ǰ״̬Ϊiʱʣ��Ŀռ�
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20 , M = 1<<21 , inf = 0x3f3f3f3f;
int n,m,w[N];
int dp[M];
int dw[M];//״̬s�¿��Էŵ�����ֵ
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>w[i];
    dp[0]=1,dw[0]=m;
    for(int s=0;s<(1<<n);s++){
        for(int j=0;j<n;j++){
            if((1<<j)&s) continue;
            if(dw[s]>=w[j]){
                dp[s|(1<<j)]=dp[s];
                dw[s|(1<<j)]=max(dw[s|(1<<j)],dw[s]-w[j]);
            }else{
                dp[s|(1<<j)]=dp[s]+1;
                dw[s|(1<<j)]=max(dw[s|(1<<j)],m-w[j]);
            }
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}
