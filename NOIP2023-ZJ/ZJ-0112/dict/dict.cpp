#include<algorithm>
#include<cstdio>
int n,m,L,b[30],ind[6010],min1,min2,rk[6010],p;
unsigned long long s1[6010][300],t;
char s[3010];
bool cmp(int x,int y)
{
	for (int i = 1;i <= L;++i)
		if (s1[x][i] != s1[y][i])
			return s1[x][i] < s1[y][i];
	return x%2 < y%2;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m),L = (m-1)/13+1;
	for (int i = 1;i <= n;++i)
	{
		
		scanf("%s",s+1),p = 0;
		for (int j = 1;j <= m;++j)
			++b[s[j]-97];
		for (int j = 0;j < 26;++j)
			while (b[j])
				s[++p] = j,--b[j];
		for (int j = 1;j <= m;j += 13)
		{
			t = 0;
			for (int k = 0;k < 13 && j+k <= m;++k)
				t = t*26ull+s[j+k];
			s1[i*2-1][j/13+1] = t;
		}
		for (int j = m;j > 0;j -= 13)
		{
			t = 0;
			for (int k = 0;k < 13 && j-k > 0;++k)
				t = t*26ull+s[j-k];
			s1[i*2][(m-j)/13+1] = t;
		}
		ind[i*2] = i*2,ind[i*2-1] = i*2-1;
	}
	std::sort(ind+1,ind+n*2+1,cmp);
	for (int i = 1;i <= n*2;++i)
		if (ind[i]%2 == 1)
			rk[ind[i]/2+1] = i;
		else
		{
			if (!min1)
				min1 = i;
			else if (!min2)
				min2 = i;
		}
	for (int i = 1;i <= n;++i)
		if (i != ind[min1]/2)
			putchar((rk[i] < min1)?'1':'0');
		else
			putchar((rk[i] < min2)?'1':'0');
	return 0;
}