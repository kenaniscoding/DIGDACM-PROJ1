#!/bin/bash

# Function to compile and run a C program
run_program() {
    program_name=$1
    gcc ${program_name}.c -o ${program_name}
    
    if [ $? -eq 0 ]; then
        #echo "Compilation successful. Running ${program_name}..."
        #./${program_name}
        read -p "Enter the input to be piped: " user_input
        echo "$user_input"|./${program_name} 
    else
        echo "Compilation failed for ${program_name}."
    fi 
}
run_with_piping() {
    read -p "Pipe in => " user_input
    echo "$user_input" | ./linecoding_nrzs_decoding | ./linecoding_nrzs_encoding
}
# Display the menu
while true; do
    echo "Select a program to run:"
    echo "1) NRZS Decoding"
    echo "2) NRZS Encoding"
    echo "3) BAMI HDB3 Encoder"
    echo "4) BAMI HDB3 Decoder"
    echo "5) Exit"
    read -p "Enter your choice [1-5]: " choice

    case $choice in
        1)
            echo "Input high (+) and low (-) values: "
            run_program "linecoding_nrzs_decoding"
            echo
            read -n 1 -p "Do you want to connect from decoding to encoding? (y or n): " response1
            echo
            if [ "$response1" = "y" ]; then
                read -p "Pipe in => " user_input1
                echo "$user_input1" | ./linecoding_nrzs_decoding | ./linecoding_nrzs_encoding
            else
                echo "Not piping."
            fi
            echo
            ;;
        2)
            echo "Input binary (0 and 1) values: "
            run_program "linecoding_nrzs_encoding"
            echo
            read -n 1 -p  "Do you want to connect it to the from encoding to decoding? (y or n): " response2
            echo
            if [ "$response2" = "y" ]; then
                read -p "Pipe in => " user_input2
                echo "$user_input2"|./linecoding_nrzs_encoding|./linecoding_nrzs_decoding
            else
                echo "Not piping."
            fi
            echo
            ;;
        3)
            echo "Input binary (0 and 1) values: "
            run_program "BAMI_HDB3_Encoder"
            echo
            read -n 1 -p "Do you want to connect it to the from encoding to decoding? (y or n): " response3
            echo
            if [ "$response3" = "y" ]; then
                read -p "Pipe in => " user_input3
                echo "$user_input3"|./BAMI_HDB3_Encoder|./BAMI_HDB3_Decoder
            else
                echo "Not piping."
            fi
            echo
            ;;
        4)
            echo "Input positive (+), negative (-), and null (0) values"
            run_program "BAMI_HDB3_Decoder"
            echo
            read -n 1 -p "Do you want to connect it to the from decoding to encoding? (y or n): " response4
            echo
            if [ "$response4" = "y" ]; then
                read -p "Pipe in => " user_input4
                echo "$user_input4" | ./BAMI_HDB3_Decoder | ./BAMI_HDB3_Encoder
            else
                echo "Not piping."
            fi
            echo
            ;;
        5)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please select a valid option."
            ;;
    esac
done
