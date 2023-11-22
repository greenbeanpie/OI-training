#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,i,j,k,m,fi=0,se=0;
LL cnt[3005][26];
string s[3005],s1[3005],s2[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	  cin>>s[i];
	for(i=1;i<=n;i++)
	  for(j=0;j<m;j++)
	    cnt[i][s[i][j]-'a']++;
	for(i=1;i<=n;i++){
		for(j=25;j>=0;j--)
		  for(k=1;k<=cnt[i][j];k++)
		    s1[i]+=(char)('a'+j);
		for(j=0;j<=25;j++)
		  for(k=1;k<=cnt[i][j];k++)
		    s2[i]+=(char)('a'+j);
	}
	if(n==1){
		printf("1");
		return 0;
	}
	if(s1[1]<s1[2]) fi=1,se=2;
	else fi=2,se=1;
	for(i=3;i<=n;i++){
		if(s1[i]<s1[fi]){
	  	    se=fi;fi=i;
	    }  
	    else if(s1[i]<s1[se]){
	    	se=i;
		}
	}
	for(i=1;i<=n;i++){
		if(i==fi){
			if(s2[i]>=s1[se]) printf("0");
			else printf("1");
		}
		else{
			if(s2[i]>=s1[fi]) printf("0");
			else printf("1");
		}
	}
	return 0;
}
