#include<bits/stdc++.h>
using namespace std;
int fa[300000];
int fb[100010];
int quan[300000];
int lun;int c;
char bf[10];
//int zhan[300000];
//int top=0;
int find(int x){

	if(fa[x]!=x){
		int t=find(fa[x]);
		quan[x]=(quan[x]+quan[fa[x]])%2;
		fa[x]=t;
		if(t==3)quan[x]=0;
	}
	return fa[x];
/*	top=0;
	while(x!=fa[x]){
		zhan[top++]=x;
		x=fa[x];
	}
	while(top){
		int y=zhan[top-1];
		top--;
		int t=fa[x];
		x=y;
		quan[x]=(quan[x]+quan[fa[x]])%2;
		fa[x]=t;	
		if(t==3)quan[x]=0;
	}
	return fa[x];*/
}
int hhh[300];
int t,n,m;
void nb(int x,int y,int f){
	int f1=find(x);
	int f2=find(y);
	if(f1==3&&f2==3)return;
	if(f1<=3)swap(f1,f2),swap(x,y);
	if(f2==3){
		fa[f1]=3;
		quan[f1]=0;
		return;
	}
	if(f1!=f2){
		fa[f1]=f2;
		quan[f1]=(f-quan[x]-quan[y]+4)%2;
	}
	else{
		if((quan[x]+quan[y]-f+2)%2){
			nb(f1,3,0);
			nb(f2,3,0);
		}
	} 
}
int main(){
 	freopen("tribool.in","r",stdin);
 	freopen("tribool.out","w",stdout);
	hhh['T']=1;
	hhh['F']=2;
	hhh['U']=3;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		lun=n+3;
		for(int i=1;i<=n+3;i++)
		fa[i]=i,quan[i]=0;
		for(int i=1;i<=n;i++)
		fb[i]=i+3;
		for(int i=1;i<=m;i++){
			scanf("%s",bf);
			int x,y;
			if(bf[0]=='+'){
				scanf("%d%d",&x,&y);
				lun++;
				fa[lun]=lun;
				quan[lun]=0;
				nb(lun,fb[y],0);
				fb[x]=lun;
			}
			else if(bf[0]=='-'){
				scanf("%d%d",&x,&y);
				lun++;
				fa[lun]=lun;
				quan[lun]=0;
				nb(lun,fb[y],1);
				fb[x]=lun;
			}
			else{
				scanf("%d",&x);
				lun++;
				fa[lun]=lun;
				quan[lun]=0;
				nb(lun,hhh[bf[0]],0);
				fb[x]=lun;
			}
		}
	/*	for(int i=1;i<=n;i++){
			cout<<fb[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=lun;i++)
		cout<<i<<" "<<fa[i]<<" "<<quan[i]<<endl;*/
		for(int i=1;i<=n;i++) {
			nb(i+3,fb[i],0);
		}
		
		int ans=0;
		for(int i=4;i<=n+3;i++){
			if(find(i)==3)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}