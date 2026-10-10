#include <iostream>
#include <array>
#include <string>
#include <thread>
#include <mutex>
#include <random>
#include <semaphore>
#include <syncstream>
#include <sstream>

template <std::size_t N = 10>
class CarPark
{
public:
    CarPark() : sem(N) {}

    int enter()
    {
        std::cout << "[" << std::this_thread::get_id() << "] Entering car park\n";

        // First acquire semaphore to limit total cars
        sem.acquire();

        // Then lock to modify parking spaces
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "[" << std::this_thread::get_id() << "] Entered car park\n";

        for (int i = 0; i < N; ++i)
        {
            if (spaces[i].empty())
            {
                std::stringstream ss;
                ss << std::this_thread::get_id();
                spaces[i] = ss.str();
                std::cout << "[" << std::this_thread::get_id() << "] Parked in space " << i << "\n";
                return i;
            }
        }

        // Should never reach here due to semaphore
        sem.release();
        throw std::runtime_error("No free spaces");
    }

    void do_something()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(rn(gen)));
    }

    void leave(int idx)
    {
        std::cout << "[" << std::this_thread::get_id() << "] Leaving car park\n";

        {
            std::lock_guard<std::mutex> lock(mtx);
            spaces[idx].clear();
            std::cout << "[" << std::this_thread::get_id() << "] Left car park\n";
        }

        sem.release();
    }

private:
    std::array<std::string, N> spaces;
    std::counting_semaphore<N> sem;
    std::mutex mtx;
    std::random_device rd; // Non-deterministic random number generator
    std::mt19937 gen;      // Standard mersenne_twister_engine
    std::uniform_int_distribution<> rn{500, 5000};
};

int main()
{
    const int NSpace = 10;
    const int NCars = 100;
    CarPark<NSpace> carpark;
    std::array<std::thread, NCars> threads;

    for (auto &t : threads)
    {
        t = std::thread([&carpark]()
                        {
            int idx = carpark.enter();
            carpark.do_something();
            carpark.leave(idx); });
    }

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "All cars have left the car park\n";
    std::cout << "Car park is empty\n";
    std::cin.get();
    return 0;
}