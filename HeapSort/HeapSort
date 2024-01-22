#ifndef HEAP
#define HEAP

template <class T>
void Swap(T* a, T* b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

int LeftChild(int i) {
  return 2 * i + 1;
}
int RightChild(int i) {
  return 2 * i + 2;
}

template <class T>
void SiftDown(T* begin, T* end, T* i) {
  if (i < begin) {
    return;
  }
  T* largest = i;
  int left = LeftChild(i - begin);
  int right = RightChild(i - begin);
  int size = end - begin;
  if (left < size && (*largest < begin[left])) {
    largest = begin + left;
  }
  if (right < size && (*largest < begin[right])) {
    largest = begin + right;
  }
  if (largest != i) {
    Swap(largest, i);
    SiftDown(begin, end, largest);
  }
}

template <class T>
void MakeHeap(T* begin, T* end) {
  int size = end - begin;
  for (int i = size / 2; i > 0; --i) {
    SiftDown(begin, end, begin + i - 1);
  }
}

template <class T>
void SortHeap(T* begin, T* end) {
  int size = end - begin;
  for (int i = size - 1; i > 0; --i) {
    Swap(begin, begin + i);
    --size;
    SiftDown(begin, begin + size, begin);
  }
}

#endif
