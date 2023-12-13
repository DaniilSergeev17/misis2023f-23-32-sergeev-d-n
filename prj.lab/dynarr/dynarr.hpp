#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <sstream>

class DynArr {
private:
    std::ptrdiff_t size_ = 0;
    float data_ = 0;
public:
    DynArr() = default;
    DynArr(const DynArr&) = default;
    DynArr(const std::ptrdiff_t size) : size_(size) { }
    ~DynArr() = default;
    DynArr& operator=(const DynArr&) = default;

    bool operator==(const DynArr& other) const { // may work not properly, because of data_
        return data_ == other.data_;
    }

    bool operator!=(const DynArr& other) const { // may work not properly, because of data_
        return data_ != other.data_;
    }

    std::ptrdiff_t Size() const { 
        return size_; 
    }
    void Resize(const std::ptrdiff_t size) { 
        size_ = size; 
    }
    bool is_empty(const std::ptrdiff_t size) {
        return size_ == size;
    }
    float& operator[](const std::ptrdiff_t idx) { 
        return data_; 
    }
    const float& operator[](const std::ptrdiff_t idx) const { 
        return data_; 
    }
};

#endif
