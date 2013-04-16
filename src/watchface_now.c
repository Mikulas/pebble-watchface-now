#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

#define MY_UUID { 0xDA, 0x61, 0x26, 0x49, 0xCA, 0x3C, 0x46, 0xF1, 0x83, 0x89, 0x8E, 0x77, 0xE5, 0xC6, 0x96, 0xDD }

PBL_APP_INFO(MY_UUID,
             "Now", "Mikulas",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;

BmpContainer background_image;

void handle_init(AppContextRef ctx) {
  (void)ctx;
  static char text[] = "NOW";

  window_init(&window, "Now");
  window_stack_push(&window, true /* Animated */);

  resource_init_current_app(&APP_RESOURCES);

  bmp_init_container(RESOURCE_ID_IMAGE_BACKGROUND, &background_image);
  layer_add_child(&window.layer, &background_image.layer.layer);
}

void handle_deinit(AppContextRef ctx) {
  (void)ctx;

  bmp_deinit_container(&background_image);
}

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,
    .deinit_handler = &handle_deinit
  };
  app_event_loop(params, &handlers);
}
