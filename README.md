<h1>🗃️ C++ Cdn Framework</h1>
<p>
This project is a C++-based API designed to streamline access to and processing of files stored in various cloud services such as Dropbox, Google Drive, and others. The API provides a single endpoint through which users can retrieve files and apply various transformations or optimizations, all via query parameters.
</p>
<p>
The goal is to make resource handling more efficient and versatile without requiring specialized graphic or document-editing tools like Photoshop or Microsoft Word. While it does not aim to replace such tools, this API offers a lightweight solution for specific processing tasks directly in the cloud, reducing the need for heavy downloads or manual interventions.
</p>

<h2>Table of Contents</h2>
<ul>
  <li><a href=#features>Features</a>
    <ul>
      <li><a href=#1-cloud-integration>Cloud Integration</a></li>
      <li><a href=#2-file-processing-options>File Processing Options</a></li>
      <li><a href=#3-simple-usage>Simple Usage</a></li>
    </ul>
  </li>
  <li><a href=#requeriments>Requeriments</a></li>
  <li><a href=#how-to-build>How to Build</a></li>
  <li><a href=#how-to-run-it>How to Run it</a></li>
  <li><a href=#useful-resources>Useful Resources</a></li>
  <li><a href=#tested-with>Tested with</a></li>
</ul>

<h2>Features</h2>

<h3 style=font-weight=bold>1. Cloud Integration:</h3>
<ul>
  <li>Supports retrieving files from multiple cloud storage services</li>
</ul>

<h3 style=font-weight=bold>2. File Processing Options:</h3>
<ul>
  <li><b>Images:</b>
    <ul>
      <li>Compression to reduce file size</li>
      <li>Format conversion (e.g., PNG to JPEG)</li>
      <li>Color filters (e.g., grayscale, sepia)</li>
    </ul>
  </li>
    <li><b>Documents:</b>
    <ul>
      <li>Compression</li>
      <li>Format conversion (e.g., PDF to DOCX)</li>
    </ul>
  </li>
</ul>

<h3 style=font-weight=bold>3. Simple Usage:</h3>
<ul>
  <li>Access all functionality through a single endpoint</li>
  <li>Customize processing through query parameters</li>
</ul>


<h2>Requeriments</h2>
<ul>
  <li><a href=https://en.cppreference.com/w/cpp/17>C++17</a></li>
  <li><a href=https://cmake.org/download/>CMake</a></li>
  <li><a href=https://en.cppreference.com/w/cpp/compiler_support>Clang++19 or Alternative Compiler</a></li>
  <li><a href=https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode?pivots=shell-bash>vcpkg</a></li>
</ul>


<h2>How to Build</h2>

<p>I already made all the build process, you just need to run the file</p>

```shell
sh ./scripts/build
```

<h2>How to Run it</h2>

<p>It is simple, just run this command</p>

```shell
./build/CdnFramework --port 8080
```

<p>And for requests with a curl it's ok</p>

```shell
curl -X GET 127.0.0.1:8080
```

<h2>Useful Resources</h2>
<ul>
  <li><a href=https://learn.microsoft.com/en-us/vcpkg/get_started/overview>vcpkg Overview</a></li>
  <li><a href=https://cmake.org/cmake/help/latest/guide/tutorial/index.html>CMake Tutorials</a></li>
  <li><a href=https://en.cppreference.com/w/>C++ Reference</a></li>
  <li><a href=https://devdocs.io/cpp/>C++ DevDocs</a></li>
  <li><a href=https://cpp-core-guidelines-docs.vercel.app/>C++ Core Guidelines</a></li>
  <li><a href=https://google.github.io/styleguide/cppguide.html>Google C++ Style Guide</a></li>
</ul>

<h2>Tested with</h2>

<h3>vcpkg</h3>

```
vcpkg package management program version 2024-12-09-1005b78fa1bf1dde1a20c2734cba4ea61ca94d9a

See LICENSE.txt for license information.
```

<h3>clang++</h3>

```
Homebrew clang version 19.1.6
Target: x86_64-apple-darwin23.6.0
Thread model: posix
InstalledDir: #
Configuration file: #
```

<h3>cmake</h3>

```
cmake version 3.31.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
