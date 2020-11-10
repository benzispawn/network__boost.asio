#include <boost/asio.hpp>
#include <iostream>

int main () 
{
    // Step 1. Assume that the client application has already
    // obtained the ip address and the protocol port number.
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    // Used to store information about error that happens
    // whilw parsing the raw ip address.
    boost::system::error_code ec;

    // Step 2. Using ip protocol version independent address
    // representation
    boost::asio::ip::address ip_address = 
        boost::asio::ip::address::from_string(raw_ip_address, ec);

    /*
        boost::asio::address_v6::any()
        Just for ipv6 connections
    */
    
    if (ec.value() != 0)
    {
        // Provided ip address is incalid. Breaking execution.
        std::cout
            << "Failed to parse the IP address. Error code = "
            << ec.value() << ". Message: " << ec.message();
            return ec.value();
    }

    // Step 3.
    boost::asio::ip::tcp::endpoint ep(ip_address, port_num);

    // Step 2. The endpoint is ready and can be used to specify a particular
    // server in the nerwork the client wants to communicate with

    return 0;
}