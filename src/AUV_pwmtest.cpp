#include "PCA9685.h"

#include <unistd.h>

#define I2C_BUS 1
#define AUV_PCA9685_ADDR 0x55

int main()
{
	PCA9685 pwmDriver(I2C_BUS, AUV_PCA9685_ADDR);
	
	pwmDriver.setPWMFreq(250);
	
	pwmDriver.setPWM(1, 0);
	
	sleep(5);
	
	pwmDriver.setPWM(1, (1400 / 4000.0) * 4095);
	
	sleep(5);
	
	pwmDriver.setPWM(1, 1700);
	
	sleep(5);
	
	pwmDriver.setPWM(1, 0);
}