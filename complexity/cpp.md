| C++ Benefit                  | What it gives you                         | Simple example                                |
| ---------------------------- | ----------------------------------------- | --------------------------------------------- |
| **Classes / OOP**            | Groups data + functions together          | `class Device { void start(); int status; };` |
| **Encapsulation**            | Controls access to data                   | `private: int status;`                        |
| **RAII** ⭐                   | Automatic resource cleanup                | `std::lock_guard<std::mutex> lock(mutex);`    |
| **Constructor / Destructor** | Automatically acquire/release resources   | `File()` → acquire, `~File()` → release       |
| **Function Overloading**     | Same function name for different types    | `print(int)`, `print(double)`                 |
| **Templates**                | Write generic code once                   | `template<typename T> T max(T a,T b)`         |
| **STL**                      | Ready-made containers & algorithms        | `std::vector`, `std::map`, `std::sort()`      |
| **Type Safety**              | More compile-time error checking          | `enum class State { IDLE, RUNNING };`         |
| **Polymorphism**             | Same interface, different implementations | `Network *n = new Ethernet(); n->connect();`  |
| **Namespaces**               | Avoid name conflicts                      | `Network::connect()` / `Database::connect()`  |
