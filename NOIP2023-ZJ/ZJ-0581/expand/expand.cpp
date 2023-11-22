#include<bits/stdc++.h>
#define ll long long
const ll maxn=10e9;
using namespace std;
ll a[500010],b[500010],a1[500010],b1[500010];
ll c,n,m,q;
ll mina=maxn,minb=maxn,maxa=0,maxb=0;
string s;
ll dfs1(ll x,ll y){
	if(y==m)
	return 1;
	if(a[x]<b[y+1]){
		if(dfs1(x,y+1)==1)
		return 1;
	}
	if(a[x+1]<b[y+1]){
		if(dfs1(x+1,y+1)==1)
		return 1;
	}
	return 0;
}
ll dfs2(ll x,ll y){
	if(y==m)
	return 1;
	if(a[x]>b[y+1]){
		if(dfs2(x,y+1)==1)
		return 1;
	}
	if(a[x+1]>b[y+1]){
		if(dfs2(x+1,y+1)==1)
		return 1;
	}
	return 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
		if(a[i]<mina)
		mina=a[i];
		if(a[i]>maxa)
		maxa=a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		b1[i]=b[i];
		if(b[i]<minb)
		minb=b[i];
		if(b[i]>maxb)
		maxb=b[i];
	}
	if(c>=8&&c<=14){
		if(a[1]<minb)
		s=s+'1';
		else if(b[1]>maxa)
		s=s+'1';
		else{
			if(dfs1(1,1)==1)
			s=s+'1';
			else
			s=s+'0';
		}
		while(q--){
			ll x1,y11;
			for(int i=1;i<=n;i++){
				a[i]=a1[i];
			}
			for(int i=1;i<=m;i++){
				b[i]=b1[i];
			}
			cin>>x1>>y11;
			for(int i=1;i<=x1;i++){
				ll u,val;
				cin>>u>>val;
				a[u]=val;
				if(a[u]<mina)
				mina=a[u];
				if(a[u]>maxa)
				maxa=a[u];
			}
			for(int i=1;i<=y11;i++){
				ll u,val;
				cin>>u>>val;
				b[u]=val;
				if(b[u]<mina)
				mina=b[u];
				if(b[u]>maxa)
				maxa=b[u];
			}
			if(maxa<minb){
				s=s+'1';
				continue;
			}
			if(a[1]<minb){
				s=s+'1';
				continue;
			}
			if(dfs1(1,1)==1)
			s=s+'1';
			else
			s=s+'0';
		}
		cout<<s;
		return 0;
	}
	if(a[1]-b[1]<0&&a[n]-b[m]>0)
	s=s+'0';
	else if(a[1]-b[1]>0&&a[n]-b[m]<0)
	s=s+'0';
	else if(a[1]-b[1]==0||a[n]-b[m]==0)
	s=s+'0';
	else{
		if(a[1]-b[1]>0){
			if(mina>maxb){
				s=s+'1';
			}
			else if(a[1]>maxb){
				s=s+'1';
			}
			else{
				if(dfs2(1,1)==1)
				s=s+'1';
				else
				s=s+'0';
			}
		}
		else{
			if(maxa<minb){
				s=s+'1';
			}
			else if(a[1]<minb){
				s=s+'1';
			}
			else{
				if(dfs1(1,1)==1)
				s=s+'1';
				else
				s=s+'0';
			}
		}
	}
	while(q--){
		ll x1,y11;
		for(int i=1;i<=n;i++){
			a[i]=a1[i];
		}
		for(int i=1;i<=m;i++){
			b[i]=b1[i];
		}
		cin>>x1>>y11;
		for(int i=1;i<=x1;i++){
			ll u,val;
			cin>>u>>val;
			a[u]=val;
			if(a[u]<mina)
			mina=a[u];
			if(a[u]>maxa)
			maxa=a[u];
		}
		for(int i=1;i<=y11;i++){
			ll u,val;
			cin>>u>>val;
			b[u]=val;
			if(b[u]<mina)
			mina=b[u];
			if(b[u]>maxa)
			maxa=b[u];
		}
		if(a[1]-b[1]<0&&a[n]-b[m]>0){
			s=s+'0';
			continue;
		}
		if(a[1]-b[1]>0&&a[n]-b[m]<0){
			s=s+'0';
			continue;
		}
		if(a[1]-b[1]==0||a[n]-b[m]==0){
			s=s+'0';
			continue;
		}
		if(a[1]-b[1]>0){
			if(mina>maxb){
				s=s+'1';
				continue;
			}
			if(a[1]>maxb){
				s=s+'1';
				continue;
			}
			if(dfs2(1,1)==1)
			s=s+'1';
			else
			s=s+'0';
		}
		else{
			if(maxa<minb){
				s=s+'1';
				continue;
			}
			if(a[1]<minb){
				s=s+'1';
				continue;
			}
			if(dfs1(1,1)==1)
			s=s+'1';
			else
			s=s+'0';
		}
	}
	cout<<s;
	return 0;
}
