#include <iostream>
#include <ctime>
#include <cstdlib>


const int SIZE = 100;
const char C[] = {'a', 'b', 'c', 'd', 'e'};


void myrand(char m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            m[i][j] = C[rand() % 5];
        }
    }
}


// Compute the first (row, col) position such that
// this is the center of a cross of 5 index positions
// where the characters in array m at these have
// different distinct. For instance this is a cross
//                d
//               abc
//                e
// of distinct chracters. If the b is at row 5, column 2
// then the function should set parameter row to 5 and
// col to 2.

void f(char m[SIZE][SIZE], int & row, int & col)
{
    myrand(m);

    for (int i = 1; i < (SIZE - 1); i++)
    {
        for (int j = 1; j < (SIZE - 1); j++)
        {
            if (m[i - 1][j] != m[i][j] && m[i + 1][j] != m[i][j] && m[i][j - 1] != m[i][j] && m[i][j + 1] != m[i][j]

                &&

                m[i][j - 1] != m[i - 1][j] && m[i][j + 1] != m[i - 1][j] && m[i + 1][j] != m[i - 1][j]

                &&

                m[i + 1][j] != m[i][j - 1] && m[i][j + 1] != m[i][j - 1]

                &&

                m[i + 1][j] != m[i][j + 1])
            {
                row = i;
                col = j;
                return;
            }
        }
    }

    // Default if there is somehow no index with four distinct values surrounding it
    
    row = -1;
    col = -1;
}


int main()
{
    srand(0); // seed with another value for different test
    char m[SIZE][SIZE];
    int row, col;
    f(m, row, col);
    std::cout << row << ' ' << col << std::endl;
    
    return 0;
}
