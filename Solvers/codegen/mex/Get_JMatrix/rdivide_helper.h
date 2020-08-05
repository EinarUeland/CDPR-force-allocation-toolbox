/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide_helper.h
 *
 * Code generation for function 'rdivide_helper'
 *
 */

#ifndef RDIVIDE_HELPER_H
#define RDIVIDE_HELPER_H

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
extern void rdivide_helper(const emlrtStack *sp, const real_T x_data[], const
  int32_T x_size[2], const real_T y_data[], const int32_T y_size[2], real_T
  z_data[], int32_T z_size[2]);

#endif

/* End of code generation (rdivide_helper.h) */
