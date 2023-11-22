#include<bits/stdc++.h>
#define N (100005)
using namespace std;
string s[N][5];
int n,m,c,T,minn,TT;
int q[N],w[N];
int f(int l,int r){int u=r-l+1;return (rand()%u+u)%u;}
int ch(int x,int y){int nu=0;for(auto i:s[x][y])nu=nu*10+(i^48);return nu;}
bool check();
bool checkk()
{
	for(int i=1;i<=m;++i)
	  {
	    int k=w[ch(i,2)];
		if(s[i][0]=="-") 
  	      w[ch(i,1)]=(k==3?3:3-k);
		else
	      w[ch(i,1)]=k;
	  }
	for(int i=1;i<=n;++i) q[i]=w[i];
	return check();
}
bool check()
{
	for(int i=1;i<=n;++i) w[i]=q[i];
	for(int i=1;i<=m;++i)
	  if(s[i][0]=="T") w[ch(i,1)]=1;
	  else if(s[i][0]=="F") w[ch(i,1)]=2;
	  else if(s[i][0]=="U") w[ch(i,1)]=3;
	  else 
	    {
	      int k=w[ch(i,2)];
		  if(s[i][0]=="-") 
		    w[ch(i,1)]=(k==3?3:3-k);
		  else
		    w[ch(i,1)]=k;
	    }
	for(int i=1;i<=n;++i) 
	  if(w[i]!=q[i]) 
	    return 0; 
	return 1;
}
void dfs(int x,int p)
{
	if(x==n)
	  {
	  	if(check()) minn=min(minn,p);
	  	return ;
	  }
	q[x+1]=1,dfs(x+1,p);
	q[x+1]=2,dfs(x+1,p);
	q[x+1]=3,dfs(x+1,p+1);
	return ;
}
void sub12()
{
	minn=1e9;
	dfs(0,0);
	cout<<minn<<'\n';
	return ;
}
void sub34()
{
	int cnt=0;
	for(int i=1;i<=n;++i) q[i]=0;
	for(int i=1;i<=n;++i)
	  if(s[i][0]=="T") w[ch(i,1)]=1;
	  else if(s[i][0]=="F") w[ch(i,1)]=2;
	  else if(s[i][0]=="U") w[ch(i,1)]=3;
	  else 
	    {
	      int k=w[ch(i,2)];
		  if(s[i][0]=="-") 
		    w[ch(i,1)]=(k==3?3:3-k);
		  else
		    w[ch(i,1)]=k;
	    }
	for(int i=1;i<=n;++i)cnt+=(q[i]==3);
	cout<<cnt<<'\n';
	return ;
}
void sub56()
{
	int cnt=0;
	for(int i=1;i<=n;++i) q[i]=0;
	for(int k=1;k<=n;++k)
	  {
  	    for(int i=1;i<=m;++i)
	      if(s[i][0]=="U") q[ch(i,1)]=3;
	      else if(s[i][0]=="+")
	        q[ch(i,1)]=q[ch(i,2)];
	  }
	for(int i=1;i<=n;++i) 
	  cnt+=(q[i]==3);
	cout<<cnt<<'\n';
	return ;
}
void sub78()
{
	for(int i=1;i<=n;++i)
	  {
	  	q[i]=1;
	  	if(check()) continue;
	  	else 
	  	  {
	  	  	q[i]=2;
			if(check()) continue;	
		    else q[i]=3;
		  }
	  }
	int cnt=0;
	for(int i=1;i<=n;++i)
	  cnt+=(q[i]==3);
	cout<<cnt<<'\n';
	return ;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	  {
	  	cin>>s[i][0]>>s[i][1];
	  	if(s[i][0]=="+"||s[i][0]=="-") 
	  	  cin>>s[i][2];
	  }
	if(c<=2) sub12();
	else if(c==3||c==4) sub34();
	else if(c==5||c==6) sub56();
	else if(c==7||c==8) sub78(); 
	return void();
}
signed main(void)
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	cin>>c>>T,TT=T;
	for(;T--;)solve();
	return 0;
}
/* 
ÔÝÇÒÐ´¸ö50·ÖµÄ 
*/
