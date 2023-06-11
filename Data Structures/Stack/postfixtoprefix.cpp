#include <bits/stdc++.h>
using namespace std;

bool isOperator(char i)
{
    switch (i)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string prefix(string exp)
{

    stack<string> s;

    for (int i = 0; i < (int)exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = exp[i] + op2 + op1;
            s.push(temp);
        }
        else
        {
            s.push(string(1, exp[i]));
        }
    }
    return s.top();
}

int main()
{
    string exp = "ABC/-AK/L-*";
    cout << "Prefix: " << prefix(exp);
}