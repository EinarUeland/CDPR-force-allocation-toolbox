/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Newton_Slack_api.c
 *
 * Code generation for function '_coder_Newton_Slack_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Newton_Slack.h"
#include "_coder_Newton_Slack_api.h"
#include "Newton_Slack_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[10];
static const mxArray *b_emlrt_marshallOut(const real_T u[3]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq,
  const char_T *identifier))[12];
static const mxArray *c_emlrt_marshallOut(const real_T u);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *WTarget,
  const char_T *identifier))[3];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X0, const
  char_T *identifier))[10];
static const mxArray *emlrt_marshallOut(const real_T u[4]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmin,
  const char_T *identifier))[4];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tau1,
  const char_T *identifier);
static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q, const
  char_T *identifier))[9];
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9];
static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10];
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12];
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[10]
{
  real_T (*y)[10];
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u[3])
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv5[1] = { 0 };

  static const int32_T iv6[1] = { 3 };

  y = NULL;
  m4 = emlrtCreateNumericArray(1, iv5, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m4, iv6, 1);
  emlrtAssign(&y, m4);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Aeq,
  const char_T *identifier))[12]
{
  real_T (*y)[12];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(Aeq), &thisId);
  emlrtDestroyArray(&Aeq);
  return y;
}
  static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m5);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *WTarget, const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(WTarget), &thisId);
  emlrtDestroyArray(&WTarget);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X0, const
  char_T *identifier))[10]
{
  real_T (*y)[10];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(X0), &thisId);
  emlrtDestroyArray(&X0);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[4])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv3[1] = { 0 };

  static const int32_T iv4[1] = { 4 };

  y = NULL;
  m3 = emlrtCreateNumericArray(1, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv4, 1);
  emlrtAssign(&y, m3);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmin,
  const char_T *identifier))[4]
{
  real_T (*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(tmin), &thisId);
  emlrtDestroyArray(&tmin);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tau1,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(tau1), &thisId);
  emlrtDestroyArray(&tau1);
  return y;
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q, const
  char_T *identifier))[9]
{
  real_T (*y)[9];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(Q), &thisId);
  emlrtDestroyArray(&Q);
  return y;
}
  static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[9]
{
  real_T (*y)[9];
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10]
{
  real_T (*ret)[10];
  static const int32_T dims[1] = { 10 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[10])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  real_T (*ret)[12];
  static const int32_T dims[2] = { 3, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[1] = { 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  real_T (*ret)[4];
  static const int32_T dims[1] = { 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9]
{
  real_T (*ret)[9];
  static const int32_T dims[2] = { 3, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void Newton_Slack_api(const mxArray * const prhs[15], int32_T nlhs, const
  mxArray *plhs[6])
{
  real_T (*f)[4];
  real_T (*s)[3];
  real_T (*lambda)[3];
  real_T (*X0)[10];
  real_T (*Aeq)[12];
  real_T (*WTarget)[3];
  real_T (*tmin)[4];
  real_T (*tmax)[4];
  real_T tau1;
  real_T tau2;
  real_T (*OptimalTension)[4];
  real_T Tol;
  real_T IterMax;
  real_T (*KappaMat)[3];
  real_T (*Q)[9];
  real_T epsilon;
  real_T SqFac;
  real_T alpha;
  real_T N_Iter;
  real_T InfeasibleFlag;
  real_T LineIter;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  f = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));
  s = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  lambda = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));

  /* Marshall function inputs */
  X0 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X0");
  Aeq = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Aeq");
  WTarget = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "WTarget");
  tmin = g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "tmin");
  tmax = g_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "tmax");
  tau1 = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "tau1");
  tau2 = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "tau2");
  OptimalTension = g_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "OptimalTension");
  Tol = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "Tol");
  IterMax = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "IterMax");
  KappaMat = e_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "KappaMat");
  Q = k_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "Q");
  epsilon = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "epsilon");
  SqFac = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "SqFac");
  alpha = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "alpha");

  /* Invoke the target function */
  Newton_Slack(&st, *X0, *Aeq, *WTarget, *tmin, *tmax, tau1, tau2,
               *OptimalTension, Tol, IterMax, *KappaMat, *Q, epsilon, SqFac,
               alpha, *f, *s, *lambda, &N_Iter, &InfeasibleFlag, &LineIter);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*f);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*s);
  }

  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(*lambda);
  }

  if (nlhs > 3) {
    plhs[3] = c_emlrt_marshallOut(N_Iter);
  }

  if (nlhs > 4) {
    plhs[4] = c_emlrt_marshallOut(InfeasibleFlag);
  }

  if (nlhs > 5) {
    plhs[5] = c_emlrt_marshallOut(LineIter);
  }
}

/* End of code generation (_coder_Newton_Slack_api.c) */
