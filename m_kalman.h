#ifndef _M_KALMAN_H_
#define _M_KALMAN_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct kalman_parameters
{
	  float q; //process noise covariance
	  float r; //measurement noise covariance
	  float x; //value
	  float p; //estimation error covariance
	  float k; //kalman gain
}kalman_paras_t;

void kalman_init(kalman_paras_t * kalman_paras);

float calman_predict(kalman_paras_t * kalman_paras);

float claman_update(kalman_paras_t * kalman_paras, float original_x, float Pminus);

float calman_filter(kalman_paras_t * kalman_paras,float original_x);

#endif
