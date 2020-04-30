/*
** EPITECH PROJECT, 2020
** message_queue
** File description:
** client
*/

#include <iostream>

#include "MessageQueue.hpp"

int main(int ac, char **av)
{
    std::string buff;
    Client cli("/test_queue");

    do {
        std::cout << "> ";
        std::cout.flush();

        std::getline(std::cin, buff);
        cli.send_message(buff);
    } while (buff != "exit");
    return 0;
}
