// Sin cordic

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

// Smart pointer.
auto d = std::make_unique<int[] >(100);

const double pi = 3.141592653589793238463;

//auto k = std::make_unique<double[] >(100000000);

double fn(double test_angle)
{
	double cos_v = 0.;
	double sin_v = 0.;
	double tan_v = 0;
	double initial_x = .6072;
	double initial_y = 0.;
	double angle_radian = 0;

	double k[61] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.00195312, 0.000976562, 0.000488281, 0.000244141, 0.00012207, 6.10352e-05, 3.05176e-05, 1.52588e-05, 7.62939e-06, 3.8147e-06, 1.90735e-06, 9.53674e-07, 4.76837e-07, 2.38419e-07, 1.19209e-07, 5.96046e-08, 2.98023e-08, 1.49012e-08, 7.45058e-09, 3.72529e-09, 1.86265e-09, 9.31323e-10, 4.65661e-10, 2.32831e-10, 1.16415e-10, 5.82077e-11, 2.91038e-11, 1.45519e-11, 7.27596e-12, 3.63798e-12, 1.81899e-12, 9.09495e-13, 4.54747e-13, 2.27374e-13, 1.13687e-13, 5.68434e-14, 2.84217e-14, 1.42109e-14, 7.10543e-15, 3.55271e-15, 1.77636e-15, 8.88178e-16, 4.44089e-16, 2.22045e-16, 1.11022e-16, 5.55112e-17, 2.77556e-17, 1.38778e-17, 6.93889e-18, 3.46945e-18, 1.73472e-18, 8.67362e-19 };   //typical cordic values
	double ph[61] = { 7.8539816339744830962e-01, 4.6364760900080611621e-01, 2.4497866312686415417e-01, 1.2435499454676143503e-01, 6.2418809995957348474e-02, 3.1239833430268276254e-02, 1.5623728620476830803e-02, 7.8123410601011112965e-03, 3.9062301319669718276e-03, 1.9531225164788186851e-03, 9.7656218955931943040e-04, 4.8828121119489827547e-04, 2.4414062014936176402e-04, 1.2207031189367020424e-04, 6.1035156174208775022e-05, 3.0517578115526096862e-05, 1.5258789061315762107e-05, 7.6293945311019702634e-06, 3.8146972656064962829e-06, 1.9073486328101870354e-06, 9.5367431640596087942e-07, 4.7683715820308885993e-07, 2.3841857910155798249e-07, 1.1920928955078068531e-07, 5.9604644775390554414e-08, 2.9802322387695303677e-08, 1.4901161193847655147e-08, 7.4505805969238279871e-09, 3.7252902984619140453e-09, 1.8626451492309570291e-09, 9.3132257461547851536e-10, 4.6566128730773925778e-10, 2.3283064365386962890e-10, 1.1641532182693481445e-10, 5.8207660913467407226e-11, 2.9103830456733703613e-11, 1.4551915228366851807e-11, 7.2759576141834259033e-12, 3.6379788070917129517e-12, 1.8189894035458564758e-12, 9.0949470177292823792e-13, 4.5474735088646411896e-13, 2.2737367544323205948e-13, 1.1368683772161602974e-13, 5.6843418860808014870e-14, 2.8421709430404007435e-14, 1.4210854715202003717e-14, 7.1054273576010018587e-15, 3.5527136788005009294e-15, 1.7763568394002504647e-15, 8.8817841970012523234e-16, 4.4408920985006261617e-16, 2.2204460492503130808e-16, 1.1102230246251565404e-16, 5.5511151231257827021e-17, 2.7755575615628913511e-17, 1.3877787807814456755e-17, 6.9388939039072283776e-18, 3.4694469519536141888e-18, 1.7347234759768070944e-18, 8.673617379884035472e-19 };
	double angle_temp = 0.;
	int i = 0;

	while (test_angle > 2 * pi)
	{
		test_angle = test_angle - 2 * pi;
	}

	while (test_angle < -2 * pi)
	{
		test_angle = test_angle + 2 * pi;
	}

	angle_radian = test_angle;

	if (angle_radian > pi)
	{
		angle_radian = (angle_radian - 2 * pi);
	}
	else if (angle_radian < -pi)
	{
		angle_radian = (angle_radian + 2 * pi);
	}

	if (angle_radian > 0 && angle_radian < 0.5 * pi)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}
	else if (angle_radian < 0 && angle_radian > -0.5 * pi)
	{
		angle_temp = angle_radian;
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}

	if (angle_radian > 0.5 * pi)
	{
		angle_temp = -(pi - angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = -1;
	}
	else if (angle_radian < -0.5 * pi)
	{
		angle_temp = (pi + angle_radian);
		cos_v = initial_x;
		sin_v = initial_y;
		d[0] = 1;
	}

	cos_v = cos_v - d[0] * sin_v * k[0];
	sin_v = sin_v + d[0] * cos_v * k[0];
	angle_temp = angle_temp - d[0] * ph[0];


	// Calculate cordic

	for (int i = 1; i < 32; i++)

	{
		if (angle_temp > 0)
		{
			d[i] = 1;
		}
		else {
			d[i] = -1;
		}

		double cos_v1 = 0.;
		cos_v = cos_v - d[i] * sin_v * k[i];
		cos_v1 = cos_v + d[i] * sin_v * k[i];
		sin_v = sin_v + d[i] * cos_v1 * k[i];

		angle_temp = angle_temp - d[i] * ph[i];

	}


	if (angle_radian > 0.5 * pi || angle_radian < -0.5 * pi)
	{
		cos_v = -cos_v;
		sin_v = -sin_v;
	}

	if (angle_radian == 0. || angle_radian == 2 * pi)
	{
		cos_v = 1.;
		sin_v = 0.;
	}

	if (angle_radian == -0. || angle_radian == -2 * pi)

	{
		cos_v = 1.;
		sin_v = 0.;
	}

	if (angle_radian == 0.5 * pi || angle_radian == -1.5 * pi)
	{
		cos_v = 0.;
		sin_v = 1.;
	}

	if (angle_radian == -0.5 * pi || angle_radian == 1.5 * pi)
	{
		cos_v = 0.;
		sin_v = -1.;
	}

	return sin_v;
}


int main()
{
	double test_angle_fn = 0;

	for (int m = 0;m < 5;m++)
	{
		srand(time(0));

		for (int n = 0;n < 10000; n++)
		{
			double test_angle_fn_fl = -2*pi* (((double)rand()) / RAND_MAX);

			double sin_v = fn(test_angle_fn_fl);

			double sin_v_real = sin(test_angle_fn_fl);

			double error_abs_sin = abs(sin_v_real - sin_v);

			if (error_abs_sin > 0.0001)

			{
				printf("Error is more than .0001, please see the values below: \n");
				printf("sin(%f %s) %s = %f   %s  %f   %s  %f \n", test_angle_fn_fl, " radian", "calculated", sin_v, "sin value real =", sin_v_real, "percent error = ", error_abs_sin);
			}
		}
	}

}