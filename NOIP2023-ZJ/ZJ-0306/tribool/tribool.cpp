//50p?
#include<bits/stdc++.h>
using namespace std;
const int MS=1e5+5;
struct node{
	int type,mul,x,y;
	//type1表示赋值初值
	//type2表示转移a[x]=a[y] 
}ord[MS];
int c,t,n,m;
int a[MS],b[MS],fa[MS],eq[MS];
char s;
bool tfu=1,ujia=1,zf=1;
bool tfuvis[MS],ifu[MS],hf[MS];
int KSM(int x,int idx){
	int res=1;
	while(idx){
		if(idx&1)res*=x;
		x*=x;
		idx>>=1;
	}
	return res;
}
int findfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
int cheak(int x){
	int cnt=0,flag=1;
	for(int j=1;j<=n;j++){
		a[j]=x%3-1;
		b[j]=x%3-1;
		if(x%3-1==0)cnt++;
		x/=3;
	}
	for(int j=1;j<=m;j++){
		if(ord[j].type==1){
			b[ord[j].x]=ord[j].y;
		}else{
			b[ord[j].x]=b[ord[j].y]*ord[j].mul;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]){
			return 1e9;
		}
//		for(int i=1;i<=n;i++)
//			printf("%d ",a[i]);
//		printf("\n");	
	return cnt;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	//多组数据记得清空
	scanf("%d%d",&c,&t);
	while(t--){
		int ans=1e9;
		tfu=ujia=zf=1;
		memset(ord,0,sizeof(ord));
		memset(tfuvis,0,sizeof(tfuvis));
		memset(ifu,0,sizeof(ifu));
		memset(eq,0,sizeof(eq));
		memset(hf,0,sizeof(hf));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=m;i++){
			cin>>s;
			if(s=='-'){
				ord[i].type=2;
				ord[i].mul=-1;
				scanf("%d%d",&ord[i].x,&ord[i].y);
				tfu=0; ujia=0;
			}
			if(s=='+'){
				ord[i].type=2;
				ord[i].mul=1;
				scanf("%d%d",&ord[i].x,&ord[i].y);
				tfu=0;
			}
			if(s=='T'){
				ord[i].type=1;
				scanf("%d",&ord[i].x);
				ord[i].y=1;
				ujia=0;
				zf=0;
			}
			if(s=='U'){
				ord[i].type=1;
				scanf("%d",&ord[i].x);
				ord[i].y=0;
				zf=0;
			}
			if(s=='F'){
				ord[i].type=1;
				scanf("%d",&ord[i].x);
				ord[i].y=-1;
				ujia=0;
				zf=0;
			}
		}
		if(tfu){
			ans=0;
			for(int i=m;i>=1;i--){
				if(tfuvis[ord[i].x])continue;
				tfuvis[ord[i].x]=1;
				if(ord[i].y==0)ans++;
			}
			printf("%d\n",ans);
		}else
		if(ujia){
			int last=-1;
			ans=0;
			while(last!=ans){
				last=ans;
				ans=0;
				for(int i=1;i<=m;i++){
					if(ord[i].type==1)ifu[ord[i].x]=1;
					else ifu[ord[i].x]=ifu[ord[i].y];
				}
				for(int i=1;i<=n;i++)
					if(ifu[i])ans++;			
			}
			printf("%d\n",ans);
		}else
		if(zf){
			ans=0;
			for(int i=1;i<=m;i++)
				eq[ord[i].x]=ord[i].y*ord[i].mul;
			for(int i=1;i<=n;i++)
				if(eq[i]>0){
					fa[findfa(i)]=fa[findfa(eq[i])];
				}
			for(int i=1;i<=n;i++)
				if(eq[i]<0){
					if(fa[findfa(i)]==fa[findfa(-eq[i])])
						hf[fa[i]]=1;	
				}
			for(int i=1;i<=n;i++)
				if(hf[findfa(i)])ans++;
			printf("%d\n",ans);
		}else{
			for(int i=0;i<KSM(3,n);i++){
				ans=min(ans,cheak(i));
			}
			printf("%d\n",ans);		
		}
	} 
	return 0;
}
//伟大的CCF保佑我rp++ 
