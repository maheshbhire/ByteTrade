#!/bin/bash
# Specify the name of the output executable
OUTPUT_EXECUTABLE="output/trade"

# Create output directory if it doesn't exist
mkdir -p output

# Compile the C++ code
g++ -o "$OUTPUT_EXECUTABLE" main.cpp curl_functions.cpp functions.cpp -lcurl -ljsoncpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./"$OUTPUT_EXECUTABLE"
else
    echo "Compilation failed."
fi