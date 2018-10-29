//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
#define ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H

#include "iostream"
#include "variant"
namespace DATA {
    class payload {
    private:

        struct blob{
            blob(const char* values, int length):
                    arr{std::make_unique<char[]>(length)},
                size{length}
            {
                std::copy(values, values+length, arr.get());
            }

            std::unique_ptr<char[]> arr;
            int size;

            blob(const blob& other):
                arr{std::make_unique<char[]>(other.size)},
                size{other.size}
            {}


            blob& operator=(const blob& other) {
                if (this != &other) {
                    if (size != other.size) {
                        arr = std::make_unique<char[]>(other.size);
                        size = other.size;
                    }
                    std::copy(other.arr.get(), other.arr.get()+other.size, arr.get());
                }
                return *this;
            }

        };

        std::variant<double, bool, std::string, blob> m_value; //, m_flag, m_description;
//        std::unique_ptr<char[]> m_data;
    public:
        /* copy ctor for all types */
//        payload(const DATA::payload &o, const std::string &type);

        /* ctors for individual types */
        payload(const char data[],const int& size);
        explicit payload(const double& value);
        explicit payload(const bool& flag);
        explicit payload(const std::string& description);
        explicit payload(std::string&& description);

        /* overloaded copy  assignment operators */
//        payload& operator=(const DATA::payload &o);
//        payload& operator=(const char data[]);

        /* destructor */
        ~payload() = default;

        /* getters */
        const std::string&  get_description() const;
        const char* get_data() const;
        int get_size() const;
        double get_value() const;
        bool get_flag() const;
    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
