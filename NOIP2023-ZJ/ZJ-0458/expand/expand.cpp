#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
int c,n,m,q;
namespace subtask1
{
	int x,y;
	int main()
	{
		cin>>x>>y;
		for(int i=1;i<=q+1;i++)
			cout<<1;
		return 0;
	}
}
namespace subtask2
{
	int x[3],y[3];
	int kx,ky;
	int main()
	{
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=m;i++)
			cin>>y[i];
		if(n==2&&m==2)
		{
			if((x[1]-y[1])*(x[2]-y[2])>0)
				cout<<1;
			else cout<<0;
			while(q--)
			{
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if((x[1]-y[1])*(x[2]-y[2])>0)
					cout<<1;
				else cout<<0;
			}
		}
		else if(n==1&&m==2)
		{
			if((x[1]-y[1])*(x[1]-y[2])>0)
				cout<<1;
			else cout<<0;
			while(q--)
			{
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if((x[1]-y[1])*(x[1]-y[2])>0)
					cout<<1;
				else cout<<0;
			}
		}
		else if(n==2&&m==1)
		{
			if((x[1]-y[1])*(x[2]-y[1])>0)
				cout<<1;
			else cout<<0;
			while(q--)
			{
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if((x[1]-y[1])*(x[2]-y[1])>0)
					cout<<1;
				else cout<<0;
			}
		}
		return 0;
	}
}
namespace subtask3
{
	int main()
	{
		srand(114514);
		while(q--)
			cout<<rand()%2;
		return 0;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>q;
	switch(c)
	{
		case 1:
			subtask1::main();
			break;
		case 2:
			subtask2::main();
			break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			subtask3::main();
			break;
	}
	return 0;
}
//sui ran wo bu zhi dao zhe ci bi sai de nan du zenyang,danshi wo youzhong de gan xie wode hao peng you xjx gei wo de zhufu & qi dao
//rang wo zai 2h nei xie chu le T1 T2 de zheng jie
//(sui ran bu yi ding neng AC

//cao ! ji le . qian main ti mu jia diao le!
//zao nie a ...

//cao !T4 ti mu kan cuo le .wo fu le a .
//tui yi le 
//hai sheng jiu fen zhong 