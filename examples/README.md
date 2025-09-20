# C++ Examples

Small, focused examples of useful C++ functions and patterns. Each file is self-contained with:
- A reusable function (or two)
- A short explanation in comments
- A tiny main() demo that prints results

How to run (from VS Code):
- Open an example file and use the "Build and Run active file" task.
- Or run the repo's script with that file path.

Contents
- smallestPrimeDivisor.cpp: Find the smallest prime divisor of a number in O(n^0.5/2) time. Used in problem [PBInfo 4330] (https://www.pbinfo.ro/probleme/4330/).

Notes
- All examples target C++11 and only use the standard libraries.
- Feel free to copy-paste functions into your solutions; the demos are optional.

## How to add examples

Recommended naming
- Use short, descriptive names like `kmpStringMatch.cpp`, `fenwickTree.cpp`, `dsuUnionFind.cpp`.

Inputs via resources (optional)
- When you run a file named `foo.cpp`, the helper script creates and runs in `resources/foo/`.
- You can add `resources/foo/foo.in` and read from it in your program if you want to simulate judge I/O.
