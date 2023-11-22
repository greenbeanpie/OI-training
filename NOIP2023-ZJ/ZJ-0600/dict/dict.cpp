#include<bits/stdc++.h>
using namespace std;
char s[3002],mn[3001],mx[3001];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,i,j;bool f;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s+1;
		mn[i]=*min_element(s+1,s+m+1);
		mx[i]=*max_element(s+1,s+m+1);
	}
	for(i=1;i<=n;i++)
	{
		f=true;
		for(j=1;j<=n;j++) if(j!=i)
		if(mx[j]<=mn[i]) f=false;
		printf("%d",f?1:0);
	}
	printf("\n");
	return 0;
}
//the conclusion: for strings A and B, A can be smaller than B (in dict) by swaping the letters when only there is a letter in A that bigger than the smallest letter in B.
//the turned meaning: for every string X, query if there is a letter in all other strings that bigger than the smallest letter in X.
//the solution: for every string X, query if the biggest letter in all other strings is bigger than the smallest letter in X.
