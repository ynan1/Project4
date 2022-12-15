// Her only one thread will execute fully at a time then any of the threads can execute.
//Note: By lock unlock of std::cout we are NOT ensuring that first thread t1 will run then only t2 
//executes. Any threads t1 or t2 can get executed here once fully and then then any threads can
// get executed that OS is deciding. Run and see that threads are getting executed one after another randomly.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m; // will guard std::cout
void function1(const std::string& param1)
{
	for (int i = 0; i < 10; i++)
	{
		m.lock();
		std::cout << "Executing function1." << param1 << '\n';
		m.unlock();
	}
}
void function2(const std::string& param2)
{
	for (int i = 0; i < 10; i++)
	{
		m.lock();
		std::cout << "Executing function2." << param2 << '\n';
		m.unlock();
	}
}
int main()
{
	std::thread t1{ function1,  "Hello World from a thread." }; // t1 gets executed later than t2
	std::thread t2{ function2, "Hello World from a thread." };  // Here t2 gets executed first and t1 later, run and see the result
	t1.join();
	t2.join();
}