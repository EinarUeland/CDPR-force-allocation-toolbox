/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pinv.h
 *
 * Code generation for function 'pinv'
 *
 */

#ifndef PINV_H
#define PINV_H

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
extern void pinv(const emlrtStack *sp, const real_T A[48], real_T X[48]);

#endif

/* End of code generation (pinv.h) */
