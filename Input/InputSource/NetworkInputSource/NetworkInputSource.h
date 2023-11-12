#ifndef NETWORK_INPUT_SOURCE_H
#define NETWORK_INPUT_SOURCE_H

#include "../InputSource.h"
#include <asio.hpp>

class NetworkInputSource : public InputSource
{
private:
    asio::ip::tcp::socket socket;

public:
    NetworkInputSource(asio::io_context &io_context, const std::string &host, const std::string &port);

    char getInput() override;
};

#endif