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
	float initial_x = .6072;
	float initial_y = 0.;
	//float test_angle = 0;
	float angle_radian = 0;

	float k[33] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.001953125, 0.0009765625, 0.000488281, 0.000244141, 0.0001220705, 0.00006103525, 0.000030517625, 0.0000152588125, 7.62941e-06, 3.8147e-06, 1.90735e-06, 9.53676e-07, 4.76838e-07, 2.38419e-07, 1.19209e-07, 5.96047e-08, 2.98024e-08, 1.49012e-08, 7.45059e-09, 3.7253e-09, 1.86265e-09, 9.31324e-10, 4.65662e-10, 2.32831e-10 };   //typical cordic values
	float ph[33] = { 0.7854, 0.4636, 0.2450, 0.1244, 0.0624, 0.0312, 0.0156, 0.0078, 0.0039, 0.00195, 0.000975, 0.0004875, 0.00024375, 0.000121875, 0.0000609375, 0.00003046875, 0.000015234375, 7.61719e-06, 3.80859e-06, 1.9043e-06, 9.52148e-07, 4.76074e-07, 2.38037e-07, 1.19019e-07, 5.95093e-08, 2.97546e-08, 1.48773e-08, 7.43866e-09, 3.71933e-09, 1.85966e-09, 9.29832e-10, 4.64916e-10, 2.32458e-10 };  // rotation angle in radian
	float angle_temp = 0.; // angle in cordic calculations
	int i = 0;
	//int test_angle = 0;  // angles being tested for sin values in radian, increasing from minus two pi to plus two pi in step of 0.0001(see, line 32 - 34)
	while (test_angle > 6.28318)
	{
		test_angle = test_angle - 6.28318;
	}

	while (test_angle < -6.28318)
	{
		test_angle = test_angle + 6.28318;
	}

	angle_radian = test_angle;

	if (angle_radian > 3.14159)
	{
		angle_radian = (angle_radian - 6.28318);
	}
	else if (angle_radian < -3.14159)
	{
		angle_radian = (angle_radian + 6.28318);
	}

	if (angle_radian > 0 && angle_radian < 1.570795)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}
	else if (angle_radian < 0 && angle_radian > -1.570795)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}

	if (angle_radian > 1.570795)
	{
		angle_temp = -(3.14159 - angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}
	else if (angle_radian < -1.570795)
	{
		angle_temp = (3.14159 + angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}

	cos_v = cos_v - d[0] * sin_v * k[0];
	sin_v = sin_v + d[0] * cos_v * k[0];
	angle_temp = angle_temp - d[0] * ph[0];


	// Calculate

	for (int i = 1; i < 33; i++)

	{
		if (angle_temp > 0)
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


	if (angle_radian > 1.570795 || angle_radian < -1.570795)
	{
		cos_v = -cos_v;
		sin_v = -sin_v;
	}

	if (angle_radian == 0. || angle_radian == 6.283180) // IF ANGLE IS PLUS MINUS 0 OR 360
		// TAKE THE EXACT VALUES OF cos AND sin WITHOUT CALCULATING, THOUGH PROGRAM
	{                 //   IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		cos_v = 1.;   //THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 0/360
		sin_v = 0.;
	}
	if (angle_radian == -0. || angle_radian == -6.283180) // IF ANGLE IS PLUS MINUS 0 OR 360
		// TAKE THE EXACT VALUES OF cos AND sin WITHOUT CALCULATING, THOUGH PROGRAM
	{                 //   IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		cos_v = 1.;   //THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 0/360
		sin_v = 0.;
	}
	
	if (angle_radian == 3.141590 || angle_radian == -3.141590);
	{
		cos_v = -1.;
		sin_v = 0.;
	}

	if (angle_radian == 1.570795 || angle_radian == -4.712385)
	{
		cos_v = 0.;
		sin_v = 1.;
	}

	if (angle_radian == -1.570795 || angle_radian == 4.712385)
	{
		cos_v = 0.;
		sin_v = -1.;
	}

	tan_v = sin_v / cos_v;

	return sin_v;

}


int main()
{
	float test_angle_fn = 0;

	//std::cout << "\n \n Please Enter the Angle in Radian and press enter: ";
	//std::cin >> radian_angle;
	for (int test_angle_fn = -1000000; test_angle_fn < 1000001; test_angle_fn++)
	{

		float test_angle_fn_fl = test_angle_fn / 100000.;

		float sin_v = tann(test_angle_fn_fl);

		float sin_v_real = sin(test_angle_fn_fl);

		float error_percent = (abs(sin_v_real - sin_v)/ sin_v_real) * 100;

		if (error_percent > 1)
		{
			printf("Error is more than 100 percent \n");
			printf("Sin(%f%s) is = %f  %f \n", test_angle_fn_fl, " radian", sin_v, sin_v_real);
		}
		//else
		//{
		//	printf("Error is less than 0.00055 \n");
		//}
	}
}