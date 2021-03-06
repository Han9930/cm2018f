#ifndef CONSTANTH
#define CONSTANTH

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;


extern "C" { 
        void dgetrf_(int* M, int* N, double* A, int* LDA, int* IPIV, int* INFO); 
        void dgetrs_(char* TRANS, int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO); 
        void dgetri_(int* N, double* A, int* LDA, int* IPIV, double* WORK, int* LWORK, int* INFO); 
} 
// refer to lapack library 
 
 
int Solver(int N, double *A, double *b){ 
 
        int i, j, *ipiv = new int[N], nrhs = 1, info, lwork = 4*N; 
        char trans = 'N'; 
        double *work = new double[lwork], *temp = new double[N]; 
 
        dgetrf_(&N, &N, A, &N, ipiv, &info); 
        dgetri_(&N, A, &N, ipiv, work, &lwork, &info); 
 
        for(i = 0; i < N; i++) {*(temp+i) = *(b+i); *(b+i) = 0;} 
        for(i = 0; i < N; i++) for(j = 0; j < N; j++) *(b+i) += A[N*i+j]*temp[j]; 
 
        delete ipiv, work, temp; 
        return info; 
} 
// Linear Solver

#define e0 8.854187817e-12 //Vacuum permittivity
#define h 6.626176e-34 //Planck constant
#define hbar (h/(2*PI)) // Reduced Planck constant
#define q 1.602192e-19 // Elementary charge
#define m0 9.109534e-31 // Electron rest mass
#define k_B 1.380662e-23 // Boltzmann constant
#define T 300.0 // Temperature
#define Nacc 1e24 
#define ni 1.075e16
#define eOx (3.9*e0)
#define eSi (11.7*e0)
#define VT (k_B*T/q)
// Constants


#define Lo 1e-9
#define Ls 5e-9

// Settings


#endif
