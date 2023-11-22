#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define ve vector<ll>
#define pa pair<ll,ll>
#define pb push_back
using namespace std;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,m,k,t,b[100005],ans;
char a[10];
struct s{
	ll op;
	ll x,y;
}c[100005];
ve v,vv;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	k=rd;t=rd;
	while(t--){
		n=rd;m=rd;memset(b,0,sizeof(b));ans=0;v.clear();
		for(int i=1;i<=m;i++){
			scanf("%s",a);
			if(a[0]=='T'){
				c[i].op=1;
				c[i].x=rd;
				b[c[i].x]=1;
			}
			if(a[0]=='F'){
				c[i].op=2;
				c[i].x=rd;
				b[c[i].x]=2;
			}
			if(a[0]=='U'){
				c[i].op=3;
				c[i].x=rd;
				b[c[i].x]=3;
			}
			if(a[0]=='+'){
				c[i].x=rd;c[i].y=rd;
				c[i].op=4;
				if(b[c[i].y]>0)b[c[i].x]=b[c[i].y];
				else b[c[i].x]=0;
			}
			if(a[0]=='-'){
				c[i].x=rd;c[i].y=rd;
				c[i].op=5;
				if(b[c[i].y]>0){
					if(b[c[i].y]==1)b[c[i].x]=2;
					else if(b[c[i].y]==2)b[c[i].x]=1;
					else if(b[c[i].y]==3)b[c[i].x]=3;
				}else{
					b[c[i].x]=0;
				}
			}
		}
		for(int ii=1;ii<=900;ii++){
			for(int i=1;i<=m;i++){
				if(c[i].op==1){
					b[c[i].x]=1;
				}
				if(c[i].op==2){
					b[c[i].x]=2;
				}
				if(c[i].op==3){
					b[c[i].x]=3;
				}
				if(c[i].op==4){
					if(b[c[i].y]>0)b[c[i].x]=b[c[i].y];
					else b[c[i].x]=0;
				}
				if(c[i].op==5){
					if(b[c[i].y]>0){
						if(b[c[i].y]==1)b[c[i].x]=2;
						else if(b[c[i].y]==2)b[c[i].x]=1;
						else if(b[c[i].y]==3)b[c[i].x]=3;
					}else{
						b[c[i].x]=0;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(c[i].op==1){
				b[c[i].x]=1;
			}
			if(c[i].op==2){
				b[c[i].x]=2;
			}
			if(c[i].op==3){
				b[c[i].x]=3;
			}
			if(c[i].op==4){
				if(b[c[i].y]==0){
					if(b[c[i].x]!=3)vv.pb(b[c[i].x]),v.pb(i),b[c[i].y]=b[c[i].x];
					else vv.pb(1),v.pb(i),b[c[i].y]=1;
				}
				b[c[i].x]=b[c[i].y];
			}
			if(c[i].op==5){
				if(b[c[i].y]==0){
					if(b[c[i].x]==1)vv.pb(2),v.pb(i),b[c[i].y]=2;
					else vv.pb(1),v.pb(i),b[c[i].y]=1;
				}
				if(b[c[i].y]==1)b[c[i].x]=2;
				else if(b[c[i].y]==2)b[c[i].x]=1;
				else if(b[c[i].y]==3)b[c[i].x]=3;
			}
		}
		ll p=v.size();
		for(int i=0;i<p;i++){
			if(b[c[v[i]].y]!=vv[i]){
				b[c[v[i]].y]=3;
			}
		}
		for(int ii=1;ii<=1000;ii++)
		for(int i=1;i<=m;i++){
			if(c[i].op==1){
				b[c[i].x]=1;
			}
			if(c[i].op==2){
				b[c[i].x]=2;
			}
			if(c[i].op==3){
				b[c[i].x]=3;
			}
			if(c[i].op==4){
				if(b[c[i].y]==0)v.pb(i),b[c[i].y]=1;
				b[c[i].x]=b[c[i].y];
			}
			if(c[i].op==5){
				if(b[c[i].y]==0)v.pb(i),b[c[i].y]=1;
				if(b[c[i].y]==1)b[c[i].x]=2;
				else if(b[c[i].y]==2)b[c[i].x]=1;
				else if(b[c[i].y]==3)b[c[i].x]=3;
			}
		}
		for(int i=1;i<=n;i++)if(b[i]==3)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}/*
1 1
1000 1000
U 2
U 4
*/
