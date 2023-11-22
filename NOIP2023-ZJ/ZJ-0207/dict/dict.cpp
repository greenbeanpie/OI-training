#include<bits/stdc++.h>
using namespace std;
struct P{
	int ch,cnt;
}x[30];
char s[3005];
int c[3005][30];
vector<P> mi[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		for(j=1;j<=m;j++)c[i][s[j]-'a'+1]++;
		for(j=1;j<=26;j++){
			if(c[i][j]!=0){
				mi[i].push_back((P){j,c[i][j]});
			}
		}
	}
	for(i=1;i<=n;i++){
		char f='1';
		for(j=1;j<=n;j++){
			if(j==i)continue;
			k=0;
			for(auto v:mi[j]){
				k++;
				x[k]=v;
			}
			for(auto v:mi[i]){
				if(v.ch>x[k].ch){
					f='0';
					break;
				}
				if(v.ch<x[k].ch)break;
				if(v.cnt!=x[k].cnt){
					f='0';
					break;
				}
				k--;
			}
			if(f=='0')break;
		}
		printf("%c",f);
	}
	return 0;
}