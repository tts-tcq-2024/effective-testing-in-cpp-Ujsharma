#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms < 42) { // Adjusted to include boundary values
        sizeName = 'M';
    } else if(cms >= 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    // Test cases
    assert(size(37) == 'S');  // Should return 'S'
    assert(size(38) == 'M');  // Should return 'M'
    assert(size(40) == 'M');  // Should return 'M'
    assert(size(42) == 'L');  // Should return 'L'
    assert(size(43) == 'L');  // Should return 'L'
    
    // If all assertions pass, print success message
    std::cout << "All is well (maybe!)\n";
    return 0;
}
