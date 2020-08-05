/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "repmat.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 27,  /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 46,    /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 55,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static const char_T cv0[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
  'x', 's', 'i', 'z', 'e' };

static emlrtRSInfo v_emlrtRSI = { 46,  /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void b_repmat(const emlrtStack *sp, const real_T a_data[], const int32_T a_size
              [2], real_T varargin_1, real_T b_data[], int32_T b_size[2])
{
  int32_T i3;
  int32_T ncols;
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 1, 15 };

  const mxArray *m2;
  static const int32_T iv2[2] = { 1, 15 };

  int32_T jcol;
  int32_T ibmat;
  int32_T itilerow;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &k_emlrtRSI;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  i3 = (int32_T)varargin_1;
  ncols = (int8_T)i3;
  if (ncols != i3) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(sp, 15, m1, &cv0[0]);
    emlrtAssign(&y, m1);
    st.site = &v_emlrtRSI;
    error(&st, y, &emlrtMCI);
  }

  if ((int8_T)a_size[1] != a_size[1]) {
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(sp, 15, m2, &cv0[0]);
    emlrtAssign(&y, m2);
    st.site = &v_emlrtRSI;
    error(&st, y, &emlrtMCI);
  }

  b_size[0] = ncols;
  b_size[1] = (int8_T)a_size[1];
  ncols = a_size[1];
  for (jcol = 0; jcol < ncols; jcol++) {
    ibmat = jcol * i3;
    for (itilerow = 0; itilerow < i3; itilerow++) {
      b_data[ibmat + itilerow] = a_data[jcol];
    }
  }
}

void repmat(const emlrtStack *sp, const real_T a[3], real_T varargin_2, real_T
            b_data[], int32_T b_size[2])
{
  int32_T i2;
  int32_T jtilecol;
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 15 };

  int32_T ibtile;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &k_emlrtRSI;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  i2 = (int32_T)varargin_2;
  jtilecol = (int8_T)i2;
  if (jtilecol != i2) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(sp, 15, m0, &cv0[0]);
    emlrtAssign(&y, m0);
    st.site = &v_emlrtRSI;
    error(&st, y, &emlrtMCI);
  }

  b_size[0] = 3;
  b_size[1] = jtilecol;
  for (jtilecol = 0; jtilecol < i2; jtilecol++) {
    ibtile = jtilecol * 3;
    b_data[ibtile] = a[0];
    b_data[ibtile + 1] = a[1];
    b_data[ibtile + 2] = a[2];
  }
}

/* End of code generation (repmat.c) */
