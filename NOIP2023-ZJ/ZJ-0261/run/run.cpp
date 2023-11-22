#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d,ans,anss;
bitset<18>bit;
bool check(){
	int add=0;
	for(int i=0;i<n;i++){
		if(bit[i])add++;else add=0;
		if(add>k)return 0;
	}return 1;
}
int x[100039],y[100039],v[100039];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x[i],&y[i],&v[i]);
		}
		if(n<=18){anss=0;
			for(int i=0;i<(1<<n);i++){
				bit=i;ans=0;
				if(check()){
					ans-=bit.count()*d;
					for(int i=1;i<=m;i++){
						bool ct=1;
						for(int j=x[i]-y[i]+1;j<=x[i];j++){
							if(!bit[j-1])ct=0;
						}
						if(ct)ans+=v[i];
					}
				}
				anss=max(anss,ans);
			}
		}
		printf("%d\n",anss);
	}
}