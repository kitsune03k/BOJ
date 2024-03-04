#include <stdio.h>
#include <stdlib.h>

int compare(const void* i1, const void* i2){
    int ii1 = *(int*)i1;
    int ii2 = *(int*)i2;

    if(ii1 == ii2)
        return 0;
    else{
        if(ii1 > ii2)
            return 1;
        else
            return -1;
    }
}

int myround(long double ld){
    if(ld == 0)
        return 0;
    else{
        long double tmp = ld;

        if(ld > 0){
            while(tmp >= 1) // tmp가 0.0~0.9가 되면 탈출
                tmp -= (long double)1;

            if(tmp <= (long double)0.50)
                return (int)ld;
            else
                return (int)ld+1;
        }
        else{
            while(tmp <= -1) // tmp가 -0.99~-0.00이 되면 탈출
                tmp += 1;

            if(tmp <= (long double)-0.50) {
                return (int)ld - 1;
            }
            else
                return (int)ld;
        }
    }
}

unsigned int times[8001]; // 빈도, 최소 0

int mymode(){
    int maxtimes = 0; // 최대 빈도
    int maxidx = -1; // 최대빈도 위치
    int maxcount = 0;

    for(int i = 0; i < 8001; i++) {
        if(times[i] != 0) {
            if(times[i] > maxtimes) {
                maxtimes = times[i];
                maxidx = i;
                maxcount = 1;
            }
            else if(times[i] == maxtimes) {
                if(maxcount == 1) {
                    maxidx = i;
                }
                maxcount++;
            }
        }
    }

    return maxidx-4000;
}

int main(void){
    int N;

    scanf("%d", &N); // N은 홀수
    getchar();

    int arr[N];

    int sum = 0, min = 4001, max = -4001;
    int tmp;

    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        if(tmp < min)
            min = tmp;
        if(tmp > max)
            max = tmp;

        times[tmp+4000]++;

        arr[i] = tmp;
        sum += tmp;
    }

    long double tmpavg = (long double)sum/(long double)N;
    int avg = myround(tmpavg);
    printf("%d\n", avg); // 1. 산술평균

    qsort(arr, N, sizeof(int), compare);
    printf("%d\n", arr[N/2]); // 2. 중앙값

    printf("%d\n", mymode()); // 3. 최빈값

    printf("%d", max-min); // 4. 범위
}