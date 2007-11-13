#!/bin/ksh
#BHEADER**********************************************************************
# Copyright (c) 2007, Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# Written by the HYPRE team. UCRL-CODE-222953.
# All rights reserved.
#
# This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
# Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
# disclaimer, contact information and the GNU Lesser General Public License.
#
# HYPRE is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License (as published by the Free Software 
# Foundation) version 2.1 dated February 1999.
#
# HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
# WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
# FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
# Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# $Revision$
#EHEADER**********************************************************************


TNAME=`basename $0 .sh`

#=============================================================================
# The outputs below should differ only in timings.
#=============================================================================

diff -bI"time" solvers.out.0 solvers.out.1 >&2
diff -bI"time" solvers.out.2 solvers.out.3 >&2
diff -bI"time" solvers.out.4 solvers.out.5 >&2
diff -bI"time" solvers.out.6 solvers.out.7 >&2
diff -bI"time" solvers.out.8 solvers.out.9 >&2
diff -bI"time" solvers.out.10 solvers.out.11 >&2

#=============================================================================
# compare with baseline case
#=============================================================================

FILES="\
 ${TNAME}.out.0\
 ${TNAME}.out.1\
 ${TNAME}.out.2\
 ${TNAME}.out.3\
"
for i in $FILES
do
  echo "# Output file: $i"
  tail -17 $i | head -8
done > ${TNAME}.out

FILES="\
 ${TNAME}.out.4\
 ${TNAME}.out.5\
 ${TNAME}.out.6\
 ${TNAME}.out.7\
"
for i in $FILES
do
  echo "# Output file: $i"
  tail -4 $i
done >> ${TNAME}.out

FILES="\
 ${TNAME}.out.8\
 ${TNAME}.out.9\
 ${TNAME}.out.10\
 ${TNAME}.out.11\
"

for i in $FILES
do
  echo "# Output file: $i"
  tail -22 $i | head -13
done >> ${TNAME}.out

if [ -z $HYPRE_NO_SAVED ]; then
   diff -U3 -bI"time" ${TNAME}.saved ${TNAME}.out >&2
fi

#=============================================================================
# remove temporary files
#=============================================================================

# rm -f ${TNAME}.testdata*
