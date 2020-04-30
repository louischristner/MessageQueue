/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
**
*/

#ifndef MYEXCEPTION_HPP_
#define MYEXCEPTION_HPP_

#include <string>
#include <exception>

class MyException : public std::exception
{
    public:
        MyException(const std::string &msg) noexcept : Msg("Exception: " + msg) {}
        const char *what() const noexcept override { return Msg.data(); }

    private:
        std::string Msg;
};

#endif /* !MYEXCEPTION_HPP_ */
