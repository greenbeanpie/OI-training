#include <iostream>//卑微的头文件
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int a[2050][2050];

void dfs(int x1,int y1,int x2,int y2,int num)//(x1,y1)为正方形的左上角坐标，（x2，y2）为右下角坐标，这里注意：由于读入坐标的时候和  平常数学的平面直角坐标系不同，左上角的“纵坐标”是小于右下角的“纵坐标”的
{
	if(num<n)//判断是否能递归下去，分成三个小正方形
	{
		dfs((x2-x1)/2+x1+1,y1,x2,y1+(y2-y1)/2,num+1);
		dfs((x2-x1)/2+x1+1,(y2-y1)/2+y1+1,x2,y2,num+1);
		dfs(x1,(y2-y1)/2+y1+1,x1+(x2-x1)/2,y2,num+1);
	}
	for(int i=x1;i<=(x2-x1)/2+x1;i++)
	  for(int j=y1;j<=(y2-y1)/2+y1;j++)
	     a[i][j]=1;//标记能赦免，等等输出时取反即可qwq
}
	
int main()
{
	memset(a,0,sizeof(a));//初始化
	scanf("%d",&n);
	dfs(1,1,(1<<n),(1<<n),1);//位运算貌似快一点（雾）
	for(int i=1;i<=(1<<n);i++)
	   {
	    	for(int j=1;j<=(1<<n);j++)
	    	  printf("%d ",!a[i][j]);//取反输出
	    	printf("\n");//注意换行
	   }
	return 0;//华丽的结束
}