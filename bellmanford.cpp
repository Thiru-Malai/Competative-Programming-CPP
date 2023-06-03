#include <bits/stdc++.h>
using namespace std;
int n;
int arr[4];

void findWeight(int i, int root, int n, int target, int prevWeight, int tempWeight, vector<vector<int>> vec)
{
    int weight = prevWeight;
    for (int j = 0; j < n; j++)
    {
        if (vec[i][j] != 0)
        {
            weight += vec[i][j];
            if (j == target)
            {
                if (arr[j] > weight)
                {
                    arr[j] = weight;
                }
                weight = tempWeight;
            }
            else if (j != root)
            {
                findWeight(j, root, n, target, weight, tempWeight, vec);
                weight = tempWeight;
            }
        }
    }
}

int main()
{

    int m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        vec[u][v] = w;
    }
    arr[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[0][i] != 0)
            arr[i] = vec[0][i];
        else
            arr[i] = 100;
    }

    int weight;

    for (int k = 1; k < n; k++)
    {
        for (int i = 1; i < n; i++)
        {
            if (vec[0][i] != 0)
            {
                weight = vec[0][i];
                findWeight(i, i, n, k, weight, weight, vec);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 100)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
}
