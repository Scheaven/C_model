#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "m_kalman.h"

float K = 0.0;
float Pminus = 0.0;
void kalman_init(kalman_paras_t * kalman_paras){
    kalman_paras->q = 1e-5;
    kalman_paras->r = 0.01;
    kalman_paras->p = 1.0;
    kalman_paras->x = 0.0; //x will hold the iterated filtered value
}

float calman_predict(kalman_paras_t * kalman_paras){
    Pminus = kalman_paras->p + kalman_paras->q;
    return Pminus;

}

float claman_update(kalman_paras_t * kalman_paras, float original_x, float Pminus){
    K = Pminus / (Pminus + kalman_paras->r);
    kalman_paras->x = kalman_paras->x + K * (original_x - kalman_paras->x);
    kalman_paras->p = (1 - K) * Pminus;
    return kalman_paras->x;
}

float calman_filter(kalman_paras_t * kalman_paras,float original_x){
    Pminus = calman_predict(kalman_paras);
    return claman_update(kalman_paras,original_x,Pminus);
}


