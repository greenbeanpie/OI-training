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
}io(fopen("dict.in","r"),fopen("dict.out","w"));
int n,m,p1,p2;
struct node{
	char buf[3005];
	int cnt[26];
	bool operator < (const node &x){
		for(int i=0;i<m;i++)
			if(buf[i]!=x.buf[i]) return buf[i]<x.buf[i];
		return false;
	}
}s[3005],k1,k2,tmp;
int main(){
	io>>n>>m;
	for(int i=0;i<m;i++)
		k1.buf[i]=k2.buf[i]=25;
	for(int i=0;i<n;i++){
		io>>s[i].buf;
		for(int j=0;j<m;j++)
			s[i].cnt[s[i].buf[j]-'a']++;
		for(int j=25,sum=0;j>-1;sum+=s[i].cnt[j--])
			for(int k=0;k<s[i].cnt[j];k++)
				s[i].buf[sum+k]=j;
		if(s[i]<k1){
			p2=p1,k2=k1;
			p1=i,k1=s[i];
		}else if(s[i]<k2) p2=i,k2=s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0,sum=0;j<26;sum+=s[i].cnt[j++])
			for(int k=0;k<s[i].cnt[j];k++)
				tmp.buf[sum+k]=j;
		io<<(int)(tmp<(i==p1?k2:k1));
	}
	io<<'\n';
	return 0;
}
//Goodbye