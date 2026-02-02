{ pkgs ? import <nixpkgs> { } }:

pkgs.buildFHSEnv {
  name = "bazel-env";
  
  targetPkgs = pkgs: with pkgs; [
    bazel_7
    jdk21
    gcc
  ];
  
  runScript = "bash";
}
