#include<iostream>
#include <boost/asio.hpp>

using namespace std;


namespace asio = boost::asio

int add(int num1, int num2){
    return num1 + num2;
}

int multiply(int num1, int num2){
    return num1*num2;
}

string process_request(const string& req){

    ptree pt;
    istringstream request_stream(request);
    read_xml(request_stream, pt);

    std::string operation = pt.get<std::string>("request.operation");
    int num1 = pt.get<int>("request.data.num1");
    int num2 = pt.get<int>("request.data.num2");

    int result = 0;
    if (operation == "add") {
        result = add(num1, num2)
    } else if (operation == "multiply") {
        result = mul(num1, num2);
    } else {
        result = -1;  // Invalid operation
    }

    ptree response
    response.put("response.status", result == -1 ? "failure" : "success");
    response.put("response.result", result);
    response.put("response.num1", num1);
    response.put("response.num2", num2);

    ostringstream response_stream;
    write_xml(response_stream, response);
    return response_stream.str();
}



int main(){

    asio::io_context ioCntxt;

    //setup tcp server
    asio::ip::tcp::acceptor acceptor(ioContxt, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 8080));
    
    cout<<"server configuration..."<<endl;
    cout<<"server started listening on port 8080..."<<endl;

    while(true){
        asio::ip::tcp::socket(ioContxt);
        acceptor.accept(socket);

        boost::asio::streambuf req_buff;
        asio::read_until(socket, req_buff,"\n");
        
        istream request_stream(&request_buffer);
        string request((istreambuf_iterator<char>(request_stream)), 
                            istreambuf_iterator<char>());

        cout << "Received request: " << request << std::endl;

        // Process the request and generate the response
        string response = process_request(request);

        // Send the response back to the client
        asio::write(socket, asio::buffer(response));
        
        socket.close();
    }

    return 0;
}