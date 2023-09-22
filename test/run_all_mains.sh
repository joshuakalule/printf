#!/usr/bin/sh

# Compile and run all main-*.c files in the current directory
for source_file in main-*.c; do
	if [ -f "$source_file" ]; then
		# Extract the file name without the extension
		file_name="${source_file%.c}"
		
		# Compile the C file and create an executable
		gcc -Wall -Werror -Wextra -pedantic -std=gnu89 "$source_file" ../*.c -o "$file_name"

		# Check if compilation was successful
		if [ $? -eq 0 ]; then
			echo ""
			echo "------> Compiled $source_file successfully"

			# Run the executable
			"./$file_name"

			# Clean up the executable
			rm -f "$file_name"
		else
			echo "------> Compilation of $source_file failed"
			echo "Exiting..."
			return 1
		fi		
	fi
done
