#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int c,t,n,m,x[N],ans;
char ch;
int op;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		ans=0;
		cin>>n>>m;
		while(m--){
			cin>>ch>>op;
			if(ch=='T')x[op]=1;
			if(ch=='F')x[op]=2;
			if(ch=='U')x[op]=3;
		}
		for(int i=1;i<=n;i++){
			if(x[i]==3)ans+=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}