// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.

#include <iostream>

using namespace std;

void zeroMatrix(int x[], int r, int c)
{
    if (r == 1 || c == 1)
        return;

    bool isFirstColZero = false;
    for (int i = 0; i < r; i++)
        if (x[i * c] == 0)
            isFirstColZero = true;

    bool isFirstRowZero = false;
    for (int j = 0; j < c; j++)
        if (x[j] == 0)
            isFirstRowZero = true;

    if (x[0] == 0)
    {
        isFirstColZero = true;
        isFirstRowZero = true;
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (x[i * c + j] == 0)
            {
                x[j] = 0;
                x[i * c] = 0;
            }
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (x[i * c] == 0 || x[j] == 0)
            {
                x[i * c + j] = 0;
            }
        }
    }

    if (isFirstColZero)
        for (int i = 0; i < r; i++)
            x[i * c] = 0;

    if (isFirstRowZero)
        for (int j = 0; j < c; j++)
            x[j] = 0;
}

int main(void)
{
    int x[10][20];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            x[i][j] = (i + 1) * 10 + (j + 1);
        }

        cout << endl;
    }

    x[0][3] = 0;
    x[2][2] = 0;
    x[8][6] = 0;
    x[9][8] = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << x[i][j] << " ";
        }

        cout << endl;
    }

    cout << "----------" << endl;

    zeroMatrix(&x[0][0], 10, 20);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << x[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}