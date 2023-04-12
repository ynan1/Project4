if (imag_x == 0 && real_x > 0)
{
	angle_cal = 0;
}

if (imag_x == 0 && real_x < 0)
{
	angle_cal = PI;
}

if (real_x == 0 && imag_x > 0)
{
	angle_cal = PI / 2;
}
if (real_x == 0 && imag_x < 0)
{
	angle_cal = -PI / 2;
}
