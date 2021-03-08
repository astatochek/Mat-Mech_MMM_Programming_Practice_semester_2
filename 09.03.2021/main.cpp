#include <iostream>
#include <vector>

using namespace std;

int Fibonacci(int n){
    vector <int> vec(n);
    vec[0] = 1;
    vec[1] = 1;
    for (int i = 2; i < n; i++) vec[i] = vec[i-1] + vec[i-2];
    return vec[n-1];
}

int main(){
    int a;
    cin >> a;
    a = Fibonacci(a);
    cout << a;

    return 0;
}