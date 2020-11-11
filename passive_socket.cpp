#include <boost/asio.hpp>
#include <iostream>

int main()
{
    // Step 1. An instance of 'io_sevice' class is required by 
    // socket constructor
    boost::asio::io_service ios;

    // Step 2. Creating an object of 'tcp' class representing
    // aTCP protocol with IPv6 as underlying protocol
    boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v6();

    //Step 3. Instantiating an acceptor socket object 
    boost::asio::ip::tcp::acceptor acceptor(ios);

    // Userd to store information about error that happens
    // while opening the acceptor socket
    boost::system::error_code ec;

    //Step 4. Opening the acceptor socket
    acceptor.open(protocol, ec);

    if (ec.value() != 0)
    {
        std::cout
            << "Failed to opoen the acceptor socket!"
            << "Error code = "
            << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }

    return 0;

}