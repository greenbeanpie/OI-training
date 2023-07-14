#include<bits/stdc++.h>
using namespace std;

struct P {
	double x;
	double y;
} p[50000], b[50000];

bool cmpx(P a, P b)
{
	return a.x < b.x;
}

bool cmpy(P a, P b)
{
	return a.y < b.y;
}

double dist(P a, P b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double min_dist(P *a, int low, int high)
{
	if (low == high - 1) {
		return DBL_MAX;
	}
	
	// 分 
	int mid = (low + high) / 2;
	double d1 = min_dist(a, low, mid);
	double d2 = min_dist(a, mid, high);
	double d0 = min(d1, d2);
	
	// 合
	int k = 0;
	for (int i = low; i < high; i++) {
		if (fabs(p[i].x - p[mid].x) < d0) {
			b[k++] = p[i];
		}
	}
	sort(b, b + k, cmpy);
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k && b[j].y - b[i].y < d0; j++) {
			d0 = min(d0, dist(b[i], b[j]));
		}
	}
	
	return d0;
}

int main()
{
	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	
	sort(p, p + n, cmpx); // 按照x从小到大排序
	
	printf("%.2lf\n", min_dist(p, 0, n));
	
	return 0;
}