#include<bits/stdc++.h>
using namespace std;
int n,m;
struct str{
	int y,b,s;
}g[30];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int bi=1;
		char j,p;
		cin>>j;
		for(int i=2;i<=n;i++){
			cin>>p;
			if(p<j){
				bi=i;
				j=p;
			}
		}
		for(int i=1;i<=n;i++)
			if(i==bi) cout<<1;
			else cout<<0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			char t[3];
			cin>>t;
			int t1=t[0]-'a'+1;
			int t2=t[1]-'a'+1;
			int t3=t1;
			g[i].y=27*t1+t2;
			t1=max(t1,t2);
			t2=min(t2,t3);
			g[i].b=27*t1+t2;
			g[i].s=27*t2+t1;
		}
		for(int i=1;i<=n;i++){
			int v=1;
			for(int j=1;j<=n;j++){
				if(j==i)
					continue;
				if(g[j].b<=g[i].s){
					v=0;
					break;
				}
			}
			cout<<v;
		}
	}
	return 0;
}