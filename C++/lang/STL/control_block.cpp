template <typename T>
class ControlBlock
{
public:
    explicit ControlBlock(T *ptr) : ptr(ptr), shared_count(1), weak_count(0) {}

    // Thread-safe reference counting
    void incrementShared()
    {
        // use memory_order_relaxed because we don't need to synchronize with other threads
        // when incrementing the shared count
        shared_count.fetch_add(1, std::memory_order_relaxed);
    }

    void decrementShared()
    {
        // use memory_order_acq_rel to ensure that the decrement is atomic and
        // that the memory is synchronized with other threads
        if (shared_count.fetch_sub(1, std::memory_order_acq_rel) == 1)
        {
            delete ptr;
            ptr = nullptr;
            // use memory_order_acquire to ensure that the weak count is synchronized
            // with other threads before checking it
            if (weak_count.load(std::memory_order_acquire) == 0)
            {
                delete this;
            }
        }
    }

    void incrementWeak()
    {
        weak_count.fetch_add(1, std::memory_order_relaxed);
    }

    void decrementWeak()
    {
        // use memory_order_acq_rel to ensure that the decrement is atomic and
        // that the memory is synchronized with other threads
        // before checking the shared count
        if (weak_count.fetch_sub(1, std::memory_order_acq_rel) == 1)
        {
            // use memory_order_acquire to ensure that the shared count is synchronized
            // with other threads before checking it
            if (shared_count.load(std::memory_order_acquire) == 0)
            {
                delete this;
            }
        }
    }

    T *get() const noexcept
    {
        return ptr;
    }

    size_t use_count() const noexcept
    {
        // use memory_order_relaxed because we don't need to synchronize with other threads
        // when getting the shared count
        return shared_count.load(std::memory_order_relaxed);
    }

private:
    T *ptr;
    std::atomic<size_t> shared_count;
    std::atomic<size_t> weak_count;
};
