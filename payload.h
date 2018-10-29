#ifndef ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
#define ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H

#include "iostream"
#include "variant"
#include "iostream"

namespace saxion {
    class payload {
    private:
        struct blob {
            std::unique_ptr<char[]> arr;
            int size;

            blob(const char *values, int length) :
                    arr{std::make_unique<char[]>(static_cast<size_t>(length))},
                    size{length} {
                std::copy(values, values + length, arr.get());
            }

            blob(const blob &other) :
                    arr{std::make_unique<char[]>(static_cast<size_t>(other.size))},
                    size{other.size} {
                std::copy(other.arr.get(), other.arr.get() + size, arr.get());
            }

            blob &operator=(const blob &other) {
                if ((this != &other) && (size != other.size)) {
                    arr = std::make_unique<char[]>(static_cast<size_t>(other.size));
                    size = other.size;
                    std::copy(other.arr.get(), other.arr.get() + other.size, arr.get());
                }
                return *this;
            }
        };

        std::variant<double, bool, std::string, blob> m_value;
    public:
        explicit payload(const double &value);

        explicit payload(const bool &flag);

        explicit payload(const std::string &description);

        explicit payload(std::string &&description);

        payload(const char *data, int size);

        const std::string &get_description() const;

        const char *get_data() const;

        int get_size() const;

        double get_value() const;

        bool get_flag() const;
    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
