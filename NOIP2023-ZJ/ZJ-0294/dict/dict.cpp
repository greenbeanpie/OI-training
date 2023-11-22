#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,a[N][26],ans[N],tmp1[26],tmp2[26];
string s[N];
bool check(int x,int y)
{
    int p1=0,p2=25;
    for(int i=0;i<26;i++)
    {
        tmp1[i]=a[x][i];
        tmp2[i]=a[y][i];
    }
    for(int i=0;i<26;i++)
    {
        while(!tmp1[p1]) p1++;
        while(!tmp2[p2]) p2--;
        if(p2>p1) return true;
        else if(p2<p1) return false;
        tmp1[p1]--,tmp2[p2]--;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i]; 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++) a[i][s[i][j]-'a']++;
        ans[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==i) continue;
            if(!check(i,j))
            {
                ans[i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<endl;
    return 0;
}