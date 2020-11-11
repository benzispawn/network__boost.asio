#include <boost/predef.h> // Is a tool to identify the OS
#ifdef BOOST_OS_WINDOWS
#define _WIN32_WINNT 0x0501

#if _WIN32_WINNT <= 0x502 // WINDOWS SERVER 2003 OR EARLIER
    #define BOOST_ASIO_DISABLE_IOCP
    #define BOOST_ASIO_ENABLE_CANCELIO
#endif

#endif

#include <boost/asio.hpp>
#include <thread>
#include <mutex>
#include <memory>
#include <iostream>

typedef void(*Callback) (unsigned int request_id,
    const std::string& response,
    const boost::system::error_code& ec);

// STRUCTURE
struct Session {
    Session(boost::asio::io_service& ios,
    const std::string& raw_ip_address,
    unsigned short port_num,
    const std::string& request,
    unsigned int id,
    Callback callback) :
    m_sock(ios),
    m_ep(boost::asio::ip::address::from_string(raw_ip_address),
        port_num),
    m_request(request),
    m_id(id),
    m_callback(callback),
    m_was_cancelled(false) {}

    boost::asio::ip::tcp::socket m_sock; // Socket used for communication
    boost::asio::ip::tcp::endpoint m_ep; // Remote endpoint
    std::string m_request; // Request string

    // streambuf where the response will be stored
    boost::asio::streambuf m_response_buf;
    std::string m_response; // REsponse represented as a string
    // Contains the description of an error if one occurs during
    // the request life cycle
    boost::system::error_code m_ec;

    unsigned int m_id; // Unique ID assigned to the request

    // Point to the function to be called when the request
    // complete
    Callback m_callback;

    bool m_was_cancelled;

    std::mutex m_cancel_guard;
};
