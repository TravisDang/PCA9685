#include "PCA9685.h"

#include <unistd.h>
#include <thread>
#include <chrono>
#include <iostream>

#define I2C_BUS 1
#define AUV_PCA9685_ADDR 0x55

#define PORT 15

#define PORT2 8

#define PORT3 9

#define PORT4 10

#define PORT5 11

#define PORT6 10

#define PORT7 9
#define CALIBRATION_POINT 1550

int main()
{
	PCA9685 pwmDriver(I2C_BUS, AUV_PCA9685_ADDR);

	PCA9685 pwmDriver2(I2C_BUS, AUV_PCA9685_ADDR);

	PCA9685 pwmDriver3(I2C_BUS, AUV_PCA9685_ADDR);

	PCA9685 pwmDriver4(I2C_BUS, AUV_PCA9685_ADDR);

	PCA9685 pwmDriver5(I2C_BUS, AUV_PCA9685_ADDR);

	PCA9685 pwmDriver6(I2C_BUS, AUV_PCA9685_ADDR);

	PCA9685 pwmDriver7(I2C_BUS, AUV_PCA9685_ADDR);

	pwmDriver.setPWMFreq(250);
	pwmDriver2.setPWMFreq(250);
	pwmDriver3.setPWMFreq(250);
	pwmDriver4.setPWMFreq(250);
	/*pwmDriver5.setPWMFreq(250);
	pwmDriver6.setPWMFreq(250);
	pwmDriver7.setPWMFreq(250);*/

	pwmDriver.setPWM(PORT, 0);
	pwmDriver2.setPWM(PORT2, 0);
	pwmDriver3.setPWM(PORT3, 0);
	pwmDriver4.setPWM(PORT4, 0);
	/*pwmDriver5.setPWM(PORT5, 0);
	pwmDriver6.setPWM(PORT6, 0);
	pwmDriver7.setPWM(PORT7, 0);*/
	sleep(1);

/*
	pwmDriver.setPWM(PORT, (CALIBRATION_POINT / 4000.0) * 4095);

	sleep(1);
*/
	for(int power = CALIBRATION_POINT; power <= CALIBRATION_POINT + 70; ++power)
	{
		pwmDriver.setPWM(PORT, (power / 4000.0) * 4095);
		pwmDriver2.setPWM(PORT2, (power / 4000.0) * 4095);
		pwmDriver3.setPWM(PORT3, (power / 4000.0) * 4095);
		pwmDriver4.setPWM(PORT4, (power / 4000.0) * 4095);
		/*pwmDriver5.setPWM(PORT5, (power / 4000.0) * 4095);
		pwmDriver6.setPWM(PORT6, (power / 4000.0) * 4095);
		pwmDriver7.setPWM(PORT7, (power / 4000.0) * 4095);*/
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}

	for(int power = CALIBRATION_POINT; power >= CALIBRATION_POINT - 70; --power)
	{
		pwmDriver.setPWM(PORT, (power / 4000.0) * 4095);
		pwmDriver2.setPWM(PORT2, (power / 4000.0) * 4095);
		pwmDriver3.setPWM(PORT3, (power / 4000.0) * 4095);
		pwmDriver4.setPWM(PORT4, (power / 4000.0) * 4095);
		/*pwmDriver5.setPWM(PORT5, (power / 4000.0) * 4095);
		pwmDriver6.setPWM(PORT6, (power / 4000.0) * 4095);
		pwmDriver7.setPWM(PORT7, (power / 4000.0) * 4095);*/
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}

	std::cerr << "Calibration test done" << std::endl;

	pwmDriver.setPWM(PORT, (CALIBRATION_POINT / 4000.0) * 4095);
	pwmDriver2.setPWM(PORT2, (CALIBRATION_POINT / 4000.0) * 4095);
	pwmDriver3.setPWM(PORT3, (CALIBRATION_POINT / 4000.0) * 4095);
	pwmDriver4.setPWM(PORT4, (CALIBRATION_POINT / 4000.0) * 4095);
	/*pwmDriver5.setPWM(PORT5, (CALIBRATION_POINT / 4000.0) * 4095);
	pwmDriver6.setPWM(PORT6, (CALIBRATION_POINT / 4000.0) * 4095);
	pwmDriver7.setPWM(PORT7, (CALIBRATION_POINT / 4000.0) * 4095);*/

	sleep(1);	

	pwmDriver.setPWM(PORT, ((CALIBRATION_POINT + 50) / 4000.0) * 4095);
	pwmDriver2.setPWM(PORT2, ((CALIBRATION_POINT + 50) / 4000.0) * 4095);
	/*pwmDriver3.setPWM(PORT3, ((CALIBRATION_POINT - 50) / 4000.0) * 4095);
	pwmDriver4.setPWM(PORT4, ((CALIBRATION_POINT - 50) / 4000.0) * 4095);
	pwmDriver5.setPWM(PORT5, ((CALIBRATION_POINT - 50) / 4000.0) * 4095);
	pwmDriver6.setPWM(PORT6, ((CALIBRATION_POINT - 50) / 4000.0) * 4095);
	pwmDriver7.setPWM(PORT7, ((CALIBRATION_POINT - 50) / 4000.0) * 4095);*/
	
	
        pwmDriver3.setPWM(PORT3, ((CALIBRATION_POINT + 50) / 4000.0) * 4095);
        pwmDriver4.setPWM(PORT4, ((CALIBRATION_POINT + 50) / 4000.0) * 4095);
	
	sleep(20);

	pwmDriver.setPWM(PORT, 0);

	pwmDriver2.setPWM(PORT2, 0);

	pwmDriver3.setPWM(PORT3, 0);

	pwmDriver4.setPWM(PORT4, 0);

	pwmDriver5.setPWM(PORT5, 0);

	pwmDriver6.setPWM(PORT6, 0);

	pwmDriver7.setPWM(PORT7, 0);
}
