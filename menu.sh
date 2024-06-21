#!/bin/bash

# Compile the C program
gcc nrzs_decoding.c -o nrzs_decoding

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the compiled program
    ./nrzs_decoding
else
    echo "Compilation failed."
fi
