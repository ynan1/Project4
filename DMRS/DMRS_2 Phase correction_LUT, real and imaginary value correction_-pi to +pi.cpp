#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>


int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';
    int* s = new int[15000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
    // integers using operator new[]. Our pointer s now points at the first
             // element in the array. tewt

    //int* k = new int[15000] {}; // we can use short int(2 byte) or int(4 byte).
    double* cr = new double[30000] {};
    double* crr = new double[30000] {};
    double* cri = new double[30000] {}; // real part of complex random no.
    float* ci = new float[30000] {};  // imaginary part of complex random no.
    double* S = new double[15000] {};
    //float* K = new float[15000] {};
    int J = 0;
    int R = 0;
    int* d = new int[15000] {};
    int Count;

   // std::cout << "The size of type float is: " << sizeof(float) << " byte(s)" << '\n';
   // std::cout << "The size of type double is: " << sizeof(double) << " byte(s)" << '\n';

    srand(time(0));         // intialising random variable each time program starts, else rand() will give
    // same value each time program is run.

    for (int i = 0; i < 100; i++)   // Arrays of 10,000 elements taken here.
    {
        s[i] = (rand() % (3142 - -3142)) + -3142; //values starting from 1 and goes upto 100. 
        //syntax:(rand() % (upper limit -lower limit)) + lower limit
        //k[i] = (rand() % (3142 - -3142)) + -3142;
    }
     std::cout << "\n \n Values of received 100 DMRS random Signal phases(in Radian) are:\n " << '\n'; // print
     for (int n = 0;n < 100;n++)
     {
         S[n] = s[n] / 1000.;
         std::cout << S[n] << "," << ' ';
     }
     std::cout << '\n';
   

    // std::cout << "\n \n Values of Ks are: " << '\n' ;

   // for (int p = 0;p < 100;p++)
   // {
    //    K[p] = k[p] / 1000.;
    //    std::cout << K[p] << "," << ' ';
    //}
    // LUT S1 is:

    const double  S1[100] = { 1.813, -2.271, -2.049, -1.714, 0.012, -1.104, -1.466, -3.022, -2.202, 2.521, 1.486, -0.189, 0.046, -2.301, 1.757, -0.45, 2.909, 2.494, -0.315, 1.236, 1.802, -0.353, -3.008, -1.789, 2.335, -2.636, -0.215, -0.397, 1.913, -1.199, -2.851, -2.066, 1.692, 0.576, 0.175, 1.209, -0.939, 2.758, -0.871, 2.429, 2.399, 0.76, -1.463, 0.567, 1.222, -1.413, 2.748, 0.276, 2.615, -1.408, 1.766, -0.691, 1.478, 2.717, 1.355, -2.688, 0.906, 1.914, -0.892, 1.761, -2.627, 1.737, 0.301, -1.278, -0.575, -0.246, -2.783, 0.184, 0.404, -3.108, -1.867, -0.324, 2.636, 2.782, -0.432, -0.038, -2.088, -0.801, 1.024, -0.707, 2.998, -2.87, 0.232, 1.262, -1.965, -0.118, -0.072, 1.156, -1.922, 2.807, -2.163, 3.122, -3.011, -3.088, -1.974, -0.559, -0.41, -2.112, -2.573, -1.422 };
    
    std::cout << "\n \n Values of Stored 100 DMRS Signal phases(From LUT)(in Radian) are:\n " << '\n';
    for (int n = 0;n < 100;n++)
    {
       
        std::cout << S1[n] << "," << ' ';
    }
    std::cout << '\n';
    
   


   // const float K1[100] = {3.009, -1.392, -1.412, -2.696, 0.192, 0.151, 0.934, 0.47, -3.12, -0.467, -3.086, -1.55, 2.773, -0.418, -2.373, 1.163, -2.57, -0.889, 2.323, 1.289, -0.71, -1.418, 1.451, 1.299, -0.385, 1.354, -1.827, -2.568, 1.098, -1.18, 0.751, 1.461, 1.297, -1.299, -2.503, 2.338, 2.621, -0.482, -2.698, -2.503, 2.172, -0.755, 2.447, 1.742, -0.86, 3.119, -1.473, -0.343, -3.122, 2.769, 1.881, 0.851, 0.987, -0.147, -0.19, 0.101, -2.289, 2.368, 0.365, 2.191, 1.061, 0.346, 1.392, 2.362, -1.448, -0.001, -2.643, -3.097, -2.002, -1.37, -1.677, -2.618, 0.284, -0.872, 2.761, -3.1, 0.043, 2.062, -1.301, 0.602, -2.851, 2.768, -2.312, 0.575, 1.541, -0.273, 2.397, -1.619, 1.282, 2.084, 2.084, 2.517, -2.868, -0.47, -2.234, 3.034, 2.584, -0.432, 0.49, -1.274

   // };
   // std::cout << "\n \n Values of K1s are: " << '\n';
  //  for (int n = 0;n < 100;n++)
   // {

   //     std::cout << K1[n] << "," << ' ';
   // }
   

    std::cout << "\n \n Values of 100 Compensation phases(in Radian), Compensation real values(Cos of Comp. phases) and Compensation imag. values(Sin of Comp. phases) are: \n" << '\n';  // real part of complex random no. matrix multiplication

    for (int r = 0; r < 10; r++)
    {

        for (int j = 0; j < 10; j++)
        {

           
            cr[r * 10 + j] = -(S[10 *r +  j ] - S1[10 * r +  j ]);

            crr[r * 10 + j] = cos( - (S[10 * r + j] - S1[10 * r + j]));

            cri[r * 10 + j] = sin( - (S[10 * r + j] - S1[10 * r + j]));

            std::cout <<"Phase: " << cr[r * 10 + j] << ' ';
            std::cout << "Real value: " << crr[r * 10 + j] << ' ';
            std::cout << "Imag. value: " << cri[r * 10 + j]  << "," << ' ';
        }

       

        //std::cout << cr[r * 100 + j] << ' ';

    }

    std::cout << '\n' << '\n';

    delete[] s;    // Clear memory/objects.
   // delete[] k;
    delete[] S;    // Clear memory/objects.
   // delete[] K;
    delete[] cr;    // Clear memory/objects.
    delete[] crr;
    delete[] cri;
    delete[] ci;
    delete[] d;    // Clear memory/objects.

}