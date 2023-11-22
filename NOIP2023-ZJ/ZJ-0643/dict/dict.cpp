#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3030,M=3030;
int n,m;
char s[N][M];
bool chk(int p,int q){
	for(int i=1;i<=m;++i){
		if(s[p][i]<s[q][i])return 1;
		if(s[p][i]>s[q][i])return 0;
	}
}
inline bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		sort(s[i]+1,s[i]+m+1,cmp);
	}
	for(int i=1;i<=n;++i){
		sort(s[i]+1,s[i]+m+1);
		if(i>=2)sort(s[i-1]+1,s[i-1]+m+1,cmp);
		int flag=1;
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(!chk(i,j)){
				flag=0;
				break;
			}
		}
		printf("%d",flag);
	}
	return 0;
}
//fc E:\ZJ-0643\dict\dict4.ans E:\ZJ-0643\dict\asd.out
