#!/bin/sh
sed -n '/^'${1^^}'(.*'${1^^}'(.*$/,/__________/p' ../$2/coffre-fort
exit
