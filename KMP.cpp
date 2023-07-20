// KMP ALGORITHM
// Frequency Of Substring In A String

#include <iostream>
using namespace std;

void compareLPS(string sub, int m, int lps[]){
    lps[0] = 0;
    int i = 1, len = 0;
    while(i < m){
        if(sub[i] == sub[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = len;
                i++;
            }
        }
    }
}

int main() {
    string parent = "timtimtim";
    string sub = "timtimt";
    
    
    int n = parent.size();
    int m = sub.size();
    int lps[m];
    
    compareLPS(sub, m, lps);
    
    
    int j = 0;
    int i = 0;
    int res = 0;
    
    while(i < n){
        if(sub[j] == parent[i]){
            j++;
            i++;
        }
        if(j == m){
            j = lps[j-1];
            res++;
        }
        else if(i < n && sub[j] != parent[i]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i+=1;
            }
        }
    }

    cout << res;

    return 0;
}
