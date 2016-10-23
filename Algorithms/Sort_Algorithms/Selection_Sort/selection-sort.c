#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int ar[n], i, j;
    for(i = 0 ; i < n ; i++)
        scanf("%d", ar+i);

    for(i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            if(ar[i] > ar[j]) {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }

    for(i = 0 ; i < n ; i++)
        printf("%d\n", ar[i]);
}
