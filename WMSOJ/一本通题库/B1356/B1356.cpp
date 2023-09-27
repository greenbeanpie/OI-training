#include <bits/stdc++.h>
using namespace std;
string d;
int rules[128], n;
stack<int> num;
stack<char> ops;
void calc()
{
    int a, b;
    char op;
    b = num.top();
    num.pop();
    a = num.top();
    num.pop();
    op = ops.top();
    ops.pop();
    if (op == '^')
    {
        num.push(pow(a, b));
    }
    if (op == '+')
    {
        num.push(a + b);
    }
    if (op == '-')
    {
        num.push(a - b);
    }
    if (op == '*')
    {
        num.push(a * b);
    }
    if (op == '/')
    {
        num.push(a / b);
    }
}
int main()
{

    rules['+'] = 1;
    rules['-'] = 1;
    rules['*'] = 2;
    rules['/'] = 2;
    rules['^'] = 3;
    cin >> d;
    int s=0;
    for(int i=0;i<d.size();i++){
        if(s<0){
            cout << "NO";
            return 0;
        }
        if(d[i]=='('){
            if(d[i+1]>='0'&&d[i+1]<='9'){
                s++;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
        else if(d[i]==')'){
            if(d[i-1]>='0'&&d[i-1]<='9'){
                s++;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if(s!=0){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < d.size(); i++)
    {
        if (isdigit(d[i]))
        {
            int j, t;
            j = i;
            t = 0;
            while (j < n && isdigit(d[j]))
            {
                t = t * 10 + (d[j] - '0');
                j++;
            }

            i = j - 1;
            num.push(t);
        }
        else if (d[i] == ')')
        {
            while (ops.top() != '(')
                calc();
            ops.pop();
        }
        else if (d[i] == '(')
        {
            ops.push(d[i]);
        }
        else if (ops.size()!=0 && ops.top() != '(')
        {
            while (ops.size() && rules[(int)d[i]] <= rules[(int)ops.top()])
            {
                calc();
            }
            ops.push(d[i]);
        }
        else
        {
            ops.push(d[i]);
        }
    }
    while (ops.size())
    {
        calc();
    }
    cout << num.top();
    return 0;
}
