#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,d,c,t,x,y,v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
    cin>>c>>t;
    if(c==17||c==18){
    	while(t--){
    		ll tmp=0;
    		cin>>n>>m>>k>>d;
    		for(int i=1;i<=m;i++){
    			cin>>x>>y>>v;
    		    if(y>k) continue;
    		    if(y*d<v) tmp+=(v-y*d);
			}
			cout<<tmp<<"\n";
		}
	}
	return 0;
}
