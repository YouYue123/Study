#include <memory>

template <typename T>
class MyUniquePtr
{
public:
    // Constructor
    explicit MyUniquePtr(T *ptr = nullptr) noexcept : mPtr(ptr) {}

    // Destructor
    ~MyUniquePtr()
    {
        reset();
    }

    // Move constructor
    MyUniquePtr(MyUniquePtr &&other) noexcept : mPtr(other.release()) {}

    // Move assignment operator
    MyUniquePtr &operator=(MyUniquePtr &&other) noexcept
    {
        reset(other.release());
        return *this;
    }

    // Reset the pointer
    void reset(T *ptr = nullptr) noexcept
    {
        if (mPtr != ptr)
        {
            delete mPtr;
            mPtr = ptr;
        }
    }

    // Release ownership
    T *release() noexcept
    {
        T *ptr = mPtr;
        mPtr = nullptr;
        return ptr;
    }

    // Get the raw pointer
    T *get() const noexcept { return mPtr; }

    // Swap with another unique pointer
    void swap(MyUniquePtr &other) noexcept
    {
        using std::swap;
        swap(mPtr, other.mPtr);
    }

    // Dereference operators
    T &operator*() const noexcept { return *mPtr; }
    // Arrow operator
    T *operator->() const noexcept { return mPtr; }

    // Boolean conversion
    explicit operator bool() const noexcept { return mPtr != nullptr; }

    // Deleted copy operations
    MyUniquePtr(const MyUniquePtr &) = delete;
    MyUniquePtr &operator=(const MyUniquePtr &) = delete;

private:
    T *mPtr;
};

// Non-member swap function
template <typename T>
void swap(MyUniquePtr<T> &lhs, MyUniquePtr<T> &rhs) noexcept
{
    lhs.swap(rhs);
}
// template <typename T, typename Deleter = std::default_delete<T>>
// class MyUniquePtr
// {
// public:
//     // 构造函数现在接受删除器
//     explicit MyUniquePtr(T *ptr = nullptr, Deleter deleter = Deleter())
//         : mPtr(ptr), mDeleter(std::move(deleter)) {}

//     ~MyUniquePtr()
//     {
//         if (mPtr)
//             mDeleter(mPtr);
//     }

// private:
//     T *mPtr;
//     Deleter mDeleter; // 存储删除器
// };