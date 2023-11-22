#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,t[N][30],mi[N],ma[N];
char s[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		mi[i]=100;ma[i]=0;
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			t[i][s[j]-'a'+1]++;
			int x=(int)s[j]-'a'+1;
			mi[i]=min(mi[i],x);
			ma[i]=max(ma[i],x);
		}
	}
	for(int i=1;i<=n;i++){
		int f=1;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(mi[i]>=ma[j]){
				f=0; break;
			}
		}
		printf("%d",f);
	}
	return 0;
}