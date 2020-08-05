/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_SlackAnyP.h"
#include "power.h"
#include "Newton_SlackAnyP_data.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 64,  /* lineNo */
  "fltpower",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 65,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 188, /* lineNo */
  "flatIter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 124, /* lineNo */
  "scalar_float_power",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 12,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* Function Definitions */
void b_power(const emlrtStack *sp, const real_T a[3], real_T y[3])
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  d_st.site = &m_emlrtRSI;
  e_st.site = &n_emlrtRSI;
  if (a[0] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&e_st, &b_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  y[0] = muDoubleScalarSqrt(a[0]);
  d_st.site = &m_emlrtRSI;
  e_st.site = &n_emlrtRSI;
  if (a[1] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&e_st, &b_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  y[1] = muDoubleScalarSqrt(a[1]);
  d_st.site = &m_emlrtRSI;
  e_st.site = &n_emlrtRSI;
  if (a[2] < 0.0) {
    emlrtErrorWithMessageIdR2018a(&e_st, &b_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  y[2] = muDoubleScalarSqrt(a[2]);
}

void c_power(const emlrtStack *sp, const real_T a[4], real_T b, real_T y[4])
{
  boolean_T p;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  y[0] = muDoubleScalarPower(a[0], b);
  y[1] = muDoubleScalarPower(a[1], b);
  y[2] = muDoubleScalarPower(a[2], b);
  y[3] = muDoubleScalarPower(a[3], b);
  if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
    p = (a[0] < 0.0);
    if (p || (a[1] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    if (p || (a[2] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    if (p || (a[3] < 0.0)) {
      p = true;
    } else {
      p = false;
    }
  } else {
    p = false;
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }
}

void d_power(const real_T a[4], real_T y[4])
{
  y[0] = a[0] * a[0];
  y[1] = a[1] * a[1];
  y[2] = a[2] * a[2];
  y[3] = a[3] * a[3];
}

void power(const real_T a[3], real_T y[3])
{
  y[0] = a[0] * a[0];
  y[1] = a[1] * a[1];
  y[2] = a[2] * a[2];
}

/* End of code generation (power.c) */
