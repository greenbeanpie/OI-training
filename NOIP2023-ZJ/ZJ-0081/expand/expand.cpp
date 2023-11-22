#include<bits/stdc++.h>
using namespace std;
struct op{
	int x,y;op(int aa=0,int bb=0):x(aa),y(bb){}
	op operator+(const op&aa)const{return op(min(x,aa.x),max(y,aa.y));}
}ky[2000005],c[500005],u[500005],yk[2000005];
int s,d,f,o,i,p,l,a[500005],b[500005],cc,inf=1e9;
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
void build(int x,int y,int z){
	if(x==y){ky[z].x=ky[z].y=a[x];return;}int mid=(x+y)>>1;
	build(x,mid,z<<1),build(mid+1,y,z<<1|1),ky[z]=ky[z<<1]+ky[z<<1|1];
}
void gai(int x,int y,int z,int o){
	if(x==y){ky[z].x=ky[z].y=a[x];return;}int mid=(x+y)>>1;
	if(o<=mid)gai(x,mid,z<<1,o);else gai(mid+1,y,z<<1|1,o);ky[z]=ky[z<<1]+ky[z<<1|1];
}
op cha(int x,int y,int z,int o,int i){
	if(o<=x&&y<=i){yk[z]=ky[z];return ky[z];}
	int mid=(x+y)>>1;op kk;kk.x=inf;
	if(o<=mid)kk=cha(x,mid,z<<1,o,i);if(i>mid)kk=kk+cha(mid+1,y,z<<1|1,o,i);
	yk[z]=kk;return kk;
}
int cha1(int x,int y,int z,int o,int i){
	if(x==y)return x;int mid=(x+y)>>1;if(o<=x)yk[z<<1]=ky[z<<1];
	if(o<=mid&&yk[z<<1].x<=i)return cha1(x,mid,z<<1,o,i);
	return cha1(mid+1,y,z<<1|1,o,i);
}
int cha2(int x,int y,int z,int o,int i){
	if(x==y)return x;int mid=(x+y)>>1;if(o>=y)yk[z<<1|1]=ky[z<<1|1];
	if(o>mid&&yk[z<<1|1].y>i)return cha2(mid+1,y,z<<1|1,o,i);
	return cha2(x,mid,z<<1,o,i);
}
int cha3(int x,int y,int z,int o,int i){
	if(x==y)return x;int mid=(x+y)>>1;if(o<=x)yk[z<<1]=ky[z<<1];
	if(o<=mid&&yk[z<<1].y>=i)return cha3(x,mid,z<<1,o,i);
	return cha3(mid+1,y,z<<1|1,o,i);
}
int cha4(int x,int y,int z,int o,int i){
	if(x==y)return x;int mid=(x+y)>>1;if(o>=y)yk[z<<1|1]=ky[z<<1|1];
	if(o>mid&&yk[z<<1|1].x<i)return cha4(mid+1,y,z<<1|1,o,i);
	return cha4(x,mid,z<<1,o,i);
}
void wk(){
	if(a[1]==b[1]){cout<<0;return;}
	if(a[1]>b[1]){
		op kk=cha(1,s,1,1,s);int k1;
		if(kk.x>b[1])k1=s;else k1=cha1(1,s,1,1,b[1])-1;
		for(int g=2;g<=d;g++)
			if(b[g]<b[g-1]){
				if(k1<s&&a[k1+1]>b[g]){
					op kk=cha(1,s,1,k1,s);if(kk.x>b[g])k1=s;else k1=cha1(1,s,1,k1,b[g])-1;
				}
			}
			else if(b[g]>=a[k1]){
				op kk=cha(1,s,1,1,k1);
				if(kk.y<=b[g]){cout<<0;return;}else k1=cha2(1,s,1,k1,b[g]);
			}
		if(k1==s)cout<<1;else cout<<0;
	}
	else{
		op kk=cha(1,s,1,1,s);int k1;
		if(kk.y<b[1])k1=s;else k1=cha3(1,s,1,1,b[1])-1;
		for(int g=2;g<=d;g++)
			if(b[g]>b[g-1]){
				if(k1<s&&a[k1+1]<b[g]){
					op kk=cha(1,s,1,k1,s);if(kk.y<b[g])k1=s;else k1=cha3(1,s,1,k1,b[g])-1;
				}
			}
			else if(b[g]<=a[k1]){
				op kk=cha(1,s,1,1,k1);
				if(kk.x>=b[g]){cout<<0;return;}else k1=cha4(1,s,1,k1,b[g]);
			}
		if(k1==s)cout<<1;else cout<<0;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read(cc),read(s),read(d),read(f);
	for(int g=1;g<=s;g++)read(a[g]);for(int g=1;g<=d;g++)read(b[g]);
	build(1,s,1),wk();
	for(int g=1;g<=f;g++){
		read(o),read(i);
		for(int h=1;h<=o;h++)read(p),read(l),c[h].x=p,c[h].y=a[p],a[p]=l,gai(1,s,1,p);
		for(int h=1;h<=i;h++)read(p),read(l),u[h].x=p,u[h].y=b[p],b[p]=l;wk();
		for(int h=1;h<=o;h++)a[c[h].x]=c[h].y,gai(1,s,1,c[h].x);
		for(int h=1;h<=i;h++)b[u[h].x]=u[h].y;
	}
	return 0;
}
