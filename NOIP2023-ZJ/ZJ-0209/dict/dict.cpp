#include<bits/stdc++.h>
using namespace std;
int n,m,a[3001][31],mi[3001],mx[3001];
string s;
bool tt;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		mi[i]=10001;
	    cin>>s;
	    for(int j=1;j<=m;j++)
	      a[i][s[j-1]-'a']++,mi[i]=min(mi[i],s[j-1]-'a'),mx[i]=max(mx[i],s[j-1]-'a');
	}
	for(int i=1;i<=n;i++)
	{
		tt=false;
		for(int j=1;j<=n;j++)
	      if(i!=j)
	      {
			if(mi[i]>=mx[j])
			{
				tt=true;
				break;
			}	
		  }
	    if(!tt)
	      cout<<1;else
	      cout<<0;
    }
    return 0;
}