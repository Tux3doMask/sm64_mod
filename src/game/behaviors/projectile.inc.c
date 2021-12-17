// projectile.inc.c

// code for projectiles for magikoopa, hammer bro and fire bro

static struct ObjectHitbox sProjectileHitbox = {
    /* interactType:      */ INTERACT_MR_BLIZZARD,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 40,
    /* height:            */ 40,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 40,
};

void bhv_projectile_init(void) {
	// set up damage
	obj_set_hitbox(o, &sProjectileHitbox);
}

/* void bhv_hammer_loop(void) {
	cur_obj_update_floor_and_walls();
	
	if (o->oTimer == 0) {
		// on spawn set movement
		o->oVelY = 40.0f;
		o->oForwardVel = 20.0f;
	}
	
	if (o->oTimer == 300 || o->oMoveFlags & OBJ_MOVE_LANDED) {
        // if hit wall or time up (lag prevention) spawn particle and delete
		spawn_mist_particles();
		mark_obj_for_deletion(o);
	}
	
	cur_obj_move_standard(-78);
} */

static struct SpawnParticlesInfo sMagicParticles = {
    /* behParam:        */ 2,
    /* count:           */ 1,
    /* model:           */ MODEL_SPARKLES,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 0,
    /* forwardVelRange: */ 0,
    /* velYBase:        */ 0,
    /* velYRange:       */ 0,
    /* gravity:         */ 0,
    /* dragStrength:    */ 0,
    /* sizeBase:        */ 30.0f,
    /* sizeRange:       */ 10.0f,
};

void bhv_magic_loop(void) {
	//updates and stuff
	if (o->oTimer % 3 == 0) {
		sMagicParticles.offsetY = random_u16() % 50;
		cur_obj_spawn_particles(&sMagicParticles);
	}
	
	cur_obj_update_floor_and_walls();
	cur_obj_scale(0.25f);
	cur_obj_init_animation(0);
	
	if (o->oTimer == 0) {
		switch (random_u16() % 3) {
			case 0:
				// fire type
				o->oInteractType = INTERACT_FLAME;
				break;
			case 1:
				// electric type
				o->oInteractType = INTERACT_SHOCK;
				o->oDamageOrCoinValue = 3;
				break;
			case 2:
				// wind type
				o->oInteractType = INTERACT_STRONG_WIND;
				break;
		}
	}
	
	cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x300);
	o->oForwardVel = 19.0f;
	
	if (o->oTimer == 200 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED) {
        // if hit wall or mario, or time up spawn particle and delete
		spawn_mist_particles();
		obj_mark_for_deletion(o);
	}
}
