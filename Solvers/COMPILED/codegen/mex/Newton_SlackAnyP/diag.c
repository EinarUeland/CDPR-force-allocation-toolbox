/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Newton_SlackAnyP.h"
#include "diag.h"

/* Function Definitions */
void diag(const real_T v[7], real_T d[49])
{
  int32_T j;
  memset(&d[0], 0, 49U * sizeof(real_T));
  for (j = 0; j < 7; j++) {
    d[j + 7 * j] = v[j];
  }
}

/* End of code generation (diag.c) */
