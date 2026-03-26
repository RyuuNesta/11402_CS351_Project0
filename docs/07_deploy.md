# Deployment

Build instructions (local):

```
g++ -std=c++20 -Wall -Wextra -o twosum src/main.cpp src/twosum.cpp
./twosum
```

For CI:
- Use GitHub Actions with matrix on ubuntu-latest/windows-latest
- Run the same command above and ensure exit code 0
