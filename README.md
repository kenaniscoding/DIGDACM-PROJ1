# NRZ-S and BAMI HDB3 Line Encoding and Decoding
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
Run the main program
```
./menu.sh
```
### NRZ-S Encoding
```
-+++-+---++-
```
output should be 101100011010
### NRZ-S Decoding
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
![image](https://github.com/kenaniscoding/DIGDACM-PROJ1/assets/112913035/c7839ad9-271b-46c9-8e71-68fd85f54eb3)

