#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define ve vector<ll>
#define pa pair<ll,ll>
using namespace std;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,m,k,t;
char a[3005][3005];
struct s{
	ll p[30],num;
}b[3005],c[3005];
bool cmp(s a,s b){
	for(int i=25;i>=0;i--){
		if(a.p[i]!=b.p[i])return a.p[i]<b.p[i];
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=rd;m=rd;
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i].p[a[i][j]-'a']++;
			b[i].num=i;
			c[i]=b[i];
		}
	}
	sort(b+1,b+1+n,cmp);
	for(int i=25;i>=0;i--){
		if(b[1].p[i]!=0){
			k=i,t=b[1].p[i];
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=b[1].num){
			int j=0;
			for(;j<=25;j++){
				if(c[i].p[j]!=0){
					break;
				}
			}
			if(j<k){
				printf("1");
			}else{
				printf("0");
			}
		}else{
			printf("1");
		}
	}
	return 0;
}
