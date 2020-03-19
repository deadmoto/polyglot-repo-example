#!/usr/bin/env bash

base=$(git merge-base origin/master HEAD)
echo Merge base:
echo - ${base}
echo

declare -a files=($(git diff --name-only HEAD ${base}))
if [[ ${#files[@]} -eq 0 ]]; then
    echo No changed files
    exit 0
fi
echo Changed files:
printf " - %s\n" ${files[@]}
echo

declare -a targets=($(bazel query --keep_going "rdeps(//...,set(${files[@]}))" 2>/dev/null))
if [[ ${#targets[@]} -eq 0 ]]; then
    echo No changed targets
    exit 0
fi
echo Affected targets:
printf " - %s\n" ${targets[@]}
echo

echo Rebuild targets: bazel build ${targets[@]}
bazel build ${targets[@]}
