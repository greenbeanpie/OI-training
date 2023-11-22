#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
int Max[3005],Min[3005],n,m;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int c;
		while((c=getchar())<97);
		Min[i]=Max[i]=c;
		for(int j=2;j<=m;j++){
			while((c=getchar())<97);
			Min[i]=min(Min[i],c);
			Max[i]=max(Max[i],c);
		}
	}
	for(int i=1;i<=n;i++){
		int b=1;
		for(int j=1;j<=n;j++)if(i!=j){
			if(Min[i]>=Max[j])b=0;
		}
		printf("%d",b);
	}
	return 0;
}