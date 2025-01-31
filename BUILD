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
    implementation_deps = [":private"],
)

cc_shared_library(
    name = "transitive_shared",
    dynamic_deps = [":private_shared"],
    deps = [":transitive"],
)

cc_library(
    name = "private",
    srcs = ["private.cc"],
    hdrs = ["private.h"],
)

cc_shared_library(
    name = "private_shared",
    deps = [":private"],
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
