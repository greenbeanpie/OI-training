#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M=200020;
int n, m, k, c, t;
ll d;
struct Bonus{
	int l, r;
	ll v;
}b[M];
int tt[M<<1];
int tn;
ll f[M<<1];
ll ma[M<<1];

bool cmp(const Bonus& a, const Bonus& b){
	return a.l==b.l?a.r<b.r:a.l<b.l;
}

int tf(int x){
	int l=1, r=tn, mid=((r-l)>>1)+l;
	while(l<=r){
		if(tt[mid]==x) return mid;
		if(tt[mid]<x) l=mid+1;
		else if(tt[mid]>x) r=mid-1;
		mid=((r-l)>>1)+l;
	}
	return l;
}

ll find(int l, int r){
	ll ans=-(tt[r]-tt[l]+1)*d;
	for(int _=1; _<=m; ++_)
		if(b[_].l>=l&&b[_].r<=r)
			ans+=b[_].v;
	return ans;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	cin>>c>>t;
	
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1; i<=m; ++i){
			int y;
			cin>>b[i].r>>y>>b[i].v;
			b[i].l=b[i].r-y+1;
			tt[i*2-1]=b[i].l;
			tt[i*2]=b[i].r;
		}
		if(c<=2){
			ll fan=0;
			for(int sta=0; sta<(1<<n); ++sta){
				bool flag=true;
				ll ans=0;
				int tmp=0;
				for(int i=0; flag&&i<n; ++i){
					if((sta>>i)&1){
						ans-=d;
						++tmp;
						if(tmp>k)
							flag=false;
					}else tmp=0;
				}
				if(!flag) continue;
				for(int i=1; i<=m; ++i){
					int tp=(1<<b[i].r)-(1<<(b[i].l-1));
					if((tp&sta)==tp)
						ans+=b[i].v;
				}
				fan=max(fan,ans);
			}
			cout<<fan<<endl;
		}else{
			memset(f, 0, sizeof f);
			memset(ma, 0, sizeof ma);
			sort(tt+1, tt+m*2+1);
			tn=1;
			for(int i=2; i<=2*m; ++i)
				if(tt[i]!=tt[i-1])
					tt[++tn]=tt[i];
			ll ans=0;
			f[0]=0;
			for(int i=1; i<=tn; ++i){
				f[i]=0;
				if(tt[i]-tt[1]+1<=k) f[i]=max(f[i],find(tt[1], tt[i]));
				for(int j=2; j<=i; ++j){
					if(tt[i]-tt[j]+1<=k){
						f[i]=max(f[i], find(tt[j], tt[i])+(tt[j-1]<tt[j]-1?ma[j-1]:ma[j-2]));
					}
				}
				ma[i]=max(ma[i-1], f[i]);
				ans=max(ans,f[i]);
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}