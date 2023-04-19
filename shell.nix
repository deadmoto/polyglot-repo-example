{ pkgs ? import <nixpkgs> { } }:
pkgs.mkShell {
  packages = [
    pkgs.bazel_5
    pkgs.jdk8
  ];
}
