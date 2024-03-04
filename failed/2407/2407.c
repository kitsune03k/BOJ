#include <stdio.h>

int bunmo[101];
int bunja[101];
int ret[101];

void prime(int n, int r)
{
    int nr = n-r;

    for(int i=1; i<=n; i++)
        bunmo[i]++;
    for(int i=1; i<=r; i++)
        bunja[i]++;
    for(int i=1; i<=nr; i++)
        bunja[i]++;
    for(int i=1; i<=n; i++)
        ret[i] = bunmo[i]-bunja[i];
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    prime(n,m);



}