/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cross.c
 *
 * Code generation for function 'cross'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "cross.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 67,  /* lineNo */
  "cross",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\specfun\\cross.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 69,  /* lineNo */
  "cross",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\specfun\\cross.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 36,/* lineNo */
  19,                                  /* colNo */
  "cross",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\specfun\\cross.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 46,/* lineNo */
  23,                                  /* colNo */
  "cross",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\specfun\\cross.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 49,/* lineNo */
  19,                                  /* colNo */
  "cross",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\specfun\\cross.m"/* pName */
};

/* Function Definitions */
void cross(const emlrtStack *sp, const real_T a_data[], const int32_T a_size[2],
           const real_T b_data[], const int32_T b_size[2], real_T c_data[],
           int32_T c_size[2])
{
  int8_T varargin_1[2];
  int8_T varargin_2[2];
  boolean_T overflow;
  boolean_T p;
  int32_T nHigh;
  boolean_T exitg1;
  int32_T dim;
  int32_T stride;
  int32_T stridem1;
  int32_T iNext;
  int32_T iEnd;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  real_T c_data_tmp;
  real_T b_c_data_tmp;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1[0] = (int8_T)a_size[0];
  varargin_2[0] = (int8_T)b_size[0];
  varargin_1[1] = (int8_T)a_size[1];
  varargin_2[1] = (int8_T)b_size[1];
  overflow = false;
  p = true;
  nHigh = 0;
  exitg1 = false;
  while ((!exitg1) && (nHigh < 2)) {
    if (varargin_1[nHigh] != varargin_2[nHigh]) {
      p = false;
      exitg1 = true;
    } else {
      nHigh++;
    }
  }

  if (p) {
    overflow = true;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(sp, &j_emlrtRTEI,
      "MATLAB:cross:InputSizeMismatch", "MATLAB:cross:InputSizeMismatch", 0);
  }

  c_size[0] = 3;
  c_size[1] = (int8_T)a_size[1];
  if (a_size[1] != 0) {
    dim = 0;
    nHigh = 0;
    exitg1 = false;
    while ((!exitg1) && (nHigh < 2)) {
      if (a_size[nHigh] == 3) {
        dim = nHigh + 1;
        exitg1 = true;
      } else {
        nHigh++;
      }
    }

    if (dim < 1) {
      emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
        "MATLAB:cross:InvalidDimAorB", "MATLAB:cross:InvalidDimAorB", 0);
    }

    if ((a_size[1] == 1) && (b_size[1] == 1)) {
      varargin_1[0] = (int8_T)a_size[0];
      varargin_2[0] = (int8_T)b_size[0];
      varargin_1[1] = (int8_T)a_size[1];
      varargin_2[1] = (int8_T)b_size[1];
      overflow = false;
      p = true;
      nHigh = 0;
      exitg1 = false;
      while ((!exitg1) && (nHigh < 2)) {
        if (varargin_1[nHigh] != varargin_2[nHigh]) {
          p = false;
          exitg1 = true;
        } else {
          nHigh++;
        }
      }

      if (p) {
        overflow = true;
      }

      if (overflow) {
      } else {
        emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI,
          "Coder:toolbox:variableSizeMatrixToVector",
          "Coder:toolbox:variableSizeMatrixToVector", 0);
      }
    }

    if (dim >= 2) {
      stride = 3;
      stridem1 = 2;
    } else {
      stride = 1;
      stridem1 = 0;
    }

    iNext = stride * 3;
    if (dim >= 2) {
      nHigh = 1;
    } else {
      nHigh = 1 + iNext * (a_size[1] - 1);
    }

    st.site = &q_emlrtRSI;
    overflow = ((1 <= nHigh) && (nHigh > MAX_int32_T - iNext));
    if (overflow) {
      b_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (dim = 1; iNext < 0 ? dim >= nHigh : dim <= nHigh; dim += iNext) {
      iEnd = dim + stridem1;
      st.site = &r_emlrtRSI;
      if ((dim <= iEnd) && (iEnd > 2147483646)) {
        b_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i1 = dim; i1 <= iEnd; i1++) {
        i2 = (i1 + stride) - 1;
        i3 = i2 + stride;
        c_data[i1 - 1] = a_data[i2] * b_data[i3] - a_data[i3] * b_data[i2];
        c_data_tmp = a_data[i1 - 1];
        b_c_data_tmp = b_data[i1 - 1];
        c_data[i2] = a_data[i3] * b_c_data_tmp - c_data_tmp * b_data[i3];
        c_data[i3] = c_data_tmp * b_data[i2] - a_data[i2] * b_c_data_tmp;
      }
    }
  }
}

/* End of code generation (cross.c) */
