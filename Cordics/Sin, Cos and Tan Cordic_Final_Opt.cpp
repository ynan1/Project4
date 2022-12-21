
// This a Sin, Cos and Tan Calculator, optimised by LUTs using Smart Pointer. It does 12 iterations

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <mutex>

using namespace std;
using namespace std::chrono;
std::mutex m;

auto objects1 = std::make_unique<int[]>(14);
auto d = std::make_unique<int[] >(14);
auto objects2 = std::make_unique<float[]>(14);
auto k = std::make_unique<float[] >(14);
auto objects3 = std::make_unique<float[]>(14);
auto ph = std::make_unique<float[] >(14);

int main()
{
	float real_x = .6072;
	float imag_y = 0.;
	float phase;
	float x_cal = 0;
	float y_cal = 0;

	float k[14] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	float ph[14] = { 0.785398, 0.463648, 0.244979, 0.124355, 0.0624188, 0.0312398, 0.0156237, 0.00781234, 0.00390623, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	float ph_temp = 0;
	float x_re = 0;
	float y_im = 0;
	int i;
	int count;
	const double PI = 3.141592653589793238463;

	ios_base::sync_with_stdio(false);

	std::cout << "\n This is Sin, Cos and Tan Optimised Cordic Calculator ";
	std::cout << "\n \n Please Enter the Angle in Degree and press enter: ";
	phase = 0.;
	std::cin >> phase;

	auto start1 = high_resolution_clock::now();  // Start of Program

	if (phase > 0 && phase <= 90.)
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}
	else if (phase < 0 && phase >= -90.)
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = -1;
	}

	if (phase > 0 && phase > 90.)
	{
		ph_temp = -(PI - PI * phase / 180);
		x_re = real_x;
		y_im = imag_y;
		d[0] = -1;
	}
	else if (phase < 0 && phase < -90.)
	{
		ph_temp = (PI + PI * phase / 180);
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}

	if (phase > 0 && phase > 180.)
	{
		phase = (phase - 360);
	}
	else if (phase < 0 && phase < -180.)
	{
		phase = (phase + 360);
	}

	k[0] = 1.;
	x_re = x_re - d[0] * y_im * k[0];
	y_im = y_im + d[0] * x_re * k[0];
	ph_temp = ph_temp - d[0] * PI / 4;

	

	for (int i = 1; i < 13; i++)   
	{
		if (ph_temp >= 0)
		{
			d[i] = 1;
		}
		else {
			d[i] = -1;
		}

		if (y_im >= 0)
		{
			float x_re1 = 0.;
			x_re = x_re - d[i] * y_im * k[i];
			x_re1 = x_re + d[i] * y_im * k[i];
			y_im = y_im + d[i] * x_re1 * k[i];
			ph_temp = ph_temp - d[i] * ph[i];

		}
		else {

			float x_re2 = 0.;
			x_re = x_re - d[i] * y_im * k[i];
			x_re2 = x_re + d[i] * y_im * k[i];
			y_im = y_im + d[i] * x_re2 * k[i];
			ph_temp = ph_temp - d[i] * ph[i];

		}

		x_cal = x_re;
		y_cal = y_im;
		count = i;
	}



	if (phase > 90. || phase < -90)
	{
		x_cal = -x_cal;
		y_cal = -y_cal;
	}                       // End of Program

	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	std::cout << "\n Time taken by Full Program excluding std::cin and cout: "
		<< duration1.count() << " microseconds" << endl;



	std::cout << "\n Sin(" << phase << ") = " << y_cal << "\n Percentage Error in Sin, in " << count <<" iterations is: " << 100 * ((y_cal - sin(phase*PI/180))/ sin(phase * PI / 180)) <<" % " 
		<< "\n \n Cos(" << phase << ") = " << x_cal << "\n Percentage Error in Cos, in " << count << " iterations is: " << 100 * ((x_cal - cos(phase * PI / 180)) / cos(phase * PI / 180)) << " % "
		<< "\n \n Tan(" << phase << ") = " << (y_cal / x_cal) << "\n Percentage Error in Tan, in " << count << " iterations is: " << 100 * (((y_cal/x_cal) - tan(phase * PI / 180)) / tan(phase * PI / 180)) << " % ";
	
	std::cout << '\n';

}