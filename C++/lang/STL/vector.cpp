#include <memory>
template <class T, class Allocator = std::allocator<T>>
class Vector
{
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef value_type const *const_pointer;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef value_type *iterator;

protected:
    typedef simple_alloc<value_type, Alloc> data_allocator;
    iterator start;
    iterator finish;
    iterator end_of_storage;
    void insert_aux(iterator position, const T &x);
    void deallocate()
    {
        if (start)
        {
            data_allocator::deallocate(start, end_of_storage - start);
        }
    }
    void fill_initialize(int n, const T &value)
    {
        start = data_allocator::allocate(n);
        finish = start + n;
        end_of_storage = finish;
    }

public:
    iterator begin() { return start; }
    iterator end() { return finish; }
    size_type size() const { return finish - start; }
    size_type capacity() const { return end_of_storage - start; }
    bool empty() const { return end() == begin(); }
    reference operator[](size_type n) { return *(begin() + n); }
    vector() : start(0), finish(0), end_of_storage(0) {}
    vector(int n, const T &value)
    {
        fill_initialize(n, value);
    }
    ~vector()
    {
        destroy(start, finish);
        deallocate();
    }
    void push_back(const T &x)
    {
        if (finish != end_of_storage)
        {
            construct(finish, x);
            ++finish;
        }
        else
        {
            insert_aux(end(), x);
        }
    }
    void pop_back()
    {
        --finish;
        destroy(finish);
    }
    void destroy(iterator first, iterator last)
    {
        for (; first < last; ++first)
        {
            first->~T();
        }
    }
    void construct(iterator position, const T &x)
    {
        new (position) T(x);
    }

private:
};