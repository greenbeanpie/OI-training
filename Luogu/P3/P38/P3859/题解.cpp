#include <bits/stdc++.h>
using namespace std;
#define N 1005
int n, m, i, j, k, close[N], f[N];//close数组记录门关闭的（真正的）时间，f数组是当前时间拿的最大价值 
struct baoshi{//习惯用结构体了。。。 
	int room, val, t;//宝石的 房间编号 价值 拿走的时间 
}d[N];
int main(){
	scanf ("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf ("%d", &close[i]);//0号房开始 
	for (i = 1; i < n; i++) close[i] = min (close[i], close[i-1]);
	//因为前面的门如果关上了，就不能去后面的门了，所以每扇门真正的关闭时间是前面的门最早的关闭时间 
	for (i = 1; i <= m; i++) scanf ("%d%d%d", &d[i].room, &d[i].val, &d[i].t);
	for (i = 1; i < close[0]; i++){//第一重循环，枚举时间（一定要在0号房关闭之前出去） 
		f[i] = f[i-1];//如果不偷宝石 
		for (j = 1; j <= m; j++){//枚举宝石
			if (close[d[j].room] > i /*关闭的时间大于枚举的时间，能进*/ && d[j].t <= i)//能拿 
			f[i] = max (f[i], f[i-d[j].t] + d[j].val);//拿或者不拿的最大值 
		}
	}
	printf ("%d", f[close[0]-1]);//可以理解为门关闭前最后一秒拿的价值 
	return 0;//完美收场
}
