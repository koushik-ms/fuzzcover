#!/bin/bash

set -euo pipefail

BUILD_DIR=cmake-build-debug
REPO_ROOT=$(git rev-parse --show-toplevel)

echo "Switching to ${REPO_ROOT}..."
cd ${REPO_ROOT}

rm -rf ${BUILD_DIR}
mkdir ${BUILD_DIR} && cd ${BUILD_DIR}

cmake .. && make

