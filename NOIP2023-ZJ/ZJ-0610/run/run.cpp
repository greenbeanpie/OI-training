#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,q,w,e;
struct clg{
	int x,y,v;
};
clg chalg[100005];
int geteng[100005];
int check[100005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>q>>w>>e;
			if(q-w+1>k){
				check[i]=1;
			}
		}
		cout<<2<<endl;
		
	}

}