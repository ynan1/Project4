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
auto objects2 = std::make_unique<double[]>(14);
auto k = std::make_unique<double[] >(14);
auto objects3 = std::make_unique<double[]>(14);
auto ph = std::make_unique<double[] >(14);

int main()
{
	double real_x = .6072;
	double imag_y = 0.;
	double phase;
	double x_cal = 0;
	double y_cal = 0;
	double ph_temp = 0;
	double x_re = 0;
	double y_im = 0;
	int i;
	const double PI = 3.141592653589793238463;

	ios_base::sync_with_stdio(false);
	std::cout << "\n Please Enter the Angle in Degree and press enter: ";
	phase = 0.;
	std::cin >> phase;

	auto start1 = high_resolution_clock::now();

	if (phase > 0 && phase <= 90.)
	{
		ph_temp = PI * phase / 180;
		x_re = real_x;
		y_im = imag_y;
		d[0] = 1;
	}
	else if(phase < 0 && phase >= -90.)
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
	else if(phase < 0 && phase < -90.)
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

	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	std::cout << "\n Time taken by phase selection function: "
		<< duration1.count() << " microseconds" << endl;

	auto start = high_resolution_clock::now();

	for (int i = 1; i < 14; i++)   
	{
		k[i] = pow(2, -(i - 1));
		//ph[i] = atan(k[i]);
		std::cout << k[i] << "," << ' ';
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "\n Time taken by k & ph Calculation function: "
		<< duration.count() << " microseconds" << endl;

	k[0] = 1.;
	x_re = x_re - d[0] * y_im * k[0];
	y_im = y_im + d[0] * x_re * k[0];
	ph_temp = ph_temp - d[0] * PI / 4;

	auto start2 = high_resolution_clock::now();

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
			double x_re1 = 0.;
			x_re = x_re - d[i] * y_im * k[i + 1];
			x_re1 = x_re + d[i] * y_im * k[i + 1];
			y_im = y_im + d[i] * x_re1 * k[i + 1];
			ph_temp = ph_temp - d[i] * ph[i + 1];

		}
		else {

			double x_re2 = 0.;
			x_re = x_re - d[i] * y_im * k[i + 1];
			x_re2 = x_re + d[i] * y_im * k[i + 1];
			y_im = y_im + d[i] * x_re2 * k[i + 1];
			ph_temp = ph_temp - d[i] * ph[i + 1];

		}

		x_cal = x_re;
		y_cal = y_im;

	}

	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);

	std::cout << "\n Time taken by Calculation function: "
		<< duration2.count() << " microseconds" << endl;

	if (phase > 90. || phase < -90)
	{
		x_cal = -x_cal;
		y_cal = -y_cal;
	}

	std::cout  << "\n Sin(" << phase <<") = " << y_cal << "\n Cos(" << phase << ") = " << x_cal << "\n Tan(" << phase <<") = " << (y_cal / x_cal);
	std::cout << '\n';

}