#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);	
	cin>>c>>t;
	while(t--)
	{
		ll an=0,m,n,x[100005],a,b;
		char ch;
		cin>>n>>m;
		if(c==3||c==4)
		{
			for(int i=0;i<m;i++)
			{
				cin>>ch>>a;
				if(ch=='U')
					x[a]=2;
				else 
					x[a]=0;
			}
			for(int i=0;i<n;i++)
				if(x[a]==2)
					an++;
		}
		else if(c==1||c==2)
		{
			char cc[15];
			ll l[15],r[15],g[15];
			for(int i=0;i<m;i++)
			{	
				cin>>cc[i];
				if(cc[i]=='+'||cc[i]=='-')cin>>l[i]>>r[i];
				else cin>>g[i];
				an+=g[i];
			}
		}
		else
		{
			ll f_=0,f1_=0,v[100005];
			for(int i=0;i<m;i++)
			{	
				cin>>ch;
				if(ch!='+')f_=1;
				if(ch!='-')f1_=1;
				if(ch=='+'||ch=='-')cin>>a>>b;
				else cin>>a;
				if(ch=='-'){
					v[a]++;v[b]++;
				}
			}
			if(f_==0)an=0;
			else if(f1_==0)
			{
				for(int i=0;i<n;i++)
					if(v[i]!=0)
						an++;			
			}
	//		else
	//		{
	//		
	//		}
		}
		cout<<an<<'\n';	
	}
	return 0;
}
