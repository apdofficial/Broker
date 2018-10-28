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
        std::variant<double, bool, std::string> m_value, m_flag, m_description;
        int m_size;
        std::unique_ptr<char[]> m_data;
    public:
        /* copy ctor for all types */
        payload(const DATA::payload &o, const std::string &type);

        /* ctors for individual types */
        payload(const char data[],const int& size);
        explicit payload(const double &value);
        explicit payload(const bool &flag);
        explicit payload(const std::string &description);

        /* overloaded copy  assignment operators */
        payload& operator=(const DATA::payload &o);
        payload& operator=(const char data[]);

        /* destructor */
        ~payload();

        /* getters */
        const std::string&  get_description() const;
        const std::unique_ptr<char[]>& get_data() const;
        const int& get_size() const;
        const double& get_value() const;
        const bool& get_flag() const;
    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_PLAYLOAD_H
