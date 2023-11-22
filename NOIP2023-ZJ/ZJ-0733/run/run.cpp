#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
struct node{
	int v,x,y;
}a[100010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		int ans=0;
		for(int i=1;i<=m;i++){
			cin>>a[i].x<<a[i].y<<a[i].v;
			ans+=a[i].v-a[i].y;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
