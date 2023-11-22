#include<bits/stdC++.h>
using namespace std;
int c,t;
int n,m;
long long k,d;
const int N=1e5+10;
long long f[3100];
long long db[3100];
struct data{
	long long x,y,z;
	bool operator<(const data& e){
		return x<e.x;
	}
}miss[N];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t){
		int cnt=0;
		long long lx,ly,lz;
		t--;
//		cout<<t;
		scanf("%d%d%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
//			cout<<i;
			scanf("%lld%lld%lld",&lx,&ly,&lz);
//			cout<<lx<<endl;
			if(ly>lx||ly>k)continue;
			miss[++cnt]={lx,ly,lz};
		}
//		cout<<miss[0].x<<endl;
		sort(miss+1,miss+1+cnt);
//		long long sum=0,res=0;
		memset(f,-0x3f,sizeof(f));
		f[0]=0;
		memset(db,0,sizeof(db));
		miss[0]={-1,0,0};
		long long res=0;
		for(int i=1;i<=cnt;i++){
			db[i]=max(db[i-1],f[i-1]);
			f[i]=miss[i].z-d*miss[i].y;
			long long sum=miss[i].z-miss[i].y*d;
//			long long res=miss[i].y;
//cout<<sum<<endl;
			int y=i-1,j;
			for(j=i-1;j>=0;j--){
//				f[i]=max(f[i],f[j]+miss[i].z-d*miss[i].y);
				if(miss[i].x-miss[j].x+miss[j].y-1>k)break;
//				if(miss[i].x-miss[i].y<=miss[j].x-miss[j].y)res=res+miss[j].z;
				sum+=miss[j].z-(miss[j].y-(miss[j].x-(miss[j+1].x-miss[j+1].y))+2)*d;
				while(y>0&&miss[j].x-miss[j].y<=miss[y].x)y--;
				f[i]=max(f[i],sum+db[y]);
			}
//			cout<<f[i]<<endl;
			f[i]=max(f[i],miss[i].z-d*miss[i].y+db[j]);
//			cout<<miss[i].x<<" "<<miss[i].y<<" "<<miss[i].z<<endl;
//			sum+=miss[i].z;
//			res=max(res,sum-miss[i].y*d);
		}
		db[cnt+1]=max(f[cnt],db[cnt]);
		printf("%lld\n",db[cnt+1]);
	}
}
