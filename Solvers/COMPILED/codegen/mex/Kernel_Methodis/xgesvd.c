/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgesvd.c
 *
 * Code generation for function 'xgesvd'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "xgesvd.h"
#include "infocheck.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 193,/* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

/* Function Definitions */
void ceval_xgesvd(const emlrtStack *sp, real_T A_data[], int32_T A_size[2],
                  real_T U_data[], int32_T U_size[2], real_T S_data[], int32_T
                  S_size[1], real_T V_data[], int32_T V_size[2], int32_T *info)
{
  int32_T minnm;
  int32_T i3;
  int32_T loop_ub;
  int32_T i4;
  real_T Vt_data[576];
  ptrdiff_t info_t;
  real_T superb_data[5];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  minnm = muIntScalarMin_sint32(A_size[1], A_size[0]);
  U_size[0] = A_size[0];
  U_size[1] = minnm;
  S_size[0] = minnm;
  if ((A_size[0] != 0) && (A_size[1] != 0)) {
    info_t = LAPACKE_dgesvd(102, 'S', 'A', (ptrdiff_t)A_size[0], (ptrdiff_t)
      A_size[1], &A_data[0], (ptrdiff_t)A_size[0], &S_data[0], &U_data[0],
      (ptrdiff_t)A_size[0], &Vt_data[0], (ptrdiff_t)A_size[1], &superb_data[0]);
    *info = (int32_T)info_t;
  } else {
    *info = 0;
  }

  V_size[0] = A_size[1];
  V_size[1] = A_size[1];
  minnm = A_size[1];
  for (i3 = 0; i3 < minnm; i3++) {
    loop_ub = A_size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      V_data[i4 + V_size[0] * i3] = Vt_data[i3 + A_size[1] * i4];
    }
  }

  st.site = &ob_emlrtRSI;
  infocheck(&st, *info);
}

/* End of code generation (xgesvd.c) */
