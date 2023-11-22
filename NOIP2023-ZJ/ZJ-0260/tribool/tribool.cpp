#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,ans[100100],a[200100],r[200100],x,y,anss;
bool ji[200100];
char s;
int find(int x){
	if(a[x]==x){
		return x;
	}
	else return a[x]=find(a[x]);
}
void hb(int x,int y){
	int zx=find(x),zy=find(y);
	if(r[zx]>r[zy]){
		a[zy]=zx;
	}
	else{
		a[zx]=zy;
		if(r[zx]==r[zy]){
			r[zy]++;
		}
	}
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		anss=0;
		memset(ji,0,sizeof(ji));
		for(int i=1;i<=n;i++){
			ans[i]=i;
		}
		for(int i=1;i<=2*n;i++){
			a[i]=i;
			r[i]=1;
		}
		for(int i=1;i<=m;i++){
			getchar();
			scanf("%c",&s);
			if(s=='+'||s=='-'){
				scanf("%d%d",&x,&y);
				if(ans[y]<=n){
					if(s=='+'){
						ans[x]=ans[y];
					}
					else{
						ans[x]=-ans[y];
					}
				}
				else{
					if(ans[y]==n+1){
						if(s=='+') ans[x]=n+1;
						else ans[x]=n+2;
					}
					else if(ans[y]==n+2){
						if(s=='+') ans[x]=n+2;
						else ans[x]=n+1;
					}
					else{
						ans[x]=n+3;
					}
				}
			}
			else{
				scanf("%d",&x);
				if(s=='F'){
					ans[x]=n+1;
				}
				else if(s=='T'){
					ans[x]=n+2;
				}
				else ans[x]=n+3;
			}
		}
		for(int i=1;i<=n;i++){
			if(ans[i]==n+3) anss++;
			if(ans[i]<=n){
				if(ans[i]<0){
					if(find(i)==find(-ans[i])){
						ji[i]=1;
					}
					if(find(i)!=find(-ans[i]+n)){
						hb(i,-ans[i]+n);
					}
					if(find(i+n)!=find(-ans[i])){
						hb(i+n,-ans[i]);
					}
				}
				else{
					if(find(i)==find(ans[i]+n)){
						ji[i]=1;
					}
					if(find(i)!=find(ans[i])){
						hb(i,ans[i]);
					}
					if(find(i+n)!=find(ans[i]+n)){
						hb(i+n,ans[i]+n);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(ji[i]||ans[i]==n+3){
				ji[find(i)]=ji[find(n+i)]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(ans[i]<=n){
				if(ji[find(i)]){
					anss++;
				}
			}
		}
		printf("%d\n",anss);
	}
	return 0;
}
