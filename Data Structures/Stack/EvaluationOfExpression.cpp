// Evaluate Postfix expression
// Input:  2 3 1 * + 9 -
// Output: 1000000003
// Use Modular Division - 10^9+7

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll M = 1e9+7;

ll mod(ll a){
    return ((a%M) + M)%M;
}

ll add(ll a, ll b){
    return mod(mod(a) + mod(b));
}

ll sub(ll a, ll b){
    return mod(mod(a)-mod(b));
}

ll mul(ll a, ll b){
    return mod(mod(a)*mod(b));
}

ll bin(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1){
            res = mul(res, a);
        }
        a = mul(a, a);
        b>>=1;
    }
    return res;
}

ll divide(ll a, ll b){
    b = bin(b, M-2);
    return mul(a, b);
}

ll op(ll a, ll b, char c){
    if(c == '+'){
        return add(a, b);
    }
    else if(c == '-'){
        return sub(b, a);
    }
    else if(c == '*'){
        return mul(a, b);
    }    
    return divide(b, a);
}

int evaluatePostfix(string &exp) {
    stack<int> s;
    int n = exp.size();

    for(int i = 0; i < n; i++){
        if(isspace(exp[i])){
            continue;
        }
        if(isdigit(exp[i])){
            string temp = "";
            while(i < n && isdigit(exp[i])){
                temp+=exp[i];
                i++;
            }
            i--;
            ll number = stoll(temp);
            s.push(number);
        }
        else{
            char c = exp[i];
            ll num1 = s.top();
            s.pop();
            ll num2 = s.top();
            s.pop();
            ll ans = op(num1, num2, c);
            s.push(ans);
        }
    }
    return mod(s.top());
}


int main(){
    string s = "2 3 1 * + 9 -";
    cout<<evaluatePostfix(s);
}
