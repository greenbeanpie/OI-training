#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
char s[N*2][N];
int ma[N*2][N],mi[N*2][N],ans[N],cnt[30];
int n,m,mma,cmma,mmi,cmmi;
bool com(int a,int b){
	int i=1;
	while(i<=m&&ma[a][i]==ma[b][i]) i++;
	if(i>m) return 1;
	else if(ma[a][i]>ma[b][i]) return 1;
	else return 0;
}
int ncom(int a,int b){
	int i=1;
	while(i<=m&&ma[a][i]==mi[b][i]) i++;
	if(i>m) return 0;
	else if(ma[a][i]>mi[b][i]) return 1;
	else return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	if(n==1){
		cout<<1;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cnt[s[i][j]-'a']++;
		for(int j=0,k=1;j<26;j++){
			int res=cnt[j];
			while(res) res--,mi[i][k++]=j;
		}
		for(int j=25,k=1;j>=0;j--){
			while(cnt[j]) cnt[j]--,ma[i][k++]=j;
		}
	}
	for(int i=1;i<=n;i++){
		if(mmi==0) mmi=i;
		else if(com(mmi,i)){
			cmmi=mmi;
			mmi=i;
		}else if(com(cmmi,i)) cmmi=i;
	}
	for(int i=1;i<=n;i++){
		if(mmi==i) ans[i]=ncom(cmmi,i);
		else ans[i]=ncom(mmi,i);
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	return 0;
}