#include<bits/stdc++.h>
//#define int loli
#define siz(x) int((x).size())
#define all(x) std::begin(x),std::end(x)
#define fi first
#define se second
using namespace std;
using loli=long long;
constexpr int N=6007;
int C,T,n,m,o,d;
loli f[N];
struct zzz{
	int x,y;loli z;
	bool operator<(const zzz&t){
		return x<t.x;
	}
}a[N];
std::vector<int>l[N],ys[N];
vector<pair<int,loli>>xd[N];
vector<int>b;
signed main(){
	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--){
		cin>>n>>m>>o>>d;
		b.clear();
		for(int i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].y=a[i].x-a[i].y+1;
			swap(a[i].x,a[i].y);
			b.push_back(a[i].x);
			b.push_back(a[i].y);
//			b.push_back(a[i].y+o);
		}
		b.push_back(1);
		b.push_back(n);
		sort(all(b));
		b.erase(unique(all(b)),b.end());
		for(int i=0;i<=siz(b);i++)l[i].clear(),xd[i].clear(),ys[i].clear();
		for(int i=1;i<=m;i++){
			a[i].x=lower_bound(all(b),a[i].x)-b.begin()+1;
			a[i].y=lower_bound(all(b),a[i].y)-b.begin()+1;
			l[a[i].x-1].push_back(i);
		}
		for(int i=0;i<siz(b);i++){
			for(int j=0;j<siz(b);j++)ys[j].clear();
			loli sum=0;
			for(int j=i;j<siz(b);j++){
				if(b[j]-b[i]+1>o)break;
//				cout<<"solve "<<b[i]<<' '<<b[j]<<'\n';
				for(int k:l[j])ys[a[k].y-1].push_back(a[k].z);
//				for(int k:l[j])ys[a[k].y-1].push_back(a[k].z),cout<<"pus "<<a[k].y<<' '<<a[k].z<<'\n';
				for(loli k:ys[j])sum+=k;
//				for(loli k:ys[j])sum+=k,cout<<"add "<<j<<' '<<k<<'\n';
				sum-=d;
//				xd.push_back(zzz{i+1,j+1,sum});
				if(sum>0)xd[j+1].emplace_back(i+1,sum);
//				cout<<b[i]<<' '<<b[j]<<' '<<sum<<'\n';
//				xd[lower_bound(all(b),b[j]+o)-b.begin()+1].emplace_back(i+1,sum);
			}
		}
		f[0]=0;
		for(int i=1;i<=siz(b);i++){
			f[i]=f[i-1];
			for(auto[j,k]:xd[i]){
//				int op=(--upper_bound(all(b),b[j-1]-2))-b.begin();
				int op=(lower_bound(all(b),b[j-1]-1))-b.begin()+1;
//				int op=(--lower_bound(all(b),b[j-1]-1))-b.begin()+1;
				f[i]=max(f[i],f[op]+k);
			}
		}
		cout<<f[siz(b)]<<'\n';
	}
	return 0;
}
