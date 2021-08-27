#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

void sort_sets(int len, int n, char **sets, int (*measure)(char *set));
int measureDNASet(char *set);

int main()
{
    int n = 0;
    int len = 0;

    // freopen("input.txt", "r", stdin);
    cin >> len >> n;

    char **DNASets = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        DNASets[i] = (char *)malloc(sizeof(char) * (len + 1));
        cin >> DNASets[i];
    }

    sort_sets(len, n, DNASets, measureDNASet);

    for (int i = 0; i < n; i++)
    {
        cout << DNASets[i] << endl;
        free(DNASets[i]);
    }

    free(DNASets);

    return 0;
}

// TODO: Change selection sort to quick sort
void sort_sets(int len, int n, char **sets, int (*measure)(char *set))
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (measure(sets[j]) < measure(sets[min]))
                min = j;
        }

        if (min != i)
        {
            char *tmp = (char *)malloc(sizeof(char) * (len + 1));
            strncpy(tmp, sets[min], len);
            strncpy(sets[min], sets[i], len);
            strncpy(sets[i], tmp, len);
            free(tmp);
        }
    }
}

int measureDNASet(char *set)
{
    int measure = 0;

    while (*set != '\0')
    {
        char *ptr = (set + 1);
        while (*ptr != '\0')
        {
            if (*set > *ptr)
                measure++;

            ptr++;
        }
        set++;
    }

    return measure;
}