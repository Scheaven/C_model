#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "m_utils.h"
#include "m_queue.h"


static int int_pow(int a){
        return (a * a);
}
static float float_pow(float a){
        return (a * a);
}


//calculate m
unsigned int cal_m(imu_report_t * imu_data)
{
        // printf("m value=%d\n", imu_data->gyro_x);
        int m2 = 0;
        unsigned int data_m;
        m2 = int_pow(imu_data->gyro_x)+int_pow(imu_data->gyro_y)+int_pow(imu_data->gyro_z);

        data_m = (int)sqrt((double)m2);
        return data_m;
}

//calculate mean(junzhi)
float get_mean(int *p_items){
        float mean;
        long sum=0;
        int j=0;
        for (j = 0; j < MAXSIZE; j++) {
                        sum+=p_items[j];
        }
        mean = sum/MAXSIZE;
        return mean;
}


//calculate the difference value
float get_diff(Queue* q){
    float diff = 0.0;
    int qitems[MAXSIZE];
    int *p_items;
    float mean;
    p_items = GetQueueItems(q,qitems);
    mean = get_mean(p_items);
    diff = p_items[MAXSIZE-1] - mean;
    return diff;
}

//calculate ay_means
float get_ay_means(Queue* q){
    float mean;
    int qitems[MAXSIZE];
    int *p_items;
    p_items = GetQueueItems(q,qitems);
    mean = get_mean(p_items);
    return mean;
}

//calculate fangcha
float get_variance(Queue* q)
{
        int qitems[MAXSIZE];
        int *p_items;
        float mean;
        p_items = GetQueueItems(q,qitems);
        mean = get_mean(p_items);
        float divisor,sum;
        int k;
        for(sum=k=0;k<MAXSIZE;k++){
                sum+=float_pow(p_items[k]-mean);
        }
        // printf("std********%f\n",sum/MAXSIZE);
        return sum/MAXSIZE;
}
