# CharacterComparison GitHub Actions CI/CD

This repository uses **GitHub Actions** to automate **Continuous Integration (CI)** and **Continuous Deployment (CD)** for the `CompareTwoCharacters` C++ project.

---

## CI Workflow

**Workflow File:** `.github/workflows/charactercomparison-ci.yml`

**Triggers:**
- On `push` to `main`
- On `pull_request` to `main`

**Steps:**
1. **Checkout repository** – gets the latest code.
2. **Install C++ compiler**
   - Linux/macOS: `g++` and build tools.
   - Windows: MinGW.
3. **Compile code** – `main.cpp` → executable.
4. **Run program** – optional, ensures program runs correctly.
5. **Upload artifact** – stores the compiled executable for download.

**Cross-Platform Executables:**

| OS       | Executable                         |
|----------|-----------------------------------|
| Windows  | `CompareTwoCharacters_V1.2.exe`  |
| Linux    | `CompareTwoCharacters_V1.2`      |
| macOS    | `CompareTwoCharacters_V1.2`      |

Artifacts can be downloaded from GitHub Actions → Workflow Run → Artifacts.

---

## CD / Auto Merge Workflow

**Workflow File:** `.github/workflows/auto-merge.yml`

**Trigger:**
- Runs after a CI workflow completes successfully.

**Steps:**
1. Checks if the previous workflow was successful.
2. Automatically merges the PR using `pascalgn/automerge-action`.
3. No human review required if all CI checks pass.

**Requirements:**
- `GITHUB_TOKEN` secret is used.

---

## Usage

1. Push code or create a pull request to `main`.
2. GitHub Actions automatically:
   - Builds the project (CI)
   - Runs tests
   - Uploads artifacts
   - Auto-merges PR if CI passes (CD)
3. Download artifacts as needed from the workflow run.

---

This setup ensures **automated CI/CD**, providing quick feedback and seamless deployment for your project.
