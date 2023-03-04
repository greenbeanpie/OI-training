#include <iostream>
#define reg register
using namespace std;

int dp[510];
int a[510], b[510];
int ans = -114514;
int n1, n2;

int main()
{
    scanf("%d", &n1);
    for (int i = 1; i <= n1; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n2);
    for (int i = 1; i <= n2; ++i)
        scanf("%d", &b[i]);

    for (reg int i = 1; i <= n1; ++i)
    {
    	int p = 0;
    	for (reg int j = 1; j <= n2; ++j)
    	{
    		// 寻找[上升]的[更长]的序列 
    		if (a[i] > b[j])
    			p = max(p, dp[j]);
    	
    		// 我谔谔这就是说狗尾续貂是么
    		if (a[i] == b[j])
    			dp[j] = p + 1;
    	}
    }
  
    // 寻找答案
    for (reg int i = 1; i <= n2; ++i)
    	ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}

