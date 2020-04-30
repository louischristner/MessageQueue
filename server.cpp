/*
** EPITECH PROJECT, 2020
** message_queue
** File description:
** server
*/

#include <iostream>

#include "MessageQueue.hpp"

int main(int ac, char **av)
{
    std::string buff;
    Server serv("/test_queue");

    do {
        buff = serv.receive_message();
        if (buff == "exit")
            break;
        std::cout << "Received: " << buff << std::endl;
    } while (true);
    return 0;
}
