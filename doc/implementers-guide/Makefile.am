include ../Makefile.inc

SRC    = $(top_srcdir)/doc/implementers-guide/implementers-guide.adoc
TARGET = implementers-guide.html

EXTRA_DIST = $(SRC)

doc_DATA = $(TARGET)
$(TARGET): $(SRC)

clean-local:
	rm -f  $(builddir)/$(TARGET)
