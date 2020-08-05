/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "pinv.h"
#include "xaxpy.h"

/* Function Definitions */
void b_xaxpy(int32_T n, real_T a, const real_T x[48], int32_T ix0, real_T y[8],
             int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    b = n - 1;
    for (k = 0; k <= b; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

void c_xaxpy(int32_T n, real_T a, const real_T x[8], int32_T ix0, real_T y[48],
             int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    b = n - 1;
    for (k = 0; k <= b; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

void d_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    b = n - 1;
    for (k = 0; k <= b; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[48], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T b;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    b = n - 1;
    for (k = 0; k <= b; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* End of code generation (xaxpy.c) */
