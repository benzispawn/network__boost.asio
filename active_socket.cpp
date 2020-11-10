#include <boost/asio.hpp>
#include <iostream>

int main() 
{
    // Step 1. An instance of 'io_service'
    // required by sockett constructor
    boost::asio::io_service ios;

    // Step 2. Creating an object of 'tcp' class
    // a tcp protocol with ipv4 as underlying protocol
    boost::asio::ip::tcp protocol  = boost::asio::ip::tcp::v4();

    // Step 3. Instantiating an active  TCP 
    // socket object
    boost::asio::ip::tcp::socket sock(ios);
    // USED TO STORE INFORMATION ABOUT ERROR THAT HAPPENS
    // WHILE OPENING THE SOCKET
    boost::system::error_code ec;

    // Step 4. Opening the socket
    sock.open(protocol, ec);

    if (ec.value() != 0)
    {
        // Failed to open the socket
        std::cout
            << "Failed to open the socket! Error code = "
            << ec.value() << ". Message: " << ec.message();
        return ec.value(); 
    }
    return 0;
}