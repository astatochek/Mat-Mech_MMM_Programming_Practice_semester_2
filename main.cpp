#include <iostream>
#include <cmath>
using namespace std;

class Complex{
public:
    float re, im;

    Complex (float x, float y){
        re = x;
        im = y;
    };

    float module(){
        return pow(re*re + im*im, 0.5);
    };

    Complex conjugated(){
        return Complex(re, -im);
    };

    Complex &operator += (Complex &x){
        re += x.re;
        im += x.im;
        return * this;
    };

    Complex &operator -= (Complex &x){
        re -= x.re;
        im -= x.im;
        return * this;
    };

    Complex &operator *= (Complex &x){
        float new_re = re*x.re - im*x.im, new_im = re*x.im + x.re*im;
        re = new_re;
        im = new_im;
        return * this;
    };

    Complex &operator /= (Complex &x){
        float new_re = re*x.re + im*x.im, new_im = im*x.re - x.im*re;
        re = new_re / (x.re*x.re + x.im*x.im);
        re = new_im / (x.re*x.re + x.im*x.im);
        return * this;
    };

};

Complex &operator - (Complex x, Complex &y){
    return x -= y;
};

Complex &operator + (Complex x, Complex &y){
    return x += y;
};

Complex &operator * (Complex x, Complex &y){
    return x *= y;
};

Complex &operator / (Complex x, Complex &y){
    return x /= y;
};

ostream &operator << (ostream &out, Complex &x){
    if (x.im < 0) out << "(" << x.re << " - " << -x.im << " i" << ")";
    else if (x.re == x.im && x.im == 0) out << 0;
    else if (x.im == 0) out << x.re;
    else out << "(" << x.re << " + " << x.im << " i" << ")";
    return out;
};

bool Compare(Complex first, Complex second){
    return first.module() >= second.module();
};

int main() {

    Complex a(13.3, 4.0), b(16.1, -3.2);
    Complex difference = a-b, sum = a+b, product = a*b, quotient = a/b;
    Complex a_c = a.conjugated();

    cout << a << " - " << b << " = " << difference << "\n";
    cout << a << " + " << b << " = " << sum << "\n";
    cout << a << " * " << b << " = " << product << "\n";
    cout << a << " / " << b << " = " << quotient << "\n";
    cout << "module of a: " << a.module() << "\n";
    cout << "module of b: " << b.module() << "\n";
    cout << "a >= b: " << Compare(a, b) << "\n";
    cout <<"a: " << a << ", conjugated to a: " << a_c << "\n";
}
