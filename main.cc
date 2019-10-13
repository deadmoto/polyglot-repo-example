#include <iostream>
#include "proto/example.pb.h"

int main() {
    example::Msg msg;
    msg.set_text("Yo!");
    std::cout << msg.DebugString() << std::endl;
    return 0;
}
