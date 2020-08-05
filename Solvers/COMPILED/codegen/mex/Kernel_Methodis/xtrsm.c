/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsm.c
 *
 * Code generation for function 'xtrsm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "xtrsm.h"
#include "blas.h"

/* Function Definitions */
void b_xtrsm(int32_T m, const real_T A_data[], int32_T lda, real_T B_data[],
             int32_T ldb)
{
  real_T alpha1;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  char_T SIDE1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  if (m >= 1) {
    alpha1 = 1.0;
    DIAGA1 = 'N';
    TRANSA1 = 'N';
    UPLO1 = 'U';
    SIDE1 = 'L';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)1;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &alpha1, &A_data[0],
          &lda_t, &B_data[0], &ldb_t);
  }
}

void c_xtrsm(int32_T n, const real_T A_data[], int32_T lda, real_T B_data[])
{
  real_T alpha1;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  char_T SIDE1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  if (n >= 1) {
    alpha1 = 1.0;
    DIAGA1 = 'N';
    TRANSA1 = 'N';
    UPLO1 = 'U';
    SIDE1 = 'R';
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)1;
    dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &alpha1, &A_data[0],
          &lda_t, &B_data[0], &ldb_t);
  }
}

void d_xtrsm(int32_T n, const real_T A_data[], int32_T lda, real_T B_data[])
{
  real_T alpha1;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  char_T SIDE1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  if (n >= 1) {
    alpha1 = 1.0;
    DIAGA1 = 'U';
    TRANSA1 = 'N';
    UPLO1 = 'L';
    SIDE1 = 'R';
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)1;
    dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &alpha1, &A_data[0],
          &lda_t, &B_data[0], &ldb_t);
  }
}

void xtrsm(int32_T m, const real_T A_data[], int32_T lda, real_T B_data[],
           int32_T ldb)
{
  real_T alpha1;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  char_T SIDE1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  if (m >= 1) {
    alpha1 = 1.0;
    DIAGA1 = 'U';
    TRANSA1 = 'N';
    UPLO1 = 'L';
    SIDE1 = 'L';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)1;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    dtrsm(&SIDE1, &UPLO1, &TRANSA1, &DIAGA1, &m_t, &n_t, &alpha1, &A_data[0],
          &lda_t, &B_data[0], &ldb_t);
  }
}

/* End of code generation (xtrsm.c) */
