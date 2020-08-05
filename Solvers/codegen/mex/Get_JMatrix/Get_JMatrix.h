/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Get_JMatrix.h
 *
 * Code generation for function 'Get_JMatrix'
 *
 */

#ifndef GET_JMATRIX_H
#define GET_JMATRIX_H

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
extern void Get_JMatrix(const emlrtStack *sp, const real_T Actuator_Bases_data[],
  const int32_T Actuator_Bases_size[2], const real_T End_effectors_data[], const
  int32_T End_effectors_size[2], const real_T Eta_data[], const int32_T
  Eta_size[1], real_T J_data[], int32_T J_size[2]);

#endif

/* End of code generation (Get_JMatrix.h) */
