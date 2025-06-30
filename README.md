# All Projects Studies

This repository is a collection of self-study projects covering a range of topics in programming and computer science. Each directory contains experiments, exercises or small applications meant for learning purposes.

## Table of Contents

- [Networking](Networking/README.md)
- [c](c/README.md)
- [cyber](cyber/README.md)
- [ds](ds/README.md)
- [python](python/README.md)
- [quizzes](quizzes/README.md)
- [system_programming](system_programming/README.md)
- [utils](utils/README.md)

## Directory Overview

### Networking
Materials related to computer networking such as the OSI model, network protocols, tunneling and basic cryptography.

### c
Small C projects exploring compilation, debugging and other language features.

### cyber
Exercises from various cybersecurity topics including recon, brute force, command and control and more.

### ds
Data structure implementations in C.

### python
Sample Python programs demonstrating fundamental language features as well as a simple Flask web application.

### quizzes
Short quiz programs and coding puzzles.

### system_programming
Experiments with system programming concepts like memory mapping, shared libraries and custom allocators.

### utils
Supporting utility code used across projects.

## Building and Running Examples

### C Programs
Many directories contain C sources. Compile them using `gcc` and run the resulting executable:

```bash
gcc path/to/file.c -o program
./program
```

### Python Scripts
Python examples require Python 3. Simply execute them with:

```bash
python3 path/to/script.py
```

The Flask example in `python/python3_web_app_project` additionally requires `flask`, `pymongo` and `requests`. Install dependencies and run it with:

```bash
cd python/python3_web_app_project
pip install flask pymongo requests
python3 app.py
```

For further details, check the README inside each subproject directory.
