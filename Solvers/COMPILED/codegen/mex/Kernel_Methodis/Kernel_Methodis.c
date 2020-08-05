/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Kernel_Methodis.c
 *
 * Code generation for function 'Kernel_Methodis'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "error.h"
#include "null.h"
#include "mldivide.h"
#include "mrdivide_helper.h"
#include "ifWhileCond.h"
#include "Kernel_Methodis_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6,     /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 16,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 17,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 19,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 31,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 32,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 38,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 40,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 43,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 45,  /* lineNo */
  "Kernel_Methodis",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 54,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 23,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 114, /* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 118, /* lineNo */
  "mtimes",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\mtimes.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 44, /* lineNo */
  "unaryOrBinaryDispatch",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 13, /* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  9,                                   /* lineNo */
  7,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  20,                                  /* lineNo */
  4,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  21,                                  /* lineNo */
  4,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  39,                                  /* lineNo */
  8,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  8,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  41,                                  /* lineNo */
  8,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  41,                                  /* lineNo */
  8,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  43,                                  /* lineNo */
  8,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  43,                                  /* lineNo */
  8,                                   /* colNo */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 89,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 84,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 84,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "K1",                                /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  5,                                   /* colNo */
  "Lambdamin",                         /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  18,                                  /* colNo */
  "K2",                                /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  5,                                   /* colNo */
  "Lambdamin",                         /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  18,                                  /* colNo */
  "K2",                                /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  5,                                   /* colNo */
  "Lambdamax",                         /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  18,                                  /* colNo */
  "K1",                                /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "Lambdamax",                         /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  4,                                   /* colNo */
  "Vh",                                /* aName */
  "Kernel_Methodis",                   /* fName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Kernel_Methodis.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void Kernel_Methodis(const emlrtStack *sp, const real_T Aeq_data[], const
                     int32_T Aeq_size[2], const real_T Wt_data[], const int32_T
                     Wt_size[1], const real_T tmin_data[], const int32_T
                     tmin_size[1], const real_T tmax_data[], const int32_T
                     tmax_size[1], const real_T OptimalTension_data[], const
                     int32_T OptimalTension_size[1], real_T FLINES_data[],
                     int32_T FLINES_size[1], real_T FGlob_data[], int32_T
                     FGlob_size[1], real_T *Flag)
{
  int32_T b_Wt_size[1];
  int32_T loop_ub;
  int32_T i8;
  real_T b_Wt_data[6];
  int32_T idx;
  real_T alpha1;
  int32_T i9;
  real_T beta1;
  ptrdiff_t m_t;
  int32_T Lambdamin_size_idx_0;
  ptrdiff_t n_t;
  real_T Lambdamin_data[24];
  ptrdiff_t k_t;
  int32_T Lambdamax_size_idx_0;
  ptrdiff_t lda_t;
  real_T Lambdamax_data[24];
  real_T Vh_data[576];
  int32_T Vh_size[2];
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  char_T TRANSA;
  real_T a_data[24];
  char_T TRANSB;
  int32_T LambdaStar_size[2];
  real_T LambdaStar_data[24];
  int32_T tmp_size[2];
  real_T b_a_data[576];
  real_T tmp_data[576];
  int32_T a_size[2];
  int32_T tmp_data_tmp;
  int32_T i10;
  real_T K1_data[24];
  int32_T K2_size_idx_0;
  real_T K2_data[24];
  boolean_T exitg1;
  real_T Lambdamax;
  int32_T b_LambdaStar_size[2];
  boolean_T b_LambdaStar_data[24];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;

  /* (X0,Aeq,WTarget,tmin,tmax,tau1,tau2,OptimalTension,Tol,IterMax,KappaMat,epsilon,SqFac,TANFAC) */
  /* KernelBased Method for quadratic programming with  n-m=1; */
  if (Aeq_size[1] - Aeq_size[0] != 1) {
    st.site = &emlrtRSI;
    error(&st, Aeq_size[0], Aeq_size[1]);
  }

  /*  FINDING DESIRED */
  st.site = &b_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  if (Aeq_size[1] != OptimalTension_size[0]) {
    if (((Aeq_size[0] == 1) && (Aeq_size[1] == 1)) || (OptimalTension_size[0] ==
         1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  if ((Aeq_size[1] == 1) || (OptimalTension_size[0] == 1)) {
    b_Wt_size[0] = Aeq_size[0];
    loop_ub = Aeq_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_Wt_data[i8] = 0.0;
      idx = Aeq_size[1];
      for (i9 = 0; i9 < idx; i9++) {
        b_Wt_data[i8] += Aeq_data[i8 + Aeq_size[0] * i9] *
          OptimalTension_data[i9];
      }
    }
  } else {
    b_st.site = &l_emlrtRSI;
    if ((Aeq_size[0] == 0) || (Aeq_size[1] == 0) || (OptimalTension_size[0] == 0))
    {
      b_Wt_size[0] = Aeq_size[0];
      loop_ub = Aeq_size[0];
      if (0 <= loop_ub - 1) {
        memset(&b_Wt_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &n_emlrtRSI;
      c_st.site = &o_emlrtRSI;
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)Aeq_size[0];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)Aeq_size[1];
      lda_t = (ptrdiff_t)Aeq_size[0];
      ldb_t = (ptrdiff_t)Aeq_size[1];
      ldc_t = (ptrdiff_t)Aeq_size[0];
      b_Wt_size[0] = Aeq_size[0];
      TRANSA = 'N';
      TRANSB = 'N';
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Aeq_data[0], &lda_t,
            &OptimalTension_data[0], &ldb_t, &beta1, &b_Wt_data[0], &ldc_t);
    }
  }

  if (Wt_size[0] != b_Wt_size[0]) {
    emlrtSizeEqCheck1DR2012b(Wt_size[0], b_Wt_size[0], &emlrtECI, sp);
  }

  *Flag = 0.0;
  Lambdamin_size_idx_0 = Aeq_size[1];
  loop_ub = Aeq_size[1];
  if (0 <= loop_ub - 1) {
    memset(&Lambdamin_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  Lambdamax_size_idx_0 = Aeq_size[1];
  loop_ub = Aeq_size[1];
  if (0 <= loop_ub - 1) {
    memset(&Lambdamax_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &c_emlrtRSI;
  null(&st, Aeq_data, Aeq_size, Vh_data, Vh_size);
  b_Wt_size[0] = Wt_size[0];
  loop_ub = Wt_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_Wt_data[i8] = Wt_data[i8] - b_Wt_data[i8];
  }

  st.site = &d_emlrtRSI;
  mldivide(&st, Aeq_data, Aeq_size, b_Wt_data, b_Wt_size, FLINES_data,
           FLINES_size);
  st.site = &e_emlrtRSI;
  if (0 <= FLINES_size[0] - 1) {
    memcpy(&a_data[0], &FLINES_data[0], (uint32_T)(FLINES_size[0] * (int32_T)
            sizeof(real_T)));
  }

  b_st.site = &m_emlrtRSI;
  if ((int8_T)FLINES_size[0] != Vh_size[0]) {
    if (((int8_T)FLINES_size[0] == 1) || ((Vh_size[0] == 1) && (Vh_size[1] == 1)))
    {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  if (((int8_T)FLINES_size[0] == 1) || (Vh_size[0] == 1)) {
    LambdaStar_size[1] = Vh_size[1];
    loop_ub = Vh_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      LambdaStar_data[i8] = 0.0;
      idx = FLINES_size[0];
      for (i9 = 0; i9 < idx; i9++) {
        LambdaStar_data[i8] += FLINES_data[i9] * Vh_data[i9 + Vh_size[0] * i8];
      }
    }
  } else {
    b_st.site = &l_emlrtRSI;
    if (((int8_T)FLINES_size[0] == 0) || (Vh_size[0] == 0) || (Vh_size[1] == 0))
    {
      LambdaStar_size[1] = Vh_size[1];
      if (0 <= Vh_size[1] - 1) {
        memset(&LambdaStar_data[0], 0, (uint32_T)(Vh_size[1] * (int32_T)sizeof
                (real_T)));
      }
    } else {
      c_st.site = &n_emlrtRSI;
      c_st.site = &o_emlrtRSI;
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)1;
      n_t = (ptrdiff_t)Vh_size[1];
      k_t = (ptrdiff_t)(int8_T)FLINES_size[0];
      lda_t = (ptrdiff_t)1;
      ldb_t = (ptrdiff_t)(int8_T)FLINES_size[0];
      ldc_t = (ptrdiff_t)1;
      LambdaStar_size[1] = Vh_size[1];
      TRANSA = 'N';
      TRANSB = 'N';
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_data[0], &lda_t,
            &Vh_data[0], &ldb_t, &beta1, &LambdaStar_data[0], &ldc_t);
    }
  }

  st.site = &e_emlrtRSI;
  loop_ub = Vh_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    idx = Vh_size[1];
    for (i9 = 0; i9 < idx; i9++) {
      b_a_data[i9 + Vh_size[1] * i8] = Vh_data[i8 + Vh_size[0] * i9];
    }
  }

  b_st.site = &m_emlrtRSI;
  if (Vh_size[0] == 1) {
    tmp_size[0] = Vh_size[1];
    tmp_size[1] = Vh_size[1];
    loop_ub = Vh_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      idx = Vh_size[1];
      for (i9 = 0; i9 < idx; i9++) {
        tmp_data_tmp = i8 + tmp_size[0] * i9;
        tmp_data[tmp_data_tmp] = 0.0;
        for (i10 = 0; i10 < 1; i10++) {
          tmp_data[tmp_data_tmp] += b_a_data[i8] * Vh_data[i9];
        }
      }
    }
  } else {
    b_st.site = &l_emlrtRSI;
    if ((Vh_size[1] == 0) || (Vh_size[0] == 0) || (Vh_size[0] == 0) || (Vh_size
         [1] == 0)) {
      tmp_size[0] = Vh_size[1];
      tmp_size[1] = Vh_size[1];
      loop_ub = Vh_size[1] * Vh_size[1];
      if (0 <= loop_ub - 1) {
        memset(&tmp_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &n_emlrtRSI;
      c_st.site = &o_emlrtRSI;
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)Vh_size[1];
      n_t = (ptrdiff_t)Vh_size[1];
      k_t = (ptrdiff_t)Vh_size[0];
      lda_t = (ptrdiff_t)Vh_size[1];
      ldb_t = (ptrdiff_t)Vh_size[0];
      ldc_t = (ptrdiff_t)Vh_size[1];
      tmp_size[0] = Vh_size[1];
      tmp_size[1] = Vh_size[1];
      TRANSA = 'N';
      TRANSB = 'N';
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b_a_data[0], &lda_t,
            &Vh_data[0], &ldb_t, &beta1, &tmp_data[0], &ldc_t);
    }
  }

  a_size[0] = 1;
  a_size[1] = LambdaStar_size[1];
  loop_ub = LambdaStar_size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    a_data[i8] = -LambdaStar_data[i8];
  }

  st.site = &e_emlrtRSI;
  mrdivide_helper(&st, a_data, a_size, tmp_data, tmp_size, LambdaStar_data,
                  LambdaStar_size);
  if (tmin_size[0] != FLINES_size[0]) {
    emlrtSizeEqCheck1DR2012b(tmin_size[0], FLINES_size[0], &b_emlrtECI, sp);
  }

  if (FLINES_size[0] != OptimalTension_size[0]) {
    emlrtSizeEqCheck1DR2012b(FLINES_size[0], OptimalTension_size[0], &b_emlrtECI,
      sp);
  }

  tmp_data_tmp = tmin_size[0];
  loop_ub = tmin_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    K1_data[i8] = (tmin_data[i8] - FLINES_data[i8]) - OptimalTension_data[i8];
  }

  if (tmax_size[0] != FLINES_size[0]) {
    emlrtSizeEqCheck1DR2012b(tmax_size[0], FLINES_size[0], &c_emlrtECI, sp);
  }

  if (FLINES_size[0] != OptimalTension_size[0]) {
    emlrtSizeEqCheck1DR2012b(FLINES_size[0], OptimalTension_size[0], &c_emlrtECI,
      sp);
  }

  K2_size_idx_0 = tmax_size[0];
  loop_ub = tmax_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    K2_data[i8] = (tmax_data[i8] - FLINES_data[i8]) - OptimalTension_data[i8];
  }

  i8 = OptimalTension_size[0];
  for (idx = 0; idx < i8; idx++) {
    i9 = Vh_size[0] * Vh_size[1];
    i10 = 1 + idx;
    if ((i10 < 1) || (i10 > i9)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, i9, &i_emlrtBCI, sp);
    }

    if (Vh_data[idx] < 0.0) {
      i9 = 1 + idx;
      if ((i9 < 1) || (i9 > K2_size_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, K2_size_idx_0, &c_emlrtBCI, sp);
      }

      i10 = 1 + idx;
      if ((i10 < 1) || (i10 > Lambdamin_size_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, Lambdamin_size_idx_0, &d_emlrtBCI,
          sp);
      }

      Lambdamin_data[i10 - 1] = K2_data[i9 - 1] / Vh_data[idx];
      i9 = 1 + idx;
      if ((i9 < 1) || (i9 > tmp_data_tmp)) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, tmp_data_tmp, &g_emlrtBCI, sp);
      }

      i10 = 1 + idx;
      if ((i10 < 1) || (i10 > Lambdamax_size_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, Lambdamax_size_idx_0, &h_emlrtBCI,
          sp);
      }

      Lambdamax_data[i10 - 1] = K1_data[i9 - 1] / Vh_data[idx];
    } else {
      i9 = 1 + idx;
      if ((i9 < 1) || (i9 > tmp_data_tmp)) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, tmp_data_tmp, &emlrtBCI, sp);
      }

      i10 = 1 + idx;
      if ((i10 < 1) || (i10 > Lambdamin_size_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, Lambdamin_size_idx_0, &b_emlrtBCI,
          sp);
      }

      Lambdamin_data[i10 - 1] = K1_data[i9 - 1] / Vh_data[idx];
      i9 = 1 + idx;
      if ((i9 < 1) || (i9 > K2_size_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, K2_size_idx_0, &e_emlrtBCI, sp);
      }

      i10 = 1 + idx;
      if ((i10 < 1) || (i10 > Lambdamax_size_idx_0)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, Lambdamax_size_idx_0, &f_emlrtBCI,
          sp);
      }

      Lambdamax_data[i10 - 1] = K2_data[i9 - 1] / Vh_data[idx];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &f_emlrtRSI;
  b_st.site = &td_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  d_st.site = &vd_emlrtRSI;
  if (Lambdamin_size_idx_0 < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  if (Lambdamin_size_idx_0 <= 2) {
    if (Lambdamin_size_idx_0 == 1) {
      beta1 = Lambdamin_data[0];
    } else if ((Lambdamin_data[0] < Lambdamin_data[1]) || (muDoubleScalarIsNaN
                (Lambdamin_data[0]) && (!muDoubleScalarIsNaN(Lambdamin_data[1]))))
    {
      beta1 = Lambdamin_data[1];
    } else {
      beta1 = Lambdamin_data[0];
    }
  } else {
    if (!muDoubleScalarIsNaN(Lambdamin_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      tmp_data_tmp = 2;
      exitg1 = false;
      while ((!exitg1) && (tmp_data_tmp <= Lambdamin_size_idx_0)) {
        if (!muDoubleScalarIsNaN(Lambdamin_data[tmp_data_tmp - 1])) {
          idx = tmp_data_tmp;
          exitg1 = true;
        } else {
          tmp_data_tmp++;
        }
      }
    }

    if (idx == 0) {
      beta1 = Lambdamin_data[0];
    } else {
      beta1 = Lambdamin_data[idx - 1];
      idx++;
      for (tmp_data_tmp = idx; tmp_data_tmp <= Lambdamin_size_idx_0;
           tmp_data_tmp++) {
        alpha1 = Lambdamin_data[tmp_data_tmp - 1];
        if (beta1 < alpha1) {
          beta1 = alpha1;
        }
      }
    }
  }

  st.site = &g_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  d_st.site = &vd_emlrtRSI;
  if (Lambdamax_size_idx_0 < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  if (Lambdamax_size_idx_0 <= 2) {
    if (Lambdamax_size_idx_0 == 1) {
      Lambdamax = Lambdamax_data[0];
    } else if ((Lambdamax_data[0] > Lambdamax_data[1]) || (muDoubleScalarIsNaN
                (Lambdamax_data[0]) && (!muDoubleScalarIsNaN(Lambdamax_data[1]))))
    {
      Lambdamax = Lambdamax_data[1];
    } else {
      Lambdamax = Lambdamax_data[0];
    }
  } else {
    if (!muDoubleScalarIsNaN(Lambdamax_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      tmp_data_tmp = 2;
      exitg1 = false;
      while ((!exitg1) && (tmp_data_tmp <= Lambdamax_size_idx_0)) {
        if (!muDoubleScalarIsNaN(Lambdamax_data[tmp_data_tmp - 1])) {
          idx = tmp_data_tmp;
          exitg1 = true;
        } else {
          tmp_data_tmp++;
        }
      }
    }

    if (idx == 0) {
      Lambdamax = Lambdamax_data[0];
    } else {
      Lambdamax = Lambdamax_data[idx - 1];
      idx++;
      for (tmp_data_tmp = idx; tmp_data_tmp <= Lambdamax_size_idx_0;
           tmp_data_tmp++) {
        alpha1 = Lambdamax_data[tmp_data_tmp - 1];
        if (Lambdamax > alpha1) {
          Lambdamax = alpha1;
        }
      }
    }
  }

  if (beta1 > Lambdamax) {
    /* #infeasible */
    FLINES_size[0] = Aeq_size[1];
    loop_ub = Aeq_size[1];
    if (0 <= loop_ub - 1) {
      memset(&FLINES_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    *Flag = 1.0;

    /* INFEASIBLE, But what we really should is to scale down... */
  } else {
    b_LambdaStar_size[0] = 1;
    b_LambdaStar_size[1] = LambdaStar_size[1];
    idx = LambdaStar_size[0] * LambdaStar_size[1];
    for (i8 = 0; i8 < idx; i8++) {
      b_LambdaStar_data[i8] = (LambdaStar_data[i8] < beta1);
    }

    st.site = &h_emlrtRSI;
    if (ifWhileCond(b_LambdaStar_data, b_LambdaStar_size)) {
      idx = Vh_size[0] * Vh_size[1] - 1;
      for (i8 = 0; i8 <= idx; i8++) {
        Vh_data[i8] *= beta1;
      }

      if (1 != Vh_size[1]) {
        emlrtDimSizeEqCheckR2012b(1, Vh_size[1], &d_emlrtECI, sp);
      }

      if (Vh_size[0] != FLINES_size[0]) {
        emlrtSizeEqCheck1DR2012b(Vh_size[0], FLINES_size[0], &e_emlrtECI, sp);
      }

      if (Vh_size[0] != OptimalTension_size[0]) {
        emlrtSizeEqCheck1DR2012b(Vh_size[0], OptimalTension_size[0], &e_emlrtECI,
          sp);
      }

      loop_ub = Vh_size[0];
      FLINES_size[0] = Vh_size[0];
      for (i8 = 0; i8 < loop_ub; i8++) {
        FLINES_data[i8] = (Vh_data[i8] + FLINES_data[i8]) +
          OptimalTension_data[i8];
      }
    } else {
      b_LambdaStar_size[0] = 1;
      b_LambdaStar_size[1] = LambdaStar_size[1];
      for (i8 = 0; i8 < idx; i8++) {
        b_LambdaStar_data[i8] = (LambdaStar_data[i8] > Lambdamax);
      }

      st.site = &i_emlrtRSI;
      if (ifWhileCond(b_LambdaStar_data, b_LambdaStar_size)) {
        loop_ub = Vh_size[0] * Vh_size[1] - 1;
        for (i8 = 0; i8 <= loop_ub; i8++) {
          Vh_data[i8] *= Lambdamax;
        }

        if (1 != Vh_size[1]) {
          emlrtDimSizeEqCheckR2012b(1, Vh_size[1], &f_emlrtECI, sp);
        }

        if (Vh_size[0] != FLINES_size[0]) {
          emlrtSizeEqCheck1DR2012b(Vh_size[0], FLINES_size[0], &g_emlrtECI, sp);
        }

        if (Vh_size[0] != OptimalTension_size[0]) {
          emlrtSizeEqCheck1DR2012b(Vh_size[0], OptimalTension_size[0],
            &g_emlrtECI, sp);
        }

        loop_ub = Vh_size[0];
        FLINES_size[0] = Vh_size[0];
        for (i8 = 0; i8 < loop_ub; i8++) {
          FLINES_data[i8] = (Vh_data[i8] + FLINES_data[i8]) +
            OptimalTension_data[i8];
        }
      } else {
        st.site = &j_emlrtRSI;
        b_st.site = &m_emlrtRSI;
        if (Vh_size[1] != 1) {
          if (((Vh_size[0] == 1) && (Vh_size[1] == 1)) || (LambdaStar_size[1] ==
               1)) {
            emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
              "Coder:toolbox:mtimes_noDynamicScalarExpansion",
              "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
              "MATLAB:innerdim", 0);
          }
        }

        loop_ub = Vh_size[0];
        for (i8 = 0; i8 < loop_ub; i8++) {
          idx = LambdaStar_size[1];
          for (i9 = 0; i9 < idx; i9++) {
            tmp_data[i8 + Vh_size[0] * i9] = Vh_data[i8] * LambdaStar_data[i9];
          }
        }

        if (1 != LambdaStar_size[1]) {
          emlrtDimSizeEqCheckR2012b(1, LambdaStar_size[1], &h_emlrtECI, sp);
        }

        if (Vh_size[0] != FLINES_size[0]) {
          emlrtSizeEqCheck1DR2012b(Vh_size[0], FLINES_size[0], &i_emlrtECI, sp);
        }

        if (Vh_size[0] != OptimalTension_size[0]) {
          emlrtSizeEqCheck1DR2012b(Vh_size[0], OptimalTension_size[0],
            &i_emlrtECI, sp);
        }

        loop_ub = Vh_size[0];
        FLINES_size[0] = Vh_size[0];
        for (i8 = 0; i8 < loop_ub; i8++) {
          FLINES_data[i8] = (tmp_data[i8] + FLINES_data[i8]) +
            OptimalTension_data[i8];
        }
      }
    }
  }

  st.site = &k_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  if (Aeq_size[1] != FLINES_size[0]) {
    if (((Aeq_size[0] == 1) && (Aeq_size[1] == 1)) || (FLINES_size[0] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }

  if ((Aeq_size[1] == 1) || (FLINES_size[0] == 1)) {
    FGlob_size[0] = Aeq_size[0];
    loop_ub = Aeq_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      FGlob_data[i8] = 0.0;
      idx = Aeq_size[1];
      for (i9 = 0; i9 < idx; i9++) {
        FGlob_data[i8] += Aeq_data[i8 + Aeq_size[0] * i9] * FLINES_data[i9];
      }
    }
  } else {
    b_st.site = &l_emlrtRSI;
    if ((Aeq_size[0] == 0) || (Aeq_size[1] == 0) || (FLINES_size[0] == 0)) {
      FGlob_size[0] = Aeq_size[0];
      loop_ub = Aeq_size[0];
      if (0 <= loop_ub - 1) {
        memset(&FGlob_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &n_emlrtRSI;
      c_st.site = &o_emlrtRSI;
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)Aeq_size[0];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)Aeq_size[1];
      lda_t = (ptrdiff_t)Aeq_size[0];
      ldb_t = (ptrdiff_t)Aeq_size[1];
      ldc_t = (ptrdiff_t)Aeq_size[0];
      FGlob_size[0] = Aeq_size[0];
      TRANSA = 'N';
      TRANSB = 'N';
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Aeq_data[0], &lda_t,
            &FLINES_data[0], &ldb_t, &beta1, &FGlob_data[0], &ldc_t);
    }
  }
}

/* End of code generation (Kernel_Methodis.c) */
