#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"ok desu"<<endl
using namespace std;

int read(){
	int f=1,x=0; char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}

const int inf=0x7fffffff;
const int maxn=4010;

struct node{
	ll y,v;
	bool operator>(const node &o)const{
		if(v==o.v)return y>o.y;
		return v>o.v;
	}
	bool operator<(const node &o)const{
		if(v==o.v)return y<o.y;
		return v<o.v;
	}
};

int c,t;
int n,m,k,d;
vector<node> CL[maxn];
ll rmber[maxn][maxn];

ll kanon(int day,int cnt){
	if(day==n+1)return 0;
	if(rmber[day][cnt]!=-1)return rmber[day][cnt];
	int p1=0,p2=0;
	if(cnt<k){
		p1=-d;
		for(auto u:CL[day]){
			if(cnt+1>=u.y)p1+=u.v;
		}
		p1+=kanon(day+1,cnt+1);
	}
	p2=kanon(day+1,0);
	return rmber[day][cnt]=max(p1,p2);
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	if(c==17||c==18){
		while(t--){
			n=read(),m=read(),k=read(),d=read();
			ll ans=0;
			while(m--){
				int x=read(),y=read(),v=read();
				if(k>=y&&v>1ll*y*d)ans+=v-y*d;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(t--){
		for(int i=0;i<1005;i++){
			for(int j=0;j<1005;j++){
				rmber[i][j]=-1;
			}
		}
		n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;i++){
			ll x=read(),y=read(),v=read();
			if(y<=k)CL[x].push_back((node){y,v});
		}
		cout<<kanon(1,0)<<endl;
		for(int i=0;i<=n;i++){
			CL[i].clear();
		}
	}
	return 0;
}