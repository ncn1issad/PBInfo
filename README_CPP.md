# Single-file C++ development setup

This workspace is configured for quick single-file C++ development using g++ and gdb.

New workflow: keep your .cpp sources under `src/` and compiled executables will be emitted to `out/` while preserving the `src/` directory layout.

Files added/updated:

- `.vscode/tasks.json` — build task compiles the active file; if the file is under `src/` it will place the binary under `out/<same-relative-path>/`.
- `.vscode/launch.json` — debug configuration that launches the corresponding binary in `out/` (preLaunchTask builds it first).
- `.vscode/c_cpp_properties.json` — IntelliSense include paths and compiler settings.
- `.vscode/extensions.json` — recommended extensions (C/C++).
- `scripts/run_cpp.sh` — helper script that compiles a source and, if under `src/`, writes the binary to `out/` preserving subfolders.
- `src/main.cpp` — a tiny sample program to verify the setup (built into `out/main`).

Quick usage

1. Put your single-file sources in `src/` (you can keep subdirectories: `src/contest/problem1.cpp`).
2. Build the active file:
	- Run the default build task (Terminal → Run Build Task or Ctrl+Shift+B). If the source is in `src/`, the executable will appear in `out/` with the same relative path, e.g. `src/foo/bar.cpp` -> `out/foo/bar`.
3. Run the binary:
	- Use the "Run active file" task, or run the produced executable from `out/`.
4. Debug:
	- Build the file, then use the "Debug active file (src -> out)" configuration (F5). It will launch the binary located under `out/` that corresponds to the source file.

Command-line helper

Build & run from shell:

```bash
./scripts/run_cpp.sh src/main.cpp
```

Examples

- Source: `src/main.cpp` -> Binary: `out/main`
- Source: `src/contests/abc123/problemA.cpp` -> Binary: `out/contests/abc123/problemA`

Notes

- This setup assumes `g++` and `gdb` are available at `/usr/bin`. On some systems the path differs — update `.vscode/launch.json` and `c_cpp_properties.json` accordingly.
- If you prefer clang, change `compilerPath` in `c_cpp_properties.json` and the build command in `tasks.json`.
