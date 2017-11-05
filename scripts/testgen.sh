#!/bin/bash

# "Bixi" - Basic types management C89 library
#
#  Copyright (C) Alexey Shishkin 2017
#
#  This file is part of Project "Bixi".
#
#  Project "Bixi" is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Project "Bixi" is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with Project "Bixi". If not, see <http://www.gnu.org/licenses/>.

license="/*\n"`
`"* "Bixi" - Basic types management C89 library\n"`
`"*\n"`
`"*  Copyright (C) Alexey Shishkin 2017\n"`
`"*\n"`
`"*  This file is part of Project "Bixi".\n"`
`"*\n"`
`"*  Project "Bixi" is free software: you can redistribute it and/or modify\n"`
`"*  it under the terms of the GNU Lesser General Public License as published by\n"`
`"*  the Free Software Foundation, either version 3 of the License, or\n"`
`"*  (at your option) any later version.\n"`
`"*\n"`
`"*  Project "Bixi" is distributed in the hope that it will be useful,\n"`
`"*  but WITHOUT ANY WARRANTY; without even the implied warranty of\n"`
`"*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n"`
`"*  GNU Lesser General Public License for more details.\n"`
`"*\n"`
`"*  You should have received a copy of the GNU Lesser General Public License\n"`
`"*  along with Project "Bixi". If not, see <http://www.gnu.org/licenses/>.\n"`
`"*/"

list=$(  find code/libbixi/ -type f -name "*.h" )
while read -r line
do
    echo "making \"$line\""
    fileh=$( echo "$line" | sed 's/libbixi/test/' )
    if [ ! -f "$fileh" ]
    then
        echo "    creating"

        dir=$( dirname "$line" | sed 's/libbixi/test/' )
        echo "        directory: $dir"
        mkdir -p "$dir"
        filec=$( echo "$fileh" | sed 's/\.h/\.c/' )

        echo "        files    : $fileh"
        guard=$( basename "$fileh" | awk '{print toupper($0)}' | sed 's/\./_/' )
        echo "            guard: $guard"
        func=$( echo "$fileh" | sed 's:code\/test\/::; s:\/:_:; s:\.h::' )
        echo "            func : $func"
        echo -e "$license"                                       > "$fileh"
        echo                                                    >> "$fileh"
        echo "#ifndef $guard"                                   >> "$fileh"
        echo "#define $guard"                                   >> "$fileh"
        echo                                                    >> "$fileh"
        echo "void test_$func(void);"                           >> "$fileh"
        echo                                                    >> "$fileh"
        echo "#endif /* $guard */"                              >> "$fileh"

        include=$( echo "$fileh" | sed 's:code\/test:..:' )
        echo "        files    : $filec"
        echo -e "$license"                                       > "$filec"
        echo                                                    >> "$filec"
        echo "#include <stdio.h>"                               >> "$filec"
        echo "#include <libbixi.h>"                             >> "$filec"
        echo "#include \"../test.h\""                           >> "$filec"
        echo "#include \"$include\""                            >> "$filec"
        echo                                                    >> "$filec"
        echo "void test_$func(void)"                            >> "$filec"
        echo "{"                                                >> "$filec"
        echo "   print_info;"                                   >> "$filec"
        echo                                                    >> "$filec"
        echo                                                    >> "$filec"
        echo                                                    >> "$filec"
        echo "   print_passed();"                               >> "$filec"
        echo "}"                                                >> "$filec"
    else
        echo "    already exists"
    fi
done <<< "$list"
