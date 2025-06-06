#include <iostream>
#include <thread>
#include <string>
void myfunction(const std::string& param)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Executing function from a " << param << '\n'; //wrong results because of same
		                    //function and same class template std::cout being accessed by 2 threads.
	}
}
int main()
{
	std::thread t1{ myfunction, "Thread 1" };
	std::thread t2{ myfunction, "Thread 2" };
	t1.join();
	t2.join();
}