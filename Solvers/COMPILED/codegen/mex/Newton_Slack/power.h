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
#include "Newton_Slack_types.h"

/* Function Declarations */
extern void b_power(const real_T a[3], real_T y[3]);
extern void c_power(const emlrtStack *sp, const real_T a[3], real_T y[3]);
extern void power(const real_T a[4], real_T y[4]);

#endif

/* End of code generation (power.h) */
