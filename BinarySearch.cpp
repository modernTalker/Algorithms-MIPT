#ifndef BOUND
#define BOUND
template <class T>
bool Equal(const T& a, const T& b) {
  return (!(a < b)) && (!(b < a));
}

template <class T>
bool BinarySearch(const T* array, const T* end, const T& value) {
  const T* left = array;
  const T* right = end - 1;

  while (0 < right - left) {
    auto middle = left + (right - left) / 2;

    if (*(middle) < value) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }
  return (!Equal(left, end)) && (Equal(*(left), value));
}

template <class T>
const T* LowerBound(const T* arr, const T* end, const T& value) {
  const T* left = arr;
  const T* right = end - 1;
  while (0 < right - left) {
    auto middle = left + (right - left) / 2;

    if (*(middle) < value) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }
  if ((left < end) && (*left < value)) {
    ++left;
  }
  return left;
}

template <class T>
const T* UpperBound(const T* arr, const T* end, const T& value) {
  const T* left = arr;
  const T* right = end - 1;
  while (0 < right - left) {
    auto middle = left + (right - left) / 2;
    if (*middle < value) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }
  while ((left < end) && ((*left < value) || (Equal(*left, value)))) {
    ++left;
  }
  return left;
}

#endif
