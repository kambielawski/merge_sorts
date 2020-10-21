import numpy as np
import math

def merge(left, right):
  i = 0
  j = 0
  merged = []

  while i < len(left) and j < len(right):
    if left[i] < right[j]:
      merged.append(left[i])
      i += 1
    else:
      merged.append(right[j])
      j += 1
  
  while i < len(left):
    merged.append(left[i])
    i += 1
  while j < len(right):
    merged.append(right[j])
    j += 1

  return merged

def mergesort(arr):
  if len(arr) < 2:
    return arr

  m = math.floor(len(arr)/2)
  left = arr[:m]
  right = arr[m:]

  return merge(mergesort(left), mergesort(right))


if __name__ == '__main__':
  print(mergesort([4,1,2,5,7,8,1,2,5,2]))
