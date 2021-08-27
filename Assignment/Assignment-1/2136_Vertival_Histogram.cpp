#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void printHistogram(int height, int alphaTable[]);

int main()
{
    string buff = "";
    int alphaTable[26] = {0};
    freopen("input.txt", "r", stdin);

    while (getline(cin, buff))
    {
        for (int i = 0; i < buff.size(); i++)
        {
            if (buff[i] < 'A' || buff[i] > 'Z')
                continue;

            alphaTable[buff[i] - 'A']++;
        }
    }

    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphaTable[i] > max)
            max = alphaTable[i];
    }

    printHistogram(max + 1, alphaTable);

    return 0;
}

void printHistogram(int height, int inputTable[])
{
    char outputTable[height][52];
    memset(outputTable, '\0', sizeof(char) * height * 51);

    char finalLine[52] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    strncpy(outputTable[height - 1], finalLine, 52);

    for (int i = height - 2; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (inputTable[j] != 0)
            {
                outputTable[i][2 * j] = '*';
                inputTable[j]--;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        bool whetherEmpty = true;
        for (int j = 50; j >= 0; j--)
        {
            if (i == height - 1)
                break;

            if (outputTable[i][j] != '\0')
                whetherEmpty = false;

            if (!whetherEmpty && outputTable[i][j] == '\0')
                outputTable[i][j] = ' ';
        }

        cout << outputTable[i] << endl;
    }
}
