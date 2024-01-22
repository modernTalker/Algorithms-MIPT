#ifndef KTH
#define KTH
template <class T>
T* Partition(T* begin, T* end) {
  T* pivot = begin;
  for (auto i = begin + 1; i < end; ++i) {
    if (*i < *begin) {
      ++pivot;
      T tmp1 = *i;
      *i = *pivot;
      *pivot = tmp1;
    }
  }
  T tmp2 = *pivot;
  *pivot = *begin;
  *begin = tmp2;
  return pivot;
}

template <class T>
void KthElement(T* begin, T* position, T* end) {
  if (end < begin) {
    return;
  }
  T* value = Partition(begin, end);
  if (value < position) {
    KthElement(value + 1, position, end);
  }
  if (position < value) {
    KthElement(begin, position, value + 1);
  }
}
#endif
