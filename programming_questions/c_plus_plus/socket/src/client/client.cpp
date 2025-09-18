#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <fstream>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT "8080"

namespace asio = boost::asio;

// Function to read the XML request from a file
std::string load_request_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open request file: " << filename << std::endl;
        exit(1);
    }

    std::string request((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return request;
}

// Function to send the XML request to the server and receive the response
void send_request_to_server(const std::string& request) {
    asio::io_context io_context;
    asio::ip::tcp::socket socket(io_context);

    // Connect to server
    asio::ip::tcp::resolver resolver(io_context);
    asio::connect(socket, resolver.resolve(SERVER_IP, SERVER_PORT));

    // Send request
    asio::write(socket, asio::buffer(request));

    // Receive response
    boost::asio::streambuf response_buffer;
    asio::read_until(socket, response_buffer, "\n");

    std::istream response_stream(&response_buffer);
    std::string response((std::istreambuf_iterator<char>(response_stream)), std::istreambuf_iterator<char>());
    
    // Print the response
    std::cout << "Server Response: " << response << std::endl;
}

int main() {
    // Load XML request from file
    std::string request = load_request_from_file("request.xml");
    
    // Send request to the server
    send_request_to_server(request);

    return 0;
}
