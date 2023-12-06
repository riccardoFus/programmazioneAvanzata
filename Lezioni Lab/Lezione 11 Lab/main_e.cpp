#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
using namespace std;

atomic<long> multiThreadSum(0);

void sumNumbers(const vector<int>& v, int start, int end){
    for(int i = start; i < end; i++){
        multiThreadSum += v[i];
    }
}

int main(int argc, char ** argv){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    return 0;
}