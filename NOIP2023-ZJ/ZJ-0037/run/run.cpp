#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int max_m=200000;
constexpr int max_n=max_m*2+1;
vector<int> pos;
vector<pii> vec[max_n+1];
array<int,3>que[max_m+1];
struct node{
	ll mx,tg;
	void pushtag(const ll&tag){
		mx+=tag,tg+=tag;
	}
	void pushdown(node&lsn,node&rsn){
		if(tg){
			lsn.pushtag(tg),rsn.pushtag(tg);
			tg=0;
		}
	}
	void pushup(const node&lsn,const node&rsn){
		mx=max(lsn.mx,rsn.mx);
	}
};
node tr[max_n<<1];
void build(const int now,const int lft,const int rgt){
	tr[now].mx=tr[now].tg=0;
	if(lft==rgt)
		return;
	const int mid=(lft+rgt)>>1;
	build(mid<<1,lft,mid);
	build(mid<<1|1,mid+1,rgt);
}
void updatepos(const int now,const int lft,const int rgt,const int p,const ll v){
	if(lft==rgt){
		tr[now].mx=v;
		return;
	}
	const int mid=(lft+rgt)>>1;
	const int lsn=mid<<1;
	tr[now].pushdown(tr[lsn],tr[lsn|1]);
	if(p<=mid)
		updatepos(lsn,lft,mid,p,v);
	else
		updatepos(lsn|1,mid+1,rgt,p,v);
	tr[now].pushup(tr[lsn],tr[lsn|1]);
}
void updatepre(const int now,const int lft,const int rgt,const int r,const ll v){
	if(rgt<=r){
		tr[now].pushtag(v);
		return;
	}
	const int mid=(lft+rgt)>>1;
	const int lsn=mid<<1;
	tr[now].pushdown(tr[lsn],tr[lsn|1]);
	if(r<=mid)
		updatepre(lsn,lft,mid,r,v);
	else{
		tr[lsn].pushtag(v);
		updatepre(lsn|1,mid+1,rgt,r,v);
	}
	tr[now].pushup(tr[lsn],tr[lsn|1]);
}
void updatesuf(const int now,const int lft,const int rgt,const int l,const ll v){
	if(l<=lft){
		tr[now].pushtag(v);
		return;
	}
	const int mid=(lft+rgt)>>1;
	const int lsn=mid<<1;
	tr[now].pushdown(tr[lsn],tr[lsn|1]);
	if(l<=mid){
		tr[lsn|1].pushtag(v);
		updatesuf(lsn,lft,mid,l,v);
	}
	else
		updatesuf(lsn|1,mid+1,rgt,l,v);
	tr[now].pushup(tr[lsn],tr[lsn|1]);
}
void update(const int now,const int lft,const int rgt,const int l,const int r,const ll v){
	// fprintf(stderr,"update %d(%d %d %lld %lld) %d %d %lld\n",now,lft,rgt,tr[now].mx,tr[now].tg,l,r,v);
	if(l<=lft&&rgt<=r){
		tr[now].pushtag(v);
		return;
	}
	const int mid=(lft+rgt)>>1;
	const int lsn=mid<<1;
	tr[now].pushdown(tr[lsn],tr[lsn|1]);
	if(l<=mid)
		if(r<=mid)
			update(lsn,lft,mid,l,r,v);
		else
			updatesuf(lsn,lft,mid,l,v),updatepre(lsn|1,mid+1,rgt,r,v);
	else
		update(lsn|1,mid+1,rgt,l,r,v);
	tr[now].pushup(tr[lsn],tr[lsn|1]);
}
void test(){
	int n,m,k,d;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	pos.clear();
	pos.emplace_back(-1);
	for(int i=1; i<=m; ++i){
		int&x=que[i][0],&y=que[i][1],&v=que[i][2];
		scanf("%d%d%d",&x,&y,&v);
		if(y>k){
			--i,--m;
			continue;
		}
		pos.emplace_back(x);
		pos.emplace_back(x-y);
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	n=pos.size()-1;
	if(!n){
		puts("0");
		return;
	}
	build(1,1,n);
	for(int i=1; i<=n; ++i)
		vec[i].clear();
	// for(int i=0; i<=n; ++i)
	// 	fprintf(stderr,"pos %d: %d\n",i,pos[i]);
	for(int i=1; i<=m; ++i){
		const int r=lower_bound(pos.begin(),pos.end(),que[i][0])-pos.begin();
		const int l=lower_bound(pos.begin(),pos.end(),que[i][0]-que[i][1])-pos.begin();
		vec[r].emplace_back(l,que[i][2]);
	}
	for(int i=1; i<=n; ++i){
		const ll v=ll(pos[i]-pos[i-1])*d;
		// fprintf(stderr,"%d: %lld %lld\n",i-1,tr[1].mx,v);
		if(i>1){
			updatepos(1,1,n,i,tr[1].mx);
			updatepre(1,1,n,i-1,-v);
		}
		const int lft=max<int>(lower_bound(pos.begin(),pos.end(),pos[i]-k)-pos.begin(),1);
		for(const pii&p:vec[i])
			if(lft<=p.first)
				update(1,1,n,lft,p.first,p.second);
	}
	printf("%lld\n",tr[1].mx);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int t;
	for(scanf("%*d%d",&t); t; test(),--t);
	return 0;
}