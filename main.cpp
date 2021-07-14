#include <iostream>
#include <cmath>

class Power {
    double num{1}, exp{1};
public:
    void set(double num, double exp) {
        this->num = num;
        this->exp = exp;
    }

    double calculate() const {
        return pow(this->num, this->exp);
    }
};

class RGBA {
    uint8_t m_red{0}, m_green{0}, m_blue{0}, m_alpha{255};
public:
    RGBA() = default;

    RGBA(uint8_t i_red, uint8_t i_green, uint8_t i_blue, uint8_t i_alpha) :
            m_red{i_red}, m_green{i_green}, m_blue{i_blue}, m_alpha{i_alpha} {}

    void print() const {
        std::cout << "red   = " << (int) m_red << std::endl;
        std::cout << "green = " << (int) m_green << std::endl;
        std::cout << "blue  = " << (int) m_blue << std::endl;
        std::cout << "alpha = " << (int) m_alpha << std::endl;
    }

};

class Stack {
    int arr[10]{0};
    int size{0};
public:
    void reset() {
        for (int &i : arr) {
            i = 0;
        }
        size = 0;
    }

    bool push(int num) {
        if (size >= 10) return false;
        arr[size] = num;
        ++size;
        return true;
    }

    int pop() {
        if (size == 0) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        int result = arr[size - 1];
        arr[size - 1] = 0;
        --size;
        return result;
    }

    void print() {
        std::cout << "(";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i];
            if(i != size - 1) std::cout << " ";
        }
        std::cout << ")" << std::endl;
    }
};


int main() {
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();


    return 0;
}
