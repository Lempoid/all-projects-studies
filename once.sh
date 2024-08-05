#!/bin/bash

read -p "Enter starting directory: " starting_directory

# Validate the input directory
if [ ! -d "$starting_directory" ]; then
    echo "The directory '$starting_directory' does not exist."
    exit 1
fi

# Find and delete all dummy.md files
find "$starting_directory" -type f -name 'dummy.md' -exec rm -f {} +

echo "All dummy.md files have been removed from '$starting_directory' and its subdirectories."

