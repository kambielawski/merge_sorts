#include <stdio.h>

void swap (int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

void merge (int arr[], unsigned int l, unsigned int mid, unsigned int r) {
  unsigned int leftsize = mid-l+1;
  unsigned int rightsize = r - mid;

  int left[leftsize];
  int right[rightsize];

  unsigned int i, j, k;

  for (i = 0; i < leftsize; i++)
    left[i] = arr[l+i];
  for (j = 0; j < rightsize; j++)
    right[j] = arr[mid+j+1];

  i = 0, j = 0;
  k = l;

  while (i < leftsize && j < rightsize) {
    if (left[i] < right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < leftsize) {
    arr[k] = left[i];
    i++; k++;
  }
  
  while (j < rightsize) {
    arr[k] = right[j];
    j++; k++;
  }
}

void mergeSort(int arr[], unsigned int l, unsigned int r) {
  
  // base case
  if (l < r) {
    unsigned int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid, r);
  }
}

int main() {
  const int size = 10;
  int unsorted[size] = { 3,5,7,4,5,9,10,11,1,19 };
  mergeSort(unsorted, 0, size-1);
  printArr(unsorted, size);
  return 0;
}
