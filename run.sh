#!/bin/bash

# Compile the program
g++ src/main.cpp src/cyberpunk.cpp src/IO.cpp -o bin/mainLinux

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the compiled program
    ./bin/mainLinux
else
    echo "Compilation failed."
fi