#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,w=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		w=w*10+ch-'0';
		ch=getchar();
	}
	return w*f;
}
int c,T,n,m,a[1000001]={},su=0,b[1000001]={},C[1000001]={};
int emm(int g){
	if(a[g]<=0){
		return a[g];
	}
	if(a[g]==g){
		return g;
	}
	return emm(a[g]);
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	if(c==3||c==4){
		//cout<<3;
		for(int i=0;i<T;i++){
			n=read();
			m=read();
			su=0;
			for(int j=1;j<=n;j++){
				a[j]=0;
			}
			for(int j=0;j<m;j++){
				char ss;
				int l;
				cin>>ss>>l;
				if(ss=='U'){
					a[l]=1;
				}else if(ss=='F'){
					a[l]=0;
				}else{
					a[l]=2;
				}
			}
			
			for(int j=1;j<=n;j++){
				if(a[j]==1){
					su++;
				}
			}
			cout<<su;
		}
	}else{
		//cout<<1;
		for(int i=0;i<T;i++){
			cin>>n>>m;
			su=0;
			for(int j=1;j<=n;j++){
				a[j]=j;
				b[j]=0;
			}
			for(int j=0;j<m;j++){
				char ss;
				int l,x,y;
				cin>>ss;
				if(ss=='U'){
					scanf("%d",&l);
					a[l]=-2;
				}else if(ss=='T'){
					scanf("%d",&l);
					a[l]=-1;
				}else if(ss=='F'){
					scanf("%d",&l);
					a[l]=-3;
				}else{
					scanf("%d%d",&x,&y);
					if(ss=='-'){
						b[x]=1-b[y];
					}else{
						b[x]=b[y];
					}
					a[x]=emm(y);
				}
			}
			for(int j=1;j<=n;j++){
				if(a[j]==j){
					if(b[j]==1){
						a[j]=-2;
					}else{
						a[j]=-1;
					}
				}
			}
			bool flag=true;
			while(flag){
				flag=false;
				for(int j=1;j<=n;j++){
					if(a[j]>0){
						a[j]=a[a[j]];
						flag=true;
					}
				}
			}
			
			for(int j=1;j<=n;j++){
				if(a[j]==-2){
					su++;
				}
			}
			cout<<su;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

