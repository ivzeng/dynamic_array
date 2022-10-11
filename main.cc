#include <chrono>

#include "dynamic_array.h"
#include "main.h"

using namespace std;
using namespace std::chrono;

int main() {
	runtimeTest();
	return 0;
}

// produces the execution time of the some sequence of operations
//	on DynamicArray and std::vector, with type int.
//	n: number of executions on the same operation, default 10^8
// 	type of options:
//		initializing an array of size n
//		pushing numbers from 1 to n to the array
//		reading an array of size n
//		writing an array of size n
void runtimeTest(int n) {
	auto start = high_resolution_clock::now();
	DynamicArray<int> da{n};
	auto end = high_resolution_clock::now();
	cout	<< "Time of initialization (DynamicArray):" 
			<< duration_cast<microseconds>(end - start).count() 
			<< " microseconds" << endl;

	start = high_resolution_clock::now();
	vector<int> vc(n, 0);
	end = high_resolution_clock::now();
	cout	<< "Time of initialization (vector):"
			<< duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;

	start = high_resolution_clock::now();
    da = DynamicArray<int> {1};
	for (int i = 1; i <= n; i += 1)
		da.push_back(i);
    end = high_resolution_clock::now();
    cout    << "Time of pushing numbers (DynamicArray):"
            << duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;

	start = high_resolution_clock::now();
    vc = vector<int> {};
	for (int i = 1; i <= n; i += 1)
		vc.push_back(i);
    end = high_resolution_clock::now();
    cout    << "Time of pushing numbers (vector):"
            << duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;

	start = high_resolution_clock::now();
    for (int i = 0; i < da.length(); i += 1){
		int k = da[i] + 1;
		k -= 1;
	}
    end = high_resolution_clock::now();
    cout    << "Time of read (DynamicArray):"
            << duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;

	start = high_resolution_clock::now();
    for (int i = 0; i < static_cast<int>(vc.size()); i += 1) {
        int k = vc[i] + 1;
		k -= 1;
	}
    end = high_resolution_clock::now();
    cout    << "Time of read (vector):"
            << duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;

	start = high_resolution_clock::now();
    for (int i = 0; i < da.length(); i += 1)
        da[i] = 0;
    end = high_resolution_clock::now();
    cout    << "Time of write (DynamicArray):"
            << duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;

	start = high_resolution_clock::now();
    for (int i = 0; i < static_cast<int>(vc.size()); i += 1)
       	vc[i] = 0;
    end = high_resolution_clock::now();
    cout    << "Time of write (vector):"
            << duration_cast<microseconds>(end - start).count()
            << " microseconds" << endl;
}
