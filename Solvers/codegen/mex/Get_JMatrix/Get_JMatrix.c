/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Get_JMatrix.c
 *
 * Code generation for function 'Get_JMatrix'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "cross.h"
#include "rdivide_helper.h"
#include "repmat.h"
#include "power.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "Get_JMatrix",                       /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 7,   /* lineNo */
  "Get_JMatrix",                       /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 9,   /* lineNo */
  "Get_JMatrix",                       /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 10,  /* lineNo */
  "Get_JMatrix",                       /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 54,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 23,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 26,  /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 101, /* lineNo */
  "cat_impl",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  17,                                  /* colNo */
  "Eta",                               /* aName */
  "Get_JMatrix",                       /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  7,                                   /* lineNo */
  6,                                   /* colNo */
  "Get_JMatrix",                       /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  9,                                   /* lineNo */
  4,                                   /* colNo */
  "Get_JMatrix",                       /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  9,                                   /* lineNo */
  28,                                  /* colNo */
  "Get_JMatrix",                       /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\HelperFunctions\\Get_JMatrix.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 89,  /* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 84,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 282,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

/* Function Definitions */
void Get_JMatrix(const emlrtStack *sp, const real_T Actuator_Bases_data[], const
                 int32_T Actuator_Bases_size[2], const real_T
                 End_effectors_data[], const int32_T End_effectors_size[2],
                 const real_T Eta_data[], const int32_T Eta_size[1], real_T
                 J_data[], int32_T J_size[2])
{
  real_T dv0[9];
  real_T alpha1;
  real_T beta1;
  real_T a[9];
  int32_T i0;
  int32_T i1;
  real_T dv1[9];
  int32_T r_size[2];
  ptrdiff_t m_t;
  real_T Eta[3];
  ptrdiff_t n_t;
  real_T a_ei_data[72];
  int32_T a_ei_size[2];
  ptrdiff_t k_t;
  int32_T r[2];
  ptrdiff_t lda_t;
  int32_T a_ei[2];
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  int32_T loop_ub;
  char_T TRANSB;
  real_T r_data[72];
  int32_T b_Actuator_Bases_size[2];
  real_T b_Actuator_Bases_data[72];
  real_T varargin_2_data[72];
  real_T tmp_data[24];
  real_T b_tmp_data[24];
  int32_T result;
  boolean_T empty_non_axis_sizes;
  int8_T input_sizes_idx_0;
  int8_T sizes_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /*  save INN */
  if (6 > Eta_size[0]) {
    emlrtDynamicBoundsCheckR2012b(6, 1, Eta_size[0], &emlrtBCI, sp);
  }

  dv0[1] = 0.0;
  alpha1 = muDoubleScalarCos(Eta_data[3]);
  dv0[4] = alpha1;
  beta1 = muDoubleScalarSin(Eta_data[3]);
  dv0[7] = -beta1;
  dv0[2] = 0.0;
  dv0[5] = beta1;
  dv0[8] = alpha1;
  alpha1 = muDoubleScalarCos(Eta_data[4]);
  a[0] = alpha1;
  a[3] = 0.0;
  beta1 = muDoubleScalarSin(Eta_data[4]);
  a[6] = beta1;
  dv0[0] = 1.0;
  a[1] = 0.0;
  dv0[3] = 0.0;
  a[4] = 1.0;
  dv0[6] = 0.0;
  a[7] = 0.0;
  a[2] = -beta1;
  a[5] = 0.0;
  a[8] = alpha1;
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      dv1[i0 + 3 * i1] = (dv0[i0] * a[3 * i1] + dv0[i0 + 3] * a[1 + 3 * i1]) +
        dv0[i0 + 6] * a[2 + 3 * i1];
    }
  }

  alpha1 = muDoubleScalarCos(Eta_data[5]);
  dv0[0] = alpha1;
  beta1 = muDoubleScalarSin(Eta_data[5]);
  dv0[3] = -beta1;
  dv0[6] = 0.0;
  dv0[1] = beta1;
  dv0[4] = alpha1;
  dv0[7] = 0.0;
  dv0[2] = 0.0;
  dv0[5] = 0.0;
  dv0[8] = 1.0;
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      a[i0 + 3 * i1] = (dv1[i0] * dv0[3 * i1] + dv1[i0 + 3] * dv0[1 + 3 * i1]) +
        dv1[i0 + 6] * dv0[2 + 3 * i1];
    }
  }

  st.site = &emlrtRSI;
  b_st.site = &f_emlrtRSI;
  if (3 != End_effectors_size[0]) {
    if ((End_effectors_size[0] == 1) && (End_effectors_size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  b_st.site = &e_emlrtRSI;
  if (End_effectors_size[1] == 0) {
    r_size[0] = 3;
    r_size[1] = 0;
  } else {
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)3;
    n_t = (ptrdiff_t)End_effectors_size[1];
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)3;
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)3;
    r_size[0] = 3;
    r_size[1] = End_effectors_size[1];
    TRANSA = 'N';
    TRANSB = 'N';
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t,
          &End_effectors_data[0], &ldb_t, &beta1, &r_data[0], &ldc_t);
  }

  st.site = &b_emlrtRSI;
  indexShapeCheck(&st, Eta_size[0]);
  Eta[0] = Eta_data[0];
  Eta[1] = Eta_data[1];
  Eta[2] = Eta_data[2];
  st.site = &b_emlrtRSI;
  repmat(&st, Eta, Actuator_Bases_size[1], a_ei_data, a_ei_size);
  r[0] = 3;
  a_ei[0] = a_ei_size[0];
  r[1] = r_size[1];
  a_ei[1] = a_ei_size[1];
  if ((3 != a_ei_size[0]) || (r_size[1] != a_ei_size[1])) {
    emlrtSizeEqCheckNDR2012b(&r[0], &a_ei[0], &emlrtECI, sp);
  }

  loop_ub = 3 * r_size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    a_ei_data[i0] += r_data[i0];
  }

  r[0] = Actuator_Bases_size[0];
  a_ei[0] = 3;
  r[1] = Actuator_Bases_size[1];
  a_ei[1] = r_size[1];
  if ((Actuator_Bases_size[0] != 3) || (Actuator_Bases_size[1] != r_size[1])) {
    emlrtSizeEqCheckNDR2012b(&r[0], &a_ei[0], &b_emlrtECI, sp);
  }

  r[0] = Actuator_Bases_size[0];
  a_ei[0] = 3;
  r[1] = Actuator_Bases_size[1];
  a_ei[1] = r_size[1];
  if ((Actuator_Bases_size[0] != 3) || (Actuator_Bases_size[1] != r_size[1])) {
    emlrtSizeEqCheckNDR2012b(&r[0], &a_ei[0], &c_emlrtECI, sp);
  }

  b_Actuator_Bases_size[0] = Actuator_Bases_size[0];
  b_Actuator_Bases_size[1] = Actuator_Bases_size[1];
  loop_ub = Actuator_Bases_size[0] * Actuator_Bases_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_Actuator_Bases_data[i0] = Actuator_Bases_data[i0] - a_ei_data[i0];
  }

  power(b_Actuator_Bases_data, b_Actuator_Bases_size, varargin_2_data, r);
  sum(varargin_2_data, r, tmp_data, a_ei);
  st.site = &c_emlrtRSI;
  b_power(&st, tmp_data, a_ei, b_tmp_data, r);
  st.site = &c_emlrtRSI;
  b_repmat(&st, b_tmp_data, r, Actuator_Bases_size[0], varargin_2_data, a_ei);
  b_Actuator_Bases_size[0] = Actuator_Bases_size[0];
  b_Actuator_Bases_size[1] = Actuator_Bases_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_Actuator_Bases_data[i0] = Actuator_Bases_data[i0] - a_ei_data[i0];
  }

  st.site = &c_emlrtRSI;
  rdivide_helper(&st, b_Actuator_Bases_data, b_Actuator_Bases_size,
                 varargin_2_data, a_ei, a_ei_data, a_ei_size);
  st.site = &d_emlrtRSI;
  cross(&st, r_data, r_size, a_ei_data, a_ei_size, varargin_2_data, r);
  st.site = &d_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  if (a_ei_size[1] != 0) {
    result = a_ei_size[1];
  } else if (r[1] != 0) {
    result = r[1];
  } else {
    result = 0;
  }

  c_st.site = &u_emlrtRSI;
  if ((a_ei_size[1] == result) || (a_ei_size[1] == 0)) {
  } else {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((r[1] == result) || (r[1] == 0)) {
  } else {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes || (a_ei_size[1] != 0)) {
    input_sizes_idx_0 = 3;
  } else {
    input_sizes_idx_0 = 0;
  }

  if (empty_non_axis_sizes || (r[1] != 0)) {
    sizes_idx_0 = 3;
  } else {
    sizes_idx_0 = 0;
  }

  loop_ub = input_sizes_idx_0;
  J_size[0] = input_sizes_idx_0 + sizes_idx_0;
  J_size[1] = result;
  for (i0 = 0; i0 < result; i0++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      J_data[i1 + J_size[0] * i0] = a_ei_data[i1 + 3 * i0];
    }
  }

  for (i0 = 0; i0 < result; i0++) {
    loop_ub = sizes_idx_0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      J_data[(i1 + input_sizes_idx_0) + J_size[0] * i0] = varargin_2_data[i1 + 3
        * i0];
    }
  }
}

/* End of code generation (Get_JMatrix.c) */
