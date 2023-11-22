#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=3005;
int n,m;
string s[N],s1[N];
char c;
int tong[30];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		c=getchar();
		for(int j=1;j<=m;j++) c=getchar(),s[i]+=c;
		s1[i]=s[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) tong[j]=0;
		for(int j=0;j<m;j++) tong[s[i][j]-'a']++;
		int temp=0;
		for(int j=0;j<26;j++){
			if(tong[j]){
				s[i][temp]=j+'a';
				tong[j]--;
				temp++;	
			}
		}
		for(int j=0;j<26;j++) tong[j]=0;
		for(int j=0;j<m;j++) tong[s1[i][j]-'a']++;
		temp=0;
		for(int j=25;j>=0;j--){
			if(tong[j]){
				s1[i][temp]=j+'a';
				tong[j]--;
				temp++;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=1;j<=n;j++)
			if(s[i]>=s1[j]&&i!=j){
				ok=false;break;
			}
		if(ok) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}
