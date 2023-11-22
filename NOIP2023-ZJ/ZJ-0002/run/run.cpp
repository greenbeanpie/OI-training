#include<bits/stdc++.h>
using namespace std;
constexpr int N=100000;
typedef long long ll;
inline void up(ll &x,ll y){if(y>x) x=y;}
mt19937 rd(114514);
struct qry{
	int x,tp,len,val;
	bool operator<(const qry &ob)const{
		if(x!=ob.x) return x<ob.x;
		return tp<ob.tp;
	}
}Q[N*3+10];
int qtop;
struct node{
	int x,l,r,w;
	ll val,max_,tag;
}s[N+10];
int stop;
void puttag(int rt,ll c){s[rt].val+=c,s[rt].max_+=c,s[rt].tag+=c;}
void pushdown(int rt){
	if(s[rt].tag){
		if(s[rt].l) puttag(s[rt].l,s[rt].tag);
		if(s[rt].r) puttag(s[rt].r,s[rt].tag);
		s[rt].tag=0;
	}
}
void pushup(int rt){s[rt].max_=max(s[rt].val,max(s[s[rt].l].max_,s[s[rt].r].max_));}
void split(int rt,int c,int &rt1,int &rt2){
	if(!rt) return rt1=rt2=0,void();
	pushdown(rt);
	if(s[rt].x<=c){
		rt1=rt;
		split(s[rt].r,c,s[rt1].r,rt2);
	}
	else{
		rt2=rt;
		split(s[rt].l,c,rt1,s[rt2].l);
	}
	pushup(rt);
}
int merge(int rt1,int rt2){
	if(!rt1||!rt2) return rt1|rt2;
	pushdown(rt1),pushdown(rt2);
	if(s[rt1].w>s[rt2].w){
		s[rt1].r=merge(s[rt1].r,rt2);
		pushup(rt1);
		return rt1;
	}
	else{
		s[rt2].l=merge(rt1,s[rt2].l);
		pushup(rt2);
		return rt2;
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	s[0].max_=-2e18;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cid,T;
	cin>>cid>>T;
	while(T--){
		int n,m,K,d;
		cin>>n>>m>>K>>d;
		int i;
		vector<int> vl,vr;
		qtop=0;
		for(i=1;i<=m;++i){
			int x,y,v;
			cin>>x>>y>>v;
			if(y>K) continue;
			vl.push_back(x-y);
			vr.push_back(x);
			Q[++qtop]={x,1,y,v};
		}
		sort(vl.begin(),vl.end());
		vl.resize(unique(vl.begin(),vl.end())-vl.begin());
		sort(vr.begin(),vr.end());
		vr.resize(unique(vr.begin(),vr.end())-vr.begin());
		for(auto &i:vl) Q[++qtop]={i,2,0,0};
		for(auto &i:vr) Q[++qtop]={i,3,0,0};
		sort(Q+1,Q+1+qtop);
		stop=0;
		s[++stop]={0,0,0,rd(),0,0,0};
		int rt=stop,lst=0;
		ll maxg=0;
		for(i=1;i<=qtop;++i){
			if(Q[i].x>lst){
				lst=Q[i].x;
				int rt1,rt2;
				split(rt,Q[i].x-K-1,rt1,rt2);
				rt=rt2;
			}
			if(Q[i].tp==1){
				int rt1,rt2;
				split(rt,Q[i].x-Q[i].len,rt1,rt2);
				if(rt1) puttag(rt1,Q[i].val);
				rt=merge(rt1,rt2);
			}
			else if(Q[i].tp==2){
				ll c=maxg+1ll*d*Q[i].x;
				s[++stop]={Q[i].x,0,0,rd(),c,c,0};
				rt=merge(rt,stop);
			}
			else{
				ll tmp=s[rt].max_-1ll*d*Q[i].x;
				up(maxg,tmp);
			}
		}
		cout<<maxg<<'\n';
	}
	return 0;
}
