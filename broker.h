#include <utility>

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
        using _iter = std::map<int, sax::message>::iterator;
    private:
        struct iter {
            _iter _end;
            _iter _begin;
            _iter _current;
            std::string _request;

            //ctor for begin("request")
            iter(_iter map_begin, _iter map_end, std::string str) :
                    _current(map_begin),
                    _end(map_end),
                    _request(std::move(str))
            {
                if (_request.back() == '*') _request = _request.substr(0, _request.length() - 1);
                move_to_next();//finds first mach ->_current
            }

            //ctor for end("request")
            iter(_iter map_begin, _iter map_end, std::string str, int i) :
                    _current(map_end),
                    _begin(map_begin),
                    _request(std::move(str))
            {
                --_current;//_current has to be decremented as end is pointing to one element after the map
                if (_request.back() == '*') _request = _request.substr(0, _request.length() - 1);
                move_to_prev();//finds last mach  ->_current
            }


            //provides just beginning of the map
            iter(_iter map_begin, int i) :
                    _current(map_begin),
                    _request() {}


            //provides just end of the map
            iter(_iter map_end) :
                    _current(map_end),
                    _request() {}

            reference operator*() const { return _current->second; }

            pointer operator->() const { return std::addressof(_current->second); }


            const iter &operator++() {
                ++_current;
                return move_to_next();
            }

            const iter operator++(int) {
                iter copy(*this);
                ++(*this);
                return copy;
            }

            const iter &operator--() {
                --_current;
                return move_to_prev();
            }

            const iter operator--(int) {
                iter copy(*this);
                ++(*this);
                return copy;
            }

            iter &move_to_next() {
                for (; _current != _end; ++_current) {
                    if (_request == _current->second.topic().substr(0, _request.size())) { break; }
                }
                return *this;
            }

            iter &move_to_prev() {
                for (; _current != _begin; --_current) {

                    if (_request == _current->second.topic().substr(0, _request.size())) { break; }
                }
                return *this;
            }

            friend
            bool operator==(const iter &__x, const iter &__y) { return __x._current == __y._current; }

            friend
            bool operator!=(const iter &__x, const iter &__y) { return __x._current != __y._current; }

        };

    public:
        using iterator = iter;

        iterator begin(std::string request);

        iterator begin();

        iterator end(std::string request);

        iterator end();

        broker() = default;

        int post(const sax::message &message);

        sax::message operator[](int id_num) const;

        std::vector<std::string> list(std::string request);

        std::vector<sax::message> extract(std::string request);

        std::vector<sax::message> get(std::string request);

    private:
        int id{0};
        std::map<int, sax::message> m_messages;
    };
}

#endif //ASSIGNMENT_5_MESSAGE_BROKER_BROKER_H
