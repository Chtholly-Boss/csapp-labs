/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);
void Blocking(int access_flag);
void Diagonal(int M, int N, int A[N][M], int B[M][N]);
void All_Special(int M, int N, int A[N][M], int B[M][N]);
void Column_wise(int M, int N, int A[N][M], int B[M][N]);
/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    if(M == 32 && N == 32){
        Diagonal(M,N,A,B);
    }else if(M == 64 && N == 64){
        All_Special(M,N,A,B);
    }else if(M == 61 && N == 67){
        Column_wise(M,N,A,B);
    }else{
        Column_wise(M,N,A,B);
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j]; //0.25
            B[j][i] = tmp; //1.00
        }
    }    

}
/*****************Colomn wise pattern  Perfect for 61 * 67*******************************************************/
char Col_wise[] = "Column wise";
void Column_wise(int M, int N, int A[N][M], int B[M][N]){
    int i = 0,j = 0;
    int k;
    for ( i = 0; i < N-9; i+=11)
    {    
        for ( j = M-1; j >= 0; j--)
        {
            for ( k = 0; k < 11; k++)
            {
                B[j][i+k] = A[i+k][j];
            }
        }
        for (; j >= 0; j--)
        {
            for ( k = 0; k < 11; k++)
            {
                B[j][i+k] = A[i+k][j];   
            } 
        }
    }
    for (; i < N; i++) {
        for ( j = 0; j < M; j++)
        {
            B[j][i] = A[i][j];
        } 
    }
}

char Diagonal_Special[] = "Diagonal 4";
void Diagonal(int M, int N, int A[N][M], int B[M][N]){
    /* Specifically deel with diagonal matrix */
    /* Enough for 32 * 32*/
    int i = 0,j = 0;
    int m,n;
    int tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6;
    // For Back-Diagonal
    for ( i = 0; i < N-7; i+=8){   
        for(j = 0;j < M-7;j+=8){
            if(i == j){
                tmp_1 = A[i][j]; // 1 miss
                tmp_2 = A[i][j+1];
                tmp_3 = A[i][j+2];
                tmp_4 = A[i][j+3];
                for(m = 0;m < 4;m++){ // 4 miss
                    B[j+4+m][i] = A[i][j+4+m];
                }

                B[j][i] = tmp_1;    // 1 miss
                B[j][i+1] = A[i+1][j]; // 1 miss
                tmp_1 = A[i+1][j+1];
                tmp_5 = A[i+1][j+2];
                tmp_6 = A[i+1][j+3];
                for(m = 0;m < 4;m++){
                    B[j+4+m][i+1] = A[i+1][j+4+m];
                }

                B[j+1][i] = tmp_2; // 1 miss
                B[j+1][i+1] = tmp_1; 
                B[j][i+2] = A[i+2][j]; // 1 miss
                B[j+1][i+2] = A[i+2][j+1];
                tmp_1 = A[i+2][j+2];
                tmp_2 = A[i+2][j+3];
                for(m = 0;m < 4;m++){
                    B[j+4+m][i+2] = A[i+2][j+4+m];
                }

                B[j+2][i] = tmp_3; // 1 miss
                B[j+2][i+1] = tmp_5;
                B[j+2][i+2] = tmp_1;
                B[j][i+3] = A[i+3][j]; // 1 miss
                B[j+1][i+3] = A[i+3][j+1];
                B[j+2][i+3] = A[i+3][j+2];
                tmp_1 = A[i+3][j+3];
                for(m = 0;m < 4;m++){
                    B[j+4+m][i+3] = A[i+3][j+4+m];
                }

                B[j+3][i] = tmp_4; // 1 miss
                B[j+3][i+1] = tmp_6;
                B[j+3][i+2] = tmp_2;
                B[j+3][i+3] = tmp_1;
                // Read 5-8 lines
                for(m = 0;m < 4;m++){
                    for(n = 0;n < 4;n++){
                        B[j+m][i+4+n] = A[i+4+n][j+m];
                    }
                }
                tmp_1 = A[i+4][j+4]; // 1 miss
                tmp_2 = A[i+4][j+5];
                tmp_3 = A[i+4][j+6];
                tmp_4 = A[i+4][j+7];

                B[j+4][i+4] = tmp_1;    // 1 miss
                B[j+4][i+5] = A[i+5][j+4]; // 1 miss
                tmp_1 = A[i+5][j+5];
                tmp_5 = A[i+5][j+6];
                tmp_6 = A[i+5][j+7];

                B[j+5][i+4] = tmp_2; // 1 miss
                B[j+5][i+5] = tmp_1; 
                B[j+4][i+6] = A[i+6][j+4]; // 1 miss
                B[j+5][i+6] = A[i+6][j+5];
                tmp_1 = A[i+6][j+6];
                tmp_2 = A[i+6][j+7];

                B[j+6][i+4] = tmp_3; // 1 miss
                B[j+6][i+5] = tmp_5;
                B[j+6][i+6] = tmp_1;
                B[j+4][i+7] = A[i+7][j+4]; // 1 miss
                B[j+5][i+7] = A[i+7][j+5];
                B[j+6][i+7] = A[i+7][j+6];
                tmp_1 = A[i+7][j+7];

                B[j+7][i+4] = tmp_4; // 1 miss
                B[j+7][i+5] = tmp_6;
                B[j+7][i+6] = tmp_2;
                B[j+7][i+7] = tmp_1;
            }else{
                for(m = 0;m < 8;m++){
                    for(n = 0;n < 8;n++){
                        B[j+m][i+n] = A[i+n][j+m];
                    }
                }
            }
        }
    }
}

/************************************************************************/
char Diagonal_Back_Special[] = "Diagonal+non-Diagonal Special";
void All_Special(int M, int N, int A[N][M], int B[M][N]){
    int i = 0,j = 0;
    int m,n;
    int tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8;
    for ( i = 0; i < N-7; i+=8){   
        for(j = 0;j < M-7;j+=8){
            if(i == j){
                /* For Back-Diagonal,Divide into 4 parts*/
                /* process the back-diagonal 4*4 */
                tmp_8 = 1; // For back diagonal order
                tmp_7 = 1; // for loop condition
                while(tmp_7){
                    if(tmp_8 == 1){
                        m = 0;
                        n = 1;
                        tmp_8 = 2;
                    }
                    else if(tmp_8 == 2){
                        m = 1;
                        n = 0;
                        tmp_7 = 0;
                        tmp_8 = 1;
                    }
                    tmp_1 = A[i+4*m][j+4*n]; // 1 miss
                    tmp_2 = A[i+4*m][j+4*n+1];
                    tmp_3 = A[i+4*m][j+4*n+2];
                    tmp_4 = A[i+4*m][j+4*n+3];

                    B[j+4*n][i+4*m] = tmp_1;    // 1 miss
                    B[j+4*n][i+4*m+1] = A[i+4*m+1][j+4*n]; // 1 miss
                    tmp_1 = A[i+4*m+1][j+4*n+1];
                    tmp_5 = A[i+4*m+1][j+4*n+2];
                    tmp_6 = A[i+4*m+1][j+4*n+3];

                    B[j+4*n+1][i+4*m] = tmp_2; // 1 miss
                    B[j+4*n+1][i+4*m+1] = tmp_1; 
                    B[j+4*n][i+4*m+2] = A[i+4*m+2][j+4*n]; // 1 miss
                    B[j+4*n+1][i+4*m+2] = A[i+4*m+2][j+4*n+1];
                    tmp_1 = A[i+4*m+2][j+4*n+2];
                    tmp_2 = A[i+4*m+2][j+4*n+3];

                    B[j+4*n+2][i+4*m] = tmp_3; // 1 miss
                    B[j+4*n+2][i+4*m+1] = tmp_5;
                    B[j+4*n+2][i+4*m+2] = tmp_1;
                    B[j+4*n][i+4*m+3] = A[i+4*m+3][j+4*n]; // 1 miss
                    B[j+4*n+1][i+4*m+3] = A[i+4*m+3][j+4*n+1];
                    B[j+4*n+2][i+4*m+3] = A[i+4*m+3][j+4*n+2];
                    tmp_1 = A[i+4*m+3][j+4*n+3];

                    B[j+4*n+3][i+4*m] = tmp_4; // 1 miss
                    B[j+4*n+3][i+4*m+1] = tmp_6;
                    B[j+4*n+3][i+4*m+2] = tmp_2;
                    B[j+4*n+3][i+4*m+3] = tmp_1;
                } 
                /* process the diagonal 4*4 matrix  */
                for(m = 0;m < 2;m++){
                    tmp_1 = A[i+4*m][j+4*m]; // 1 miss
                    tmp_2 = A[i+4*m][j+4*m+1];
                    tmp_3 = A[i+4*m][j+4*m+2];
                    tmp_4 = A[i+4*m][j+4*m+3];

                    B[j+4*m][i+4*m] = tmp_1;    // 1 miss
                    B[j+4*m][i+4*m+1] = A[i+4*m+1][j+4*m]; // 1 miss
                    tmp_1 = A[i+4*m+1][j+4*m+1];
                    tmp_5 = A[i+4*m+1][j+4*m+2];
                    tmp_6 = A[i+4*m+1][j+4*m+3];

                    B[j+4*m+1][i+4*m] = tmp_2; // 1 miss
                    B[j+4*m+1][i+4*m+1] = tmp_1; 
                    B[j+4*m][i+4*m+2] = A[i+4*m+2][j+4*m]; // 1 miss
                    B[j+4*m+1][i+4*m+2] = A[i+4*m+2][j+4*m+1];
                    tmp_1 = A[i+4*m+2][j+4*m+2];
                    tmp_2 = A[i+4*m+2][j+4*m+3];

                    B[j+4*m+2][i+4*m] = tmp_3; // 1 miss
                    B[j+4*m+2][i+4*m+1] = tmp_5;
                    B[j+4*m+2][i+4*m+2] = tmp_1;
                    B[j+4*m][i+4*m+3] = A[i+4*m+3][j+4*m]; // 1 miss
                    B[j+4*m+1][i+4*m+3] = A[i+4*m+3][j+4*m+1];
                    B[j+4*m+2][i+4*m+3] = A[i+4*m+3][j+4*m+2];
                    tmp_1 = A[i+4*m+3][j+4*m+3];

                    B[j+4*m+3][i+4*m] = tmp_4; // 1 miss
                    B[j+4*m+3][i+4*m+1] = tmp_6;
                    B[j+4*m+3][i+4*m+2] = tmp_2;
                    B[j+4*m+3][i+4*m+3] = tmp_1;
                }
            }else{
                /* Reverse Pattern*/
                /* 20 misses per block: 8 read,12 store without tmp */
                /* use tmp to decrease misses */
                /* 18 misses per block */

                for(n = 0;n < 4;n++){
                    for(m = 0;m < 4; m++){
                        B[j+4+m][i+n] = A[i+n][j+4+m];
                    }
                }
                tmp_1 = A[i][j];
                tmp_2 = A[i][j+1];
                tmp_3 = A[i][j+2];
                tmp_4 = A[i][j+3];
                tmp_5 = A[i+1][j];
                tmp_6 = A[i+1][j+1];
                tmp_7 = A[i+1][j+2];
                tmp_8 = A[i+1][j+3];
                for(n = 0;n < 4;n++){
                    for(m = 0;m < 4; m++){
                        B[j+4+m][i+4+n] = A[i+4+n][j+4+m];
                    }
                }
                for(n = 0;n < 4;n++){
                    for(m = 0;m < 4; m++){
                        B[j+m][i+7-n] = A[i+7-n][j+m];
                    }
                }
                for(n = 0;n < 2;n++){
                    for(m = 0;m < 4; m++){
                        B[j+m][i+3-n] = A[i+3-n][j+m];
                    }
                }
                B[j][i] = tmp_1;
                B[j+1][i] = tmp_2;
                B[j+2][i] = tmp_3;
                B[j+3][i] = tmp_4;
                B[j][i+1] = tmp_5;
                B[j+1][i+1] = tmp_6;
                B[j+2][i+1] = tmp_7;
                B[j+3][i+1] = tmp_8;
            }
        }
    }
}            
/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */

    //registerTransFunction(trans, trans_desc); 
    //registerTransFunction(Diagonal,Diagonal_Special); 
    //registerTransFunction(All_Special,Diagonal_Back_Special); 
    //registerTransFunction(Column_wise,Col_wise); 
}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
