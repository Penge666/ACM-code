/*

˼·�����͵�״ѹdp����Ϊ�ӵ������٣���������Ŀ��ʱ���Դ�Ҫ�����
���ȣ��������к�һ��״̬�����Բ��ý���ǰһ��״̬�ϡ������Ҫ����ǰһ��״̬��ֻ��������� 1����ǰ����û�б��ù� 2.��һ�����͵�ǰ�������ͬ��
ͨ����������з��̡�
dp(i,j,k)����ʾ��ǰ�Ѿ�������iλ,��ǰ״̬Ϊj(��˼�ǵ�ǰ�Ѿ�ȡ�������ı��)��kΪ���һ�������ķ�����
ת�Ʒ��̿�����
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 2e3+100 ;
const int Mod = 998244353;
int n;
int dp[N][2000][11];
char str[N];
int arr[N];
signed main(){
    cin>>n>>(str+1);
    for(int i=1;i<=n;i++) arr[i]=str[i]-'A';
    //��ʼ��
    for(int i=1;i<=n;i++) dp[i][(1<<arr[i])][arr[i]]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<10);j++){
            for(int k=0;k<10;k++){
                dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%Mod;
                if(arr[i+1]==k){
                    dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%Mod;
                }
                if((!((1<<arr[i+1])&j))){
                    dp[i+1][j|(1<<arr[i+1])][arr[i+1]]=(dp[i+1][j|(1<<arr[i+1])][arr[i+1]]+dp[i][j][k])%Mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<10);i++){
        for(int j=0;j<10;j++){
            if(i&(1<<j))
                ans=(ans+dp[n][i][j])%Mod;
        }
    }
    cout<<ans;
    return 0;
}

//dp[i][j][k]:��ǰ�Ѿ�������iλ����ǰ�ļ���Ϊj(000000) ,�����һλΪk�ķ�����

/*

*/
