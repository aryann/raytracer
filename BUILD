load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_binary(
    name = "make_image",
    srcs = ["make_image.cc"],
    deps = [
        ":vec3",
    ],
)

cc_library(
    name = "vec3",
    srcs = ["vec3.cc"],
    hdrs = ["vec3.h"],
    deps = [
    ],
)
