/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Kernel_Methodis.h
 *
 * Code generation for function 'Kernel_Methodis'
 *
 */

#ifndef KERNEL_METHODIS_H
#define KERNEL_METHODIS_H

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
extern void Kernel_Methodis(const emlrtStack *sp, const real_T Aeq_data[], const
  int32_T Aeq_size[2], const real_T Wt_data[], const int32_T Wt_size[1], const
  real_T tmin_data[], const int32_T tmin_size[1], const real_T tmax_data[],
  const int32_T tmax_size[1], const real_T OptimalTension_data[], const int32_T
  OptimalTension_size[1], real_T FLINES_data[], int32_T FLINES_size[1], real_T
  FGlob_data[], int32_T FGlob_size[1], real_T *Flag);

#endif

/* End of code generation (Kernel_Methodis.h) */
