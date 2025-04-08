#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec_point;
    for (size_t i = 0; i < count; i++) {
        vec_point.emplace_back(std::make_shared<int>(i));
    }
    return vec_point;
}
void print(std::vector<std::shared_ptr<int>> vec) {
    for (auto it : vec) {
        std::cout << it.get() << std::endl;
    }
}
void add10(std::vector<std::shared_ptr<int>> vec) {
    for (auto it : vec) {
        if (it != nullptr)
            *it += 10;
    }
}
void sub10(int* const ptr) {
    if (ptr != nullptr)
        *ptr -= 10;
}
void sub10(std::vector<std::shared_ptr<int>> vec) {
    for (auto it : vec) {
        sub10(it.get());
    }
}
