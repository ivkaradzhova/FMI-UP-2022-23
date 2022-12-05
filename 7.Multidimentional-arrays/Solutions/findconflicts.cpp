#include <iostream>
using namespace std;

bool hasConflicts(int matrix[][6], const int queens) {
   //rows
    for (int i = 0; i < queens; i++)
    {
        int counter = 0;
        for (int j = 0; j < queens; j++)
        {
            if (matrix[i][j] == 1) {
                counter++;
            }
        }
        if (counter > 1)
            return true;
    }

    //columns
    for (int i = 0; i < queens; i++)
    {
        int counter = 0;
        for (int j = 0; j < queens; j++)
        {
            if (matrix[j][i] == 1) {
                counter++;
            }
        }
        if (counter > 1)
            return true;
    }

    //int pDIndex = row - col + numberOfQueens - 1;

    //primary diagonals above the primary diagonal (including the primary diagonal)
    for (int k = 0; k < queens; k++)
    {
        int counter = 0;
        for (int j = k, i = 0; j < queens; j++, i++)
        {
            if (matrix[i][j] == 1) {
                counter++;
            }
        }
        if (counter > 1)
            return true;
    }

    //primary diagonals below the primary diagonal
    for (int k = 1; k < queens; k++)
    {
        int counter = 0;
        for (int i = k, j = 0; i < queens; i++, j++)
        {
            if (matrix[i][j] == 1) {
                counter++;
            }
        }
        if (counter > 1)
            return true;
    }

    //int sDIndex = row + col;

    //secondary diagonals above the secondary diagonal (including the secondary diagonal)
    for (int k = queens - 1; k >= 0; k--)
    {
        int counter = 0;
        for (int j = k, i = 0; j >= 0; j--, i++)
        {
            if (matrix[i][j] == 1) {
                counter++;
            }
        }
        if (counter > 1)
            return true;
    }

    //secondary diagonals below the secondary diagonal
    for (int k = queens - 1; k > 0; k--)
    {
        int counter = 0;
        for (int j = queens - 1, i = k; i < queens; j--, i++)
        {
            if (matrix[i][j] == 1) {
                counter++;
            }
        }
        if (counter > 1)
            return true;
    }

    return false;
}

int main()
{
    const int queens = 6;

    int matrix[queens][queens] = {
        {0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0}
    };

    //int matrix[queens][queens] = {
    //    {0, 0, 0, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 1},
    //    {0, 0, 0, 0, 1, 0},
    //    {0, 0, 0, 0, 0, 0}
    //};

    cout << hasConflicts(matrix, queens);
    return 0;
}
