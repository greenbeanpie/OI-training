#include<bits/stdc++.h>
using namespace std;
int c,t,i,j;
int n,m,ans;
int cha[100010];
char v,ch[100010];
bool x[100010],y[100010];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4){
		while(t--){
			memset(ch,'T',sizeof(ch));
			ans=0;
			cin>>n>>m;
			while(m--){
				cin>>v>>i;
				ch[i]=v;
			}
		for(int r=1;r<=n;r++){
			if(ch[r]=='U')ans++;
		    }
		    cout<<ans<<endl;
		}
		return 0; 
	}else if(c==5||c==6){
		while(t--){
			memset(cha,0,sizeof(cha));
			ans=0;
			cin>>n>>m;
			while(m--){
				cin>>v;
				if(v=='U'){
					cin>>i;
					cha[i]=3;
				}else{
					cin>>i>>j;
					cha[i]=cha[j]; 
				}
			}
		for(int r=1;r<=n;r++){
			if(cha[r]==3)ans++;
		    }
		    cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}
