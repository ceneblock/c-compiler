#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.72])
AC_INIT([C Compiler],[0.1],[ceneblock@users.noreply.github.com])
AC_CONFIG_SRCDIR([src/main.cpp])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

#Muk up the CFLAGS variable
: ${CFLAGS="-g"}

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
LT_INIT
LT_LANG([C++])

AC_CONFIG_MACRO_DIRS([m4])

# Checks for libraries.
AX_CXX_COMPILE_STDCXX_11([ext],[mandatory])

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])
#AC_CHECK_HEADERS([sys/types.h sys/socket.h netinet/in.h \
#                  string.h arpa/inet.h sys/stat.h fcntl.h \
#                  magic.h poll.h sys/ioctl.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_LIB([pthread], [pthread_create])

AC_OUTPUT
