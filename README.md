# Study

Personal notes, exercises, and small experiments across languages and tooling. Everything here is informal learning material—not a single product or library.

**Remote:** [github.com/YouYue123/Study](https://github.com/YouYue123/Study)

## What’s in this repo

| Area | Contents |
|------|-----------|
| **`C++/`** | Competitive programming and algorithms (`algo/`: LeetCode, Codeforces, CSES—indexed in [`C++/algo/cses/README.md`](C++/algo/cses/README.md), Advent of Code; shared snippets under `algo/common/`). C++ language experiments (`lang/`, e.g. caches, memory pool). Small standalone projects (`projects/`). |
| **`DataEng/`** | Data-engineering scraps: Airflow-related files, Spark configs and Kubernetes manifests. |
| **`Go/`** | Go language practice (`lang/`). |
| **`Infra/`** | Infrastructure-as-code (Terraform layouts under `Infra/Terraform/`, including AWS-focused modules). |
| **`LLM/`** | LLM and agent experiments: LangChain notebooks/scripts, inference sandboxes, MCP tooling, multi-agent demos. |

Editor and assistant metadata (e.g. `.vscode/`, `.claude/`) live in-repo for convenience; treat them as personal setup unless you intentionally share them.

## Conventions

- **C++ competitive solutions** often use `#include <bits/stdc++.h>` and a `main` or LeetCode `Solution` class, depending on the platform.
- **Per-problem inputs** for local runs may use `input.txt` in contest folders; that filename is gitignored (see `.gitignore`).
- **Build outputs** (`build/`, CMake artifacts, binaries) and local secrets (`.env`) are ignored—clone and compile as needed for C++/CMake projects.

## License

No license is asserted here by default. If you reuse anything, confirm with the repository owner or add a `LICENSE` when you want explicit terms.
