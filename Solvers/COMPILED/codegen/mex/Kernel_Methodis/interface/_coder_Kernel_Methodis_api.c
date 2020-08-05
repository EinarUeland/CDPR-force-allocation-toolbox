/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Kernel_Methodis_api.c
 *
 * Code generation for function '_coder_Kernel_Methodis_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "_coder_Kernel_Methodis_api.h"
#include "Kernel_Methodis_mexutil.h"
#include "Kernel_Methodis_data.h"

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void c_emlrt_marshallOut(const real_T u_data[], const int32_T u_size[2],
  const mxArray *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Wt, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmin, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1])
{
  const mxArray *y;
  const mxArray *m11;
  static const int32_T iv9[1] = { 0 };

  y = NULL;
  m11 = emlrtCreateNumericArray(1, iv9, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m11, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m11, u_size, 1);
  emlrtAssign(&y, m11);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(Aeq), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&Aeq);
}

static void c_emlrt_marshallOut(const real_T u_data[], const int32_T u_size[2],
  const mxArray *y)
{
  emlrtMxSetData((mxArray *)y, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)y, u_size, 2);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r1;
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Wt, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r2;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(Wt), &thisId, &r2, y_size);
  *y_data = r2;
  emlrtDestroyArray(&Wt);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r3;
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r3, y_size);
  *y_data = r3;
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmin, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r4;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(tmin), &thisId, &r4, y_size);
  *y_data = r4;
  emlrtDestroyArray(&tmin);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r5;
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r5, y_size);
  *y_data = r5;
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 6, 24 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv11[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv11);
  ret_size[0] = iv11[0];
  ret_size[1] = iv11[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 6 };

  const boolean_T bv1[1] = { true };

  int32_T iv12[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv12);
  ret_size[0] = iv12[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 24 };

  const boolean_T bv2[1] = { true };

  int32_T iv13[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv2[0],
    iv13);
  ret_size[0] = iv13[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

void Kernel_Methodis_api(const mxArray *prhs[5], int32_T nlhs, const mxArray
  *plhs[4])
{
  real_T (*FLINES_data)[24];
  real_T (*FGlob_data)[6];
  const mxArray *prhs_copy_idx_0;
  real_T (*Aeq_data)[144];
  int32_T Aeq_size[2];
  real_T (*Wt_data)[6];
  int32_T Wt_size[1];
  real_T (*tmin_data)[24];
  int32_T tmin_size[1];
  real_T (*tmax_data)[24];
  int32_T tmax_size[1];
  real_T (*OptimalTension_data)[24];
  int32_T OptimalTension_size[1];
  int32_T FLINES_size[1];
  int32_T FGlob_size[1];
  real_T Flag;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  FLINES_data = (real_T (*)[24])mxMalloc(sizeof(real_T [24]));
  FGlob_data = (real_T (*)[6])mxMalloc(sizeof(real_T [6]));
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, 144);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "Aeq", (real_T **)
                     &Aeq_data, Aeq_size);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Wt", (real_T **)&Wt_data,
                     Wt_size);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "tmin", (real_T **)&tmin_data,
                     tmin_size);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "tmax", (real_T **)&tmax_data,
                     tmax_size);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "OptimalTension", (real_T **)
                     &OptimalTension_data, OptimalTension_size);

  /* Invoke the target function */
  Kernel_Methodis(&st, *Aeq_data, Aeq_size, *Wt_data, Wt_size, *tmin_data,
                  tmin_size, *tmax_data, tmax_size, *OptimalTension_data,
                  OptimalTension_size, *FLINES_data, FLINES_size, *FGlob_data,
                  FGlob_size, &Flag);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*FLINES_data, FLINES_size);
  if (nlhs > 1) {
    c_emlrt_marshallOut(*Aeq_data, Aeq_size, prhs_copy_idx_0);
    plhs[1] = prhs_copy_idx_0;
  }

  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(*FGlob_data, FGlob_size);
  }

  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(Flag);
  }
}

/* End of code generation (_coder_Kernel_Methodis_api.c) */
