#include <iostream>

int main()
{
    int m, n;
    std::cout << "Input column count >> ";
    std::cin >> m;
    std::cout << "Input row count >> ";
    std::cin >> n;
    float matrix[n][m];
    float counts[n * m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    float max = matrix[0][0];
    for (int i = 0; i < n; i++)
    {
        int c = 1;
        for (int j = 0; j < m; j++)
        {
            float elem = matrix[i][j];

            if (i == 0 && j == 0)
                continue;

            // for (int k = 0; k < n * m; k++)
            // {
            //     if (elem == counts[k])
            //     {
            //         counts[k]++;
            //         break;
            //     }
            // }
            if (elem > counts[c])
            {
                counts[c] = elem;
            }
        }
    }

    std::cout << max << std::endl;
}