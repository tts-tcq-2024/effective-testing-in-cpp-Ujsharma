#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S'; // Small
    } else if (cms >= 38 && cms < 42) {
        sizeName = 'M'; // Medium
    } else if (cms >= 42) {
        sizeName = 'L'; // Large
    }
    return sizeName;
}

int main() {
    // Test cases
    assert(size(37) == 'S');  // cms < 38, should be 'S'
    assert(size(38) == 'M');  // cms >= 38 and < 42, should be 'M'
    assert(size(40) == 'M');  // cms >= 38 and < 42, should be 'M'
    assert(size(42) == 'L');  // cms >= 42, should be 'L'
    assert(size(43) == 'L');  // cms >= 42, should be 'L'
    
    // If all assertions pass, print success message
    std::cout << "All is well (maybe!)\n";
    return 0;
}
