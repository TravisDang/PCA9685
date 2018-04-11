#include "PCA9685.h"

#include <unistd.h>
#include <thread>
#include <chrono>
#include <iostream>

#define I2C_BUS 1
#define AUV_PCA9685_ADDR 0x55

#define PORT1 15
#define PORT2 8
#define PORT3 9
#define PORT4 10
#define PORT5 11
#define PORT6 10
#define PORT7 9

#define CALIBRATION_POINT 1500

int main()
{
	PCA9685 pwmDriver1(I2C_BUS, AUV_PCA9685_ADDR);
	PCA9685 pwmDriver2(I2C_BUS, AUV_PCA9685_ADDR);
	PCA9685 pwmDriver3(I2C_BUS, AUV_PCA9685_ADDR);
	PCA9685 pwmDriver4(I2C_BUS, AUV_PCA9685_ADDR);
	PCA9685 pwmDriver5(I2C_BUS, AUV_PCA9685_ADDR);
	PCA9685 pwmDriver6(I2C_BUS, AUV_PCA9685_ADDR);
	PCA9685 pwmDriver7(I2C_BUS, AUV_PCA9685_ADDR);

	pwmDriver1.setPWMFreq(250);
	pwmDriver2.setPWMFreq(250);
	pwmDriver3.setPWMFreq(250);
	pwmDriver4.setPWMFreq(250);
	pwmDriver5.setPWMFreq(250);
	pwmDriver6.setPWMFreq(250);
	pwmDriver7.setPWMFreq(250);

	pwmDriver1.setPWM(PORT1, CALIBRATION_POINT);
	pwmDriver2.setPWM(PORT2, CALIBRATION_POINT);
	pwmDriver3.setPWM(PORT3, CALIBRATION_POINT);
	pwmDriver4.setPWM(PORT4, CALIBRATION_POINT);
	pwmDriver5.setPWM(PORT5, CALIBRATION_POINT);
	pwmDriver6.setPWM(PORT6, CALIBRATION_POINT);
	pwmDriver7.setPWM(PORT7, CALIBRATION_POINT);
	sleep(5)
	
	int i = 0, j = 100;

	for(i, j; i < 3; i++, j+=100){
		pwmDriver1.setPWM(PORT1, CALIBRATION_POINT + j);
		pwmDriver2.setPWM(PORT2, CALIBRATION_POINT + j);
		pwmDriver3.setPWM(PORT3, CALIBRATION_POINT + j);
		pwmDriver4.setPWM(PORT4, CALIBRATION_POINT + j);
		pwmDriver5.setPWM(PORT5, CALIBRATION_POINT + j);
		pwmDriver6.setPWM(PORT6, CALIBRATION_POINT + j);
		pwmDriver7.setPWM(PORT7, CALIBRATION_POINT + j);
		sleep(5);
	}
	
		for(i, j; i < 3; i--, j-=100){
		pwmDriver1.setPWM(PORT1, CALIBRATION_POINT + j);
		pwmDriver2.setPWM(PORT2, CALIBRATION_POINT + j);
		pwmDriver3.setPWM(PORT3, CALIBRATION_POINT + j);
		pwmDriver4.setPWM(PORT4, CALIBRATION_POINT + j);
		pwmDriver5.setPWM(PORT5, CALIBRATION_POINT + j);
		pwmDriver6.setPWM(PORT6, CALIBRATION_POINT + j);
		pwmDriver7.setPWM(PORT7, CALIBRATION_POINT + j);
		sleep(5);
	}

	
}
