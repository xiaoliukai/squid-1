#!/bin/sh
#
## Copyright (C) 1996-2014 The Squid Software Foundation and contributors
##
## Squid software is distributed under GPLv2+ license and includes
## contributions from numerous individuals and organizations.
## Please see the COPYING and CONTRIBUTORS files for details.
##

echo "/* automatically generated by $0 $*"
echo " * do not edit"
echo " */"
cat `dirname $0`/../../scripts/boilerplate.h
echo "#include \"squid.h\""
echo "#include \"DiskIO/DiskIOModule.h\""
for module in "$@"; do
   echo "#include \"DiskIO/${module}/${module}DiskIOModule.h\""
done
echo ""
echo "void DiskIOModule::PokeAllModules(void)"
echo "{"
for module in "$@"; do
   echo "    ${module}DiskIOModule::GetInstance();"
done
echo "}"
