#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <sstream>

using boost::asio::ip::tcp;
using namespace boost::property_tree;

// Function to process XML and return response XML
std::string process_request(const std::string& xml_input) {
    std::stringstream ss(xml_input);
    ptree pt;

    try {
        read_xml(ss, pt);

        std::string operation = pt.get<std::string>("request.operation");
        int op1 = pt.get<int>("request.operand1");
        int op2 = pt.get<int>("request.operand2");

        int result = 0;
        if (operation == "add") {
            result = op1 + op2;
        } else if (operation == "multiply") {
            result = op1 * op2;
        } else {
            return "<response><error>Invalid operation</error></response>";
        }

        // Create response
        ptree response_pt;
        response_pt.put("response.result", result);

        std::ostringstream oss;
        write_xml(oss, response_pt);
        return oss.str();
    } catch (std::exception& e) {
        return "<response><error>Parsing error</error></response>";
    }
}

// Start a basic TCP server
void start_server(short port) {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

        std::cout << "Server running on port " << port << "...\n";

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            boost::asio::streambuf buffer;
            boost::system::error_code error;

            boost::asio::read_until(socket, buffer, "</request>", error);

            if (error && error != boost::asio::error::eof) {
                std::cerr << "Receive failed: " << error.message() << "\n";
                continue;
            }

            std::istream is(&buffer);
            std::string request_xml((std::istreambuf_iterator<char>(is)), {});

            std::cout << "Received:\n" << request_xml << "\n";

            std::string response_xml = process_request(request_xml);

            boost::asio::write(socket, boost::asio::buffer(response_xml), error);

            if (error) {
                std::cerr << "Send failed: " << error.message() << "\n";
            } else {
                std::cout << "Response sent.\n";
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Server exception: " << e.what() << "\n";
    }
}

int main() {
    start_server(12345); // You can change the port if needed
    return 0;
}
