# Deployment Instructions

## 1. Prerequisites

### System Requirements
- **OS**: Windows, Linux, or macOS
- **C++ Compiler**: GCC 11+, Clang 13+, or MSVC 2019+
- **Language Standard**: C++20 support required
- **Disk Space**: ~1 MB for source and executable

### Optional Requirements
- Git (for version control)
- Make (for automated builds)
- CMake (for advanced build management)

## 2. Installation & Setup

### Step 1: Obtain Source Code
```bash
# Clone repository (if using Git)
git clone https://github.com/RyuuNesta/11402_CS351_Project0.git
cd 11402_CS351_Project0

# Or extract from provided archive
unzip 11402_CS351_Project0.zip
cd 11402_CS351_Project0
```

### Step 2: Verify Directory Structure
```
11402_CS351_Project0/
├── README.md
├── src/
│   ├── main.cpp
│   ├── twosum.cpp
│   └── twosum.h
├── docs/
│   ├── 00_intended_use.md
│   ├── 01_plan.md
│   ├── 02_SRS.md
│   ├── 03_SDS.md
│   ├── 04_test_plan.md
│   ├── 05_acceptance_tests.md
│   ├── 06_traceability.md
│   ├── 07_deploy.md
│   └── 08_known_issues.md
```

## 3. Build Instructions

### Option 1: Using GCC (Recommended for Linux/macOS)
```bash
cd 11402_CS351_Project0
g++ -std=c++20 -Wall -Wextra -O2 -o twosum src/main.cpp src/twosum.cpp
```

### Option 2: Using Clang
```bash
cd 11402_CS351_Project0
clang++ -std=c++20 -Wall -Wextra -O2 -o twosum src/main.cpp src/twosum.cpp
```

### Option 3: Using MSVC (Windows)
```cmd
cd 11402_CS351_Project0
cl /std:c++20 /W4 /EHsc src/main.cpp src/twosum.cpp /Fe:twosum.exe
```

### Build Output
```
Compiling src/main.cpp...
Compiling src/twosum.cpp...
Linking...
✓ Executable created: twosum (or twosum.exe on Windows)
```

## 4. Running the Program

### Linux/macOS
```bash
./twosum
```

### Windows
```cmd
.\twosum.exe
```

### Expected Output
```
=== Two Sum Problem - C++20 Implementation ===

Test 1: Basic case
  Array Approach - Input: [2, 7, 11, 15], Target: 9 -> [0, 1] (values: 2 + 7 = 9)
  Hash Table Approach - Input: [2, 7, 11, 15], Target: 9 -> [0, 1] (values: 2 + 7 = 9)

Test 2: Negative numbers
  Array Approach - Input: [-3, 4, 3, 90], Target: 0 -> [0, 1] (values: -3 + 3 = 0)
  Hash Table Approach - Input: [-3, 4, 3, 90], Target: 0 -> [0, 1] (values: -3 + 3 = 0)

[... additional test results ...]
```

## 5. Troubleshooting

### Issue: Compiler Not Found
**GCC/Clang not found**:
```bash
# Ubuntu/Debian
sudo apt-get install build-essential g++

# macOS
brew install gcc

# Windows (MSVC)
# Download from Microsoft Visual Studio
```

### Issue: C++20 Not Supported
**Error**: Unknown option '-std=c++20'
```bash
# Update compiler to version supporting C++20
# GCC: version 11 or later
# Clang: version 13 or later
```

### Issue: Build Warnings
**Solution**: Ensure clean compilation
```bash
# Add extra flags for debugging
g++ -std=c++20 -Wall -Wextra -pedantic -o twosum src/main.cpp src/twosum.cpp
```

### Issue: Linker Errors
**Solution**: Ensure both source files are compiled
```bash
# Make sure to include both files
g++ -std=c++20 src/main.cpp src/twosum.cpp -o twosum
```

## 6. Advanced Configuration

### Optimization Levels
```bash
# Debug build (no optimization)
g++ -std=c++20 -g -O0 -o twosum src/main.cpp src/twosum.cpp

# Release build (with optimization)
g++ -std=c++20 -O2 -o twosum src/main.cpp src/twosum.cpp

# Maximum optimization
g++ -std=c++20 -O3 -o twosum src/main.cpp src/twosum.cpp
```

### Sanitizers (for debugging)
```bash
# Memory sanitizer (detects memory leaks)
g++ -std=c++20 -fsanitize=address -g -o twosum src/main.cpp src/twosum.cpp

# Undefined behavior sanitizer
g++ -std=c++20 -fsanitize=undefined -g -o twosum src/main.cpp src/twosum.cpp
```

### Using a Makefile
**Create Makefile**:
```makefile
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2
TARGET = twosum
SOURCES = src/main.cpp src/twosum.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
```

**Build with Make**:
```bash
make              # Build
make clean        # Clean
```

## 7. Integration with Other Projects

### Linking as Library
To use the twosum functions in other projects:

1. Add to your project:
```cpp
// Include in your file
#include "twosum.cpp"  // Or compile separately and link

// Use the functions
std::vector<int> result = twoSumArray(nums, target);
std::vector<int> result = twoSumHashTable(nums, target);
```

2. Compile together:
```bash
g++ -std=c++20 your_project.cpp src/twosum.cpp -o your_program
```

## 8. Performance Verification

Run performance tests:
```bash
# Build with optimization
g++ -std=c++20 -O2 -o twosum src/main.cpp src/twosum.cpp

# Run with timing
time ./twosum
```

Expected performance:
- Array approach: < 1ms for 10,000 elements
- Hash table approach: < 0.5ms for 10,000 elements

## 9. Deployment Checklist

- [ ] Source code obtained
- [ ] Directory structure verified
- [ ] Compiler installed and working
- [ ] C++20 support confirmed
- [ ] Build successful without warnings
- [ ] Program executes without errors
- [ ] All test cases produce correct output
- [ ] Performance meets expectations
- [ ] Documentation reviewed

## 10. Support & Maintenance

### Reporting Issues
If you encounter issues:
1. Check troubleshooting section above
2. Verify all prerequisites are installed
3. Review documentation files
4. Check for known issues in `docs/08_known_issues.md`

### Updates
Monitor the repository for updates:
```bash
git pull origin main  # Get latest changes
```

### Contact
For questions or support:
- Repository: https://github.com/RyuuNesta/11402_CS351_Project0
- Issues: Use GitHub Issues for bug reports
