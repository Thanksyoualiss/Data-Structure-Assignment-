#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class arrayList {
private:
    int* arr;      // Pointer to the array
    int size;      // Current size of the array
    int capacity;  // Maximum capacity of the array

public:
    // Constructor
    arrayList(int cap = 5) {
        size = 0;
        capacity = cap;
        arr = new int[capacity];  // Dynamically allocate memory
    }

    // Destructor
    ~arrayList() {
        delete[] arr;
    }

    // Function to add an element to the array
    void add(int element) {
        // Check if array is full
        if (size == capacity) {
            resize();  // Resize array if full
        }
        arr[size++] = element;  // Add element and increase size
    }

    // Resize function to increase the array size
    void resize() {
        capacity *= 2;  // Double the capacity
        int* newArr = new int[capacity];  // Create a new array with larger capacity

        // Copy old elements to new array
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;  // Delete old array
        arr = newArr;  // Point to new array
    }

    // Function to remove an element by value
    void remove(int element) {
        int index = -1;
        // Find the index of the element
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                index = i;
                break;
            }
        }

        // If element is found, remove it
        if (index != -1) {
            // Shift elements to the left
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;  // Decrease size after removing
        } else {
            std::cout << "Element not found in the array." << std::endl;
        }
    }

    // Function to display array elements
    void display() const {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // ARRAY_H
