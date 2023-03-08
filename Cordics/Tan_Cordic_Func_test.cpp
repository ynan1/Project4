// Tan cordic

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

// Smart pointer.

auto d = std::make_unique<int[] >(100000000);
auto k = std::make_unique<float[] >(100000000);

long double fn(long double test_angle)
{
	long double cos_v = 0.;     // cos value
	long double sin_v = 0.;      // sin value  
	long double tan_v = 0;     // tan value
	long double initial_x = .6072;
	long double initial_y = 0.;
	long double angle_radian = 0;

	long double k[13] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.001953125, 0.0009765625, 0.000488281, 0.000244141 };   //typical cordic values
	long double ph[13] = { 0.7853981633974483, 0.39269908169872415, 0.1963495408493621, 0.0981747704246810,0.0490873852123405, 0.0245436926061702, 0.0122718463030851, 0.0061359231515426, 0.0030679615757713, 0.0015339807878856, 0.0007669903939428, 0.0003834951969714, 0.0001917475984857 };  // rotation angle in radian
	long double angle_temp = 0; // angle in cordic calculations
	int i = 0;
	//int test_angle = 0;  // angles being tested for sin values in radian, increasing from minus two pi to plus two pi in step of 0.0001(see, line 32 - 34)
	while (test_angle > 6.2831853071795864)
	{
		test_angle = test_angle - 6.2831853071795864;
	}

	while (test_angle < -6.2831853071795864)
	{
		test_angle = test_angle + 6.2831853071795864;
	}

	angle_radian = test_angle;

	if (angle_radian > 3.1415926535897931)
	{
		angle_radian = (angle_radian - 6.2831853071795864);
	}
	else if (angle_radian < -3.1415926535897931)
	{
		angle_radian = (angle_radian + 6.2831853071795864);
	}

	if (angle_radian > 0 && angle_radian < 1.5707963267948966)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}
	else if (angle_radian < 0 && angle_radian > -1.5707963267948966)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}

	if (angle_radian > 1.5707963267948966)
	{
		angle_temp = -(3.1415926535897932 - angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}
	else if (angle_radian < -1.5707963267948966)
	{
		angle_temp = (3.1415926535897932 + angle_radian);
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

		long double cos_v1 = 0.;
		cos_v = cos_v - d[i] * sin_v * k[i];
		cos_v1 = cos_v + d[i] * sin_v * k[i];
		sin_v = sin_v + d[i] * cos_v1 * k[i];

		angle_temp = angle_temp - d[i] * ph[i];

	}

	if (angle_radian > 1.5707963267948966 || angle_radian < -1.5707963267948966)
	{
		cos_v = -cos_v;
		sin_v = -sin_v;
	}

	if (angle_radian == 0. || angle_radian == 6.2831853071795864 || angle_radian == -0. || angle_radian == -6.2831853071795864) // IF ANGLE IS PLUS MINUS 0 OR 360
		// TAKE THE EXACT VALUES OF cos AND sin WITHOUT CALCULATING, THOUGH PROGRAM
	{                 //   IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		cos_v = 1.;   //THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 0/360
		sin_v = 0.;
	}

	if (angle_radian == 3.1415926535897932 || angle_radian == -3.1415926535897932) // IF ANGLE IS PLUS MINUS 180 
		// TAKE THE EXACT VALUES OF cos AND sin WITHOUT CALCULATING, THOUGH PROGRAM
	{                   // IS CALCULATING THEM BUT OVERRIDE THOSE CALCULATED VALUES WITH EXACT VALUES
		cos_v = -1.;     // THIS IS DONE TO GET ACCURATE VALUES NEAR ANGLES 180
		sin_v = 0.;
	}
	if (angle_radian == 1.5707963267948966 || angle_radian == -4.7123889803846898)
	{
		cos_v = 0;
		sin_v = 1;
	}

	if (angle_radian == -1.5707963267948966 || angle_radian == 4.7123889803846898)
	{
		cos_v = 0;
		sin_v = -1;
	}

	//tan_v = sin_v / cos_v;

	return sin_v;

}


int main()
{
	long double test_angle_fn = 0;

	//std::cout << "\n \n Please Enter the Angle in Radian and press enter: ";
	//std::cin >> radian_angle;
	for (int test_angle_fn = -1000; test_angle_fn < 1001; test_angle_fn++)
	{

		long double test_angle_fn_fl = test_angle_fn / 100.;

		long double sin_v = fn(test_angle_fn_fl);

		long double sin_v_real = sin(test_angle_fn_fl);

		long double error_abs = abs(sin_v_real - sin_v);  // tan_v_real) * 100;

		if (error_abs > .0001)
		{
			printf("Sin(%f%s) is = %f, %f  \n", test_angle_fn_fl, " radian", sin_v, sin_v_real);
			printf("Error percent is more than 0.0001 \n");
		}
		//else
		//{
		//	printf("Error is less than 0.00055 \n");
		//}
	}
}