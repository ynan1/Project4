#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>
#include <memory>


int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';
    auto objects1 = std::make_unique<int[]>(20000);
    auto s = std::make_unique<int[] >(20000);
    auto objects2 = std::make_unique<int[]>(20000);
    auto k = std::make_unique<int[] >(20000);
    auto objects3 = std::make_unique<float[]>(20000);
    auto cr1 = std::make_unique<float[] >(20000);
    auto objects4 = std::make_unique<float[]>(20000);
    auto cr2 = std::make_unique<float[] >(20000);
    auto objects5 = std::make_unique<float[]>(20000);
    auto ci1 = std::make_unique<float[] >(20000);
    auto objects6 = std::make_unique<float[]>(20000);
    auto objects7 = std::make_unique<float[]>(20000);
    auto ci2 = std::make_unique<float[] >(20000);
    auto objects = std::make_unique<float[]>(20000);
    auto tcr1 = std::make_unique<float[] >(20000);
    auto objects8 = std::make_unique<int[]>(20000);
    auto tcr2 = std::make_unique<float[] >(20000);
    auto objects9 = std::make_unique<float[]>(20000);
    auto tci1 = std::make_unique<float[] >(20000);
    auto objects10 = std::make_unique<float[]>(20000);
    auto tci2 = std::make_unique<float[] >(20000);
    auto objects11 = std::make_unique<float[]>(20000);
    auto S = std::make_unique<float[] >(20000);
    auto objects12 = std::make_unique<float[]>(20000);
    auto K = std::make_unique<float[] >(20000);
    auto objects13 = std::make_unique<float[]>(20000);
    auto CR = std::make_unique<float[] >(20000);
    auto objects14 = std::make_unique<float[]>(20000);
    auto CI = std::make_unique<float[] >(20000);
    auto objects15 = std::make_unique<int[]>(20000);
    auto d = std::make_unique<int[] >(20000);

   
   // int* s = new int[20000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
                            // integers using operator new[]. Our pointer s now points at the first
                             // element in the array. 

    //int* k = new int[20000] {}; // we can use short int(2 byte) or int(4 byte).
   // float* cr1 = new float[20000] {};
   // float* cr2 = new float[20000] {};  // real part of complex random no.
   // float* ci1 = new float[20000] {};
   // float* ci2 = new float[20000] {};
  //  float* tcr1 = new float[20000] {};
   // float* tcr2 = new float[20000] {};
   // float* tci1 = new float[20000] {};
   // float* tci2 = new float[20000] {};
  //  float* CR = new float[20000] {};
  //  float* CI = new float[20000] {};// imaginary part of complex random no.
    //float* S = new float[20000] {};  //Here S and K are two complex numbers in cartesian co-ordinates.
   // float* K = new float[20000] {};
                                  // in which first 10000 values are real and next 10000 imaginary
    int J = 0;
    int R = 0;
   // int* d = new int[20000] {};
    int Count;

    std::cout << "The size of type float is: " << sizeof(float) << " byte(s)" << '\n';
    std::cout << "The size of type double is: " << sizeof(double) << " byte(s)" << '\n';

    srand(time(0));         // intialising random variable each time program starts, else rand() will give
    // same value each time program is run.

    for (int i = 0; i < 20000; i++)   // Arrays of 10,000 elements taken here.
    {
        s[i] = (rand() % (3000 - -3000)) + -3000; //values starting from 1 and goes upto 100. 
        //syntax:(rand() % (upper limit -lower limit)) + lower limit
        k[i] = (rand() % (3000 - -3000)) + -3000;
    }
    // std::cout << "Values of Ss are: " << '\n'; // print

    for (int n = 0;n < 20000;n++)
    {
        S[n] = s[n] / 1000.;
        // std::cout << S[n] << ' ';
    }
    std::cout << '\n';

    // std::cout << "Values of Ks are: " << '\n' << '\n';

    for (int p = 0;p < 20000;p++)
    {
        K[p] = k[p] / 1000.;
        //std::cout << K[p] << ' ';
    }
   // std::cout << "\n Values of first CRs(result of multiplication of 2 real values are) are: " << '\n';  // first real part of complex random no. matrix multiplication

    for (int r = 0; r < 100; r++)
    {

        for (int j = 0; j < 100; j++)
        {

            float tempr = 0;

            for (int m = 0; m < 100; m++)
            {

                tempr = tempr + (S[100 * r + m] * K[100 * j + m]);

            }

            cr1[r * 100 + j] = tempr;

            //std::cout << cr1[r * 100 + j] << ' ';

            J = j + 1;
        }

        R = r + 1;

    }

    std::cout << '\n' << '\n';
   // std::cout << "Values of second CRs(result of multiplication of 2 imag values are): " << '\n'; // imag. part of complex random no. matrix multiplication

    for (int r = 0; r < 100; r++)  // Second real part of complex no. multiplication.
    {

        for (int j = 0; j < 100; j++)
        {


            float tempi = 0;
            for (int m = 0; m < 100; m++)
            {

                tempi = -(tempi + (S[10000 + 100 * r + m] * K[10000 + 100 * j + m]));

            }

            cr2[r * 100 + j] = tempi;

            //std::cout << cr2[r * 100 + j] << ' ';
            //J = j + 1;
        }

        //R = r + 1;

    }
    std::cout << '\n' << '\n';
   // std::cout << "Values of first CRs truncated to 3 decimal points are: " << '\n'; //Truncation to 3 decimals
    for (int i = 0;i < R * J;i++)
    {

        if (cr1[i] > 0)
        {
            d[i] = (int)(cr1[i] * 1000 + .5);
        }
        else
        {
            d[i] = (int)(cr1[i] * 1000 - .5);
        }

        tcr1[i] = (float)d[i] / 1000;     // float values of CRs truncated to 3 decimal points.

        //std::cout << tcr1[i] << ' ';


    }
    std::cout << '\n' << '\n';
   // std::cout << "Values of second CRs truncated to 3 decimal points are: " << '\n'; //Truncation to 3 decimals

    for (int i = 0;i < R * J;i++)
    {

        if (cr2[i] > 0)
        {
            d[i] = (int)(cr2[i] * 1000 + .5);
        }
        else
        {
            d[i] = (int)(cr2[i] * 1000 - .5);
        }

        tcr2[i] = (float)d[i] / 1000;     // float values of CIs truncated to 3 decimal points.

        //std::cout << tcr2[i] << ' ';


    }
    std::cout << "\n \n Values of  CRs truncated to 3 decimal points are: " << '\n';
    for (int i = 0;i < R * J;i++)
    {
        CR[i] = tcr1[i] + tcr2[i];
        std::cout << CR[i] << ' ';
    }

    
    std::cout << '\n';

    //std::cout << "\n Values of first CIs(result of multiplication of 1 real 1 imag. values) are: " << '\n';  // first real part of complex random no. matrix multiplication

    for (int r = 0; r < 100; r++)
    {

        for (int j = 0; j < 100; j++)
        {

            float tempr = 0;

            for (int m = 0; m < 100; m++)
            {

                tempr = tempr + (S[100 * r + m] * K[10000 + 100 * j + m]);

            }

            ci1[r * 100 + j] = tempr;

            //std::cout << ci1[r * 100 + j] << ' ';

            J = j + 1;
        }

        R = r + 1;

    }

    std::cout << '\n' << '\n';
    //std::cout << "Values of second CIs(result of multiplication of 1 imag and 1 real values) are: " << '\n'; // imag. part of complex random no. matrix multiplication

    for (int r = 0; r < 100; r++)  // Second real part of complex no. multiplication.
    {

        for (int j = 0; j < 100; j++)
        {


            float tempi = 0;
            for (int m = 0; m < 100; m++)
            {

                tempi = tempi + (S[10000 + 100 * r + m] * K[100 * j + m]);

            }

            ci2[r * 100 + j] = tempi;

            //std::cout << ci2[r * 100 + j] << ' ';
            //J = j + 1;
        }

        //R = r + 1;

    }
    std::cout << '\n' << '\n';
    //std::cout << "\n Values of first CIs truncated to 3 decimal points are: " << '\n'; //Truncation to 3 decimals
    for (int i = 0;i < R * J;i++)
    {

        if (ci1[i] > 0)
        {
            d[i] = (int)(ci1[i] * 1000 + .5);
        }
        else
        {
            d[i] = (int)(ci1[i] * 1000 - .5);
        }

        tci1[i] = (float)d[i] / 1000;     // float values of CRs truncated to 3 decimal points.

        //std::cout << tci1[i] << ' ';


    }
    std::cout << '\n' << '\n';
   // std::cout << "Values of second CIs truncated to 3 decimal points are: " << '\n'; //Truncation to 3 decimals

    for (int i = 0;i < R * J;i++)
    {

        if (ci2[i] > 0)
        {
            d[i] = (int)(ci2[i] * 1000 + .5);
        }
        else
        {
            d[i] = (int)(ci2[i] * 1000 - .5);
        }

        tci2[i] = (float)d[i] / 1000;     // float values of CIs truncated to 3 decimal points.

        //std::cout << tci2[i] << ' ';


    }
    std::cout << "\n \n Values of  CIs truncated to 3 decimal points are: " << '\n';
    for (int i = 0;i < R * J;i++)
    {
        CI[i] = tci1[i] + tci2[i];
        std::cout << CI[i] << ' ';
    }


    std::cout << '\n';
    //delete[] s;    // Clear memory/objects.
   // delete[] k;
   // delete[] S;    // Clear memory/objects.
   // delete[] K;
   // delete[] cr1;    // Clear memory/objects.
   // delete[] ci1;
   // delete[] cr2;
   // delete[] ci2;
   // delete[] tcr1;
   // delete[] tci1;
   // delete[] tcr2;
   // delete[] tci2;
   // delete[] CR;
   // delete[] CI;
   // delete[] d;    // Clear memory/objects.


}