// Calculate the value of pi using a sequential approach in C++

#include <chrono>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv)
{
	size_t num_steps = 1000000;
	if (argc > 1) {
		num_steps = stoul(argv[1]);
	}

	cout << "Calculating pi in " << num_steps << " steps..." << endl;

	auto start = chrono::steady_clock::now();

	double total = 0.0;
	for (size_t i = 0; i < num_steps; ++i) {
		double x = (i + 0.5) / num_steps;
		total += 4.0 / (1.0 + x * x);
	}
	total /= num_steps;

	auto finish = chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::duration<double>>(finish - start);

	cout.precision(17);
	cout << "==> pi = " << total << "\n";
	cout.precision(6);
	cout << "Calculation took " << duration.count() << " seconds." << endl;

	return 0;
}
