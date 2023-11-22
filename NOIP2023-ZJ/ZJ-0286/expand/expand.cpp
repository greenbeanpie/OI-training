#include<bits/stdc++.h>
using namespace std;
#define R read()
#define pc putchar
#define pb push_back
#define MT int TTT=R;while(TTT--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
inline int read()
{
	int x=0;
	bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') flag=1;ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(flag) return -x;
	return x;
}
template<typename T> inline void write(T x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+'0');
}

const int N=5e5+10,M=3010;
int c,n,m,q;
int x[N],y[N],a[N],b[N];
bool f[2][N];
void query()
{
	if(a[1]>b[1]&&a[n]>b[m])
	{
		memset(f,0,sizeof f);
		f[1][1]=1;
		fo(i,1,n)
		{
			int now=(i&1),pre=1-(i&1);
			fo(j,1,m) if(i!=1||j!=1)
			{
				f[now][j]=0;
				if(a[i]>b[j]) f[now][j]=f[pre][j]|f[now][j-1];
				else f[now][j]=0;
			}
		}
		if(f[n&1][m]) pc('1');
		else pc('0');
		return;
	}
	if(a[1]<b[1]&&a[n]<b[m])
	{
		memset(f,0,sizeof f);
		f[1][1]=1;
		fo(i,1,n)
		{
			int now=(i&1),pre=1-(i&1);
			fo(j,1,m) if(i!=1||j!=1)
			{
				f[now][j]=0;
				if(a[i]<b[j]) f[now][j]=(f[pre][j]|f[now][j-1]);
				else f[now][j]=0;
			}
		}
		if(f[n&1][m]) pc('1');
		else pc('0');
		return;
	}
	pc('0');
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=R,n=R,m=R,q=R;
	fo(i,1,n) x[i]=R;
	fo(i,1,m) y[i]=R;
	fo(i,1,n) a[i]=x[i];
	fo(i,1,m) b[i]=y[i];
	query();
	while(q--)
	{
		int kx=R,ky=R;
		fo(i,1,n) a[i]=x[i];
		fo(i,1,m) b[i]=y[i];
		fo(i,1,kx)
		{
			int pos=R,val=R;
			a[pos]=val;
		}
		fo(i,1,ky)
		{
			int pos=R,val=R;
			b[pos]=val;
		}
//		if(C==20)
//		{
//			fo(i,1,n) cout<<a[i]<<' ';
//			cout<<endl;
//			fo(i,1,m) cout<<b[i]<<' ';
//			cout<<endl;
//		}
		query();
	}
}