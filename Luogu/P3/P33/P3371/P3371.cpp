#include <bits/stdc++.h>
using namespace std;
#define int long long
template <typename T>
class SegTree{
    vector<T> tree,lazy;
    int n,root,n4,end;
    void maintain(int cl,int cr,int p){//cl:current left(当前的左范围)
        int cmid=cl+(cr-cl)/2;
        if(cl!=cr&&lazy[p]){
            lazy[p*2]+=lazy[p];//更新下左节点的懒惰标记
            lazy[p*2+1]+=lazy[p];//更新下右节点的懒惰标记
            tree[p*2]+=lazy[p]*(cm-cl+1);//更新下左节点的和
            tree[p*2+1]+=lazy[p]*(cr-cm);//更新下右节点的和
            lazy[p]=0;//更新懒惰标记
        }
    }
    T range_sum(int l,int r,int cl,int cr,int p){
        if(l<=cl&&cl<=r){// 如果当前范围在查询范围内可以直接返回不用去掉左边和右边
            return tree[p];
        }
        int m=
    }
}