#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int res=0,b=1;
	while(!isdigit(c)){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=res*10+(c^48);
		c=getchar();
	}
	return res*b;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
	else {
		putchar(x+'0');
	}
}
inline bool print(int x){
	write(x);
	putchar(' ');
	return 0;
}
inline bool put(int x){
	write(x);
	putchar('\n');
	return 0;
}
int c,t;
int n,m;
struct _bu{
	int op,x,y;
}q[100005];
namespace sub1{
	int a[15],b[15];
	int xsd;
	bool flag;
	inline bool check(){
		for(int i=1;i<=n;++i) a[i]=b[i];
		for(int i=1;i<=m;++i){
			int op=q[i].op,x=q[i].x,y=q[i].y;
			if(op==2) a[x]=a[y];
			else if(op==3) a[x]=(-a[y]);
			else a[x]=y;
		}
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i]) return 0;
		}
		return 1;
	}
	inline void get_data(int pos,int x,int all){
		if(flag) return ;
		if(pos==n+1) {
			if(check()){
				flag=1;
				put(all);
			}
			return ;
		}
		if(x) b[pos]=0,get_data(pos+1,x-1,all);
		b[pos]=1,get_data(pos+1,x,all);
		b[pos]=-1,get_data(pos+1,x,all);
 	}
	int main(){
		n=read(),m=read();
		flag=0;
		for(int i=1;i<=n;++i) b[i]=0;
		for(int i=1;i<=m;++i){
			char c;
			cin>>c;
			if(c=='-'){
				int x=read(),y=read();
				q[i]={3,x,y};		
			}
			else if(c=='+'){
				int x=read(),y=read();
				q[i]={2,x,y};
			}
			else {
				int x=read();
				if(c=='T'){
					q[i]={1,x,1};
				}
				else if(c=='F'){
					q[i]={1,x,-1};
				}
				else q[i]={1,x,0};
			}
		}
		for(int i=0;i<=n;++i){
			xsd=i;
			get_data(1,i,i);
			if(flag) return 0;
		}
		return 0;
	}
}
namespace sub2{
	int a[100005];
	int main(){
		for(int i=1;i<=n;++i) a[i]=0;
		n=read(),m=read();
		for(int i=1;i<=m;++i){
			char c;
			cin>>c;
			int x=read();
			if(c=='U') a[x]=1;
			else a[x]=0;
		}
			int ans=0;
		for(int i=1;i<=n;++i){
			ans+=a[i];
		}
		return put(ans);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	if(c==1||c==2){
		while(t--){
			sub1::main();
		}
	}
	if(c==3||c==4){
		while(t--){
			sub2::main();
		}
	}
	return 0;
}