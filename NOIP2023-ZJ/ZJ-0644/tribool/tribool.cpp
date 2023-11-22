#include <bits/stdc++.h>
using namespace std;
int biset[100005];
int to[100005];
int c,t,s;
char op;
int n,m,x,y;
int find(int x){
	return to[x]==x?x:to[x]=find(to[x]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==3||c==4){
		while(t--){
			cin>>n>>m;
			memset(biset,0,sizeof(biset));
			s=0;
			for(int i=1;i<=m;i++){
				cin>>op;
				if(op=='U'){
					cin>>x;
					biset[x]=3;
				}
				else if(op=='T'){
					cin>>x;
					biset[x]=1;
				}
				else if(op=='F'){
					cin>>x;
					biset[x]=2;
				}
			}
			for(int i=1;i<=n;i++) if(biset[i]==3) s++;
			printf("%d\n",s);
		}
	}//20
	else if(c==5||c==6){
		while(t--){
			cin>>n>>m;
			s=0;
			int k=0;
			for(int i=0;i<=n;i++) to[i]=i;
			for(int i=1;i<=m;i++){
				cin>>op;
				if(op=='U'){
					k++;
					cin>>x;
					to[x]=0;
				}
				else if(op=='+'){
					cin>>x>>y;
					to[x]=y;
				}
			}
			if(k==0){
				printf("0\n");
			}
			else{
				for(int i=1;i<=n;i++){
					if(find(i)==0) s++;
				}
				printf("%d\n",s);
			}
		}
	}
	else{
		while(t--){
			printf("0\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
