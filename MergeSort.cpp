#ifndef SORT
#define SORT
template <class T>
bool Equal(const T& a, const T& b) {
  return (!(a < b)) && (!(b < a));
}

template <class T, class K, class P>
void Merge(const T* fleft, const T* fright, const K* sleft, const K* sright, P* out) {
  const T* ia = fleft;
  const K* ib = sleft;
  while ((ia < fright) && (ib < sright)) {
    if (*ia < *ib) {
      *out = *ia;
      ++ia;
    } else {
      *out = *ib;
      ++ib;
    }
    ++out;
  }
  while (ia < fright) {
    *out = *ia;
    ++ia;
    ++out;
  }
  while (ib < sright) {
    *out = *ib;
    ++ib;
    ++out;
  }
}

template <class T>
void MergeSort(const T* left, const T* right, T* out) {
  if ((right < left + 1) || (Equal(right, (left + 1)))) {
    auto x = ((right - left) / 2);
    Merge(left, left + x + (right - left) % 2, left + x + (right - left) % 2, right, out);
    return;
  }
  auto n1 = ((right - left) / 2) + (right - left) % 2;
  auto out1 = new T[n1];
  MergeSort(left, left + n1, out1);
  auto n2 = ((right - left) / 2);
  auto out2 = new T[n2];
  MergeSort(left + n1, right, out2);
  Merge(out1, out1 + n1, out2, out2 + n2, out);
  delete[] out1;
  delete[] out2;
}

template <class T>
void Sort(T* left, T* right) {
  int n = right - left;
  auto out = new T[n];
  MergeSort(left, right, out);
  for (int i = 0; i < n; ++i) {
    left[i] = out[i];
  }
  delete[] out;
}
#endif
