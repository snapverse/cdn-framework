#!/bin/bash

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "💅 Formatting code..."

clang-format -i $root/app/**/*.cpp -verbose
clang-format -i $root/app/**/*.hpp -verbose
cmake-format -i $root/CMakeLists.txt

if [ $? -ne 0 ]; then
  echo "❌ Formatting code failed!"
  exit 1
fi

echo "✨ Formatting code done!"