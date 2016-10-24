#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, int beg1, int half, int beg2){
    int szL, szR;
    szL = half-beg1+1;
    szR = beg2-half;
    //create auxiliar arrays;
    int left[szL], right[szR];
    for (int i = 0; i < szL; i++)
        left[i] = v[beg1 + i];
    for (int i = 0; i < szR; i++)
        right[i] = v[half + 1 + i];
    //merge aux into v
    int i= 0, j= 0, k= beg1;
    while (i<szL && j<szR)
        v[k++] = (left[i]<right[j])?left[i++]:right[j++];
    while (i < szL)
        v[k++] = left[i++];
    while (j < szR)
        v[k++] = right[j++];
}

void mergeSort(vector<int>& v, int l, int r){
    if (l >= r)
        return;
    int half = l+(r-l)/2;
    mergeSort(v, l, half);
    mergeSort(v, half+1, r);

    merge(v, l, half, r);
}
