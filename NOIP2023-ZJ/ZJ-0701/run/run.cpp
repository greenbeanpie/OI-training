/*
f(i , j) => day = i(from 1) , stick j days , cmax score;
//j <= cmin(daylim , i)
case day[i] , sti[j] win :
f(i , j) = f(i - 1 , j - 1) + v[i] - downsco;
case not win :
f(i , j) = f(i - 1 , j - 1) - downsco;
base case:
f(i , 0) = cmax(f(i - 1 , x));(0<= x <= cmin(daylim , i - 1))
f(0 , 0) = 0;
ans:
cmax(f(daynum , x));(0 <= x <= cmin(daylim , daynum))

f(j) => stick j days , maxscore;
case day = i can win :
f(j) = f(j - 1) + v[i] - downsco;
//j : from cmin(daylim , i) to 1
case cannot win :
f(j) = f(j - 1) - downsco;
//j : from cmin(daylim , i) to 1
base case:
f(0) = cmax(f(x));
//0 <= x <= cmin(daylim , i - 1)
i = 0 , f(0) = 0;
*/
#include <bits/stdc++.h>
using namespace std;

#define cmin(a , b) (a < b ? a : b)
#define cmax(a , b) (a > b ? a : b)
struct wincon
{
	long long condi;
	long long val;
};
long long daynum , chanum , sticklim , downsco;
long long *sco = 0;
map <long long , wincon> winv;
wincon mkwincon(long long con , long long val)
{
	wincon a;
	a.condi = con;
	a.val = val;
	return a;
}
long long findin(long long day , long long sti)
{
	try
	{
		if(winv.at(day).condi <= sti)return winv.at(day).val;
	}
	catch(...)
	{
		return 0;
	}
	return 0;
}
int main()
{
	//cout << freopen("run3.in" , "r" , stdin) << endl;
	freopen("run.in" , "r" , stdin);
	freopen("run.out" , "w" , stdout);
	long long testc , testtimes;
	cin >> testc >> testtimes;
	for(long long csyy = 0;csyy < testtimes;csyy++)
	{
		winv.clear();
		cin >> daynum >> chanum >> sticklim >> downsco;
		sco = new long long [sticklim + 1];
		for(long long i = 0;i < chanum;i++)
		{
			long long a;
			long long b , c;
			cin >> a >> b >> c;
			winv[a] = mkwincon(b , c);
		}
		for(long long i = 0;i <= sticklim;i++)
		{
			sco[i] = 0;
		}
		for(long long nday = 1;nday <= daynum;nday++)
		{
			long long res0 = sco[0];
			for(long long j = 1;j <= cmin(sticklim , nday - 1);j++)
			{
				res0 = cmax(sco[j] , res0);
			}
			long long v;
			for(long long j = cmin(sticklim , nday);j >= 1;j--)
			{
				v = findin(nday , j);
				//printf("nday%d j%d " , nday , j);
				//cout << v << endl;
				if(v == 0)sco[j] = sco[j - 1] - downsco;
				else sco[j] = sco[j - 1] - downsco + v;
			}
			sco[0] = res0;
			// for(long long i = 0;i <= sticklim;i++)
			// {
			// 	cout << sco[i] << " ";
			// }
			// cout << endl;
		}
		long long ans = 0;
		for(long long i = 0;i <= sticklim;i++)
		{
			ans = cmax(ans , sco[i]);
		}
		cout << ans << endl;
		// for(long long i = 0;i <= sticklim;i++)
		// {
		// 	cout << sco[i] << " ";
		// }
		delete sco;
	}
	return 0;
}