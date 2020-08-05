/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_SlackAnyP.h
 *
 * Code generation for function 'Newton_SlackAnyP'
 *
 */

#ifndef NEWTON_SLACKANYP_H
#define NEWTON_SLACKANYP_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Newton_SlackAnyP_types.h"

/* Function Declarations */
extern void Newton_SlackAnyP(const emlrtStack *sp, const real_T X0[10], const
  real_T Aeq[12], const real_T WTarget[3], const real_T tmin[4], const real_T
  tmax[4], real_T tau1, real_T tau2, const real_T OptimalTension[4], real_T Tol,
  real_T IterMax, const real_T KappaMat[3], const real_T Q[9], real_T epsilon,
  real_T SqFac, real_T P, real_T alpha, real_T f[4], real_T s[3], real_T lambda
  [3], real_T *N_Iter, real_T *InfeasibleFlag, real_T *LineIter);

#endif

/* End of code generation (Newton_SlackAnyP.h) */
