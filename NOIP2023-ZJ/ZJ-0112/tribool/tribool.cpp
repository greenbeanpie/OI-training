#include<cstdio>
#include<cstring>
const int N = 100010;
int c,t,n,m,vis[N],vis1[N],kind[N],kdp[N],p[N],s[10],u,v,cnt,ans,pre,st[N],top;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(int)*(n+10));
		memset(vis1,0,sizeof(int)*(n+10));
		memset(kind,0,sizeof(int)*(n+10));
		memset(kdp,0,sizeof(int)*(n+10));
		ans = top = 0;
		kind[n+1] = 1;
		for (int i = 1;i <= n+3;++i)
			p[i] = i;
		for (int i = 1;i <= m;++i)
		{
			scanf("%s",s);
			if (s[0] == 'T' || s[0] == 'F')
				scanf("%d",&u),p[u] = n+2;
			else if (s[0] == 'U')
				scanf("%d",&u),p[u] = n+1;
			else
			{
				scanf("%d%d",&u,&v),p[u] = p[v],kdp[u] = kdp[v];
				if (s[0] == '-')
					kdp[u] ^= 1;
			}
		}
		for (int i = 1;i <= n;++i)
			if (!vis[i])
				if (p[i] == i)
					ans += kdp[i],kind[i] = kdp[i],vis[i] = 1;
				else
					for (pre = i;;pre = p[pre])
					{
						vis[pre] = vis1[pre] = 1,st[++top] = pre;
						if (vis1[p[pre]])
						{
							cnt = 0;
							for (int j = top;j;--j)
							{
								cnt ^= kdp[st[j]];
								if (st[j] == p[pre])
									break;
							}
							ans += cnt*top;
							while (top)
								kind[st[top]] = cnt,vis1[st[top]] = 0,--top;
							break;
						}
						if (p[pre] > n || vis[p[pre]])
						{
							ans += kind[p[pre]]*top;
							while (top)
								kind[st[top]] = kind[p[pre]],vis1[st[top]] = 0,--top;
							break;
						}
					}
		printf("%d\n",ans);
	}
	return 0;
}