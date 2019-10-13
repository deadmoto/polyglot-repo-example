load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "main_proto",
    srcs = ["example.proto"],
)

cc_proto_library(
    name = "main_cc_proto",
    deps = [":main_proto"],
    visibility = ["//visibility:public"]
)
