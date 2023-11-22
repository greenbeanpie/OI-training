//bushi lian zhong wen shu ru fa dou mei you???
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MAXN=3e3+50;
char w[MAXN];
int n,m;
int s[MAXN][MAXN];
int r[MAXN];
bool cmp1(int a,int b){
	return a>b;
}
bool cmp2(int a,int b){
	for(int i=1;i<=m;++i){
		if(s[a][i]==s[b][i]) continue;
		return s[a][i]<s[b][i];
	}
	return true;
}
bool ans[MAXN];
void print(){
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<(char)(s[r[i]][j]-1+'a');
		}
		cout<<endl;
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		r[i]=i;
		scanf("%s",w);
		for(int j=0;j<m;++j)
			s[i][j+1]=w[j]-'a'+1;
		sort(s[i]+1,s[i]+m+1,cmp1);//max zidianxu
	}
	sort(r+1,r+1+n,cmp2);//cong xiao dao da
//	print();
	int j=1,i=1;
	bool flag;
	for(int x=1;x<=n;++x){
		i=r[x];
		if(i==1) j=r[2];
		else j=r[1];
		flag=true;
		for(int k=1;k<=m;++k){
			if(s[i][m-k+1]==s[j][k]) continue;
			else{
				flag=(s[i][m-k+1]<s[j][k]);
				break;
			}
		}
		ans[i]=flag;
	}
	for(int i=1;i<=n;++i) printf("%d",ans[i]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/