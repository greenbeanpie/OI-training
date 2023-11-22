#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fd(i,x,y,z) for(ll i=x;i>=y;i-=z)
ll C,T;
ll n,m,num;
ll cx=0,tot=0;
char s[200005];
ll pre[200005];
vector<ll> v[200005];
ll vis[200005],ans;
char opt;
void dfs(ll now,char t){
	if(t!=0){
		ll gg=0;
		s[now]=t;
		if(now>n){
			gg-=n;	
		}
		else{
			gg+=n;
		}
		if(t=='T'){
			s[now+gg]='F';
		}
		else if(t=='F'){
			s[now+gg]='T';
		}
		else if(t=='U'){
			s[now+gg]='U';
		}
	}
	else{
		if(now<=n){
			if(vis[now+n]==num){
				cx=1;
			}
		}
		else if(now>n){
			if(vis[now-n]==num){
				cx=1;
			}
		}
	}
	tot++;
	vis[now]=num;
	for(ll i=0;i<v[now].size();i++){
		ll yyy=v[now][i];
		if(!vis[yyy]){
			dfs(yyy,t);
		}
	}
}
void solve1(){
	while(m--){
			ll xx,yy;
			cin>>opt;
			if(opt=='-'){
				scanf("%lld%lld",&xx,&yy);
				if(xx==yy){
					s[xx]='U';
					s[xx+n]='U';
					pre[xx]=0;
				}
				else{
					pre[xx]=yy+n;
					s[xx]=0;
					s[xx+n]=0;
				}
			}
			else if(opt=='+'){
				scanf("%lld%lld",&xx,&yy);
				if(xx==yy){
					pre[xx]=0;
					continue;
				}
				pre[xx]=yy;
				s[xx]=0;
				s[xx+n]=0;
			}
			else{
				scanf("%lld",&xx);
				pre[xx]=0;
				s[xx]=opt;
				if(opt=='T'){
					s[xx+n]='F';
				}
				else if(opt=='F'){
					s[xx+n]='T';
				}
				else if(opt=='U'){
					s[xx+n]='U';
				}
			}
		}
		num=0;
		f(i,1,n,1){
			if(pre[i]){
				if(pre[i]<=n){
					v[i].push_back(pre[i]);
					v[pre[i]].push_back(i);
					v[i+n].push_back(pre[i]+n);
					v[pre[i]+n].push_back(i+n);
				}
				else{
					v[i].push_back(pre[i]);
					v[pre[i]].push_back(i);
					v[i+n].push_back(pre[i]-n);
					v[pre[i]-n].push_back(i+n);
				}
			}
		}
		f(i,1,n*2,1){
			if(s[i]&&(!vis[i])){
				num++;
				dfs(i,s[i]);
			}
		}
		f(i,1,n*2,1){
			if((!vis[i])&&(!s[i])){
				num++;
				tot=0;
				cx=0;
				dfs(i,0);
				ans+=cx*tot/2;
			}
		}
		f(i,1,n,1){
			if(s[i]=='U'){
				ans++;
			}
		}
		printf("%lld\n",ans);
		f(i,1,n*2,1){
			pre[i]=0;
			v[i].clear();
			vis[i]=0;
			s[i]=0;
		}
		num=0;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&m);
		solve1();
	}
	return 0;
}
