#include <iostream>
#include <thread>
#include <string>

using namespace std;


// /* Threads are not secure. */
// class Singleton {
// private:
//     Singleton(string value):value_(value) {}
//     static Singleton* singleton_ ;
//     string value_;
// public:
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;
//     string value() const { return value_; }
//     static Singleton *GetInstance(const std::string& value)
//     {
//         if (singleton_ == nullptr) {
//             singleton_ = new Singleton(value);
//         }
//         return singleton_;
//     }
// };

// Singleton* Singleton::singleton_ = nullptr;

// void ThreadFoo(){
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     Singleton* singleton = Singleton::GetInstance("yangchao");
//     std::cout << singleton->value() << "\n";
// }

// void ThreadBar(){
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     Singleton* singleton = Singleton::GetInstance("zhouqian");
//     std::cout << singleton->value() << "\n";
// }

/* Threads are secure */
class Singleton {
private:
    Singleton(string value):value_(value) {}
    string value_;
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    string value() const { return value_; }
    static Singleton &GetInstance(const std::string& value)
    {
        static Singleton singleton_(value);
        return singleton_;
    }
};

void ThreadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton& singleton = Singleton::GetInstance("yangchao");
    std::cout << singleton.value() << "\n";
}

void ThreadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton& singleton = Singleton::GetInstance("zhouqian");
    std::cout << singleton.value() << "\n";
}

int main()
{
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
    return 0;
}