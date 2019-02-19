#ifndef _M_UTILS_H_
#define _M_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include "m_queue.h"
#include "m_utils.h"

typedef struct imu_report
{
	int32_t m_time;
	int16_t accel_x;
	int16_t accel_y;
	int16_t accel_z;
	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;
}imu_report_t;

unsigned int cal_m(imu_report_t * i_data);

float get_mean(int *p_items);

float get_diff(Queue* qs);

float get_ay_means(Queue* q);

float get_variance(Queue* q);

#endif
