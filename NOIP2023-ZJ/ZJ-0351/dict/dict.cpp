#include<bits/stdc++.h>
using namespace std;
int cnt[40],num1[3086][3086],num2[3086][3086],ans[3086];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,min_num2=0,tot;
//	int tot1=0;
	bool flag1=false,flag2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		tot=0;
		flag2=false;
		for(int j=1;j<=m;j++){
			char ch=getchar();
//			++tot1;
			while(ch<'a'||ch>'z'){
				ch=getchar();
			}
			++cnt[ch-'a'+1];
		}
		for(int j=1;j<=26;j++){
			while(cnt[j]){
//				++tot1;
				num1[i][++tot]=j;
				num2[i][m-tot+1]=j;
				--cnt[j];
			}
		}
		for(int j=1;j<=m;j++){
//			++tot1;
			if(!min_num2||num2[i][j]<num2[min_num2][j]){
				flag2=true;
				min_num2=i;
				break;
			}
			if(num2[i][j]>num2[min_num2][j]){
				flag2=true;
				break;
			}
		}
		if(!flag2){
			flag1=true;
		}
	}
	tot=0;
	for(int i=1;i<=n;i++){
		int now=0;
		if(!flag1&&i==min_num2){
//			++tot1;
			ans[++tot]=1;
			continue;
		}
		for(int j=1;j<=m;j++){
//			++tot1;
			if(num1[i][j]<num2[min_num2][j]){
				now=1;
				break;
			}
			if(num1[i][j]>num2[min_num2][j]){
				break;
			}
		}
		ans[++tot]=now;
	}
//	printf("%d\n",tot1);
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}