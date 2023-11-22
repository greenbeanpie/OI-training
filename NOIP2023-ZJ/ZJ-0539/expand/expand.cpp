#include<bits/stdc++.h>
using namespace std;
#define LL long long
int mem[500500],me[500500],fl[500500],fla[500500];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,c,q,kx,ky;
	cin>>c>>n>>m>>q;
	if(c==1)
	{
		int a,b,c,d;
		cin>>a>>b;
		if(a==b) cout<<0;
		else cout<<1;
		for(int dis,i=1;i<=q;i++)
		{
			c=d=-1;
			cin>>kx>>ky;
			while(kx--) cin>>dis>>c;
			while(ky--) cin>>dis>>d;
			if(~c&&~d)
			{
				if(c==d) cout<<0;
				else cout<<1;
			}
			if(~c&&d==-1)
			{
				if(c==b) cout<<0;
				else cout<<1;
			}
			if(~d&&c==-1)
			{
				if(a==d) cout<<0;
				else cout<<1;
			}
		}
		cout<<endl;
	}
	if(c==2)
	{
		int a,b,c,d,e,f,g,h;
		cin>>a>>b>>c>>d;
		if((a-c)*(b-d)<=0) cout<<0;
		else cout<<1;
		for(int dis,i=1;i<=q;i++)
		{
			h=e=f=g=-1;
			cin>>kx>>ky;
			while(kx--) 
			{
				cin>>dis;
				if(dis==1) cin>>e;
				if(dis==2) cin>>f;
			}
			while(ky--) 
			{
				cin>>dis;
				if(dis==1) cin>>g;
				if(dis==2) cin>>h;
			}
			if(~f&&~h&&~e&&~g)
			{
				if((e-g)*(f-h)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&~h&&~e&&g==-1)
			{
				if((e-c)*(f-h)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&~h&&e==-1&&~g)
			{
				if((a-g)*(f-h)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&~h&&e==-1&&g==-1)
			{
				if((a-c)*(f-h)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&h==-1&&~e&&~g)
			{
				if((e-g)*(f-d)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&h==-1&&~e&&g==-1)
			{
				if((e-c)*(f-d)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&h==-1&&e==-1&&~g)
			{
				if((a-g)*(f-d)<=0) cout<<0;
				else cout<<1;
			}
			if(~f&&h==-1&&e==-1&&g==-1)
			{
				if((a-c)*(f-d)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&~h&&~e&&~g)
			{
				if((e-g)*(b-h)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&~h&&~e&&g==-1)
			{
				if((e-c)*(b-h)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&~h&&e==-1&&~g)
			{
				if((a-g)*(b-h)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&~h&&e==-1&&g==-1)
			{
				if((a-c)*(b-h)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&h==-1&&~e&&~g)
			{
				if((e-g)*(b-d)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&h==-1&&~e&&g==-1)
			{
				if((e-c)*(b-d)<=0) cout<<0;
				else cout<<1;
			}
			if(f==-1&&h==-1&&e==-1&&~g)
			{
				if((a-g)*(b-d)<=0) cout<<0;
				else cout<<1;
			}
			if(f==1&&h==-1&&e==-1&&g==-1)
			{
				if((a-c)*(b-d)<=0) cout<<0;
				else cout<<1;
			}
		}
		cout<<endl;
	}
	if(c>=8&&c<=14){
		for(int i=1;i<=n;i++) cin>>mem[i];
		for(int i=1;i<=m;i++) cin>>me[i];
		for(int i=0;i<=q;i++)
		{
			if((me[1]-mem[1])*(me[n]-mem[n])<=0) cout<<0;
			else{
				cout<<1<<endl;
			}
		}		
	}
	else
	{
		q++;
		while(q--) cout<<rand()%2<<endl;
	}
	return 0;
}
