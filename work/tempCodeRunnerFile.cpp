#include <iostream>
#include <fstream>
#include <ctime>
#include <new>
using namespace std;

int** generateMat()
{
    srand(time(0));

    int** randMat = new (nothrow) int*[10];
    for (int i = 0; i < 10; i++)
    {
        int cols = rand() % 100 + 1;
        int* randArr = new (nothrow) int[cols];
        randMat[i] = randArr;

        for (int j = 0; j < cols; j++)
        {
            randMat[i][j] = rand() % 200 + 1;
        }
    }
    return randMat;
}

void printMat(int** mat)
{
    for (int i = 0; i < 10; i++)
    {
        int cols = mat[i][0]; // Store the size of each array at the beginning
        for (int j = 1; j <= cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void freeMat(int** mat)
{
    for (int i = 0; i < 10; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    int** matrix = generateMat();
    printMat(matrix);
    freeMat(matrix);

    return 0;
}
