#include <gio/gio.h>

#include "notifications.h"
#include "gexception.h"
#include "gobjectmm.h"

void NotificationService::notify(const Message &message) {
  GException error;

  gobject_ptr<GDBusConnection> conn = g_bus_get_sync(
      G_BUS_TYPE_SESSION,
      NULL,
      error.get());

  if (error)
    throw error;

  /* no need to free this as it is "floating" */
  GVariant *parameters = g_variant_new(
      "(susssasa{sv}i)",
      "udpnotify", /* app_name */
      0, /* replaces_id */
      "", /* app_icon */
      "UDP Notification", /* summary */
      message.body.c_str(), /* body */
      NULL, /* actions */
      NULL, /* hints */
      0); /* expire_timeout */

  g_dbus_connection_call_sync(
      conn.get(),
      "org.freedesktop.Notifications",
      "/org/freedesktop/Notifications",
      "org.freedesktop.Notifications",
      "Notify",
      parameters,
      NULL, // G_VARIANT_TYPE_UINT32,
      G_DBUS_CALL_FLAGS_NONE,
      -1,
      NULL,
      error.get());

  if (error)
    throw error;
}
