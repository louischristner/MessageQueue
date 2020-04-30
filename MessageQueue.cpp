/*
** EPITECH PROJECT, 2020
** message_queue
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"

MessageQueue::MessageQueue(const std::string mqname): _mqname(mqname)
{
}

MessageQueue::~MessageQueue()
{
    mq_close(_mq);
}

Client::Client(const std::string mqname): MessageQueue(mqname)
{
    _mq = mq_open(_mqname.c_str(), O_WRONLY);
}

Client::~Client()
{
}

void Client::send_message(const std::string msg)
{
    if (mq_send(_mq, msg.c_str(), MAX_SIZE, 0) < 0)
        throw MyException(std::string(__func__) + ":" + std::to_string(__LINE__) + ": mq_send failed");
}

Server::Server(const std::string mqname): MessageQueue(mqname)
{
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    _mq = mq_open(_mqname.c_str(), O_CREAT | O_RDONLY, 0644, &attr);
}

Server::~Server()
{
    mq_unlink(_mqname.c_str());
}

const std::string Server::receive_message(void)
{
    char buffer[MAX_SIZE] = {0};

    if (mq_receive(_mq, buffer, MAX_SIZE, NULL) < 0)
        throw MyException(std::string(__func__) + ":" + std::to_string(__LINE__) + ": mq_receive failed");
    return (std::string(buffer));
}
