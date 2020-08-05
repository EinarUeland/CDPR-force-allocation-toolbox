/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cross.h
 *
 * Code generation for function 'cross'
 *
 */

#ifndef CROSS_H
#define CROSS_H

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
extern void cross(const emlrtStack *sp, const real_T a_data[], const int32_T
                  a_size[2], const real_T b_data[], const int32_T b_size[2],
                  real_T c_data[], int32_T c_size[2]);

#endif

/* End of code generation (cross.h) */
