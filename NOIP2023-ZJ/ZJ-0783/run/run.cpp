#include<bits/stdc++.h>
using namespace std;
int lst[30];
int pre[30];
struct node{
	int x,y,v;
}C[1010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m,k,d;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			int xx,yy,vv;
			cin>>xx>>yy>>vv;
			C[i].x=xx;C[i].y=yy;C[i].v=vv;
		}
		int Max=0;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					lst[j]=1;
				}
				else{
					lst[j]=0;
				}
			}
			int xx=0;
			bool flag=0;
			for(int j=1;j<=n;j++){
				if(lst[j]==1){
					xx++;
				}
				if(lst[j]==0){
					xx=0;
				}
				if(xx>k){
					flag=1;
					break;
				}
			}
			if(flag==1){
				continue;
			}
			int En=0;
			for(int j=1;j<=n;j++){
				pre[j]=pre[j-1]+lst[j];
			}
			En=En-pre[n]*d;
			for(int i=1;i<=m;i++){
				if(pre[C[i].x]-pre[C[i].x-C[i].y]==C[i].y){
					En=En+C[i].v;
				}
			}
			Max=max(Max,En);
		}
		cout<<Max<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/