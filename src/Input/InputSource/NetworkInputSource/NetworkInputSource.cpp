#include "NetworkInputSource.h"

// NetworkInputSource::NetworkInputSource(asio::io_context& io_context, const std::string& host, const std::string& port) : socket(io_context)
// {
//     asio::ip::tcp::resolver resolver(io_context);
//     asio::connect(socket, resolver.resolve(host, port));
// }

// char NetworkInputSource::getInput()
// {
//     char key;
//     asio::read(socket, asio::buffer(&key, 1));
//     return key;
// }