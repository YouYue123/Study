#include <iostream>
#include <utility>
#include <vector>

class MyString
{
public:
    // Constructor
    explicit MyString(const char *data)
    {
        if (data != nullptr)
        {
            _data = new char[strlen(data) + 1];
            strcpy(_data, data);
        }
        else
        {
            _data = new char[1];
            *_data = '\0';
        }

        std::cout << "built this object, address: " << this << std::endl;
    }

    // Destructor
    virtual ~MyString()
    {
        std::cout << "destruct this object, address: " << this << std::endl;
        delete[] _data;
    }

    // Copy constructor
    MyString(const MyString &str)
    {
        std::cout << "copy this object, address: " << this << std::endl;
        _data = new char[strlen(str._data) + 1];
        strcpy(_data, str._data);
    }

    // Move constructor
    MyString(MyString &&str) noexcept
        : _data(str._data)
    {
        std::cout << "move this object" << std::endl;
        str._data = nullptr; // Very important!
    }

    // Copy assignment
    MyString &operator=(const MyString &str)
    {
        if (this == &str) // 避免自我赋值!!
            return *this;

        delete[] _data;
        _data = new char[strlen(str._data) + 1];
        strcpy(_data, str._data);
        return *this;
    }

    // Move assignment
    MyString &operator=(MyString &&str) noexcept
    {
        if (this == &str) // 避免自我赋值!!
            return *this;

        delete[] _data;
        _data = str._data;
        str._data = nullptr; // 不再指向之前的资源了
        return *this;
    }

public:
    char *_data;
};