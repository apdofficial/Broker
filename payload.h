//
// Created by Andrej Pistek on 18/10/2018.
//

#ifndef ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
#define ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H

#include "iostream"
#include "variant"
#include <cstddef>
#include <memory>
#include <algorithm>
namespace DATA {
    class payload {
    private:
        std::variant<double, bool, std::string> m_value, m_flag, m_description;
        int m_size;
        std::unique_ptr<char[]> m_data;
    public:

        payload(const char data[],const int& size);

        explicit payload(const double &value);

        explicit payload(const bool &flag);

        explicit payload(const std::string &description);

        payload(const DATA::payload &o, const std::string &type);

        const double getM_value() const;

        const bool getM_flag() const;

        const std::string  getM_description() const;

        const std::unique_ptr<char[]> &getM_data() const;

        int getM_size() const;

        payload& operator=(const DATA::payload &o);

        payload& operator=(const char data[]);

        ~payload();

    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
