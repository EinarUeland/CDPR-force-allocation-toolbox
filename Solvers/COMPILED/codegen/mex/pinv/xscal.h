/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xscal.h
 *
 * Code generation for function 'xscal'
 *
 */

#ifndef XSCAL_H
#define XSCAL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "pinv_types.h"

/* Function Declarations */
extern void b_xscal(const emlrtStack *sp, real_T a, real_T x[36], int32_T ix0);
extern void xscal(const emlrtStack *sp, real_T a, real_T x[48], int32_T ix0);

#endif

/* End of code generation (xscal.h) */
