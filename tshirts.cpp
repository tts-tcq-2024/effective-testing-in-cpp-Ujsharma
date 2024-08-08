#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms < 42) { // Handle the case where cms == 38
        sizeName = 'M';
    } else if(cms >= 42) { // Changed from > 42 to >= 42
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'M'); // Added test for cms == 38
    assert(size(40) == 'M');
    assert(size(42) == 'L'); // Added test for cms == 42
    assert(size(43) == 'L');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
