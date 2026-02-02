#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(dirname "$0")"
LOG_FILE="$SCRIPT_DIR/$(basename "$0" .sh).log"

PODMAN_FLAGS="--rm --privileged -v nix-store:/nix -v bazel-cache:/root/.cache/bazel"
if [ -t 0 ]; then
    PODMAN_FLAGS="-it $PODMAN_FLAGS"
fi

set +e
podman run $PODMAN_FLAGS \
    -v "$SCRIPT_DIR:/workspace" \
    -w /workspace \
    docker.io/nixos/nix \
    bash -c "FHS_ENV=\$(nix-build shell.nix --no-out-link) && \$FHS_ENV/bin/bazel-env -c '$*'" 2>&1 | tee "$LOG_FILE"

exit ${PIPESTATUS[0]}
