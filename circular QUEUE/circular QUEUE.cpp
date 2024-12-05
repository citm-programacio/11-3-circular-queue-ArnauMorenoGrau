// circular QUEUE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>

using namespace std;

class CircularQueue {
public:
    CircularQueue(int capacity = 10) {
        _capacity = capacity;
        _array = new int[_capacity];
        _front = -1;
        _back = -1;
        _size = 0;
    }

    ~CircularQueue() {
        delete[] _array;
    }

    void enqueue(int value) {

        if (_back + 1 == _capacity) {
            resize();
        }
        _size++;
        if (_front == -1)
        {
            ++_front;
        }
        ++_back;
        _array[_back] = value;
    }

    int dequeue() {
        if (empty()) {
            cout << "la cola no puede vaciarse" << endl;
            return 0;
        }
        for (int i = 0; i <= _back; i++)
        {
            _array[i] = _array[i + 1];

        }
        _back--;
        _size--;
    }


    int size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }
    void printArray() {
        for (int i = 0; i < _capacity; ++i) {
            std::cout << _array[i] << " ";
            
        }
    }

    void print() const {
        if (empty()) {
            cout << "Queue is empty. Nothing to print.\n";
            return;
        }

        std::cout << "Queue elements: ";
        int index = _front;
        for (int i = 0; i < _size; ++i) {
            std::cout << _array[index] << " ";
            index++;
            if (index == _capacity) {
                index = 0;
            }
        }
        std::cout << std::endl;
    }

private:
    int _front;
    int _back;
    int* _array;
    int _capacity;
    int _size;


    void resize() {
        int newCapacity = _capacity + 1;// aqui he cambiado de *2 a +2 porque añadia espacios vacios de los necesarios 
        int* newArray = new int[newCapacity];


        int index = _front;
        for (int i = 0; i < _size; ++i) {
            newArray[i] = _array[index];
            index++;
            if (index == _capacity) {
                index = 0;
            }
        }


        delete[] _array;
        _array = newArray;
        _capacity = newCapacity;
        _front = 0;
        _back = _size - 1;
    }
};

int main() {
    CircularQueue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printArray();
    q.print();

    q.enqueue(40); // This triggers a resize
    q.printArray();
    q.print();

    q.dequeue();
    q.enqueue(50);
    q.printArray();
    q.print();

    return 0;
}
