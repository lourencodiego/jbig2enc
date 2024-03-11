AM_CXXFLAGS = -Wall
AM_LDFLAGS = -Wl,-E
if ENABLE_RPATH
AM_LDFLAGS += -Wl,-rpath -Wl,$(libdir)
endif

lib_LTLIBRARIES = libjbig2enc.la
libjbig2enc_la_SOURCES = jbig2enc.cc jbig2arith.cc jbig2sym.cc jbig2comparator.cc
libjbig2enc_la_LDFLAGS = -no-undefined -version-info $(GENERIC_LIBRARY_VERSION)
include_HEADERS = jbig2arith.h jbig2sym.h jbig2structs.h jbig2segments.h jbig2comparator.h

lib_LTLIBRARIES = libjbig2.la
libjbig2_la_SOURCES = jbig2.cc
libjbig2_la_LDFLAGS = -no-undefined -version-info $(GENERIC_LIBRARY_VERSION)
include_HEADERS = jbig2.h

bin_PROGRAMS = dsjbig2
dsjbig2_SOURCES = dsjbig2.cc
dsjbig2_LDADD = libjbig2enc.la libjbig2.la 
dsjbig2_LDFLAGS = -static

if MINGW
dsjbig2_LDADD += -lws2_32
endif 
