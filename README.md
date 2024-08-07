# Piping NRZ-S and BAMI HDB3 Line Encoding and Decoding Schemes
![image](https://github.com/kenaniscoding/DIGDACM-PROJ1/assets/112913035/d0fd85e2-9e91-4f33-bc91-fdfc5974052f)
## Description
- Digital Communications has different parts in the encoding and decoding of data
- One of the blocks is Line Coding
- Line Coding is the process of converting digital data to digital signals
- There are different Line Coding techiques as shown below
![image](https://github.com/kenaniscoding/DIGDACM-PROJ1/assets/112913035/701a7d73-8aaa-41e0-8d29-1df1809fb562)
![image](https://upload.wikimedia.org/wikipedia/commons/6/63/AMI%2C_HDB3_%281%29.jpg)
- The techniques used in this code are NRZ-S and BAMI HDB3
- NRZ-S or Non-Return-to-Zero Space
- BAMI or Bipolar Alternate Mark Inversion Encoding
- HDB3 or High Density Bipolar Order 3
## Commands 
### Running the program
Go to the correct directory
```
cd ./proj2
```
Make the shell script program executable
```
chmod +x menu.sh
```
```
gcc linecoding_nrzs_encoding.c -o linecoding_nrzs_encoding
```
```
gcc linecoding_nrzs_decoding.c -o linecoding_nrzs_decoding
```
```
gcc BAMI_HDB3_Encoder.c -o BAMI_HDB3_Encoder
```
```
gcc BAMI_HDB3_Decoder.c -o BAMI_HDB3_Decoder
```
Run the main program
```
./menu.sh
```
### NRZ-S Decoding
```
-+++-+---++-
```
output should be 101100011010
### NRZ-S Encoding
```
101100011010
```
output should be -+++-+---++-
### BAMI HDB3 Encoding
```
1010000011000011000000
```
output should be ++00--++0000++00--++--0000--++--++0000++0000
### BAMI HDB3 Decoding
```
++00--++0000++00--++--0000--++--++0000++0000
```
output should be 1010000011000011000000
## Flowchart

## Example Output
![image](https://github.com/user-attachments/assets/bebc8a4b-40e1-4007-87ae-eeaba19bee49)


