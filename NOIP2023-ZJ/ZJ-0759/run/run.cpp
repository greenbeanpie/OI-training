#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;

int c,t;
int n,m,k,d;
struct node{
	int x,y,v;
}cha[N];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;++i){
			cin>>cha[i].x>>cha[i].y>>cha[i].v;
		}
		cout<<cha[1].v-d*cha[1].y;	
	}
	

	
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3

*/
