//https://www.acmicpc.net/problem/2580

#include <iostream>

using namespace std;

int arr[9][9];
bool fix[9][9];

bool check(int i, int j)
{
    bool nums1[10] = {false, };
    bool nums2[10] = {false, };
    bool nums3[10] = {false, };
    
    for (int k = 0; k < 9; k++)
    {
        if (nums1[arr[i][k]] == true)
            return false;
        else if (arr[i][k] != 0)
            nums1[arr[i][k]] = true;
    }
    
    for (int k = 0; k < 9; k++)
    {
        if (nums2[arr[k][j]] == true)
            return false;
        else if (arr[k][j] != 0)
            nums2[arr[k][j]] = true;
    }
    
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if (nums3[arr[(i / 3) * 3 + k][(j / 3) * 3 + l]] == true)
                return false;
            else if (arr[(i / 3) * 3 + k][(j / 3) * 3 + l] != 0)
                nums3[arr[(i / 3) * 3 + k][(j / 3) * 3 + l]] = true;
        }
    }
    
    return true;
}

void solve(int i, int j)
{
    if (i == 9)
    {
        for (int k = 0; k < 9; k++)
        {
            for (int l = 0; l < 9; l++)
            {
                cout << arr[k][l];
                if (l != 8)
                    cout << " ";
            }
            cout << endl;
        }
        exit(0);
    }
    
    if (arr[i][j] == 0)
    {
        for (int k = 1; k <= 9; k++)
        {
            arr[i][j] = k;
            if (check(i, j))
            {
                if (j == 8)
                {
                    solve(i + 1, 0);
                }
                else
                {
                    solve(i, j + 1);
                }
            }
            if (fix[i][j] == false)
            {
                arr[i][j] = 0;
            }
        }
    }
    else if (j == 8)
    {
        solve(i + 1, 0);
    }
    else
    {
        solve(i, j + 1);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
                fix[i][j] = true;
        }
    }
    
    solve(0, 0);
    
    return (0);
}

