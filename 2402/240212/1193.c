#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int rc = 2, row = 1, col = 1;

    bool prev = false;
    bool end = true;

    int endcount = 2;

    for(int i=1; i<n; i++){
        if(endcount == rc){
            if(rc % 2 == 0)
                col++;
            else
                row++;

            rc++;
            endcount = 2;
        }
        else{
            if(rc % 2 == 0) {
                col++;
                row--;
            }
            else {
                row++;
                col--;
            }
            endcount++;
        }
    }

    printf("%d/%d", row, col);

    return 0;

}