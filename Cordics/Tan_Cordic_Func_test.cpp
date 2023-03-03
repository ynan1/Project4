// Tan cordic

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

// Smart pointer.

auto d = std::make_unique<int[] >(100000000);
auto k = std::make_unique<float[] >(100000000);

float tann(float test_angle)
{
	float cos_v = 0.;     // cos value
	float sin_v = 0.;      // sin value  
	float tan_v = 0;     // tan value
	float initial_x = .607197;
	float initial_y = 0.;
	float angle_radian = 0;

	float k[13] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.001953125, 0.0009765625, 0.000488281, 0.000244141 };   //typical cordic values
	float ph[13] = { 0.7854, 0.4636, 0.2450, 0.1244, 0.0624, 0.0312, 0.0156, 0.0078, 0.0039, 0.0020, 0.0010, 0.0005, 0.0002 };  // rotation angle in radian
	float angle_temp = 0; // angle in cordic calculations
	int i = 0;
	//int test_angle = 0;  // angles being tested for sin values in radian, increasing from minus two pi to plus two pi in step of 0.0001(see, line 32 - 34)
	while (test_angle > 6.2832)
	{
		test_angle = test_angle - 6.2832;
	}

	while (test_angle < -6.2832)
	{
		test_angle = test_angle + 6.2832;
	}

	angle_radian = test_angle;

	if (angle_radian > 3.1415)
	{
		angle_radian = (angle_radian - 6.2832);
	}
	else if (angle_radian < -3.1415)
	{
		angle_radian = (angle_radian + 6.2832);
	}

	if (angle_radian > 0 && angle_radian < 1.5708)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}
	else if (angle_radian < 0 && angle_radian > -1.5708)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}

	if (angle_radian > 1.5708)
	{
		angle_temp = -(3.1416 - angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}
	else if (angle_radian < -1.5708)
	{
		angle_temp = (3.1416 + angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}

	cos_v = cos_v - d[0] * sin_v * k[0];
	sin_v = sin_v + d[0] * cos_v * k[0];
	angle_temp = angle_temp - d[0] * ph[0];

	// Calculate

	for (int i = 1; i < 13; i++)

	{
		if (angle_temp >= 0)
		{
			d[i] = 1;
		}
		else {
			d[i] = -1;
		}

		float cos_v1 = 0.;
		cos_v = cos_v - d[i] * sin_v * k[i];
		cos_v1 = cos_v + d[i] * sin_v * k[i];
		sin_v = sin_v + d[i] * cos_v1 * k[i];

		angle_temp = angle_temp - d[i] * ph[i];

	}

	if (angle_radian > 1.5708 || angle_radian < -1.5708)
	{
		cos_v = -cos_v;
		sin_v = -sin_v;
	}

	if (angle_radian == 0. || angle_radian == 6.2832 || angle_radian == -0. || angle_radian == -6.2832) // IF ANGLE IS PLUS MINUS 0 OR 360
		// TAKE THE EXACT VALUES OF cos AND sin WITHOUT CALCULATING, THOUGH PROGRAM
	{                 //   IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		cos_v = 1.;   //THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 0/360
		sin_v = 0.;
	}

	if (angle_radian == 3.1416 || angle_radian == -3.1416) // IF ANGLE IS PLUS MINUS 180 
		// TAKE THE EXACT VALUES OF cos AND sin WITHOUT CALCULATING, THOUGH PROGRAM
	{                   // IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		cos_v = -1.;     // THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 180
		sin_v = 0.;
	}
	if (angle_radian == 1.5708 || angle_radian == -4.7124)
	{
		cos_v = 0;
		sin_v = 1;
	}

	if (angle_radian == -1.5708 || angle_radian == 4.7124)
	{
		cos_v = 0;
		sin_v = -1;
	}

	tan_v = sin_v / cos_v;

	return tan_v;

}


int main()
{
	float test_angle_fn = 0;

	//std::cout << "\n \n Please Enter the Angle in Radian and press enter: ";
	//std::cin >> radian_angle;
	for (int test_angle_fn = -100000; test_angle_fn < 100001; test_angle_fn++)
	{

		float test_angle_fn_fl = test_angle_fn / 10000.;

		float tan_v = tann(test_angle_fn_fl);

		float tan_v_real = tan(test_angle_fn_fl);

		float error_percentage = (abs(tan_v_real - tan_v)/tan_v_real) * 100;

		if (error_percentage > 5)
		{
			printf("Tan(%f%s) is = %f \n", test_angle_fn_fl, " radian", tan_v);
			printf("Error percent is more than 5 \n");
		}
		//else
		//{
		//	printf("Error is less than 0.00055 \n");
		//}
	}
}