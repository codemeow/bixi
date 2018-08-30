## Opening project in QtCreator

The following steps are required to work with the project in QtCreator:

### Clone

Run in terminal:
```sh
mkdir /tmp/test/
cd /tmp/test/
git clone git@github.com:codemeow/bixi.git .
```

### Open in QtCreator

Open file `bixi.creator` in QtCreator via "File -> Open" or via terminal:

Run in terminal:
```sh
qtcreator /tmpotest/bixi.creator
```

### Setup QtCreator

Open "Projects" tab

#### Build

Remove all default steps and add following parameters:

Build directory: `/tmp/test`  
*Build Steps:*  
Add -> Custom:  
Command: `/tmp/test/scripts/build.sh`  
Arguments: `debug`  
Working directory: `/tmp/test`  

Build Environment:
Add -> `LD_LIBRARY_PATH = /tmp/test/bin`

#### Run

Local Install, Run:  
Executable: `/tmp/test/bin/test`  
Working directory: `/tmp/test/`  
Run in terminal: Yes.

To run additional examples you may need to also update LD_LIBRARY_PATH in "Run environment" to
something like `LD_LIBRARY_PATH = /tmp/test/bin:/tmp/test/bin/braxel`