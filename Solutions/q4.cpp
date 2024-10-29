#include <iostream>
#include <cstdlib> 
#include <cctype>  

using namespace std;

class Month {
public:
    // Default constructor
    Month() : mnth(1) {}

    // Constructor to set month based on the first 3 chars of the month name
    Month(char c1, char c2, char c3);

    // Constructor to set month based on month number (1 for January, etc.)
    Month(int monthNumber);

    // Input functions
    void getMonthByNumber(istream& in);
    void getMonthByName(istream& in);

    // Output functions
    void outputMonthNumber(ostream& out) const;
    void outputMonthName(ostream& out) const;

    // Function to get the next month as a Month object
    Month nextMonth();

    // Function to return the month number
    int monthNumber() const { return mnth; }

private:
    int mnth;
};

// Array to map month numbers to month names
const char* monthNames[12] = {
    "jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec"
};

// Constructor to set month based on first 3 chars of month name
Month::Month(char c1, char c2, char c3) {
    char input[4] = { static_cast<char>(tolower(c1)), static_cast<char>(tolower(c2)), static_cast<char>(tolower(c3)), '\0' };
    for (int i = 0; i < 12; i++) {
        if (string(input) == monthNames[i]) {
            mnth = i + 1;
            return;
        }
    }
    cout << "Invalid month name entered.\n";
    exit(1);
}

// Constructor to set month based on month number
Month::Month(int monthNumber) {
    if (monthNumber < 1 || monthNumber > 12) {
        cout << "Invalid month number.\n";
        exit(1);
    }
    mnth = monthNumber;
}

// Function to set month by number
void Month::getMonthByNumber(istream& in) {
    int monthNumber;
    in >> monthNumber;
    if (monthNumber < 1 || monthNumber > 12) {
        cout << "Invalid month number.\n";
        exit(1);
    }
    mnth = monthNumber;
}

// Function to set month by name
void Month::getMonthByName(istream& in) {
    char c1, c2, c3;
    in >> c1 >> c2 >> c3;
    *this = Month(c1, c2, c3);
}

// Function to display month as a number
void Month::outputMonthNumber(ostream& out) const {
    out << mnth;
}

// Function to display month as the first 3 letters
void Month::outputMonthName(ostream& out) const {
    out << monthNames[mnth - 1];
}

// Function to get the next month
Month Month::nextMonth() {
    int nextMonthNumber = (mnth % 12) + 1;
    return Month(nextMonthNumber);
}

// Test program for Month class
int main() {
    Month m1(3);  // March
    Month m2('J', 'u', 'n');  // June
    Month m3;  // Default month 

    cout << "Month m1 (using number): ";
    m1.outputMonthName(cout);
    cout << " ("; m1.outputMonthNumber(cout); cout << ")\n";

    cout << "Month m2 (using name): ";
    m2.outputMonthName(cout);
    cout << " ("; m2.outputMonthNumber(cout); cout << ")\n";

    cout << "Month m3 (default constructor): ";
    m3.outputMonthName(cout);
    cout << " ("; m3.outputMonthNumber(cout); cout << ")\n";

    // Test input functions
    cout << "\nEnter a month number (1-12): ";
    m3.getMonthByNumber(cin);
    cout << "You entered month: ";
    m3.outputMonthName(cout);
    cout << " ("; m3.outputMonthNumber(cout); cout << ")\n";

    cout << "\nEnter the first 3 letters of a month (e.g., Jan): ";
    m3.getMonthByName(cin);
    cout << "You entered month: ";
    m3.outputMonthName(cout);
    cout << " ("; m3.outputMonthNumber(cout); cout << ")\n";

    // Test next month function
    Month m4 = m3.nextMonth();
    cout << "\nThe month after ";
    m3.outputMonthName(cout);
    cout << " is ";
    m4.outputMonthName(cout);
    cout << ".\n";

    return 0;
}

