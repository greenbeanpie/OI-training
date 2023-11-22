#include<bits/stdc++.h>
using namespace std;

const int N = 3010;

char str[N][N];

int cnt[30];

inline void st1(char *str, int m)
{
	int i;
	for(i=0;i<=25;i++) cnt[i] = 0;
	for(i=1;i<=m;i++) cnt[str[i]-'a']++;
	int now = 0;
	for(i=25;~i;i--)
		while(cnt[i]--)
			str[++now] = i + 'a';
	return;
}

inline void st2(char *str, int m)
{
	int i;
	for(i=0;i<=25;i++) cnt[i] = 0;
	for(i=1;i<=m;i++) cnt[str[i]-'a']++;
	int now = 0;
	for(i=0;i<=25;i++)
		while(cnt[i]--)
			str[++now] = i + 'a';
	return;
}

inline bool cmp(char *s1, char *s2, int m)
{
	int i;
	for(i=1;i<=m;i++)
		if(s1[i]!=s2[i])
			return s1[i] < s2[i];
	return 0;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n, m, i, j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			str[i][j] = getchar();
			while('a'>str[i][j]||str[i][j]>'z') str[i][j] = getchar();
		}
	str[0][1] = 100;
	for(i=1;i<=n;i++) st1(str[i],m);
	int d = 1, e = 0;
	for(i=1;i<=n;i++)
	{
		if(cmp(str[i],str[d],m))
			d = i, e = 0;
		else if(!cmp(str[d],str[i],m)) e = 1;
	}
	for(i=1;i<=m;i++) str[0][i] = str[d][i];
	for(i=1;i<=n;i++) st2(str[i],m);
	for(i=1;i<=n;i++)
	{
		if((e==0&&i==d)||cmp(str[i],str[0],m)) putchar('1');
		else putchar('0');
	}
	return 0;
}