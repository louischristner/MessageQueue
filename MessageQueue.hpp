/*
** EPITECH PROJECT, 2020
** message_queue
** File description:
** MessageQueue
*/

#include <string>

#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "MyException.hpp"

#define MAX_SIZE 1024

class MessageQueue {
    public:
        MessageQueue(const std::string mqname);
        virtual ~MessageQueue();

    protected:
        mqd_t _mq;
        const std::string _mqname;
};

class Client : public MessageQueue {
    public:
        Client(const std::string mqname);
        virtual ~Client();

        void send_message(const std::string msg);
};

class Server : public MessageQueue {
    public:
        Server(const std::string mqname);
        virtual ~Server();

        const std::string receive_message(void);
};
