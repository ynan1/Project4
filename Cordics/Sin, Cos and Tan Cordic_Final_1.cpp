#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

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

	//float ph[11] = { 0.7853981633974483,0.4636476090008061,0.2449786631268641,0.1243549945467614,0.06241880999595735,0.03123983343026828, 0.01562372862047683, 0.007812341060101111, 0.003906230131966972, 0.001953122516478819, 0.0009765621895593195 };
	//float k[14] = { 1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	//float ph[14] = { 0.785398, 0.463648, 0.244979, 0.124355, 0.0624188, 0.0312398, 0.0156237, 0.00781234, 0.00390623, 0.00195312, 0.000976562, 0.000488281, 0.000244141 };
	float ph_temp = 0;
	float x_re = 0;
	float y_im = 0;
	int i;
	const double PI = 3.141592653589793238463;

	ios_base::sync_with_stdio(false);
	std::cout << "\n Please Enter the Angle in Degree and press enter: ";
	phase = 0.;
	std::cin >> phase;

	if (phase > 0 && phase > 180.)
	{
		phase = (phase - 360);
	}
	else if (phase < 0 && phase < -180.)
	{
		phase = (phase + 360);
	}

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

	//std::cout << ph_temp << ' ';

	for (int i = 1; i < 14; i++)   
	{
		k[i] = pow(2, -(i - 1));
		ph[i] = atan(k[i]);

		//std::cout << k[i] << "," << ' ';
		//std::cout << ph[i] << "," << ' ';
		//std::cout << "\n";
	}

	k[0] = 1.;
	x_re = x_re - d[0] * y_im * k[0];
	y_im = y_im + d[0] * x_re * k[0];
	ph_temp = ph_temp - d[0] * PI / 4;

	//std::cout << 1 << ' ';
	//std::cout << x_re << ' ';
	//std::cout << y_im << ' ';
	//std::cout << 180 * ph_temp / PI << ' ' << "\n";

	for (int i = 1; i < 13; i++)   // Arrays of 10,000 elements taken here.
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
			x_re = x_re - d[i] * y_im * k[i + 1];
			x_re1 = x_re + d[i] * y_im * k[i + 1];
			y_im = y_im + d[i] * x_re1 * k[i + 1];
			ph_temp = ph_temp - d[i] * ph[i + 1];

		}
		else {

			float x_re2 = 0.;
			x_re = x_re - d[i] * y_im * k[i + 1];
			x_re2 = x_re + d[i] * y_im * k[i + 1];
			y_im = y_im + d[i] * x_re2 * k[i + 1];
			ph_temp = ph_temp - d[i] * ph[i + 1];

		}

		//std::cout << "\n" << d[i] << ' ';
		//std::cout  << ph[i] << ' ';
		//std::cout << x_re << ' ';
		//std::cout << y_im << ' ';
		//std::cout << 180 * ph_temp / PI << ' ' << "\n";

		x_cal = x_re;
		y_cal = y_im;

	}

	if (phase > 90. || phase < -90)
	{
		x_cal = -x_cal;
		y_cal = -y_cal;
	}

	std::cout  << "\n Sin(" << phase <<") = " << y_cal << "\n Cos(" << phase << ") = " << x_cal << "\n Tan(" << phase <<") = " << (y_cal / x_cal);
	std::cout << '\n';

}