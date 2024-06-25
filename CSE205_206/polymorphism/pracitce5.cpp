/*
Create a class Temperature with overloaded methods convert. One method should
convert Celsius to Fahrenheit and return an integer, another should convert Celsius to
Kelvin and return a double.
*/

#include <bits/stdc++.h>
using namespace std;

class Temperature {
    public:
    int celcius_to_fahrenheit(int celsius) {
        return (celsius * 9/5) + 32;
    }
    int celcius_to_fahrenheit(float celsius) {
        return (celsius * 9/5) + 32;
    }

    double celcius_to_kelvin(int celsius) {
        return celsius + 273.15;
    }
    double celcius_to_kelvin(float celsius) {
        return celsius + 273.15;
    }
};

int main() {
    Temperature t;
    cout << "Celsius to Fahrenheit: " << t.celcius_to_fahrenheit(100) << endl;
    cout << "Celsius to Kelvin: " << t.celcius_to_kelvin(100) << endl;
    return 0;
}