#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
const int N=5e5+50;
string s="";
int x[N],y[N],a,b,h,d;
bool flag=true;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];
	}
	for(int i=1;i<=n;i++){
		if(x[i]>y[m]){
			flag=false;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(y[i]<x[n]){
			flag=false;
			break;
		}
	}
	if(flag)s+="1";
	else s+="0";
	while(q--){
		cin>>a>>b;
		cin>>h>>d;
		if(b>y[m] or d<x[n])s+="0";
		else s+="1";
	}
	return 0;
}