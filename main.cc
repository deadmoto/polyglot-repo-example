#include <iostream>
#include <grpcpp/grpcpp.h>
#include "proto/example.pb.h"
#include "proto/example.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using example::EchoService;
using example::EchoRequest;
using example::EchoResponse;

class GreeterServiceImpl final : public EchoService::Service {
    Status Echo(ServerContext* context, const EchoRequest* request, EchoResponse* response) override {
        std::string prefix("echo -> ");
        response->set_text(prefix + request->text());
        return Status::OK;
    }
};

int main() {
    GreeterServiceImpl service;
    std::string server_address("0.0.0.0:54321");
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
    return 0;
}
