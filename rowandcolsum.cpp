#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rowsum = 0, colsum = 0;
    int n = 3;

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        rowsum += mat[i][j];
        if (i == n)
        {
            break;
        }
        if (j == n - 1)
        {
            j = -1;
            i++;
        }
    }
    i = 0;
    for (int j = 0; j < n; j++)
    {
        colsum += mat[j][i];
        if (j == n - 1)
        {
            j = -1;
            i++;
            if (i == n)
            {
                break;
            }
        }
    }
    cout << "Row Sum: " << rowsum << endl
         << "Col Sum: " << colsum;
}