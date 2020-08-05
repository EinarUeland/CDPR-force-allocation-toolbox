/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Get_JMatrix_api.c
 *
 * Code generation for function '_coder_Get_JMatrix_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "_coder_Get_JMatrix_api.h"
#include "Get_JMatrix_data.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Eta, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Actuator_Bases,
  const char_T *identifier, real_T **y_data, int32_T y_size[2]);
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r1;
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Eta, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r2;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(Eta), &thisId, &r2, y_size);
  *y_data = r2;
  emlrtDestroyArray(&Eta);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r3;
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r3, y_size);
  *y_data = r3;
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 3, 24 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv4[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv4);
  ret_size[0] = iv4[0];
  ret_size[1] = iv4[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Actuator_Bases,
  const char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Actuator_Bases), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&Actuator_Bases);
}

static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv3[2] = { 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m3, u_size, 2);
  emlrtAssign(&y, m3);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 6 };

  const boolean_T bv1[1] = { true };

  int32_T iv5[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv5);
  ret_size[0] = iv5[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

void Get_JMatrix_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray *
                     plhs[1])
{
  real_T (*J_data)[144];
  real_T (*Actuator_Bases_data)[72];
  int32_T Actuator_Bases_size[2];
  real_T (*End_effectors_data)[72];
  int32_T End_effectors_size[2];
  real_T (*Eta_data)[6];
  int32_T Eta_size[1];
  int32_T J_size[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  J_data = (real_T (*)[144])mxMalloc(sizeof(real_T [144]));

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Actuator_Bases", (real_T **)
                   &Actuator_Bases_data, Actuator_Bases_size);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "End_effectors", (real_T **)
                   &End_effectors_data, End_effectors_size);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Eta", (real_T **)&Eta_data,
                     Eta_size);

  /* Invoke the target function */
  Get_JMatrix(&st, *Actuator_Bases_data, Actuator_Bases_size,
              *End_effectors_data, End_effectors_size, *Eta_data, Eta_size,
              *J_data, J_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*J_data, J_size);
}

/* End of code generation (_coder_Get_JMatrix_api.c) */
