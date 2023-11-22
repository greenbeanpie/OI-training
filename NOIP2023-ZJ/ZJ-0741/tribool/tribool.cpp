#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,x,y,dic,line[N],ans=0;
char op;
bool f;

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		memset(line,0,sizeof(line));
		f=true;
		for(int j=1;j<=m;j++){
			cin>>op;
			if(op=='+'||op=='-'){
				f=false;
				cin>>x>>y;
			}
			else{
				cin>>dic;
				if(op=='T')line[dic]=1;
				if(op=='F')line[dic]=2;
				if(op=='U')line[dic]=3;
			}
		}
		if(f){
			for(int j=1;j<=m;j++)
				if(line[j]==3)ans++;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
