#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
ifstream fin("roy-floyd.in");
ofstream fout("roy-floyd.out");
int n, m, d[100][100];
const int Max = 0x3f3f3f3f;
static void RoyFloyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
int main() {
    FAST;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j)
                d[i][j] = Max;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        d[x - 1][y - 1] = cost;
    }
    RoyFloyd();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] != Max)
                fout << d[i][j] << " ";
            else
                fout << "-1 ";
        }
        fout << '\n';
    }
    return 0;
}
