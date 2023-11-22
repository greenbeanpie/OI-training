#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int read(){
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int n,m;
string s[maxn];
int mn[maxn],mx[maxn];

signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	For(i,1,n){
		cin>>s[i];
		mn[i]=inf,mx[i]=0;
		for(auto c:s[i]){
			int x=c-'a'+1;
			mn[i]=min(mn[i],x);
			mx[i]=max(mx[i],x);
		}
	}
	For(i,1,n){
		bool ok=1;
		For(j,1,n)if(i!=j){
			if(mn[i]<mx[j]);
			else{
				ok=0;
				break;
			}
		}
		cout<<ok;
	}
	return 0;
}
/*
shaber dayangli.
*/