//FSZ with yingxue-cat
#include<bits/stdc++.h>
using namespace std;
int l[100005],r[100005],w[100005];
int lr[200005];
long long f[2][200005];
long long S[200005];
vector<pair<int,int>>ls[200005];
long long ff[200005];
long long jz[200005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	if(c<=16){
		while(T--){
			int n,m,k,d;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			int tt=0;
			for(int i=1;i<=m;++i){
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				if(y>k){
					--m,--i;
					continue;
				}
				l[i]=x-y+1,r[i]=x+1,w[i]=v;
				lr[++tt]=l[i],lr[++tt]=r[i];
			}
			sort(lr+1,lr+tt+1);
			tt=unique(lr+1,lr+tt+1)-lr-1;
			for(int i=1;i<=tt;++i)ls[i].clear();
			for(int i=1;i<=m;++i){
				int w1=lower_bound(lr+1,lr+tt+1,l[i])-lr;
				int w2=lower_bound(lr+1,lr+tt+1,r[i])-lr;
				ls[w2].emplace_back(w1,w[i]);
			}
			int gs=0;
			for(int i=0;i<=tt;++i)f[0][i]=f[1][i]=-1e18;
			f[gs][0]=0;
			int lscd=0;
			for(int i=1;i<=tt;++i){
				int sc=lower_bound(lr,lr+tt+1,lr[i]-k)-lr;
				int cd=i-sc;
				for(int j=0;j<=cd;++j)S[j]=0;
				for(auto pi:ls[i]){
					//cout<<lr[i]<<" "<<lr[pi.first]<<" "<<pi.second<<endl;
					S[i-pi.first]+=pi.second;
				}
				for(int j=1;j<=cd;++j)S[j]+=S[j-1];
				for(int j=0;j<=lscd;++j)f[gs^1][0]=max(f[gs^1][0],f[gs][j]);
				for(int j=1;j<=cd;++j)if(j-1<=lscd){
					f[gs^1][j]=max(f[gs^1][j],S[j]+f[gs][j-1]-1ll*d*(lr[i]-lr[i-1]));
				}
				gs^=1;
				for(int j=0;j<=lscd;++j)f[gs^1][j]=-1e18;
				lscd=cd;
			}
			long long an=0;
			for(int i=0;i<=lscd;++i)an=max(an,f[gs][i]);
			printf("%lld\n",an);
		}
		return 0;
	}
	while(T--){
		int n,m,k,d;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			l[i]=x-y+1,r[i]=x,w[i]=v;
			S[i]=S[i-1]+w[i];
		}
		set<pair<int,long long>>s1;
		set<pair<long long,int>>s2;
		long long an=0;
		for(int i=1;i<=m;++i){
			if(i==1||r[i-1]<l[i]-1)ff[i]=max(ff[i],ff[i-1]+w[i]-1ll*d*(r[i]-l[i]+1));
			while(s1.size()&&l[(*s1.begin()).first+1]>r[i]-k){
				auto au=*s1.begin();
				s1.erase(au);
				s2.erase(make_pair(-au.second,au.first));
			}
			if(s2.size())ff[i]=max(ff[i],-(*s2.begin()).first+S[i]-1ll*r[i]*d);
			jz[i]=ff[i]-S[i]+1ll*d*(l[i+1]-1);
			s1.emplace(i,jz[i]);
			s2.emplace(-jz[i],i);
			an=max(an,ff[i]);
		}
		printf("%lld\n",an);
	}
	return 0;
}
/*
T#YMS@4
Y@T2L32#
*/
