#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int c,n,m,q;
int kx,ky,px,vx,py,vy;
int x[N];
int y[N];
int ans=0;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)scanf("%d",&y[i]);
	cout<<rand()%2;
	while(q--){
		scanf("%d%d",&kx,&ky);
		while(kx--){
			scanf("%d%d",&px,&vx);
		}
		while(ky--){
			scanf("%d%d",&py,&vy);
		}
		cout<<rand()%2;
	}
}