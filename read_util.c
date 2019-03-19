#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 1024


typedef struct imu_report
{
	int32_t m_time;
	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;
	int16_t accel_x;
	int16_t accel_y;
	int16_t accel_z;
}imu_report_t;



imu_report_t imu_acc = {0,0,0,0,0,0,0};

//读取本地文件数据 
char *ReadData(FILE *fp, char *buf)
{
	return fgets(buf, LINE, fp);
}	

int* get_fork_acc(int *move_data,char * buf){        
    int data_i = 0; 
    char *ptr; 
    ptr = strtok(buf, ",");	
    for (;data_i<7;data_i++) {
      sscanf(ptr,"%d",&move_data[data_i]);
      ptr = strtok(NULL, ",");
    }
    return move_data;
}

int main()
{	
	FILE *fp;
	char *buf, *p;	
	char filename[] = "F_03.txt";
	int i = 1;
	int a_acc[7];
    int *q_acc;
	
	buf=(char*)malloc(LINE*sizeof(char));
	fp=fopen(filename, "r");   

	while(1) 
	{
		p=ReadData(fp, buf);//每次调用文件指针fp会自动后移一行
	
		if(!p)//文件读取结束则跳出循环
		{
			break;
		}

    
		q_acc = get_fork_acc(a_acc,buf);
		printf("%d\n", q_acc[0]);
	}
	return 0;
}
