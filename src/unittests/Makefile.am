bin_PROGRAMS		=	test

AM_CXXFLAGS			= $(AC_CXXFLAGS)
AM_CPPFLAGS			= $(AC_CPPFLAGS)

opentxs_include_dir =	$(top_srcdir)/include
opentxs_source_dir	=	$(top_srcdir)/src

otlib_build_dir		=	$(top_builddir)/src/otlib
otapi_build_dir		=	$(top_builddir)/src/otapi

common_includes		=	-I$(opentxs_include_dir)		\
						-I$(opentxs_include_dir)/otlib		\
						-I$(opentxs_include_dir)/otapi		\
						-DOT_PREFIX_PATH="\"${prefix}\"" \
						$(DEPS_CFLAGS)

test_SOURCES		=	test.cpp
test_CXXFLAGS		=	$(common_includes) \
						-I/home/eyvind/src/gtest-1.6.0/include \
						-I/home/eyvind/src/git/hippomocks
test_LDADD			=	$(otlib_build_dir)/libot.la \
						$(otapi_build_dir)/libotapi.la \
						$(DEPS_LIBS)
#/home/eyvind/src/gtest-1.6.0/build/libgtest.a \
#/home/eyvind/src/gtest-1.6.0/build/libgtest_main.a \
test_DEPENDENCIES	=	$(otlib_build_dir)/libot.la



#### Transport ZMQ 'option'

if TRANSPORT_ZMQ
test_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif

