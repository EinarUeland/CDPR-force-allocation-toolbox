/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.h
 *
 * Code generation for function 'xdotc'
 *
 */

#ifndef XDOTC_H
#define XDOTC_H

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
extern real_T b_xdotc(const emlrtStack *sp, int32_T n, const real_T x[36],
                      int32_T ix0, const real_T y[36], int32_T iy0);
extern real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[48], int32_T
                    ix0, const real_T y[48], int32_T iy0);

#endif

/* End of code generation (xdotc.h) */
