#include "smallMath.h"

double min(double lhs, double rhs) {
  if (rhs < lhs) {
    return rhs;
  }
  return lhs;
}

double max(double lhs, double rhs) {
  if (lhs < rhs) {
    return rhs;
  }
  return lhs;
}
