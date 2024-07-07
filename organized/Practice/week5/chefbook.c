#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
    int ind;
    int pri;
    char post[100];

} node;

int compare(const void *a, const void *b)
{
    node *orderA = (node *)a;
    node *orderB = (node *)b;

    return (orderB->pri - orderA->pri);
}
node a[100001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int d[100001];
    int pos;
    //  char s[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pos); // taking id of special friends
        d[pos] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %s", &a[i].ind, &a[i].pri, a[i].post);
    }
    qsort(a, m, sizeof(node), compare);

    for (int i = 0; i < m; i++)
    {
        if (d[a[i].ind])
        {
            printf("%s\n", a[i].post);
            //      cout<<a[i].post<<endl;                //print special id
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!d[a[i].ind])
        {
            printf("%s\n", a[i].post);
            //      cout<<a[i].post<<endl;              //print non-special id
        }
    }
    return 0;
}