#include <gio/gio.h>

#include "notifications.h"
#include "gexception.h"
#include "gobjectmm.h"

using namespace notifications;

using GVariantUP = gunique_ptr<GVariant, g_variant_unref>;
using GBuilderUP = gunique_ptr<GVariantBuilder, g_variant_builder_unref>;

static const char* getIcon(const Message &message) {
  return message.urgency == CRITICAL ?
      "udpnotify-message-important" :
      "udpnotify-message";
}

static const char* getSummary(const Message &message) {
  return !message.title.empty() ?
      message.title.c_str() :
      "UDP Notification";
}

void NotificationService::notify(const Message &message) {
  GException error;

  gobject_ptr<GDBusConnection> conn = g_bus_get_sync(
      G_BUS_TYPE_SESSION,
      NULL,
      error.get());

  if (error)
    throw error;

  GBuilderUP hints = g_variant_builder_new(G_VARIANT_TYPE("a{sv}"));
  g_variant_builder_add(
      hints.get(),
      "{sv}",
      "urgency",
      g_variant_new_byte(message.urgency));

  /* no need to free this as it is "floating" */
  GVariant *parameters = g_variant_new(
      "(susssasa{sv}i)",
      "udpnotify", /* app_name */
      0, /* replaces_id */
      getIcon(message), /* app_icon */
      getSummary(message), /* summary */
      message.body.c_str(), /* body */
      NULL, /* actions */
      hints.get(), /* hints */
      0); /* expire_timeout */

  GVariantUP res = g_dbus_connection_call_sync(
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
