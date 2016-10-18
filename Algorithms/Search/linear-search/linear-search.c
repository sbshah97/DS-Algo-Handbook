#include <stdio.h>

int main() {

    int n, i, key;
    scanf("%d",&n);

    int a[n];
    for(i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);
    scanf("%d",&key);

    // Find position of the key in array a
    for(i = 0 ; i < n ; i ++)
        if( a[i] == key)
            printf("Key found at position %d \n",i + 1);

    return 0;
}