#!/bin/bash

# Compile the program
g++ src/main.cpp src/cyberpunk.cpp src/IO.cpp -o bin/main

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the compiled program
    ./bin/main
    rm ./bin/main
else
    echo "Compilation failed."
fi