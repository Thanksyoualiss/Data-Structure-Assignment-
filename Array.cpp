#include "array.h"

int main() {
    arrayList array;

    // Add elements to the array
    array.add(10);
    array.add(20);
    array.add(30);
    array.add(40);
    array.add(50);
    array.add(60);  // This will trigger a resize

    // Display array elements
    std::cout << "Array after adding elements: ";
    array.display();

    // Remove an element
    array.remove(30);
    std::cout << "Array after removing 30: ";
    array.display();

    // Try removing an element not in the array
    array.remove(100);  // Element not present

    return 0;
}
