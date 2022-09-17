#include <stdio.h>
int main()
{
    int t, n, i = 0;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        int c = 0;
        int a=0;
        if (n == 1)
        {
            printf("---1\n");
        }
        else if (n == 2)
        {
            printf("---1\n");
        }
        else
        {
            for (i = 1; i <= n; i++)
            {
                if (i & i + 1)
                {
                    ++c;
                    if (a <= c)
                    {
                        a = c;
                    }
                }
                else
                    c = 0;
            }
            printf("----%d\n", a + 1);
        }
    }
}