
#ifndef STORE_STORE_EXCEPTION_H
#define STORE_STORE_EXCEPTION_H

#include<string>

using namespace std;

class StoreException {
public:
    string m_message;

    StoreException(const string &message) : m_message(message) {};

    string GetMessage() { return m_message; }
};


#endif //STORE_STORE_EXCEPTION_H
