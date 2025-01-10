#!/bin/bash

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VCPKG_ROOT="$(dirname $(which vcpkg))"
CLANG_BIN_PATH="$(dirname $(which clang))"

echo "🏗️ Building project..."

mkdir -p $ROOT_DIR/build
sudo rm -rf $ROOT_DIR/build/CMakeCache.txt
mkdir -p $ROOT_DIR/build
chmod -R u+w $ROOT_DIR/build

sudo cmake -S. \
  -Bbuild \
  -GNinja \
  --preset=default \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_COMPILER=$CLANG_BIN_PATH/clang \
  -DCMAKE_CXX_COMPILER=$CLANG_BIN_PATH/clang++ \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake \

sudo cmake --build build
# strip $ROOT_DIR/build/CdnFramework

if [ $? -ne 0 ]; then
  echo "❌ Building project failed!"
  exit 1
fi

echo "✨ Building project done!"