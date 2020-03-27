// Calculate the value of pi using threads in C++

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;


void thread_function(size_t begin, size_t end, size_t num_steps, double& subtotal)
{
	subtotal = 0.0;
	for (size_t i = begin; i < end; ++i) {
		double x = (i + 0.5) / num_steps;
		subtotal += 4.0 / (1.0 + x * x);
	}
	subtotal /= num_steps;
}

int main(int argc, char **argv)
{
	unsigned int num_threads = thread::hardware_concurrency();
	size_t num_steps = 1000000;
	if (argc > 2) {
		num_threads = stoul(argv[2]);
	}
	if (argc > 1) {
		num_steps = stoul(argv[1]);
	}

	cout << "Calculating pi using " << num_threads << " threads in " << num_steps << " steps..." << endl;

	auto start = chrono::steady_clock::now();

	vector<thread> threads;
	vector<double> subtotals = vector<double>(num_threads, 0.0);
	size_t begin, end = 0;
	for (unsigned int i = 0; i < num_threads; ++i) {
		begin = end;
		end = (i + 1) * num_steps / num_threads;
		threads.push_back(thread(thread_function, begin, end, num_steps, ref(subtotals[i])));
	}

	double total = 0.0;
	for (unsigned int i = 0; i < num_threads; ++i) {
		threads[i].join();
		total += subtotals[i];
	}

	auto finish = chrono::steady_clock::now();
	chrono::duration<double> duration = finish - start;

	cout.precision(17);
	cout << "==> pi = " << total << "\n";
	cout.precision(6);
	cout << "Calculation took " << duration.count() << " seconds." << endl;

	return 0;
}
