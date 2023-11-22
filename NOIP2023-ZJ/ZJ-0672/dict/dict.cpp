#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
int maxn[N],minn[N];
char c;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	memset(minn,127,sizeof(minn));
	int i,j,k,x;
	bool f=0;
	cin>>n>>m;
	if(n==1){
		printf("1");
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){
			do{
				c=getchar();				
			}while(c<'a'||c>'z');
			x=c-'a';
			maxn[i]=max(maxn[i],x);
			minn[i]=min(minn[i],x);
		}
	}
	if(m==1){
		for(i=1;i<=n;i++){
			f=0;
			for(j=1;j<=n;j++){
				if(i!=j&&minn[i]>minn[j]){
					f=1;
					printf("0");
					break;
				}
			}
			if(!f) printf("1");
		}
		return 0;
	}
	for(i=1;i<=n;i++){
		f=0;
		for(j=1;j<=n;j++){
			if(i!=j){
				if(minn[i]>=maxn[j]){
					printf("0");
					f=1;
					break;
				}
			}
		}
		if(!f) printf("1");
	}
}
