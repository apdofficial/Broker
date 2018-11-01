#ifndef ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
#define ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H

#include "map"
#include "message.h"
#include "vector"
#include <iterator>
#include "iterator"

namespace saxion {
    class broker {
    public:
        using value_type = sax::message;
        using pointer = sax::message *;
        using size_type = std::size_t;
        using difference_type = std::make_signed_t<size_type>;
        using reference = sax::message &;
        using iterator_category = std::forward_iterator_tag;
    private:

        struct iter {

            iter &move_to_next() {
                for (; _current != _end; ++_current) {
                    if (request == _current->second.topic().substr(0, request.size())) {
                        break;
                    }
                }
                return *this;
            }


            using _iter = std::map<int, sax::message>::iterator;
            _iter _before_first;
            _iter _current;
            _iter _end;
            std::string request;

            iter(_iter map_begin, _iter map_end, std::string str) :
                    _current(std::move(map_begin)),
                    _end(std::move(map_end)),
                    request(std::move(str))
            {
                if (request.back() == '*') {
                    request = request.substr(0, request.length() - 1);
                }
                move_to_next();
            }

            iter(_iter map_begin, _iter map_end):
                _current(std::move(map_end)),
                _end(std::move(map_end)),
                request()

            {
            }

            reference operator*() const { return _current->second; }

            pointer operator->() const { return std::addressof(_current->second); }

            iter &operator++() {
                ++_current;
                return move_to_next();
            }

            iter operator++(int) {
                iter copy(*this);
                ++(*this);
                return copy;
            }


            friend
            bool operator==(const iter &__x, const iter &__y) { return __x._current == __y._current; }

            friend
            bool operator!=(const iter &__x, const iter &__y) { return __x._current != __y._current; }

        };

    public:



        using iterator = iter;

        iterator begin(std::string request);

        iterator end();

        broker() = default;

        int post(const sax::message &message);

        sax::message operator[](int id_num) const;

        std::vector<std::string> list(std::string request);

        std::vector<sax::message> extract(std::string request);

        std::vector<sax::message> get(std::string request);

//        std::map<int, sax::message>::const_iterator begin(std::string request);

//        std::map<int, sax::message>::const_iterator end();

    private:
        int id{0};
        std::map<int, sax::message> m_messages;


    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
