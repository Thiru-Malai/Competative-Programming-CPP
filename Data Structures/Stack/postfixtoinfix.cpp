#include <bits/stdc++.h>
using namespace std;

bool isOperator(char i)
{
    switch (i)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    }
    return false;
}

string infix(string exp)
{
    stack<string> s;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if(isOperator(exp[i])){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = ("(" + op2 + exp[i] + op1 + ")");
            s.push(temp);
        }
        else{
            s.push(string(1, exp[i]));
        }
    }
    return s.top();
}

int main()
{
    string exp = "ab*c+";
    cout << "Infix: " << infix(exp);
}