/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include "nactv-debug.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "config.h"

#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gi18n.h>

#include "mainwindow.h"
#include "definitions.h"
#include "net.h"

GtkBuilder *Builder = NULL;


int
main (int argc, char *argv[])
{
	GtkWidget *window;
	
#ifdef ENABLE_NLS
	bindtextdomain(GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);
#endif
	
	gtk_init(&argc, &argv);
	
	g_set_application_name(PACKAGE);

	Builder = gtk_builder_new();
	if (gtk_builder_add_from_file(Builder, GLADEFILE, NULL) != 0)
	{
		nactv_net_init();
		
		window = main_window_create();
		gtk_widget_show(window);
		
		gtk_main();
		
		main_window_data_cleanup();
		nactv_net_free();
		g_object_unref(Builder); Builder = NULL;
	}else
	{
		g_printerr("Error loading %s \nThe application might not be correctly installed.\n", 
				   GLADEFILE);
	}
	
	return 0;
}
