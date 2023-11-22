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
}io(fopen("tribool.in","r"),fopen("tribool.out","w"));
int n,val[100005],clr[100005];
void dfs(int u,bool flag){
	int v=abs(val[u]);
	clr[u]=flag?-1:1;
	if(clr[v]==2){
		val[u]=val[u]<0?-val[v]:val[v];
	}else if(clr[v]==1 || clr[v]==-1){
		if(clr[v]==(val[u]<0?-clr[u]:clr[u])) val[u]=n+1;
		else val[u]=0;
	}else{
		dfs(v,val[u]<0?!flag:flag);
		val[u]=val[u]<0?-val[v]:val[v];
	}
	clr[u]=2;
}
int main(){
	int id,T;
	io>>id>>T;
	while(T--){
		int m;
		io>>n>>m;
		for(int i=1;i<=n;i++) val[i]=i;
		memset(clr,0,sizeof(clr));
		clr[n+1]=clr[0]=2;
		val[n+1]=n+1;
		while(m--){
			char c[5];
			io>>c;
			switch(c[0]){
				case '+':{
					int x,y;
					io>>x>>y;
					val[x]=val[y];
					break;
				}
				case '-':{
					int x,y;
					io>>x>>y;
					val[x]=-val[y];
					break;
				}
				default:{
					int x;
					io>>x;
					val[x]=(c[0]=='T'?n+1:(c[0]=='F'?-n-1:0));
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(!clr[i]) dfs(i,0);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=!val[i];
		io<<ans<<'\n';
	}
	return 0;
}