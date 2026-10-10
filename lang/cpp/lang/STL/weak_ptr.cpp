#include "control_block.cpp";

template <typename T>
class MyWeakPtr
{
public:
    // Default constructor
    MyWeakPtr() noexcept : mControlBlock(nullptr) {}

    // Constructor from MySharedPtr
    MyWeakPtr(const MySharedPtr<T> &shared) noexcept : mControlBlock(shared.mControlBlock)
    {
        if (mControlBlock)
        {
            mControlBlock->incrementWeak();
        }
    }

    // Copy constructor
    MyWeakPtr(const MyWeakPtr &other) noexcept : mControlBlock(other.mControlBlock)
    {
        if (mControlBlock)
        {
            mControlBlock->incrementWeak();
        }
    }

    // Move constructor
    MyWeakPtr(MyWeakPtr &&other) noexcept : mControlBlock(other.mControlBlock)
    {
        other.mControlBlock = nullptr;
    }

    // Destructor
    ~MyWeakPtr()
    {
        if (mControlBlock)
        {
            mControlBlock->decrementWeak();
        }
    }

    // Assignment operators
    MyWeakPtr &operator=(const MyWeakPtr &other) noexcept
    {
        if (this != &other)
        {
            MyWeakPtr(other).swap(*this);
        }
        return *this;
    }

    MyWeakPtr &operator=(MyWeakPtr &&other) noexcept
    {
        if (this != &other)
        {
            MyWeakPtr(std::move(other)).swap(*this);
        }
        return *this;
    }

    MyWeakPtr &operator=(const MySharedPtr<T> &shared) noexcept
    {
        MyWeakPtr(shared).swap(*this);
        return *this;
    }

    // Convert to MySharedPtr
    MySharedPtr<T> lock() const noexcept
    {
        return mControlBlock && mControlBlock->use_count() > 0
                   ? MySharedPtr<T>(*this)
                   : MySharedPtr<T>();
    }

    // Observers
    size_t use_count() const noexcept
    {
        return mControlBlock ? mControlBlock->use_count() : 0;
    }

    bool expired() const noexcept
    {
        return use_count() == 0;
    }

    void reset() noexcept
    {
        MyWeakPtr().swap(*this);
    }

    void swap(MyWeakPtr &other) noexcept
    {
        std::swap(mControlBlock, other.mControlBlock);
    }

private:
    ControlBlock<T> *mControlBlock;

    friend class MySharedPtr<T>;
};

template <typename T>
void swap(MyWeakPtr<T> &lhs, MyWeakPtr<T> &rhs) noexcept
{
    lhs.swap(rhs);
}