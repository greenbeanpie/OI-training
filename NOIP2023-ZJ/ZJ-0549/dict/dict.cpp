#include<bits/stdc++.h>
namespace Solution {
	using namespace std;
	constexpr int maxn=3007,maxm=3007;
	string str1[maxn],minstr,secondminstr;
	char str[maxm];
	int cnt[31];
	int main() {
		int n;
		scanf("%d",&n);
		if(n==1)
			putc('1',stdout);
		else {
			for(int i=0; i<3001; ++i)
				str[i]='z';
			minstr=secondminstr=str;
			int m;
			scanf("%d",&m);
			int minc,maxc,minpos=n,secondminpos=n;
			for(int i=0,j,k; i<n; ++i) {
				scanf("%s",str);
				++cnt[minc=maxc=str[0]-'a'];
				k=0;
				for(j=1; j<m; ++j) {
					const int tmp=str[j]-'a';
					minc=min(minc,tmp);
					maxc=max(maxc,tmp);
					++cnt[tmp];
				}
				for(j=minc; j<=maxc; ++j)
					for(; cnt[j]; --cnt[j])
						str[k++]=j+'a';
				str1[i]=str;
				reverse(str,str+m);
				string s=str;
				if(s<minstr) {
					swap(minstr,secondminstr);
					swap(minstr,s);
					secondminpos=minpos;
					minpos=i;
				} else if(s<secondminstr) {
					swap(secondminstr,s);
					secondminpos=i;
				}
			}
			for(int i=0; i<n; ++i)
				if(i==minpos)
					putc(str1[i]<secondminstr?'1':'0',stdout);
				else putc(str1[i]<minstr?'1':'0',stdout);
		}
		return 0;
	}
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	return Solution::main();
}