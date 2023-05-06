#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> num;
template <typename T>
class SegTree
{
    vector<T> tree, lazy;
    /// @brief
    vector<T> *arr;
    int n, root=1, n4, end;
    void maintain(int cl, int cr, int p)
    { // cl:current left(当前的左范围)
        int cmid = cl + (cr - cl) / 2;
        if (cl >= cr && lazy[p])
        {
            lazy[p * 2] += lazy[p];                   // 更新下左节点的懒惰标记
            lazy[p * 2 + 1] += lazy[p];               // 更新下右节点的懒惰标记
            tree[p * 2] += lazy[p] * (cmid - cl + 1); // 更新下左节点的和
            tree[p * 2 + 1] += lazy[p] * (cr - cmid); // 更新下右节点的和
            lazy[p] = 0;                              // 更新当前点懒惰标记
        }
    }
    T range_sum(int l, int r, int cl, int cr, int p)
    {
        if (l <= cl && cl <= r)
        { // 如果当前范围在查询范围内可以直接返回不用去掉左边和右边
            return tree[p];
        }
        int mid = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p);
        if (l <= mid)
        {
            sum += range_sum(l, r, cl, mid, p * 2);
        }
        if (r > mid)
        {
            sum += range_sum(l, r, mid + 1, cr, p * 2 + 1);
        }
        return sum;
    }
    void range_add(int l, int r, T val, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
        {
            tree[p] += (cr - cl + 1) * val;
            lazy[p] += val;
            return;
        }
        int mid = cl + (cr - cl) / 2;
        maintain(l, r, p);
        if (l <= mid)
        {
            range_add(l, r, val, cl, mid, p * 2);
        }
        if (r > mid)
        {
            range_add(l, r, val, mid + 1, cr, p * 2 + 1);
        }
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
    void build(int l, int r, int p)
    {
        if (l == r)
        {
            tree[p] = (*arr)[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
        end=max(end,p*2+1);
    }

public:
    T range_sum(int l, int r)
    {
        return range_sum(l, r, 0, end, root);
    }
    void range_add(int l, int r, int val)
    {
        range_add(l, r, val, 0, end, root);
    }
};

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P3372.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        num.push_back(t);
    }
    SegTree<int> ST;
    ST.build(1,n,1);
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            ST.range_add(x, y, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << ST.range_sum(x, y) << endl;
        }
    }
    return 0;
}