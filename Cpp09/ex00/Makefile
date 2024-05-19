CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = btc

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

all: $(TARGET)