// This code calculates the real and imaginary values of channel parameter estimates 'h*' 
//by dividing the recieved real and imaginary(complex) bits by stored actual transmitted (true) 
//real and imaginary(complex) bits of the DMRS signals of 1,-1 type.

#include <iostream>
#include <string>
#include<stdlib.h>
#include <thread>
#include <math.h>


int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';
    int* sr = new int[15000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
    // integers using operator new[]. Our pointer s now points at the first
             // element in the array. tewt
    //int* SRR = new int[15000] {};
   // int* SIR = new int[15000] {};

    int* si = new int[15000] {}; // we can use short int(2 byte) or int(4 byte).
    double* cr = new double[30000] {};
    double* crr = new double[30000] {};
    double* cri = new double[30000] {}; // real part of complex random no.
    float* ci = new float[30000] {};  // imaginary part of complex random no.
    int CountR;
    int CountI ;
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
        sr[i] = (rand() % (2 - 0)) + 0; //values starting from 1 and goes upto 100. 
        //syntax:(rand() % (upper limit -lower limit)) + lower limit
        si[i] = (rand() % (2 - 0)) + 0;
    }
    std::cout << "Values of received signal's real bits are: \n" << '\n'; // print

    for (int n = 0;n < 100;n++)
    {
        if (sr[n] == 0)
        {
            sr[n] = -1;
        }
        std::cout << sr[n] << "," << ' ';
    }
    std::cout << '\n';

    std::cout << "\n \n Values of received signal's imaginary bits are: \n" << '\n';
    for (int p = 0;p < 100;p++)
    {
        if (si[p] == 0)
        {
            si[p] = -1;
        }
        std::cout << si[p] << "," << ' ';
    }
    std::cout << '\n';


    // LUT SRR and SIRs (Actual transmitted bits)is:

    const int  SRR[] = {1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, 1, -1, -1, 1, 1, 1, -1, 1, 1, 1};
    const int  SIR[] = {1, -1, -1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1, -1, -1, -1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, -1};
    
    std::cout << "\n \n 100 Real and Imaginary values of received signal's channel parameter estimates 'h' are: \n" << '\n';  // real part of complex random no. matrix multiplication

    for (int r = 0; r < 10; r++)
    {

        for (int j = 0; j < 10; j++)
        {

            crr[r * 10 + j] = ((sr[10 * r + j] * SRR[10 * r + j] + si[10 * r + j] * SIR[10 * r + j]))/2; // real values with which incoming signal is compensated

            cri[r * 10 + j] = ((sr[10 * r + j] * SIR[10 * r + j] - si[10 * r + j] * SRR[10 * r + j]))/2; // imaginary values with which incoming signal is compensated
            
           // std::cout << "Real h = " << crr[r * 10 + j] << ' ';
           // std::cout << "Imaginary h = " << cri[r * 10 + j] << "," << ' ';
        }

    }

    std::cout << "\nReal h = \n " ;
    for (int i = 0;i < 100;i++)
    {
        std::cout << crr[i] << ","  << ' ';

        CountR = i;
    }
    std::cout << '\n';
    std::cout << "CountR = " << CountR+1 << '\n';

    std::cout << "\nImaginary h = \n";

    for (int i = 0;i < 100;i++)
    {
        std::cout  << cri[i] << "," << ' ';
        CountI = i;
    }
    std::cout << '\n';
    std::cout << "CountI = " << CountI+1 << '\n';
    std::cout << '\n' << '\n';

    delete[] sr;    // Clear memory/objects.
     delete[] si;
    //delete[] CountR;    // Clear memory/objects.
    // delete[] CountI;
    delete[] cr;    // Clear memory/objects.
    delete[] crr;
    delete[] cri;
    delete[] ci;
    delete[] d;    // Clear memory/objects.

}