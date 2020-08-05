/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.h
 *
 * Code generation for function 'power'
 *
 */

#ifndef POWER_H
#define POWER_H

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
extern void b_power(const emlrtStack *sp, const real_T a_data[], const int32_T
                    a_size[2], real_T y_data[], int32_T y_size[2]);
extern void power(const real_T a_data[], const int32_T a_size[2], real_T y_data[],
                  int32_T y_size[2]);

#endif

/* End of code generation (power.h) */
