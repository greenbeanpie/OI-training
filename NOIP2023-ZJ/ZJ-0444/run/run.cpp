#include <bits/stdc++.h>
using namespace std;
#define wr(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
const int N=114514;
int read(){
	int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll c,t;
ll n,m,k,d;
ll ans;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c==17||c==18){
		while(t--){
			n=read(),m=read(),k=read(),d=read();
			ll x,y,z;
			ans=0;
			wr(i,1,m){
				x=read(),y=read(),z=read();
				if(z-y*d>0&&y<=k) ans+=(z-y*d);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}