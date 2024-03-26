cc_library(
    name = "dep",
    hdrs = ["dep.h"],
    deps = [":transitive"],
)

cc_shared_library(
    name = "dep_shared",
    dynamic_deps = [":transitive_shared"],
    deps = [":dep"],
)

cc_library(
    name = "transitive",
    srcs = ["transitive.cc"],
    hdrs = ["transitive.h"],
)

cc_shared_library(
    name = "transitive_shared",
    deps = [":transitive"],
)

cc_binary(
    name = "main_dynamic",
    srcs = ["main.cc"],
    dynamic_deps = [
        ":dep_shared",
        # Uncommenting this makes it build.
        #':transitive_shared',
    ],
    deps = [":dep"],
)

cc_binary(
    name = "main_static",
    srcs = ["main.cc"],
    deps = [":dep"],
)
