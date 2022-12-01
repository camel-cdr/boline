#!/bin/sh
printf "#define INPUT "
od -vtx1 -An|xargs|tr \  ,
echo
