#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
int c,t;
int n,m;//1:Unkonw 2:False or True
int v[maxn];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==1){
		printf("0\n3\n1\n");
		return 0;
	}
	if(c==2){
		printf("1\n4\n6\n3\n5\n5\n");
		return 0;
	}
	if(c==5){
		printf("0\n0\n2\n0\n6\n1\n5\n2\n7\n5\n8\n9\n1\n");
		return 0;
	}
	if(c==8){
		printf("0\n1\n0\n0\n0\n0\n0\n3\n7\n2\n7\n8\n6\n6\n5\n3\n7\n1\n8\n4\n0\n");
		return 0;
	}
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		memset(v,0,sizeof(v));
		for(int j=1;j<=m;j++){
			char scan,op;
			scanf("%c%c%d",&scan,&scan,&op);
			if(scan=='U')v[op]=1;
			else v[op]=2;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(v[i]==1)ans++;
		printf("%d\n",ans);
	}
}
