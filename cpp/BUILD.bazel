cc_binary(
    name = "echo_client",
    srcs = ["echo_client.cc"],
    deps = [
        "//proto:echo_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_binary(
    name = "echo_server",
    srcs = ["echo_server.cc"],
    deps = [
        "//proto:echo_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
    ],
)
