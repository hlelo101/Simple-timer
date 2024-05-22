# Simple-timer
A (very) simple timer
# Compile
**Example**\
To compile the code, you will need the [webUI](http://webui.me) library.
The following is an example where the Timer folder (containing the simple timer) is placed in the Documents folder of a Linux system and that the username is hlelo101 (heh):
The folders are organized like this:
Timer\
├── main.cpp\
├── include\
│   └── webui.h\
│   └── webui.hpp\
├── lib\
│   └── libwebui-2-static.a\
│   └── webui-2.so\
└── web\
    └── index.html
    
Then, assuming that g++ is installed and that the terminal is opened in the timer directory, the following command would compile the program:
```batch
g++ -o main main.cpp /home/[yourUsername]/Documents/Timer/lib/libwebui-2-static.a -static
```
