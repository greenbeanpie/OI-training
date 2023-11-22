#include<bits/stdc++.h>
using namespace std;
struct op{long long x,y,z;}a[100005];
long long T,s,d,f,o,k[200005],k1,ans,ky[800005],yk[800005],inf=1e15;
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
long long find(long long x){
	long long r=1,u=k1,mid;while(r<u){mid=(r+u)>>1;if(k[mid]<x)r=mid+1;else u=mid;}return r;
}
void build(long long x,long long y,long long z){
	ky[z]=-inf;yk[z]=0;
	if(x==y)return;
	long long mid=(x+y)>>1;
	build(x,mid,z<<1),build(mid+1,y,z<<1|1);
}
void gai(long long x,long long y,long long z,long long o,long long i,long long p){
	if(o<=x&&y<=i){ky[z]+=p,yk[z]+=p;return;}
	long long mid=(x+y)>>1;
	if(yk[z])yk[z<<1]+=yk[z],yk[z<<1|1]+=yk[z],ky[z<<1]+=yk[z],ky[z<<1|1]+=yk[z],yk[z]=0;
	if(o<=mid)gai(x,mid,z<<1,o,i,p);if(i>mid)gai(mid+1,y,z<<1|1,o,i,p);
	ky[z]=max(ky[z<<1],ky[z<<1|1]);
}
bool abc(op aa,op bb){return aa.y<bb.y;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(T),read(T);
	while(T--){
		read(s),read(d),read(f),read(o);
		for(int g=1;g<=d;g++)read(a[g].x),read(a[g].y),read(a[g].z),a[g].x-=a[g].y,
		a[g].y+=a[g].x,k[g*2-1]=a[g].x,k[g*2]=a[g].y;
		sort(k+1,k+1+2*d),k1=1;
		for(int g=2;g<=2*d;g++)if(k[g]!=k[g-1])k[++k1]=k[g];
		for(int g=1;g<=d;g++)a[g].x=find(a[g].x),a[g].y=find(a[g].y);
		build(1,k1,1),gai(1,k1,1,1,1,inf),ans=0;
		sort(a+1,a+1+d,abc);
		long long kk=1,k2=1;
		for(int g=2;g<=k1;g++){
			gai(1,k1,1,g,g,ans+inf);
			while(kk<=k1&&k[g]-k[kk]>f)gai(1,k1,1,kk,kk,-inf),kk++;
			gai(1,k1,1,1,g-1,-(k[g]-k[g-1])*o);
			while(k2<=d&&a[k2].y==g)gai(1,k1,1,1,a[k2].x,a[k2].z),k2++;
			ans=max(ky[1],ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
