#include <iostream>

const int MAX_SIZE = 100;

template <typename T>
class CustomContainer {
private:
    T data[MAX_SIZE];
    int size;

public:
    CustomContainer() : size(0) {}

    void addElement(T value) {
        if (size < MAX_SIZE) {
            data[size] = value;
            size++;
        } else {
            std::cout << "Container is full. Cannot add more elements." << std::endl;
        }
    }

    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* start) : ptr(start) {}

        T& operator*() {
            return *ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }
        
        Iterator& operator--() {
            --ptr;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }
};

int main() {
    CustomContainer<int> container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    std::cout << "Elements in the container: ";
    for (CustomContainer<int>::Iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
