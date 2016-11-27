#include <stdio.h>

int arr[1000000];

void swap(int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void quickSort(int l, int r) {
  if (l < r) {
    int v = arr[r];
    int i = l - 1, j = r;

    for (;;) {
      while (arr[++i] < v);
      while (arr[--j] > v);
      if (i >= j) break;
      swap(i, j);
    }

    swap(i, r);
    quickSort(l, i - 1);
    quickSort(i + 1, r);
  }
}

int main() {
  int sz;
  printf("enter the number of elements to input:\n");
  scanf("%d", &sz);

  printf("enter the elements:\n");
  for (int i = 0; i < sz; i++)
    scanf("%d", &arr[i]);

  printf("array before sorting:\n");
  for (int i = 0; i < sz; i++)
    printf("%d\n", arr[i]);

	quickSort(0, sz - 1);
  
  printf("array after sorting:\n");
  for(int i = 0; i < sz; i++)
    printf("%d\n", arr[i]);
}
