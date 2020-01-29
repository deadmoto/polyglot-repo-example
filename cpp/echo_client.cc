#include <iostream>
#include <grpcpp/grpcpp.h>
#include "proto/echo.pb.h"
#include "proto/echo.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using echo::EchoService;
using echo::EchoRequest;
using echo::EchoResponse;

class EchoClient {
    public:
        EchoClient(std::shared_ptr<Channel> channel) : stub_(EchoService::NewStub(channel)) {}
        std::string Echo(const std::string& text) {
            EchoRequest request;
            request.set_text(text);
            EchoResponse reply;
            ClientContext context;
            Status status = stub_->Echo(&context, request, &reply);
            if (status.ok()) {
                return reply.text();
            } else {
                std::cout << status.error_code() << ": " << status.error_message() << std::endl;
                return "RPC failed";
            }
        }
    private:
        std::unique_ptr<EchoService::Stub> stub_;
};

int main() {
    EchoClient greeter(grpc::CreateChannel("localhost:54321", grpc::InsecureChannelCredentials()));
    std::string user("Hello world!");
    std::string echo = greeter.Echo(user);
    std::cout << "Echo: " << echo << std::endl;
    return 0;
}
