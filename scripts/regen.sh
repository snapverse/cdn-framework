#!/bin/bash

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VCPKG_ROOT="$(dirname $(which vcpkg))"
CLANG_BIN_PATH="$(dirname $(which clang))"

echo "🏗️ Regenerating project..."

# if [ $(find $VCPKG_ROOT -type f -newer $ROOT_DIR/build) ]; then
  cmake -S . -B build --preset=default
# fi

if [ $? -ne 0 ]; then
  echo "❌ Regenerating project failed!"
  exit 1
fi

echo "✨ Regenerating project done!"