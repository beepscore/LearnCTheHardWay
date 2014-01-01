# Purpose
Record info about Learn C The Hard Way ex18

# References
ex18.c
ex18.sh

# Results

## example output

$ ./ex18.sh
0 1 2 3 4 7 8
55:48:89:e5:89:7d:fc:89:75:f8:8b:75:fc:2b:75:f8:89:f0:5d:c3:66:66:66:2e:0f:
8 7 4 3 2 1 0
55:48:89:e5:89:7d:fc:89:75:f8:8b:75:f8:2b:75:fc:89:f0:5d:c3:66:66:66:2e:0f:
3 4 2 7 1 0 8
55:48:89:e5:89:7d:f8:89:75:f4:81:7d:f8:00:00:00:00:0f:84:0d:00:00:00:81:7d:

## Extra Credit

### Hex editor
#### Xcode
To use Xcode hex editor, open file in Xcode, then shift-command-j / open as hex
Open compiled program ex18, not source code ex18.c
I changed characters in comments and re-ran ex18 without a problem.
I changed characters in error message, re-ran ex18 without arguments to make error message print, no problem.

#### HexFiend

#### Aquamacs / emacs
hexl mode for editing binary files
http://www.gnu.org/software/emacs/manual/html_node/emacs/Editing-Binary-Files.html
M-x <filename>
Or in Aquamacs pull down menu open file, then menu File/change buffer mode/hex.

#### MacVim
This seems like a poor implementation, hex at left and text at right don't update each other when editing.
Open file, then menu Tools / Convert to Hex
Edit and convert back.

