
#ifndef STORE_STORE_EXCEPTION_H
#define STORE_STORE_EXCEPTION_H

#include<string>

using namespace std;

class StoreException : exception {
public:
    string m_message;

    explicit StoreException(string message) : m_message(std::move(message)) {};

    string GetMessage() const { return m_message; }
};


#endif //STORE_STORE_EXCEPTION_H
