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
}io(fopen("expand.in","r"),fopen("expand.out","w"));
int _n,n,_m,m,_x[500005],x[500005],_y[500005],y[500005];
bool f[2005][2005];
int solve(){
	if(x[1]==y[1] || x[n]==y[m] || (long long)(x[1]-y[1])*(x[n]-y[m])<0) return 0;
	if(x[1]>y[1]){
		for(int i=max(n,m);i;i--) swap(x[i],y[i]);
		swap(n,m);
	}
	int mx=INT_MAX,my=0;
	for(int i=1;i<=n;i++)
		mx>x[i]&&(mx=x[i]);
	for(int i=1;i<=m;i++)
		my<y[i]&&(my=y[i]);
	if(n>2000 || m>2000) return mx<my;
	memset(f,0,sizeof(f));
	f[1][1]=1;
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
			f[i][j]|=x[i]<y[j]&&(f[i-1][j]||f[i][j-1]);
	return f[n][m];
}
int main(){
	int c,q;
	io>>c>>_n>>_m>>q;
	for(int i=1;i<=_n;i++) io>>_x[i];
	for(int i=1;i<=_m;i++) io>>_y[i];
	memcpy(x,_x,sizeof(x));
	memcpy(y,_y,sizeof(y));
	n=_n,m=_m;
	io<<solve();
	while(q--){
		memcpy(x,_x,sizeof(x));
		memcpy(y,_y,sizeof(y));
		n=_n,m=_m;
		int kx,ky;
		io>>kx>>ky;
		while(kx--){
			int p,v;
			io>>p>>v;
			x[p]=v;
		}
		while(ky--){
			int p,v;
			io>>p>>v;
			y[p]=v;
		}
		io<<solve();
	}
	io<<'\n';
	return 0;
}