FROM gcc:14

WORKDIR /app

COPY src/ ./src/

RUN g++ -std=c++20 -Wall -Wextra src/main.cpp src/twosum.cpp -o twosum_test

CMD ["./twosum_test"]
