#include "src/game/envfx_snow.h"

const GeoLayout magic_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 45, 0, magic_Base_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -45, 194, magic_Square_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -45, -169, magic_Triangle_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, magic_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
