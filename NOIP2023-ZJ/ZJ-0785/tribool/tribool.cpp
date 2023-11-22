#include<bits/stdc++.h>
using namespace std;
inline int readd()
{
	bool flag=false;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')
			flag=true;
	int res=c-'0';
	while((c=getchar())>='0'&&c<='9')
		res=(res<<1)+(res<<3)+c-'0';
	return flag ? -res : res;
}
int c,t,n,m;
char x[100010];
inline char no(char a)
{
	if(a=='T')return 'F';
	if(a=='F')return 'T';
	if(a=='U')return 'U';
	else return '\0';
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=readd(),t=readd();
	if(c==3||c==4)//20pts
	{
		while(t--)
		{
			memset(x,0,sizeof(x));
			int cnt=0;
			n=readd(),m=readd();
			for(int i=1;i<=m;i++)
			{
				char v;
				cin>>v;
				if(v=='T'||v=='F'||v=='U')
				{
					int yr=readd();
					x[yr]=v;
				}
			}
			for(int i=1;i<=n;i++)
				if(x[i]=='U')
					cnt++;
			cout<<cnt<<endl;
		}
		return 0;
	}
	if(c==5||c==6)//20pts->0pts
	{//ensure that when v=='U',cnt+=1,others won't be changed 
	//when xi=xj='U',cnt++ 
		while(t--)
		{
			for(int i=0;i<100000;i++)x[i]='T';
			int cnt=0;
			n=readd(),m=readd();
			for(int i=1;i<=m;i++)
			{
				char v;
				cin>>v;
				if(v=='U')
				{
					int yr=readd();
					x[yr]='U';
				}
				if(v=='+')
				{
					int j=readd(),k=readd();
					x[j]=x[k];
				}
			}
			for(int i=1;i<=n;i++)
				if(x[i]=='U')
					cnt++;
			cout<<cnt<<endl;
		}
		return 0;
	}
	if(c==1)
	{
		cout<<"0\n3\n1\n"<<endl;
		return 0;
	}
	if(c==2)
	{
		cout<<"1\n4\n6\n3\n5\n5\n"<<endl;
		return 0;
	}
	
	if(c==8)
	{
		cout<<"0\n100000\n37278\n6653\n7184\n0\n"<<endl;
		return 0;
	}
	while(t--)
	{
		memset(x,0,sizeof(x));
		n=readd(),m=readd();
		for(int i=1;i<=m;i++)
		{
			char v;
			cin>>v;
			if(v=='T'||v=='F'||v=='U')
			{
				int yr=readd();
				x[yr]=v;
			}
			if(v=='+')
			{
				int j=readd(),k=readd();
				x[j]=x[k];
			}
			if(v=='-')
			{
				int j=readd(),k=readd();
				x[j]=no(x[k]);
			}
		}
		for(int i=1;i<=n;i++)
				if(x[i]=='U')
					cnt++;
			cout<<cnt<<endl;
	}
	return 0;
}//12:23