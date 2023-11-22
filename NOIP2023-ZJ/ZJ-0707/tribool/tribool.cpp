#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,m,x,y;
ll ux[100005],ax[100005],ay[100005];
char op;
char tmp[100005];
char chr[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==5||c==6){
    	while(t--){
    		cin>>n>>m;
    		for(int i=1;i<=100000;i++) chr[i]='#';
    		for(int i=1;i<=m;i++){
    			cin>>op;
    			if(op=='U'){
    				cin>>x;
    				chr[x]='U';
				}
				else{
					cin>>x>>y;
					chr[x]=chr[y];
				}
			}
			ll res=0;
			for(int i=1;i<=n;i++) if(chr[i]=='U') res++;
		    cout<<res<<'\n';
		}
	}
	if(c==3||c==4){
		while(t--){
    		cin>>n>>m;
    		for(int i=1;i<=100000;i++) chr[i]='#';
    		for(int i=1;i<=m;i++){
    			cin>>op>>x;
    			chr[x]=op;
			}
			int cnt=0;
			for(int i=1;i<=n;i++) if(chr[i]=='U') cnt++;
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
