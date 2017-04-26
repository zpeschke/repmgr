/*
 * repmgr-client-global.h
 * Copyright (c) 2ndQuadrant, 2010-2017
 */

#ifndef _REPMGR_CLIENT_GLOBAL_H_
#define _REPMGR_CLIENT_GLOBAL_H_

#include "config.h"

typedef struct
{
	/* configuration metadata */
	bool		conninfo_provided;
	bool		connection_param_provided;
	bool		host_param_provided;
	bool		limit_provided;

	/* general configuration options */
	char		config_file[MAXPGPATH];
	bool		force;
	char		pg_bindir[MAXLEN]; /* overrides setting in repmgr.conf */

	/* logging options */
	char		loglevel[MAXLEN];  /* overrides setting in repmgr.conf */
	bool		log_to_file;
	bool		terse;
	bool		verbose;

	/* connection options */
	char		superuser[MAXLEN];

	/* node options */
	int			node_id;
	char		node_name[MAXLEN];
	char		data_dir[MAXPGPATH];

	/* event options */
	char		event[MAXLEN];
	int			limit;
	bool		all;

}	t_runtime_options;

/* global configuration structures */
extern t_runtime_options runtime_options;
extern t_configuration_options config_file_options;


extern bool	config_file_required;
extern char	 pg_bindir[MAXLEN];

extern char	 repmgr_slot_name[MAXLEN];
extern char *repmgr_slot_name_ptr;

extern t_node_info target_node_info;


extern int check_server_version(PGconn *conn, char *server_type, bool exit_on_error, char *server_version_string);
extern bool create_repmgr_extension(PGconn *conn);

#endif
