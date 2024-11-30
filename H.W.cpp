#include <iostream>
using namespace std;


 long long factorialIterative(int n) {
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 0;
    }

     long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}


 long long factorialRecursive(int n) {
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1; 
    }
    return n * factorialRecursive(n - 1); 
}

int main() {
    
    int test[] = {0, 1, 5, 10, 15, 20, 25};
    int numCases = sizeof(test) / sizeof(test[0]);

    cout << "Testing factorial functions with various values of n:\n\n";
    cout << "n\tIterative\t\tRecursive\n";
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < numCases; ++i) {
        int n = test[i];
        unsigned long long resultIter = factorialIterative(n);
        unsigned long long resultRecur = factorialRecursive(n);
        cout << n << "\t" << resultIter << "\t\t" << resultRecur << endl;
    }

    
    cout << "\nTesting with larger values of n:\n";
    int largeValues[] = {30, 35, 40}; 
    numCases = sizeof(largeValues) / sizeof(largeValues[0]);

    for (int i = 0; i < numCases; ++i) {
        int n = largeValues[i];
        cout << "n = " << n << endl;
        try {
            cout << "Iterative: " << factorialIterative(n) << endl;
            cout << "Recursive: " << factorialRecursive(n) << endl; 
        } catch (...) {
            cout << "Recursive calculation failed due to stack overflow." << endl;
        }
        cout << "------------------------------------\n";
    }

    return 0;
}