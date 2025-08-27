// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "tiny_zip",
    products: [
        .library(name: "tiny_zip", targets: ["c_tiny_zip"]),
    ],
    targets: [
        .target(
            name: "c_tiny_zip",
            path: "src"
        )
    ]
)
