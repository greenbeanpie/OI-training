#include<bits/stdc++.h>
using namespace std;
#define For(i, l ,r) for(int i=(l);i<=(r);++i)
#define RFor(i, r ,l) for(int i=(r);i>=(l);--i)
#define O(x) cerr<<#x<<":"<<x<<endl
char getdig(){char ch=getchar();while(ch=='\n'||ch=='\r'||ch==' ')ch=getchar();return  ch;}
int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-t;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*t;
}
const int N=100005;
int fa[N+5],val[N+5],dT,dF,dU,n;
int fa_[N<<1],val_[N<<1];
int getfa_(int x)
{
	if(fa_[x]==x){return x;}
	int t=getfa_(fa_[x]);
//	O(fa_[x]);O(val_[10]);
	val_[x]^=val_[fa_[x]];
	fa_[x]=t;
//	O(x);O(val_[x]);O(fa_[x]);O(t);O(val[fa_[x]]);
	return t;
}
int sol()
{
	For(i, 1 ,n) fa_[i]=i,val_[i]=0;	// T F U
	For(i, dT, dU) fa_[i]=i,val_[i]=0;
	For(i, 1, n)
	{
		int x=i,y=fa[i];
		if(y>n*2){fa_[x]=y;val_[x]=val[i];continue;}
		y-=n;int fx=getfa_(x),fy=getfa_(y),v=val[i];	//pair i, fa[i]
//		cerr<<x<<" "<<y<<" "<<fx<<" "<<fy<<" "<<v<<" "<<val_[x]<<" "<<val_[y]<<endl;
		if(fx>n&&fy>n)continue;
		if(fx>n) swap(fx,fy),swap(x,y);
		if(fx==fy) {if((val_[x]^val_[y])!=v) fa_[fy]=dU; }
			else fa_[fx]=fy,val_[fx]=val_[x]^val_[y]^v;
//		getfa_(x);getfa_(y);
//		cerr<<val[3]<<" "<<fa[3]<<endl;
//		For(j, 1, n) cerr<<j<<" "<<fa_[j]<<" "<<val_[j]<<endl;cerr<<endl;
	}
	int res=0;
	For(i, 1, n)
		if(getfa_(i)==dU)++res;//O(i),O(getfa_(i));
	return res;
}
void show()
{
	For(i, 1, n)
	{
		cerr<<i<<" ";
		if(fa[i]==dT)cerr<<"T";
		else if(fa[i]==dF)cerr<<"F";
		else if(fa[i]==dU)cerr<<"U";		
		else cerr<<fa[i]-n;
		cerr<<" "<<val[i]<<endl;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);	
	int C=read(),T=read();
	while(T--)	//
	{
		n=read();int m=read();
		dT=2*n+1,dF=2*n+2,dU=2*n+3;
			//1...n x_now i n+1, n+1...2n xi  2n+1 T  2n+2,F  2n+3,U    
		For(i, 1, n) fa[i]=i+n,val[i]=0;
		For(i, 1, m)
		{
			char op=getdig();int x=read();
			if(op=='T')fa[x]=dT;
			else if(op=='F')fa[x]=dF;
			else if(op=='U')fa[x]=dU;
			else
			{
				int y=read(),fx=fa[x],fy=fa[y];
				if(op=='+')fa[x]=fy,val[x]=val[y];
				if(op=='-')fa[x]=fy,val[x]=val[y]^1;
			}
		}
//		show();
//		cerr<<"S"<<endl;
		int t;
		printf("%d\n",t=sol());
//		O(t);
	}
	return 0;
}
