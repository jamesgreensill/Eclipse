### This program will output the amount of lines of code in all source files.
### Ignored Directories will exclude searching folders within the initialDirectory.
### This program searches recursively for source files in all languages.

### This program will create a file called results.%fileExtension%. 

### initialDirectory should point to the root directory of all source files.

### Use the format of "entry,entry,entry,entry" with no whitespace otherwise this will not work.

### EXAMPLE
"ignoredDirectories=debug,dependencies,x64"

### use "../" to go back one directory.
### ../ has to be used in initial directory in order to get out of cloc directory.
"initialDirectory=../sourceFileLocation"

### ABSOLUTE DIRECTORY EXAMPLE
"initialDirectory=C:/Users/user/dev/projectName/project/src"

### OPTIONAL
### For custom file formats, define fileExtension.

### Supported file extension

### XML
### TXT
### YAML
### CSV

### Exmaple:
### "fileExtension=csv"
### "fileExtension=xml"
### "fileExtension=yaml"
### "fileExtension=" <-- this will result in a .txt file.

### Finally the boolean exitWhenFinished.
### leave this as "exitWhenFinished=" to exit immediately.
### define this as "exitWhenFinished=y" to pause when the process is finished.

### by default, this is set as false or "exitWhenFinished=". 

### Remarks.

### Developer of Cloc.exe | AIDaniel. 
### https://github.com/AlDanial/cloc

### Peace - Ryz/James