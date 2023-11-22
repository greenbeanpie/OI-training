#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int p3[]={1,3,9,27,81,243,729,2187,6561,19683,59049};
struct step{
	char v;
	int a,b;
}o[20];
int x[15],test[20];
inline int run1(int tp)
{
	memset(x,0,sizeof(x));
	memset(test,0,sizeof(test));
	int rees=0;
	for(register int i=1;i<=n;i++)
	{
		test[i]=x[i]=tp%3;
		if(x[i]==2) rees++;
		tp/=3;
	}
	for(register int i=1;i<=m;i++)
	{
		if(o[i].v=='U') x[o[i].a]=2;
		else if(o[i].v=='T') x[o[i].a]=1;
		else if(o[i].v=='F') x[o[i].a]=0;
		else if(o[i].v=='+') x[o[i].a]=x[o[i].b];
		else if(o[i].v=='-') x[o[i].a]=(x[o[i].b]==2?2:(1-x[o[i].b]));
	}
	bool flg=0;
	for(register int i=1;i<=n;i++)
	if(test[i]!=x[i]) 
	{
		flg=1;
		break;
	}
	if(flg) return -1;
	else return rees;
}
inline void subtask1()
{
	while(t--)
	{
		int ans=20;
		cin>>n>>m;
		for(register int i=1;i<=m;i++)
		{
			char c=getchar();
			while(c!='-'&&c!='+'&&c!='T'&&c!='U'&&c!='F') c=getchar();
			o[i].v=c;
			if(c=='-'||c=='+') cin>>o[i].a>>o[i].b;
			else cin>>o[i].a;
		}
		for(register int i=0;i<=p3[n];i++)
		{
			int res=run1(i);
			if(res>=0) ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
}
char qq[100005];
inline void subtask2()
{
	while(t--)
	{
		memset(qq,0,sizeof(qq));
		cin>>n>>m;
		int ans=0;
		for(register int i=1;i<=m;i++)
		{
			char c=getchar();
			int aa;
			while(c!='F'&&c!='U'&&c!='T') c=getchar();
			cin>>aa;
			qq[aa]=c;
		}
		for(register int i=1;i<=n;i++)
		if(qq[i]=='U') ans++;
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==1||c==2) subtask1();
	else if(c==3||c==4) subtask2();
	return 0;
}
