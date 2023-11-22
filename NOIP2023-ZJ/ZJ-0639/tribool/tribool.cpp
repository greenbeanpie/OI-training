#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,m;
char tmp;
int u,v;
int chang(char mar){
	if(mar=='F')
		return 0;
	if(mar=='T')
		return 1;
	return 2;
}
int fan(int mar){
	if(mar==0)
		return 1;
	if(mar==1)
		return 0;
	return 2;
}

int dienum[100005];


struct wei{
	int fr;
	int ye;//是不是和fr的值相同，同为1 
	int val;
}dian[210000];
int cnt;
int lnum[100005];
int ans;
bool vis[100005];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		cnt=n;
		ans=0;
		memset(dienum,0,sizeof dienum);
		for(int i=1;i<=n;i++){
			lnum[i]=i;
			dian[i].fr=i;
			dian[i].ye=1;
			dian[i].val=-1;
		}
		for(int i=1;i<=m;i++){
			cin>>tmp;
			if(tmp=='T'||tmp=='F'||tmp=='U'){
				scanf("%d",&u);
				lnum[u]=++cnt;
				dian[cnt].fr=-1;
				dian[cnt].ye=-1;
				dian[cnt].val=chang(tmp);
			}else if(tmp=='+'){
				scanf("%d%d",&u,&v);
				dian[++cnt]=dian[lnum[v]];
				lnum[u]=cnt;
			}else{
				scanf("%d%d",&u,&v);
				dian[++cnt]=dian[lnum[v]];
				if(dian[cnt].val==-1)
					dian[cnt].ye^=1;
				else
					dian[cnt].val=fan(dian[cnt].val);
				lnum[u]=cnt;
			}
			//printf("%d--------\n",u);
			//cout<<dian[lnum[u]].fr<<' '<<dian[lnum[u]].ye<<' '<<dian[lnum[u]].val<<endl;;
		}
		for(int i=1;i<=n;i++){
			if(dian[lnum[i]].val!=-1){
				if(dian[lnum[i]].val==2)
					ans++;
			}
			else{
				dienum[dian[lnum[i]].fr]++;
			}
		}
		
		//for(int i=1;i<=n;i++){
		//	printf("%d--------\n",i);
		//	cout<<dian[lnum[i]].fr<<' '<<dian[lnum[i]].ye<<' '<<dian[lnum[i]].val<<endl;;
		//}
		
		
		
		for(int i=1;i<=n;i++){
			if(dienum[i])
				if(!dian[lnum[i]].ye)
					ans+=dienum[i];
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
/*


*/
