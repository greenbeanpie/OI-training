// 09:18 开题, T=1, F=-1,U=0
// 09:21 盲猜修改是并查集
// 如果a = -a, 那么a一定是0
// ... 此处省略一大堆
// 大样例过了
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N];
int fa[N];
int findf(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = findf(fa[x]);
}
inline void merge(int x, int y)
{
	x = findf(x), y = findf(y);
	if(x != y) fa[x] = y;
}
inline void So1vE()
{
    int n, m;
    cin >> n >> m;
	int sup = n + 1;
    for(int i = 1 ; i <= 2 * sup ; i++) a[i] = i, fa[i] = i;
    for(int _ = 1 ; _ <= m ; _++)
    {
        char op;
        int x;
        cin >> op >> x;
        if(op == 'U') a[x] = 0;
        else if(op == 'T') a[x] = sup;
        else if(op == 'F') a[x] = -sup;
        else if(op == '+')
        {
            int y;
            cin >> y;
            a[x] = a[y];
        }
        else if(op == '-')
        {
            int y;
            cin >> y;
            a[x] = -a[y];
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
	{
		if(a[i] == 0) merge(i, a[i]);
		else if(a[i] > 0) merge(i, a[i]), merge(sup + i, sup + a[i]);
		else merge(i, sup - a[i]), merge(sup + i, -a[i]);
	}
	for(int i = 1 ; i <= n ; i++) if(findf(i) == findf(sup + i) || findf(i) == findf(0)) merge(i, 0), merge(sup + i, 0);
    for(int i = 1 ; i <= n ; i++) if(findf(i) == findf(0)) ans ++;
    cout << ans << endl;
}
int main()
{
    #ifndef DEBUG
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int C, T;
    cin >> C >> T;
    while(T --) So1vE();
    return 0;
}