#include<bits/stdc++.h>
#define N (3005)
using namespace std;
string s,mx[N],mi[N];
int n,m;
signed main(void)
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	  {
	  	cin>>s;
	  	sort(s.begin(),s.end()),mi[i]=s;
	  	reverse(s.begin(),s.end()),mx[i]=s;
	  }
	for(int i=1;i<=n;++i)
	  {
	  	bool fl=1;
	  	for(int j=1;j<=n;++j)
	  	  if(i!=j&&mx[j]<=mi[i])
	  	    {fl=0;break;}
	  	cout<<fl;
	  }
	cout<<'\n';
	return 0;
}
/*
真的想不出别的做法了 
*/
