/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Kernel_Methodis_mexutil.c
 *
 * Code generation for function 'Kernel_Methodis_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "Kernel_Methodis_mexutil.h"

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m10;
  y = NULL;
  m10 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m10);
  return y;
}

/* End of code generation (Kernel_Methodis_mexutil.c) */
