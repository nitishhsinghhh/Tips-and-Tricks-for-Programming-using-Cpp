# Contributing Guidelines

Thank you for considering contributing to **Tips and Tricks for Programming using Cpp**   
Contributions of all kinds—code, documentation, fixes, and examples—are welcome.

---
## Before You Start
- Make sure your code compiles and runs successfully
- Keep changes focused on a single topic or improvement
- Follow the existing folder structure and naming conventions
- Add comments or documentation where it improves clarity
---
## Fork the Repository
- Open the repository on GitHub
- Click the **Fork** button (top-right)

---

## Clone Your Fork

```bash
git clone https://github.com/<YOUR_GITHUB_USERNAME>/Tips-and-Tricks-for-Programming-using-Cpp.git
cd Tips-and-Tricks-for-Programming-using-Cpp
```
Add upstream:
```bash
git remote add upstream https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp.git
git remote set-url --push upstream DISABLE
```

---
## Create a Feature Branch
```bash
git checkout -b my-feature-branch
```
---

## Make Your Changes
- Follow existing folder structure
- Keep examples simple and readable
- Use Doxygen-style comments where applicable

## Commit Your Changes
```bash
git commit -m "Add binary search edge case examples"
```
---
## Sync with Upstream
```bash
git pull upstream main
```
---
## Push and Open a Pull Request
```bash
git push origin my-feature-branch
```
---

## Pull Request Guidelines
- Use a clear and descriptive title
- Explain **what** you changed and **why**
- Keep pull requests focused on a single improvement
- Link related issues if applicable
