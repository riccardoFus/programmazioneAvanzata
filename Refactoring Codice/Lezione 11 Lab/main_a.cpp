#include <iostream>
using namespace std;

int main(int argc, char ** argv){
    auto lambda_expr_1 =  [](){
        return 5;
    };
    cout << lambda_expr_1() << endl;

    int a = 2;
    auto lambda_expr_2 = [a](){
        return a * 4;
    };
    cout << lambda_expr_2() << ", a = " << a << endl;

    auto lambda_expr_3 = [a]() mutable {
        a++; // non ha effetto sull'esterno
        return a * 4;
    };
    cout << lambda_expr_3() << ", a = " << a << endl;

    auto lambda_expr_4 = [&a](){
        a++;
        return a * 5;
    };
    cout << lambda_expr_4() << ", a = " << a << endl;

    auto lambda_expr_5 = [](int a, int b){
        return a * b;
    };
    cout << lambda_expr_5(5, 8) << endl;

    auto lambda_expr_6 = [](int& a){
        a++; // non dovrebbe modificare
        return a * 10;
    };
    cout << lambda_expr_6(a) << ", a = " << a << endl;

    auto lambda_expr_7 = [](int a, int b) -> bool {
        return a > b;
    };
    cout << lambda_expr_7(5, 10) << endl;

    return 0;
}