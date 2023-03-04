#include <iostream>

#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

#define FINDDEBUG printf("[FIND] i:%d, j:%d, length:%d \n[INFO] list:", i, j, p.len); for (auto x : p.now) printf("%d ", x); printf("\n\n");
#define LINKDEBUG printf("[LINK] i:%d, j:%d, length:%d \n[INFO] list:", i, j, p.len); for (auto x : dp[j].now) printf("%d ", x); printf("\n\n");

using namespace std;

struct Node
{
	int len;
	vector<int> now;
} dp[510];

int n1, n2, a[510], b[510];

int main()
{
//	freopen("subseq.in", "r", stdin);
//	freopen("subseq.out", "w", stdout);

    scanf("%d", &n1);
    for (int i = 1; i <= n1; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n2);
    for (int i = 1; i <= n2; ++i)
        scanf("%d", &b[i]);
  
	// start to do the dynamic programing
	// no god please no i do not want to do this
    for (reg int i = 1; i <= n1; ++i)
    {
    	Node p; p.len = 0;
    	for (reg int j = 1; j <= n2; ++j)
    	{
    		// what the f**king equaltion ahhhhhhhhhhhhhhhhhhhh
    		// it takes me two thousand years to remember this s**t one
    		// O(n^2) yyds! go to the hell O(nlogn).
  
  
    		// 寻找[上升]的[更长]的序列 
    		// 你是一个一个一个公式啊啊啊啊啊
    		if (a[i] > b[j] && dp[j].len > p.len)
    		{
    			p = dp[j];
  
                // FINDDEBUG
    		}
  
  
    		// 我谔谔这就是说狗尾续貂是么
    		if (a[i] == b[j]) 
    		{
    			dp[j].len = p.len + 1;
    			dp[j].now = p.now;
    			dp[j].now.pb(a[i]);
  
    			// LINKDEBUG
    		}
    	}
    }
  
    // 寻找答案
    Node ans = dp[1];
    for (reg int i = 2; i <= n2; ++i)
    {
    	if (dp[i].len > ans.len)
    		ans = dp[i];
    }
    printf("%d\n", ans.len);
    for (auto x : ans.now)
    	printf("%d ", x);
    return 0;
}

