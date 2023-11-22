#include <bits/stdc++.h>
#define MAXN 3010
using namespace std;
int mx[MAXN],mn[MAXN];
int n,m;

int lessThan(int t){
	for(int i=1;i<=n;i++){
		if(i==t)
			continue;
		if(mx[i]<=mn[t])
			return 0;
	}
	return 1;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	for(int i=0;i<=MAXN;i++){
		mx[i]=-1;
		mn[i]=26;
	}
	char s[MAXN];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++){
			if(s[j]-'a'<mn[i])
				mn[i]=s[j]-'a';
			if(s[j]-'a'>mx[i])
				mx[i]=s[j]-'a';
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d",lessThan(i));
	return 0;
}
