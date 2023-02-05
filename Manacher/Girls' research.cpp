#include<stdio.h>
#include<iostream>
#include<string.h>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn], s_new[maxn*2];
int Index, len, p[maxn*2];
int init()
{
    int j = 0;
    s_new[j++] = '$';
    s_new[j++] = '#';
    for(int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    return j;
}

int Manacher()
{
    int n = init();
    int mx = 0, id;
    int max_len = -1;
    for(int i = 1; i < n; i++)
    {
        if(i < mx)
        {
            p[i] = min(p[id*2-i], mx-i);
        }
        else
        {
            p[i] = 1;
        }
        while(s_new[i-p[i]] == s_new[i+p[i]]) p[i]++;
        if(p[i]+i > mx)
        {
            mx = p[i]+i;
            id = i;
        }
        if(max_len < p[i]-1)
        {
            max_len = max(max_len, p[i]-1);
            Index = i;
        }
    }
    return max_len;
}

int main()
{
    char c;
    ios::sync_with_stdio(false);
    while(cin >> c)
    {
        mem(p, 0);
        cin >> s;
        len = strlen(s);
        int v = c-'a';
        for(int i = 0; i < len; i++)
        {
            s[i] = (s[i]-'a'-v+26)%26+'a';
        }
        int ans = Manacher();
        if(ans == 1)
        {
            cout << "No solution!" << endl;
        }
        else
        {
            int L = Index-ans+1;
            int R = Index+ans-1;
            int l = L/2-1, r = R/2-1;
            cout << l << " " << r << endl;
            for(int i = L; i <= R; i++)
            {
                if(s_new[i] != '#' && s_new[i] != '$')
                {
                    cout << char(s_new[i]);
                }
            }
            cout << endl;
        }
        mem(s, 0);
        mem(s_new, 0);
    }
    return 0;
}
