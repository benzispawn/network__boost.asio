#include <boost/asio.hpp>
#include <iostream>

int main()
{
    //Step 1. Assume that the client application gas already 
    // obtained the DNS name and protocol port number and represented them as strings
    std::string host = "samplehost.com";
    std::string port_num = "3333";

    //Step 2.
    boost::asio::io_service ios;
    // Step 3. Creating a query
    boost::asio::ip::tcp::resolver::query resolver_query(host, 
        port_num, boost::asio::ip::tcp::resolver::query::numeric_service);
    /// Step 4. Creating a resolver
    boost::asio::ip::tcp::resolver resolver(ios);

    // Store error
    boost::system::error_code ec;

    // Step 5. 
    boost::asio::ip::tcp::resolver::iterator it =
        resolver.resolve(resolver_query, ec);

    if (ec.value() != 0)
    {
        std::cout << "Failed to resolve the FNS nma. Breaking execution."
            << "Error code = " << ec.value()
            << ". Message = " << ec.message();

        return ec.value();
    }

    boost::asio::ip::tcp::resolver::iterator it_end;

    for (; it != it_end; ++it)
    {
        boost::asio::ip::tcp::endpoint ep = it->endpoint();
    }

    return 0;
}