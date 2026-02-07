# Tips and Tricks for Programming using Cpp

Welcome to the GitHub repository! Here, you'll find all the code and resources from my [**Medium**](https://nitishhsinghhh.medium.com/) articles, focused on sharing practical tips for C++ developers. My aim is to provide easy-to-understand solutions and useful advice to help developers improve their C++ skills.

The articles cover a wide range of **C++ programming** topics, from basic concepts to more advanced techniques. Whether you're just starting out or have years of experience, you'll find helpful tips and examples to boost your knowledge and make coding easier.

No matter your skill level, this repository is a great place to learn and grow. Let’s work together to build a stronger, more knowledgeable tech community!

## Repository Structure

This repository is organized by core C++ and Computer Science topics.
Each folder focuses on a specific concept or learning area.
```
.
├── Algorithms
│   └── Binary Search and other algorithmic patterns
├── ASCII
│   └── ASCII-based logic and pattern problems
├── Article
│   └── Concept-based articles (e.g., Static vs Non-Static, Fibonacci)
├── ClassDiagram
│   └── UML and class diagram examples
├── CommunityResources
│   └── Learning notes and senior developer insights
├── CppBasics
│   └── Core C++ fundamentals
│       └── STL_Containers
├── DesignPattern
│   └── Common software design patterns in C++
├── GIT
│   └── Git commands, workflows, and best practices
├── Interview_Question
│   └── Frequently asked C++ interview questions
├── Leetcode
│   └── Problem-solving practice and solutions
├── Misc
│   └── Miscellaneous C++ utilities and experiments
├── OOP
│   └── Object-Oriented Programming concepts
├── STL
│   └── STL usage and internal behavior
├── SystemDesign
│   └── System design concepts and notes
├── Testing
│   └── Software testing methodologies
├── Working Application
│   └── End-to-end C++ applications
├── LICENSE.md
└── README.md
```

## How to use it

Everything below is an outline, and you should tackle the items in order from top to bottom.

I'm using GitHub's special markdown flavor, including tasks lists to track progress.
  - [More about GitHub-flavored markdown](https://guides.github.com/features/mastering-markdown/#GitHub-flavored-markdown)

### If you don't want to use git

On this page, click the Code button near the top, then click "Download ZIP". Unzip the file and you can work with the text files.

If you're open in a code editor that understands markdown, you'll see everything formatted nicely.

![How to download the repo as a zip file](https://d3j2pkmjtin6ou.cloudfront.net/how-to-download-as-zip.png)

### If you're comfortable with git

Create a new branch so you can check items like this, just put an x in the brackets: [x]

1. ***Fork the GitHub repo:*** `https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp` by clicking on the Fork button.

    ![Fork the GitHub repo](https://d3j2pkmjtin6ou.cloudfront.net/fork-button.png)

1. Clone to your local repo:

    ```bash
      git clone https://github.com/<YOUR_GITHUB_USERNAME>/Tips-and-Tricks-for-Programming-using-Cpp.git
      cd Tips-and-Tricks-for-Programming-using-Cpp

      git remote add upstream https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp.git
      git remote set-url --push upstream DISABLE  # prevent accidental pushes to original repo
    ```

1. Mark all boxes with X after you completed your changes:

    ```bash
      git commit -am "Marked personal progress"
      git pull upstream main   # keep your fork up-to-date with the original repository
      git push                # pushes changes to your fork
    ```


**[⬆ back to top](#Tips-and-Tricks-for-Programming-using-Cpp)**

## What You’ll Find Here
- Hands-on C++ examples from beginner to advanced.
- STL internals & custom implementations:
  - Stack using Queue
  - Custom Vector Class
- Problem-solving patterns for interviews.
- Computer Science basics explained with code.
- Project ideas for practice.

## Why This Repo?
C++ is a powerful language, but mastering its nuances takes time. This repo bridges the gap between theory and practice by providing:

- Clear, documented code (Doxygen-style).
- Real-world examples for interviews and system design.
- Performance insights for writing optimized solutions.

## How to Use

To run these programs, you need to have a C++ compiler installed on your computer. Once that's set up, you can download the program files from this repository and compile them using the compiler. Since C++ is a compiled language, the code needs to be converted from a human-readable format into something a computer can understand. This conversion is done by a tool called a compiler.

Typically C++ source code files are given the suffix:
1. .cpp (ex: firstCode.cpp) or
2. .h (ex: std_lib_facilities.h).

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/900ac352-6779-48de-9644-a069b0f0fef9)

- Compile:
g++ firstCode.cpp -o firstCode <br>
A compiler translates the C++ program into machine language code which it stores on the disk as a file with the extension .o (e.g. firstCode.o). A linker then links the object code with standard library routines that the program may use and creates an executable image which is also saved on disk, usually as a file with the file name without any extension (e.g. firstCode).

- Execute:
./firstCode <br>
The executable is loaded from the disk to memory and the computer’s CPU (Central Processing Unit) executes the program one instruction at a time.
Alternatively, you can also use an online C++ compiler to run these programs without needing to install a compiler on your computer.

**[⬆ back to top](#Tips-and-Tricks-for-Programming-using-Cpp)**

## Getting Started
To compile and run these programs on your local machine, you'll need to have the appropriate programming language and compiler installed. Here are the steps to get started:

1. Clone this repository to your local machine using git clone.
```
git clone https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp.git
```
2. Navigate to the folder containing the program you want to run.
3. Follow the instructions in the program's README file to compile and run the program.

## Contributions
If you have any suggestions for improvements or would like to add additional C++ programs to this repository, please feel free to create a pull request. We welcome contributions from the community to make this repository more useful for everyone.

Contributions to this repository are welcome! If you'd like to contribute, please follow these guidelines:

1. Fork this repository to your own GitHub account.
2. Create a new branch for your changes using git checkout -b my-feature-branch
3. Make your changes and commit them with a descriptive commit message.
4. Push your changes to your forked repository with git push origin my-feature-branch
5. Submit a pull request to this repository with a detailed description of your changes.


## To fork this repository, follow these steps:

1. Navigate to the repository on GitHub.
2. Click on the "Fork" button in the top-right corner of the page.
3. Select the account or organization where you want to fork the repository.
4. Wait for the forking process to complete.

## Contents:
- Tips
- Computer Science Basics
- Learning Resources
- Problem Solving
- Projects Ideas

## Code Documentation Style: Doxygen
This repository follows **[Doxygen-style comments](https://micro-os-plus.github.io/develop/doxygen-style-guide/)** to document all major classes, functions, and modules. Doxygen is a powerful tool that generates structured documentation from annotated C++ source code, making it easier for developers to understand and contribute to the project.

---
### 📌 Commonly Used Doxygen Tags

| Tag        | Description |
|------------|-------------|
| `@brief`   | A short summary of the function/class/module. |
| `@details` | A more detailed explanation, if needed. |
| `@param`   | Describes each parameter of a function. |
| `@return`  | Describes the return value of a function. |
| `@note`    | Additional notes or important information. |
| `@warning` | Highlights potential issues or important caveats. |
| `@see`     | References to related functions or documentation. |
---


## Please help by giving a star

⭐ Please give this repository a star. It takes seconds and help thousands of developers! ⭐

Once you have forked the repository, you will have your own copy of the code and resources to work with. You can make changes to the code, add new resources, and submit pull requests to contribute your changes back to the original repository.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/8ea8a38f-c347-4dcd-8d18-0246e4da2c31)

## Contact
Thank you for your suggestions! If you think there is anything to improve, please contact me at **me.singhnitish@yandex.com.**

**[⬆ back to top](#Tips-and-Tricks-for-Programming-using-Cpp)**

