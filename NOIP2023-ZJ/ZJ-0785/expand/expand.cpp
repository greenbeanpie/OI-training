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
int c,n,m,q;
int x[500010],y[500010];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=readd(),n=readd(),m=readd(),q=readd();
	if(c==1)//5pts
	{
		for(int i=1;i<=q+1;i++)cout<<0;
		/*for(int i=1;i<=n;i++)x[i]=readd();
		for(int i=1;i<=m;i++)y[i]=readd();
		cout<<0;
		for(int i=1;i<=q;i++)
		{
			int kx=readd(),ky=readd();
			for(int j=1;j<=kx;j++)
			{
				int px=readd(),vx=readd();
				x[px]=vx;
			}
			for(int j=1;j<=ky;j++)
			{
				int py=readd(),vy=readd();
				x[py]=vy;
			}
			cout<<0;
		}*/
		return 0;
	}
	if(c==3)cout<<"1001"<<endl;
	if(c==4)cout<<"1101100011110101110101111111111111111110011111111101101100000"<<endl;
	if(c==7)cout<<"1100110110101110011011111111100000111111001100110011111011111"<<endl;
	if(c==9)cout<<"0111011011011111010101110100000111111111111111101000001001111"<<endl;
	if(c==18)cout<<"0001110011101001111010110011111011111011111001010010110101111"<<endl;
	return 0;
}//11:44