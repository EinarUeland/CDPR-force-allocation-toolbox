/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "sum.h"

/* Function Definitions */
void sum(const real_T x_data[], const int32_T x_size[2], real_T y_data[],
         int32_T y_size[2])
{
  int32_T npages;
  int32_T i;
  int32_T xpageoffset;
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    npages = x_size[1];
    y_size[0] = 1;
    y_size[1] = (int8_T)x_size[1];
    for (i = 0; i < npages; i++) {
      xpageoffset = i * 3;
      y_data[i] = x_data[xpageoffset];
      y_data[i] += x_data[xpageoffset + 1];
      y_data[i] += x_data[xpageoffset + 2];
    }
  }
}

/* End of code generation (sum.c) */
