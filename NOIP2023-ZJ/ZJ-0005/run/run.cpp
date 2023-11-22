#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int f=1;
	int x=0;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar();};
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int C,T;
int n,m,k,d;
struct node{
	int l,r,v;
}a[100010];
int pos[200010];
int cnt;
vector<pair<int,int> > vec[200010];
long long mx[800010],tag[800010];
void pushup(int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void build(int p,int l,int r){
	tag[p]=0;
	if(l==r){
		mx[p]=1ll*pos[l]*d;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p);
}
void pushdown(int p){
	if(tag[p]){
		tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];
		mx[p<<1]+=tag[p];mx[p<<1|1]+=tag[p];tag[p]=0;
	}
}
void update(int p,int l,int r,int L,int R,long long k){
	if(l>=L&&r<=R){
		mx[p]+=k;tag[p]+=k;return ;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
void modify(int p,int l,int r,int pos,long long k){
	if(l==r){
		mx[p]=k;tag[p]=0;return ;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(pos<=mid) modify(p<<1,l,mid,pos,k);
	else modify(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
long long query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mx[p];
	pushdown(p);
	int mid=l+r>>1;
	long long re=0;
	if(L<=mid) re=max(re,query(p<<1,l,mid,L,R));
	if(R>mid) re=max(re,query(p<<1|1,mid+1,r,L,R));
	return re;
}
int main(){
	// double st=clock();
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	// scanf("%d%d",&C,&T);
	C=read(),T=read();
	bool f=0;
	while(T--){
		n=read(),m=read(),k=read(),d=read();
		// scanf("%d%d%d%d",&n,&m,&k,&d);
		// cerr<<n<<" "<<m<<" "<<k<<" "<<d<<"\n";
		cnt=1;pos[cnt]=0;
		for(int i=1;i<=m;++i){
			int x=read(),y=read(),v=read();
			// scanf("%d%d%d",&x,&y,&v);
			a[i].l=x-y+1,a[i].r=x,a[i].v=v;
			pos[++cnt]=x;
			pos[++cnt]=x-y;
		}
		sort(pos+1,pos+cnt+1);
		cnt=unique(pos+1,pos+cnt+1)-pos-1;
		for(int i=1;i<=cnt;++i) vector<pair<int,int> > ().swap(vec[i]);
		for(int i=1;i<=m;++i){
			int L=lower_bound(pos+1,pos+cnt+1,a[i].l)-pos-1;
			int R=lower_bound(pos+1,pos+cnt+1,a[i].r)-pos;
			assert(pos[R]==a[i].r);assert(pos[L]==a[i].l-1);
			vec[R].push_back({L,a[i].v});
		}
		build(1,1,cnt);
		int it=1;
		long long F=0;
		for(int i=2;i<=cnt;++i){
			F=max(F,query(1,1,cnt,i-1,i-1))+1ll*(pos[i]-pos[i-1])*d;
			// printf("%lld %lld\n",query(1,1,cnt,i-1,i-1),F);
			for(auto j:vec[i]){
				update(1,1,cnt,1,j.first,j.second);
			}
			while(pos[i]-pos[it]>k) ++it;
			modify(1,1,cnt,i,F);
			F=max(F,query(1,1,cnt,it,i));
			// printf("it:%d %d,i:%d %d\n",it,pos[it],i,pos[i]);
			// printf("%lld %lld\n",F,query(1,1,cnt,it,i));	
		}
		printf("%lld\n",F-1ll*pos[cnt]*d);
		// cerr<<(clock()-st)/CLOCKS_PER_SEC<<"\n";
	}
		// cerr<<(clock()-st)/CLOCKS_PER_SEC<<"\n";
	return 0;
}