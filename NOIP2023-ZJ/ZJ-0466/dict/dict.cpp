#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int p=0,o=1;char po=getchar();
	while(!(po>='0'&&po<='9')){if(po=='-')o=-1;po=getchar();}
	while(po>='0'&&po<='9'){p=p*10+po-'0';po=getchar();}
	return p*o;
}
int a,s,d[3005][2];
string f;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	a=read();s=read();
	for(int i=1;i<=a;i++){
		cin>>f;d[i][0]=999;
		for(int j=1;j<=s;j++){
			d[i][1]=max(f[j-1]-'a'+1,d[i][1]);
			d[i][0]=min(f[j-1]-'a'+1,d[i][0]);
		}
	}
	for(int i=1;i<=a;i++){
		bool ans=true;
		for(int j=1;j<=a;j++)if(j!=i)
			if(d[j][1]<=d[i][0])ans=false;
		if(ans==true)printf("1");
		else printf("0");
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/