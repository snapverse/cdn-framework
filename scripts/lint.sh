#!/bin/bash

echo "🔎 Linting code..."

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

clang-tidy -p . -header-filter=$root/app/*.hpp $root/app/*.cpp
cmake-lint $root/CMakeLists.txt

if [ $? -ne 0 ]; then
  echo "❌ Linting code failed!"
  exit 1
fi

echo "✨ Linting code done!"