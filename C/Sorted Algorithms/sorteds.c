#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}

void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(void) {
   int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arrCopy[n];

    printf("Original array: \n");
    printArray(arr, n);

    copyArray(arr, arrCopy, n);
    insertionSort(arrCopy, n);
    printf("Array after Insertion Sort: \n");
    printArray(arrCopy, n);

    copyArray(arr, arrCopy, n);
    selectionSort(arrCopy, n);
    printf("Array after Selection Sort: \n");
    printArray(arrCopy, n);

    copyArray(arr, arrCopy, n);
    mergeSort(arrCopy, 0, n - 1);
    printf("Array after Merge Sort: \n");
    printArray(arrCopy, n);

    copyArray(arr, arrCopy, n);
    bubbleSort(arrCopy, n);
    printf("Array after Bubble Sort: \n");
    printArray(arrCopy, n);

    return 0;
}
