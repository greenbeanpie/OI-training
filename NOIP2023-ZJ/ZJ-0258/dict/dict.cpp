#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

#define N 3005
int n,m;
int cnt[30];
string s1[N],s2[N],w[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1 ; i<=n ; ++i){
		cin>>w[i];
	//	for (int j=0 ; j<=26 ; ++j) cnt[j]=0;
		
		for (int j=0 ; j<m ; ++j)
		    cnt[w[i][j]-'a']++;
		for (int j=0 ; j<26 ; ++j)
		    for (int k=1 ; k<=cnt[j] ; ++k)
		        s1[i]+=('a'+j);
		        
		for (int j=25 ; j>=0 ; --j){
			while (cnt[j]) s2[i]+=('a'+j),--cnt[j];
		}
	}
	for (int i=1 ; i<=n ; ++i){
		int flag=1;
		for (int j=1 ; j<=n ; ++j){
			if (i==j) continue;
			if (s1[i]>s2[j]){
				flag=0;
				break;
			}
		}
		printf("%d",flag);
	}
	return 0;
}