#include<bits/stdc++.h>
#define ri int
using namespace std;
const int N=100005;
int is[N],nw[N],c,t,n,m,an,f[N*2],vs[N*2];string s;
int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
void add(int x,int y){f[fd(x)]=fd(y);}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	for(cin>>c>>t;t--;){
		cin>>n>>m;an=0;
		for(ri i=1;i<=n;++i)is[i]=1,nw[i]=i,f[i]=i,f[i+n]=i+n,vs[i]=vs[i+n]=0;
		for(ri x,y;m--;){
			cin>>s;
			if(s=="+"){
				cin>>x>>y;
				if(is[y])nw[x]=nw[y],is[x]=1;
				else is[x]=0,nw[x]=nw[y];
			}else if(s=="-"){
				cin>>x>>y;
				if(is[y])nw[x]=-nw[y],is[x]=1;
				else is[x]=0,nw[x]=nw[y]==2?2:-nw[y];
			}else{
				cin>>x;is[x]=0;
				if(s=="T")nw[x]=1;else if(s=="F")nw[x]=-1;else nw[x]=2;
			}
		}
		for(ri i=1;i<=n;++i)if(is[i]){
			if(nw[i]>0)add(i,nw[i]),add(i+n,nw[i]+n);
			else add(i,-nw[i]+n),add(i+n,-nw[i]);
		}else if(!is[i]&&nw[i]==2)add(i,i+n);
		for(ri i=1;i<=n;++i)if(fd(i)==fd(i+n))vs[fd(i)]=1;
		for(ri i=1;i<=n;++i)if(vs[fd(i)])++an;
		cout<<an<<'\n';
	}
}
