/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
 *
 */

#ifndef XAXPY_H
#define XAXPY_H

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
extern void b_xaxpy(int32_T n, real_T a, const real_T x[48], int32_T ix0, real_T
                    y[8], int32_T iy0);
extern void c_xaxpy(int32_T n, real_T a, const real_T x[8], int32_T ix0, real_T
                    y[48], int32_T iy0);
extern void d_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[36], int32_T iy0);
extern void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[48], int32_T iy0);

#endif

/* End of code generation (xaxpy.h) */
