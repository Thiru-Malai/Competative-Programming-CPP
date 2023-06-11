#include <bits/stdc++.h>
using namespace std;

bool isOperator(char i){
    switch(i){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}


string preToPost(string exp){
    
    stack<string> s;
    for(int i = exp.size()-1; i >= 0; i--){
        if(isOperator(exp[i])){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string c = op1 + op2 + exp[i];
            s.push(c);
        }
        else{
            s.push(string(1, exp[i]));
        }
    }
    return s.top();
}

int main()
{
    string exp = "*-A/BC-/AKL";
    cout << "Postfix: " << preToPost(exp);
}