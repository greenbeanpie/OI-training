#include<bits/stdc++.h>
using namespace std;
const int MaxN=3050;
int Mn[MaxN],Mx[MaxN];
int n,m;
char ch;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n+1;i++){
		Mn[i]=100;Mx[i]=-100;
		getchar();
		for(int j=1;j<m+1;j++){
			ch=getchar();
			Mx[i]=max(Mx[i],int(ch)-int('a')+1);
			Mn[i]=min(Mn[i],int(ch)-int('a')+1);
		}
	}
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<n+1;i++){
		bool pd=true;
		for(int j=1;j<n+1;j++)
			if(j!=i && Mn[i]>=Mx[j]){
				pd=false;
				break;
			}
		printf("%d",pd?1:0);
	}
	return 0;
}