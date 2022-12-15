// We can spawn multiple threads in our program/process by constructing multiple std::thread objects.
// An example where we have two threads executing two different functions concurrently/simultaneously
// Here there is inter function simultaneous execution executing some part of func 1 and some part of func 2 etc.
// as they have same global  object std::cout being executed. Hence this is NOT a proper code in threads.

#include <iostream>
#include <thread>
#include <mutex>

//std::mutex m; // will guard std::cout
void function1(const std::string& param1)
{
	for (int i = 0; i < 10; i++)
	{
		//m.lock();
		std::cout << "Executing function1." << param1 << '\n';
		//m.unlock();
	}
}
void function2(const std::string& param2)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Executing function2." << param2 << '\n';
	}
}
int main()
{
	std::thread t1{ function1,  "Hello World from a thread." }; // t1 gets executed later than t2
	std::thread t2{ function2, "Hello World from a thread." };  // Here t2 gets executed first and t1 later, run and see the result
	t1.join();
	t2.join();
}