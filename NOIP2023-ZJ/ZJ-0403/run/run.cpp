#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
ll C,T,N,M,K,D;
ll X[maxn],Y[maxn],V[maxn];
struct store
{
	int x,y,v;
	bool operator<(const store & b) const
	{
		return x < b.x;
	}
};
ll f[maxn][2];
vector<store> sto;
inline ll read()
{
	char ch=getchar(); bool is=false; ll ans=0;
	while(ch < '0' || '9' < ch)
	{
		if(ch == '-') is=true;
		ch=getchar();
	}
	while('0' <= ch && ch <= '9')
	{
		ans = ans*10 + (ch - '0');
		ch = getchar();
	}
	return is?-ans:ans;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=read(); T=read();
	ll x,y,v;
	while(T--)
	{
		N=read(); M=read(); K=read(); D=read();
		ll ans = 0;
		if(C == 1 || C == 2)
		{
			for(int i=1;i<=M;i++)
			{
				X[i]=read(); Y[i]=read(); V[i]=read();
			}
			for(int i=1;i<(1<<N);i++)
			{
				bool iss = true;
				for(int j=1;j<=__lg(i);j++)
				{
					for(int k=0;k<=K;k++)
					{
						if(!((i>>(j+k-1))&1)){iss=false; break;}
					}
					if(iss) break;
				}
				if(iss) continue;
				ll tmp = 0;
				for(int j=1;j<=M;j++)
				{
					iss = true;
					for(int k=X[j]-Y[j]+1;k<=X[j];k++)
					{
						if(!((i>>(k-1))&1)){iss=false; break;}
					}
					if(iss) tmp += V[j]-Y[j]*D;
				}
				ans = max(ans,tmp);
			}
			cout<<ans<<endl;
		}
		if(C == 17 || C == 18)
		{
			for(int i=1;i<=M;i++)
			{
				x=read(); y=read(); v=read();
				if(v <= y*D || y > K) continue;
				ans += v - y * D;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}