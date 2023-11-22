#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int f[N],v[N];
long c,t,n,m,x,y;
char op;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(f,1,sizeof f);
		for(long i=1;i<=m;i++){
			cin>>op;
			if(op=='+'){
				cin>>x>>y;
				f[x]=f[y];
				if(v[y]==1) v[x]=1;
			}
			else if(op=='-'){
				cin>>x>>y;
				f[x]=-f[y];
				if(v[y]==1) v[x]=1;
			}
			else{ 
				cin>>x;
				if(op=='U') f[x]=0,v[x]=1;
			}
		}
		int cnt=0;
		for(long i=1;i<=n;i++)
			if(v[i]==1) cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}
