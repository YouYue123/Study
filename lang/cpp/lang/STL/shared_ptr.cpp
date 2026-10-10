#include "control_block.cpp"
#include "weak_ptr.cpp"

template <typename T>
class MySharedPtr
{
public:
    // Default constructor
    MySharedPtr() noexcept : mControlBlock(nullptr) {}

    // Constructor with raw pointer
    explicit MySharedPtr(T *ptr) : mControlBlock(ptr ? new ControlBlock<T>(ptr) : nullptr) {}

    // Copy constructor
    MySharedPtr(const MySharedPtr &other) noexcept : mControlBlock(other.mControlBlock)
    {
        if (mControlBlock)
        {
            mControlBlock->incrementShared();
        }
    }

    // Move constructor
    MySharedPtr(MySharedPtr &&other) noexcept : mControlBlock(other.mControlBlock)
    {
        other.mControlBlock = nullptr;
    }

    // Constructor from MyWeakPtr
    explicit MySharedPtr(const MyWeakPtr<T> &weak);

    // Destructor
    ~MySharedPtr()
    {
        if (mControlBlock)
        {
            mControlBlock->decrementShared();
        }
    }

    // Copy assignment
    MySharedPtr &operator=(const MySharedPtr &other) noexcept
    {
        if (this != &other)
        {
            MySharedPtr(other).swap(*this);
        }
        return *this;
    }

    // Move assignment
    MySharedPtr &operator=(MySharedPtr &&other) noexcept
    {
        if (this != &other)
        {
            MySharedPtr(std::move(other)).swap(*this);
        }
        return *this;
    }

    // Modifiers
    void reset(T *ptr = nullptr)
    {
        MySharedPtr(ptr).swap(*this);
    }

    void swap(MySharedPtr &other) noexcept
    {
        std::swap(mControlBlock, other.mControlBlock);
    }

    // Observers
    T *get() const noexcept
    {
        return mControlBlock ? mControlBlock->get() : nullptr;
    }

    T &operator*() const
    {
        if (!mControlBlock || !mControlBlock->get())
        {
            throw std::runtime_error("Dereferencing null MySharedPtr");
        }
        return *mControlBlock->get();
    }

    T *operator->() const
    {
        if (!mControlBlock || !mControlBlock->get())
        {
            throw std::runtime_error("Accessing null MySharedPtr");
        }
        return mControlBlock->get();
    }

    size_t use_count() const noexcept
    {
        return mControlBlock ? mControlBlock->use_count() : 0;
    }

    bool unique() const noexcept
    {
        return use_count() == 1;
    }

    explicit operator bool() const noexcept
    {
        return get() != nullptr;
    }

    template <typename U>
    friend class MyWeakPtr;

private:
    ControlBlock<T> *mControlBlock;
};

// MySharedPtr constructor from MyWeakPtr
template <typename T>
MySharedPtr<T>::MySharedPtr(const MyWeakPtr<T> &weak) : mControlBlock(weak.mControlBlock)
{
    if (mControlBlock && mControlBlock->use_count() > 0)
    {
        mControlBlock->incrementShared();
    }
    else
    {
        mControlBlock = nullptr;
        throw std::bad_weak_ptr();
    }
}
