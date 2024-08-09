#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (celcius > 200) { // Simulating a failure for high temperatures
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        alertFailureCount += 1; // This should increment failure count, fixed bug
    }
}

void test_alertInCelcius() {
    alertFailureCount = 0;

    alertInCelcius(400.5);
    assert(alertFailureCount == 1); // This should pass now

    alertInCelcius(303.6);
    assert(alertFailureCount == 2); // This should pass now
}

int main() {
    test_alertInCelcius();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
