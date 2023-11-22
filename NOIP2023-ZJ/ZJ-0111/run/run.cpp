#include<bits/stdc++.h>
using namespace std;
class IO{
	FILE *in,*out;
	static const size_t sz=1<<20;
	char inbuf[sz|1],outbuf[sz|1],*p1,*p2,*p3;
	#define gc() (p1==p2&&(p2=fread(p1=inbuf,1,sz,in)+inbuf),p1==p2?EOF:*(p1++))
	#define pc(c) (p3==outbuf+sz&&fwrite(p3=outbuf,1,sz,out),*(p3++)=c)
	template<typename T>void write(const T &x){if(x>9) write(x/10);pc(x%10^48);}
	#define rt return *this
public:
	IO(FILE *in,FILE *out):in(in),out(out){p1=p2=inbuf+sz,p3=outbuf;}
	~IO(){fwrite(outbuf,1,p3-outbuf,out);}
	template<typename T>IO& operator >> (T &x){
		x=0;char c=gc();
		for(;c<48 || c>57;c=gc());
		for(;c>47 && c<58;c=gc()) x=(x<<3)+(x<<1)+(c^48);
		rt;
	}
	IO& operator >> (char *x){
		for(*x=gc();*x=='\n' || *x=='\r' || *x==' ' || *x==EOF;*x=gc());
		for(*(++x)=gc();*x!='\n' && *x!='\r' && *x!=' ' && *x!=EOF;*(++x)=gc());
		*x='\0';
		rt;
	}
	template<typename T>IO& operator << (const T &x){write(x);rt;}
	IO& operator << (const char *x){while(*x) pc(*(x++));rt;}
	IO& operator << (char *x){while(*x) pc(*(x++));rt;}
	IO& operator << (char x){pc(x);rt;}
	#undef rt
}io(fopen("run.in","r"),fopen("run.out","w"));
long long n,k,d,l[100005],r[100005],v[100005];
int m;
namespace sub1{
	long long f[1005][1005],ff[1005];
	vector<pair<long long,long long> >t[1005];
	void solve(){
		memset(f,0,sizeof(f));
		memset(ff,0,sizeof(ff));
		for(int i=1;i<=n;i++)
			t[i].clear();
		for(int i=1;i<=m;i++)
			t[r[i]].push_back(make_pair(l[i],v[i]));
		for(int i=1;i<=n;i++){
			sort(t[i].begin(),t[i].end());
			t[i].push_back(make_pair(LONG_LONG_MAX,0ll));
			for(int j=t[i].size()-2;j>-1;j--)
				t[i][j].second+=t[i][j+1].second;
			for(int j=max(i-k+1,1ll),l=0;j<=i;j++){
				while(j>t[i][l].first) l++;
				if(i==j) f[i][j]=(i==1?0:ff[i-2])+t[i][l].second-d;
				else f[i][j]=f[i-1][j]+t[i][l].second-d;
				ff[i]<f[i][j]&&(ff[i]=f[i][j]);
			}
			ff[i]=max(ff[i-1],ff[i]);
		}
		io<<ff[n]<<'\n';
	}
}
namespace subB{
	void solve(){
		long long ans=0;
		for(int i=1;i<=m;i++)
			if((r[i]-l[i]+1)*d<v[i])
				ans+=v[i]-(r[i]-l[i]+1)*d;
		io<<ans<<'\n';
	}
}
int main(){
	int id,T;
	io>>id>>T;
	while(T--){
		io>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			io>>l[i]>>r[i]>>v[i];
			l[i]-=r[i]-1;
			r[i]+=l[i]-1;
		}
		if(id<=9) sub1::solve();
		else if(id==17 || id==18) subB::solve();
		else io<<0<<'\n';
	}
	return 0;
}