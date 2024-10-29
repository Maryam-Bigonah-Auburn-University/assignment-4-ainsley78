#include <iostream>
#include <iomanip>

using namespace std;

class Temperature {
    private:
        double degreesKelvin;
        double degreesCelsius;
        double degreesFahrenheit;

    public:
        // Mutator for Kelvin
        void setTempKelvin(double kelvin) {
            degreesKelvin = kelvin;
            degreesCelsius = kelvin - 273.15;
            degreesFahrenheit = (degreesCelsius * 9.0 / 5) + 32;
        }
        double getTempKelvin() { return degreesKelvin; }

        // Mutator for Celsius
        void setTempCelsius(double celsius) {
            degreesCelsius = celsius;
            degreesKelvin = celsius + 273.15;
            degreesFahrenheit = (celsius * 9.0 / 5) + 32;
        }
        double getTempCelsius() { return degreesCelsius; }

        // Mutator for Fahrenheit
        void setTempFahrenheit(double fahrenheit) {
            degreesFahrenheit = fahrenheit;
            degreesCelsius = (5.0 / 9) * (fahrenheit - 32);
            degreesKelvin = degreesCelsius + 273.15;
        }
        double getTempFahrenheit() { return degreesFahrenheit; }
};

int main() {
    Temperature temp;
    double kelvinInput;

    // Prompt user fortemperature in Kelvin
    cout << "Enter the temperature in degrees Kelvin: ";
    cin >> kelvinInput;

    // Set temperature in Kelvin
    temp.setTempKelvin(kelvinInput);

    // Display temperatures in Kelvin, Celsius, and Fahrenheit
    cout << fixed << setprecision(2);
    cout << "Temperature in Kelvin: " << temp.getTempKelvin() << " K\n";
    cout << "Temperature in Celsius: " << temp.getTempCelsius() << " °C\n";
    cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << " °F\n";

    return 0;
}

