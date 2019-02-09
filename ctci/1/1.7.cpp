// Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include <iostream>

using namespace std;

// rotates clockwise 90 degrees
void rotateMatrix(int *x, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - 2 * i - 1; j++)
        {
            // cout << n - j << "," << i << " to " << i << "," << j << endl;
            // cout << n - i - 1 << "," << n - j << " to " << n - j << "," << i << endl;
            // cout << j << "," << i << " to " << n - i << "," << n - j << endl;
            // cout << i << "," << j << " to " << j << "," << i << endl;

            int temp = x[i * n + j];
            x[i * n + j] = x[(n - j - 1) * n + i];
            x[(n - j - 1) * n + i] = x[(n - i - 1) * n + (n - j - 1)];
            x[(n - i - 1) * n + (n - j - 1)] = x[j * n + i];
            x[j * n + (n - i - 1)] = temp;
        }
    }
}

int main(void)
{
    int x[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            x[i][j] = (i + 1) * 10 + (j + 1);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << x[i][j] << " ";
        }

        cout << endl;
    }

    cout << "----------" << endl;

    rotateMatrix(&x[0][0], 10);

    // cout << "----------" << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << x[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}