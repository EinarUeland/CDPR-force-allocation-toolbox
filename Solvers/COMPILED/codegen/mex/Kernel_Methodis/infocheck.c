/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * infocheck.c
 *
 * Code generation for function 'infocheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "infocheck.h"
#include "Kernel_Methodis_data.h"
#include "lapacke.h"

/* Function Definitions */
boolean_T infocheck(const emlrtStack *sp, int32_T info)
{
  boolean_T p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 's', 'v', 'd' };

  if (info < 0) {
    if (info == -1010) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI, "MATLAB:nomem",
        "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
        "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo",
        5, 4, 14, fname, 12, info);
    }
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (infocheck.c) */
