Lights1 magic_circle_lights = gdSPDefLights1(
	0x0, 0x5E, 0x7F,
	0x0, 0xBD, 0xFE, 0x28, 0x28, 0x28);

Lights1 magic_square_lights = gdSPDefLights1(
	0x12, 0x68, 0x0,
	0x25, 0xD1, 0x0, 0x28, 0x28, 0x28);

Lights1 magic_triangle_lights = gdSPDefLights1(
	0x7F, 0x19, 0x15,
	0xFE, 0x32, 0x2B, 0x28, 0x28, 0x28);

Vtx magic_Base_mesh_layer_1_vtx_0[22] = {
	{{{0, 278, -88},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 204, -84},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 204, -115},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 258, -64},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 317, -20},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 286, -15},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 304, 58},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 276, 42},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 243, 109},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 232, 79},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 164, 109},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 175, 79},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 131, 42},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 104, 58},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 121, -15},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 90, -20},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 129, -88},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 121, -15},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 90, -20},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 150, -64},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 204, -115},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 204, -84},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx magic_Base_mesh_layer_1_tri_0[] = {
	gsSPVertex(magic_Base_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(3, 0, 4, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSP1Triangle(7, 5, 6, 0),
	gsSP1Triangle(6, 8, 7, 0),
	gsSP1Triangle(9, 7, 8, 0),
	gsSP1Triangle(10, 9, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 11, 10, 0),
	gsSP1Triangle(13, 12, 10, 0),
	gsSP1Triangle(13, 14, 12, 0),
	gsSP1Triangle(13, 15, 14, 0),
	gsSPVertex(magic_Base_mesh_layer_1_vtx_0 + 16, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx magic_Square_mesh_layer_1_vtx_0[11] = {
	{{{0, -100, -96},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -71, 75},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -100, 104},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 100, 104},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 71, 75},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 71, -68},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 100, -96},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 71, -68},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -71, -68},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -100, -96},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -71, 75},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx magic_Square_mesh_layer_1_tri_0[] = {
	gsSPVertex(magic_Square_mesh_layer_1_vtx_0 + 0, 11, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(4, 3, 1, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(3, 5, 6, 0),
	gsSP1Triangle(5, 0, 6, 0),
	gsSP1Triangle(7, 8, 9, 0),
	gsSP1Triangle(10, 9, 8, 0),
	gsSPEndDisplayList(),
};

Vtx magic_Triangle_mesh_layer_1_vtx_0[9] = {
	{{{0, -69, -78},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 136, -2},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 81, -2},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 81, -2},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 136, -2},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -69, 73},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -93, 113},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -93, -117},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, -69, -78},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx magic_Triangle_mesh_layer_1_tri_0[] = {
	gsSPVertex(magic_Triangle_mesh_layer_1_vtx_0 + 0, 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 5, 4, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(8, 5, 7, 0),
	gsSP1Triangle(8, 7, 4, 0),
	gsSPEndDisplayList(),
};


Gfx mat_magic_circle[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(magic_circle_lights),
	gsSPEndDisplayList(),
};

Gfx mat_magic_square[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(magic_square_lights),
	gsSPEndDisplayList(),
};

Gfx mat_magic_triangle[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(magic_triangle_lights),
	gsSPEndDisplayList(),
};

Gfx magic_Base_mesh_layer_1[] = {
	gsSPDisplayList(mat_magic_circle),
	gsSPDisplayList(magic_Base_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx magic_Square_mesh_layer_1[] = {
	gsSPDisplayList(mat_magic_square),
	gsSPDisplayList(magic_Square_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx magic_Triangle_mesh_layer_1[] = {
	gsSPDisplayList(mat_magic_triangle),
	gsSPDisplayList(magic_Triangle_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx magic_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

