/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2006-2010  Nokia Corporation
 *  Copyright (C) 2004-2010  Marcel Holtmann <marcel@holtmann.org>
 *  Copyright (C) 2007-2008  Fabien Chevalier <fabchevalier@free.fr>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gdbus.h>

#include "error.h"

/* Helper function - internal use only */
DBusHandlerResult error_common_reply(DBusConnection *conn, DBusMessage *msg,
					const char *name, const char *descr)
{
	DBusMessage *derr;

	if (!conn || !msg)
		return DBUS_HANDLER_RESULT_HANDLED;

	derr = dbus_message_new_error(msg, name, descr);
	if (!derr)
		return DBUS_HANDLER_RESULT_NEED_MEMORY;

	g_dbus_send_message(conn, derr);

	return DBUS_HANDLER_RESULT_HANDLED;
}

DBusMessage *btd_error_invalid_args(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".InvalidArguments",
					"Invalid arguments in method call");
}

DBusMessage *btd_error_busy(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".InProgress",
					"Operation already in progress");
}

DBusMessage *btd_error_already_exists(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".AlreadyExists",
					"Already Exists");
}

DBusMessage *btd_error_not_supported(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".NotSupported",
					"Operation is not supported");
}

DBusMessage *btd_error_not_connected(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".NotConnected",
					"Not Connected");
}

DBusMessage *btd_error_already_connected(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".AlreadyConnected",
					"Already Connected");
}

DBusMessage *btd_error_in_progress(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".InProgress",
					"In Progress");
}

DBusMessage *btd_error_not_available(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".NotAvailable",
					"Operation currently not available");
}

DBusMessage *btd_error_does_not_exist(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".DoesNotExist",
					"Does Not Exist");
}

DBusMessage *btd_error_not_authorized(DBusMessage *msg)
{
	return g_dbus_create_error(msg, ERROR_INTERFACE ".NotAuthorized",
					"Operation Not Authorized");
}
