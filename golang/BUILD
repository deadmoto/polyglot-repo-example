load("@io_bazel_rules_go//go:def.bzl", "go_binary")

go_binary(
    name = "echo_client",
    srcs = ["echo_client.go"],
    deps = [
        "//proto:echo_go_grpc",
        "@org_golang_google_grpc//:go_default_library",
    ],
)
