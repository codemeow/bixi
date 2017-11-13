#!/bin/bash

# "C-otter" - C/C++ projects manager
#
#  Copyright (C) Alexey Shishkin 2016-2017
#
#  This file is part of Project "C-otter".
#
#  Project "C-otter" is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Project "C-otter" is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with Project "C-otter". If not, see <http://www.gnu.org/licenses/>.

set -e

GLOBAL_DEBUG_MODE="$1"
GLOBAL_COMPILER_OPTIONS="$2"

# @todo support of +--- instead of ┌───

# Error holder
ERROR_HOLDER="/tmp/build-holder.log"
> "$ERROR_HOLDER"

# Functions section
Die()
{
    echo "$@" 1>&2 
    ShowErrors
    kill -SIGPIPE $$
}

GrepValid()
{
    echo | grep $1 "" >/dev/null 2>&1
}

CompilerValid()
{
    local name="$1"
    if [ -z "$name" ]
    then
        name="cc";
    fi
    ( command -v $name > /dev/null && echo "$1"   ) || \
    ( command -v cc    > /dev/null && echo "cc"   ) || \
    ( command -v gcc   > /dev/null && echo "gcc"  ) || \
    ( command -v clang > /dev/null && echo "clang") || \
    ( command -v icc   > /dev/null && echo "icc"  ) || \
    ( Die "Can't find appropriate compiler"       )
}

Md5Calc()
{
    #          Linux                                 || Minix
    ( command -v md5sum > /dev/null && md5sum "$1" ) || md5 -n "$1"
}

Initialise()
{
    if [ "$GLOBAL_DEBUG_MODE" == "debug" ]
    then
        COMPILER_DEBUG="-g"
    elif [ "$GLOBAL_DEBUG_MODE" == "release" ]
    then
        COMPILER_DEBUG="-O2"
    else
        Die "Wrong debug type, give 'debug' or 'release'"
    fi
}

Include()
{
    GREP_OPTIONS=""

    if GrepValid --color=never
    then
        GREP_OPTIONS+=" --color=never"
    fi

    echo "┌─── Including"
    FILE_CONFIG=`find . -maxdepth 1 -name "*.config"`
    echo "├ $FILE_CONFIG"
    if [ ! -f "$FILE_CONFIG" ]
    then
        Die "Config file $FILE_CONFIG not found"
    fi

    source "$FILE_CONFIG"

    FILE_FILELIST="$GLOBAL_PROJECT_NAME.files"
    FILE_INCLUDES="$GLOBAL_PROJECT_NAME.includes"
    FILE_SUBPROJECTS="$GLOBAL_PROJECT_NAME.subprojects"

    FILE_EXPORT="$DIRECTORY_SCRIPTS/export.sh"

    echo "├ ./$FILE_EXPORT"
    source "./$FILE_EXPORT"
    echo "└───"

    mkdir -p $DIRECTORY_BIN
    mkdir -p $DIRECTORY_BUILD
    mkdir -p $DIRECTORY_INCLUDES
}

CleanSingle()
{
    DIRECTORY_CLEAN=$1
    if [ -z "$DIRECTORY_CLEAN" ]
    then
       Die "Can't load directory to clean, check config files"
    fi

    find "./$DIRECTORY_CLEAN" ! -path . ! -path "./$DIRECTORY_CLEAN" | while read -r file ;
    do
       echo "├ $file"
       rm -rf $file
    done
}

CleanBinary()
{
    echo "┌─── Cleaning binary"
    CleanSingle $DIRECTORY_BIN
    echo "└───"
}

CleanObject()
{
    echo "┌─── Cleaning objects"
    CleanSingle $DIRECTORY_BUILD
    echo "└───"
}

CleanIncludes()
{
    echo "┌─── Cleaning includes"
    CleanSingle $DIRECTORY_INCLUDES
    echo "└───"
}

Configure()
{
    PROJECT_NAME=""
    PROJECT_TYPE=""

    PROJECT_VERSION_MAJOR=""
    PROJECT_VERSION_MINOR=""
    PROJECT_VERSION_BUILD=""

    COMPILER_NAME=""
    COMPILER_STD=""
    COMPILER_OPTIONS=""

    DEPENDENCY_LINE=""
    DEPENDENCY_PATH=""
    DEPENDENCY_CINCLUDES=""
    DEPENDENCY_INCLUDE=""
    DEPENDENCY_LIST=""

    LINKER_OPTIONS=""

    EXPORT_FILE_PREFIX=""

    DIRECTORY_DESTINATION="."

    RUN_BEFORE_COMPILE=""
    RUN_AFTER_COMPILE=""
    RUN_AFTER_LINK=""
    RUN_AFTER_EXPORT=""

    DIRECTORY_PROJECT=$1

    source $DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG

    COMPILER_NAME=$( CompilerValid $COMPILER_NAME )

    COMPILER_OPTIONS+=" $GLOBAL_COMPILER_OPTIONS "

    echo "┌─── Configuring project"
    echo "├ Compiler name: $COMPILER_NAME"
    echo "├ Compiler std : $COMPILER_STD"
    echo "├ Compiler opt : $COMPILER_OPTIONS"
    echo "├ Linker opt   : $LINKER_OPTIONS"
    echo "└───"

    # Clang's whining fix about unused args
    if [ "$COMPILER_NAME" == "clang" ]
    then
        COMPILER_OPTIONS+=" -Wno-error=unused-command-line-argument"
        COMPILER_OPTIONS+=" -Wno-unused-command-line-argument"
    fi

    if [ ! -z "$DEPENDENCY_INCLUDE" ]
    then
        COMPILER_OPTIONS+=" -I$DEPENDENCY_INCLUDE"
    fi
    if [ "$PROJECT_TYPE" == "lib" ]
    then
        COMPILER_OPTIONS+=" -fPIC"
        LINKER_OPTIONS+=" -shared"
        OUTPUT_EXTENSION=".so"
        PROJECT_BINARY="lib$PROJECT_NAME"

        VERSION_M=".$PROJECT_VERSION_MAJOR"
        VERSION_MM=$VERSION_M.$PROJECT_VERSION_MINOR
        VERSION_MMB=$VERSION_MM.$PROJECT_VERSION_BUILD
    elif [ "$PROJECT_TYPE" == "app" ]
    then
        OUTPUT_EXTENSION=""
        PROJECT_BINARY="$PROJECT_NAME"

        VERSION_M=""
        VERSION_MM=""
        VERSION_MMB=""
    else
        Die "Wrong PROJECT_TYPE ($PROJECT_TYPE)"
    fi
}

IncrementBuild()
{
    if [ ! -z "$PROJECT_VERSION_BUILD" ]
    then
        BUILD_NUMBER_CURRENT=$(grep '^PROJECT_VERSION_BUILD' \
                              ./$DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG | \
                              cut -f2- -d=)
        BUILD_NUMBER_NEXT=$BUILD_NUMBER_CURRENT
        ((BUILD_NUMBER_NEXT++))
        SED_BEFORE="PROJECT_VERSION_BUILD=$BUILD_NUMBER_CURRENT"
        SED_AFTER="PROJECT_VERSION_BUILD=$BUILD_NUMBER_NEXT"
        # I'm aware of -i option. Unfortunately it is not
        # supported on some systems like Minix or Mac OS
        sed "s/^$SED_BEFORE/$SED_AFTER/" \
            "./$DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG" > "./$DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG.bak"
        rm "./$DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG"
        mv "./$DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG.bak" "./$DIRECTORY_PROJECT/$SUBPROJECT_FILE_CONFIG"
    fi
}

Compile()
{
    if [ ! -z "$RUN_BEFORE_COMPILE" ]
    then
      echo "┌─── Running before compiling"
       source "$RUN_BEFORE_COMPILE"
       echo "└───"
    fi

    echo "┌─── Compiling"
    if [ ! -z "$COMPILER_STD" ]
    then
        COMPILER_STD="-std=$COMPILER_STD"
    fi
    find $DIRECTORY_PROJECT -name "*.c" -o -name "*.cpp" | while read -r file_c ;
    do
        echo "├ $file_c"

        file_o=$(Md5Calc "$file_c" | awk '{ printf "%s%s", $1, ".o"; }')

        $COMPILER_NAME \
            $COMPILER_OPTIONS \
            $COMPILER_DEBUG \
            $COMPILER_STD \
            -DPROJECT_VERSION_MAJOR="$PROJECT_VERSION_MAJOR" \
            -DPROJECT_VERSION_MINOR="$PROJECT_VERSION_MINOR" \
            -DPROJECT_VERSION_BUILD="$PROJECT_VERSION_BUILD" \
            -L"$DIRECTORY_BIN" \
            -I"$DIRECTORY_INCLUDES" \
            -c "$file_c" \
            -o "./$DIRECTORY_BUILD/$file_o" >>"$ERROR_HOLDER" 2>&1

        if [ $? -ne 0 ]
        then
            echo "├ $COMPILER_NAME has failed, aborting"
            echo "└───"
            Die "Error occured"
        fi
    done
    echo "└───"

    if [ ! -z "$RUN_AFTER_COMPILE" ]
    then
        echo "┌─── Running after compiling"
        source "$RUN_AFTER_COMPILE"
        echo "└───"
    fi
}

Link()
{
    echo "┌─── Linking"
    find ./$DIRECTORY_BUILD -name "*.o" | while read -r file_o ;
    do
        echo "├ $file_o"
    done

    $COMPILER_NAME $LINKER_OPTIONS \
            ./$DIRECTORY_BUILD/*.o \
        -o "./$DIRECTORY_BIN/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MMB" \
           -L"$DIRECTORY_BIN" \
              $DEPENDENCY_PATH $DEPENDENCY_LIST >>"$ERROR_HOLDER" 2>&1

        if [ $? -ne 0 ]
        then
            echo "├ $COMPILER_NAME has failed linking, aborting"
            echo "└───"
            Die "Error occured"
        fi

    echo "└───"
    if [ ! -z "$RUN_AFTER_LINK" ]
    then
       echo "┌─── Running after linking"
       source "$RUN_AFTER_LINK"
       echo "└───"
    fi
}

Symlink()
{
    echo "┌─── Symlinking"
    if [ "$DIRECTORY_DESTINATION" != "." ]
    then
        mkdir -p "./$DIRECTORY_BIN/$DIRECTORY_DESTINATION"
        mv "./$DIRECTORY_BIN/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MMB" \
           "./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MMB"
    fi
    if [ ! -z "$VERSION_MMB" ]
    then
        echo  "├ ./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MM"
        ln -s "$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MMB" \
              "./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MM"

        echo  "├ ./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_M"
        ln -s "$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MMB" \
              "./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_M"

        echo  "├ ./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION"
        ln -s "$PROJECT_BINARY$OUTPUT_EXTENSION$VERSION_MMB" \
              "./$DIRECTORY_BIN/$DIRECTORY_DESTINATION/$PROJECT_BINARY$OUTPUT_EXTENSION"
    fi
    echo "└───"
}

Export()
{
    echo "┌─── Exporting"
    if [ "$PROJECT_TYPE" == "lib" ]
    then
        ExportSingle
    fi
    echo "└───"
    if [ ! -z "$RUN_AFTER_EXPORT" ]
    then
       echo "┌─── Running after exporting"
       source "$RUN_AFTER_EXPORT"
       echo "└───"
    fi
}

ShowErrors()
{
    echo "┌─── Errors" >&2

    while IFS= read -r line
    do
        echo -e "$line" >&2
    done < "$ERROR_HOLDER"

    echo "└───" >&2
}

# Run section
trap ShowErrors EXIT

Initialise
Include
CleanBinary
CleanIncludes
grep "^[^#]" $FILE_SUBPROJECTS | while read -r subproject ;
do
    CleanObject
    Configure "./$DIRECTORY_CODE/$subproject"
    IncrementBuild
    Compile
    Link
    Symlink
    Export
done

