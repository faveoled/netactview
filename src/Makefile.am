## Process this file with automake to produce Makefile.in

## Created by Anjuta

INCLUDES = \
	-DPREFIX=\""$(prefix)"\" \
	-DBINDIR=\""$(bindir)"\" \
	-DLOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DSRCDIR=\""$(srcdir)"\" \
	-DDATADIR=\""$(datadir)"\" \
	-DSYSCONFDIR=\"$(sysconfdir)\" \
	-DLIBDIR=\"$(libdir)\" \
	$(NETACTVIEW_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = netactview

netactview_SOURCES = \
	main.c \
	mainwindow.c \
	mainwindow.h \
	net.c \
	net.h \
	process.c \
	process.h \
	nactv-debug.h \
	definitions.h \
	utils.h \
	utils.c \
	filter.c \
	filter.h

netactview_LDFLAGS = 

netactview_LDADD = $(NETACTVIEW_LIBS)

@INTLTOOL_XML_RULE@
uifile = $(srcdir)/netactview.ui
uidir = $(datadir)/netactview
ui_DATA = $(uifile)
EXTRA_DIST = netactview.ui
