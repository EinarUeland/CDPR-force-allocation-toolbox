/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.h
 *
 * Code generation for function 'mldivide'
 *
 */

#ifndef MLDIVIDE_H
#define MLDIVIDE_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Kernel_Methodis_types.h"

/* Function Declarations */
extern void mldivide(const emlrtStack *sp, const real_T A_data[], const int32_T
                     A_size[2], const real_T B_data[], const int32_T B_size[1],
                     real_T Y_data[], int32_T Y_size[1]);

#endif

/* End of code generation (mldivide.h) */
