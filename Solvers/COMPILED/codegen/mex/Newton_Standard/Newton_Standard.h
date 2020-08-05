/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_Standard.h
 *
 * Code generation for function 'Newton_Standard'
 *
 */

#ifndef NEWTON_STANDARD_H
#define NEWTON_STANDARD_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Newton_Standard_types.h"

/* Function Declarations */
extern void Newton_Standard(const emlrtStack *sp, const real_T X0[7], const
  real_T Aeq[12], const real_T WTarget[3], const real_T tmin[4], const real_T
  tmax[4], real_T tau1, real_T tau2, const real_T OptimalTension[4], real_T Tol,
  real_T IterMax, real_T alpha, real_T w[4], real_T lambda[3], real_T *N_Iter,
  real_T *InfeasibleFlag, real_T *LineIter);

#endif

/* End of code generation (Newton_Standard.h) */
