/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef REPMAT_H
#define REPMAT_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Get_JMatrix_types.h"

/* Function Declarations */
extern void b_repmat(const emlrtStack *sp, const real_T a_data[], const int32_T
                     a_size[2], real_T varargin_1, real_T b_data[], int32_T
                     b_size[2]);
extern void repmat(const emlrtStack *sp, const real_T a[3], real_T varargin_2,
                   real_T b_data[], int32_T b_size[2]);

#endif

/* End of code generation (repmat.h) */
