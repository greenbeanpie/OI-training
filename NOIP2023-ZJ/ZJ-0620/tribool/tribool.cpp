#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){ x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Mx=100003;
int opti,T;
string op;
int x,y,ans,n,m;
int fa[Mx*2+100];
int find(int x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
void join(int x,int y){
	int a=find(x),b=find(y);
	if(a!=b){
		fa[a]=b;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	opti=read(),T=read();
	while(T--){
		map<int,int>sum;//3->U 2->F 1->T
		ans=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			fa[i]=i;
			fa[i+Mx]=i+Mx;
		}
		for(int i=1;i<=m;i++){
			cin>>op;
			if(op=="U"){
				x=read();
				sum[x]=3;
//				sum[find(x)]=3;
//				sum[find(x+Mx)]=3;
			}			
			if(op=="T"){
				x=read();
				sum[x]=1;
//				sum[find(x)]=1;
//				sum[find(x+Mx)]=1;
			}
			if(op=="F"){
				x=read();
				sum[x]=2;
//				sum[find(x)]=2;
//				sum[find(x+Mx)]=2;
			}
			if(op=="+"){
				x=read(),y=read();
				fa[x]=find(y);fa[x+Mx]=find(y+Mx);
			}		
			if(op=="-"){
				x=read(),y=read();
				fa[x]=find(y+Mx);
				fa[x+Mx]=find(y);			
			}	
		}
		for(int i=1;i<=n;i++){
			int a=find(i),b=find(i+Mx);
			if(a==b||sum[fa[a]]==3||sum[fa[b]]==3){
				//cout<<i<<" "<<a<<" "<<b<<endl;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
2 6
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/