#include <iostream>
#include <coroutine>
#include <exception>

struct ReturnValue
{
    struct promise_type
    {
        int value;
        ReturnValue get_return_object() { return ReturnValue{this}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_value(int v) { value = v; }
        void unhandled_exception() { std::terminate(); }
    };

    promise_type *promise;
    ReturnValue(promise_type *p) : promise(p) {}
    ~ReturnValue()
    {
        if (promise)
        {
            promise->~promise_type();
        }
    }

    int get() { return promise->value; }
};

ReturnValue computeValue()
{
    co_return 42;
}

int main()
{
    ReturnValue result = computeValue();
    std::cout << "Computed Value: " << result.get() << std::endl;
}