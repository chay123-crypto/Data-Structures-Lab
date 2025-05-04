#include <iostream>
using namespace std;
const int MAX = 1000;
const int WORD_LEN = 4;

char words[3 * MAX][WORD_LEN];
char playerWords[3][MAX][WORD_LEN];
int freq[3 * MAX];

bool isequal(const char a[], const char b[])
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i] != b[i])
            return false;
        if (a[i] == '\0' || b[i] == '\0')
            break;
    }
    return true;
}
void copy(char dest[], const char src[])
{
    int i = 0;
    while (src[i] != '\0' && i < WORD_LEN - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int total = 3 * n;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> playerWords[i][j];
                copy(words[i * n + j], playerWords[i][j]);
            }
        }

        for (int i = 0; i < total; i++)
        {
            freq[i] = 0;
            for (int j = 0; j < total; j++)
            {
                if (isequal(words[i], words[j]))
                {
                    freq[i]++;
                }
            }
        }

        int score[3] = {0, 0, 0};

        // Calculate scores
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < total; k++)
                {
                    if (isequal(playerWords[i][j], words[k]))
                    {
                        if (freq[k] == 1)
                            score[i] += 3;
                        else if (freq[k] == 2)
                            score[i] += 1;
                        break;
                    }
                }
            }
        }

        cout << score[0] << " " << score[1] << " " << score[2] << endl;
    }

    return 0;
}
