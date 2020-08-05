/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.h
 *
 * Code generation for function 'svd'
 *
 */

#ifndef SVD_H
#define SVD_H

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
extern void svd(const emlrtStack *sp, const real_T A[48], real_T U[48], real_T
                s[6], real_T V[36]);

#endif

/* End of code generation (svd.h) */
