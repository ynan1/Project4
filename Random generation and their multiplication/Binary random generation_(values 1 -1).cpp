#include <iostream>
#include <string>
#include<stdlib.h>
//#include<cstdlib>
#include <thread>
#include<time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// 38.211 3gpp word file

int main()
{
    std::cout << "Thread ID: " << std::thread::hardware_concurrency() << '\n';
    ios_base::sync_with_stdio(false);

    int* s = new int[15000] {}; // Here we allocate memory(object) space for hundred integers, an array of hundred
                              // integers using operator new[]. Our pointer s now points at the first
                                // element in the array. 

    int* k = new int[15000] {}; // we can use short int(2 byte) or int(4 byte).
    

   // std::cout << "The size of type float is: " << sizeof(float) << " byte(s)" << '\n';
    //std::cout << "The size of type double is: " << sizeof(double) << " byte(s)" << '\n';

    srand(time(0));     // intialising random variable each time program starts, else rand() will give
    //int r = srand(0);                  // same value each time program is run.
   // std::cout <<"Random initialisation value is: " << r;
    std::cout << '\n';
    int N = 2; 
    // Get starting timepoint
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)   // Arrays of 10,000 elements taken here.
    {
        // s[i] = (rand() % (2 - 0)) + 0;
        s[i] = rand() % N; //values starting from 0 and goes upto N. 
        k[i] = rand() % N;
    }

    // Get ending timepoint
    auto stop1 = high_resolution_clock::now();

    // Get duration. Substart timepoints to
   // get duration. To cast it to proper unit
   // use duration cast method
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    std::cout << "Time taken by function: "
        << duration1.count() << " microseconds" << endl;

    std::cout << "\n \n Values of Ss are: " << '\n'; // print

    auto start2 = high_resolution_clock::now();

    for (int n = 0;n < 10000;n++)
    {
        if(s[n] == 0)
        {
            s[n] = -1;
        }
        std::cout << s[n] << ' ';
    }
        auto stop2 = high_resolution_clock::now();

        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        std::cout << "\n \n Time taken by function: "
            << duration2.count() << " microseconds" << endl;

     
    std::cout << '\n';

    std::cout << "\n \n Values of Ks are: " << '\n';
    for (int p = 0;p < 10000;p++)
    {
        if (k[p] == 0)
        {
            k[p] = -1;
        }
       // ios_base::sync_with_stdio(false);
        std::cout << k[p] << ' ';
    }
    std::cout << '\n';

    //std::cout << "Total number of Cs in a row calculated = " << J << '\n';
    //std::cout << "Total number of row in C array calculated = " << R + 1 << '\n';}

    delete[] s;    // Clear memory/objects.
    delete[] k;
    return 0;
}