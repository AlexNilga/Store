
#ifndef STORE_STORE_EXCEPTION_H
#define STORE_STORE_EXCEPTION_H

#include<string>

using namespace std;

class StoreException : exception {
public:
    string m_message;

    explicit StoreException(string message) : m_message(std::move(message)) {};

    const char *what() const noexcept override {
        return m_message.c_str();
    }
};

#endif //STORE_STORE_EXCEPTION_H
