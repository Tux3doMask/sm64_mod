// magikoopa.inc.c

#define MAGIKOOPA_MAX_CHARGE       80
#define MAGIKOOPA_MAX_DISTANCE     1200.0f
#define MAGIKOOPA_STOP_DISTANCE    800.0f
#define MAGIKOOPA_MIN_DISTANCE     500.0f
#define MAGIKOOPA_SPEED            10.0f
#define MAGIKOOPA_SPEED_RATE       0.25f
#define MAGIKOOPA_WALK_SPEED       8.0f
#define MAGIKOOPA_SCALE            1.5f

static u8 sMagikoopaAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

static struct ObjectHitbox sMagikoopaHitbox = {
    /* interactType: */ INTERACT_BOUNCE_TOP,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ -1,
    /* radius: */ 130,
    /* height: */ 70,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 60,
};

void bhv_magikoopa_init(void) {
	o->oAction = MAGIKOOPA_ACT_STAND;
	obj_set_hitbox(o, &sMagikoopaHitbox);
	o->oCharge = 0;
	o->oMagikoopaCountdown = random_linear_offset(30, 100);
	cur_obj_scale(MAGIKOOPA_SCALE);
}

//too far to see mario, stand around waiting
void magikoopa_act_stand(void) {
	if (cur_obj_init_anim_and_check_if_end(7)) {
		o->oAction = MAGIKOOPA_ACT_WALK;
		o->oKoopaTargetYaw = o->oKoopaTargetYaw + 0x2000 * (s16) random_sign();
	}
	
	obj_forward_vel_approach(0.0f, MAGIKOOPA_SPEED_RATE);
	
	if (o->oDistanceToMario <= MAGIKOOPA_MAX_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_RUN_TO_MARIO;
	}
}

// walking around to make magikoopa seem alive
void magikoopa_act_walk(void) {
    cur_obj_init_animation_with_sound(9);
	obj_forward_vel_approach(MAGIKOOPA_WALK_SPEED, MAGIKOOPA_SPEED_RATE);
	cur_obj_rotate_yaw_toward(o->oKoopaTargetYaw, 0x200);
	
    if (o->oMagikoopaCountdown != 0) {
        o->oMagikoopaCountdown--;
    } else if (cur_obj_check_if_near_animation_end()) {
        o->oAction = MAGIKOOPA_ACT_STAND;
		o->oMagikoopaCountdown = random_linear_offset(30, 100);
    }
	
	if (o->oDistanceToMario <= MAGIKOOPA_MAX_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_RUN_TO_MARIO;
	}
}

//too far but can see mario, need to get closer
void magikoopa_act_run_to_mario(void) {
	cur_obj_init_animation_with_sound(9);
	
	if (o->oDistanceToMario >= MAGIKOOPA_MAX_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_STAND;
	}else if (o->oDistanceToMario <= MAGIKOOPA_STOP_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_ATTACK_MARIO;
	}
	cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x300);
	obj_forward_vel_approach(MAGIKOOPA_SPEED, MAGIKOOPA_SPEED_RATE);
}

//too close to mario, run away
void magikoopa_act_run_from_mario(void) {
	
	cur_obj_init_animation_with_sound(9);
	
	if (o->oDistanceToMario >= MAGIKOOPA_MIN_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_ATTACK_MARIO;
	}
	cur_obj_rotate_yaw_toward(o->oAngleToMario + 0x8000, 0x300);
	o->oForwardVel = MAGIKOOPA_SPEED;
	obj_forward_vel_approach(MAGIKOOPA_SPEED, MAGIKOOPA_SPEED_RATE);
}

//attack mario
void magikoopa_act_attack_mario(void) {
	cur_obj_init_animation(7);
	if (o->oDistanceToMario >= MAGIKOOPA_STOP_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_RUN_TO_MARIO;
	}
	if (o->oDistanceToMario <= MAGIKOOPA_MIN_DISTANCE) {
		o->oAction = MAGIKOOPA_ACT_RUN_FROM_MARIO;
	}
	obj_forward_vel_approach(0.0f, -MAGIKOOPA_SPEED_RATE);
	cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x500);
	o->oCharge ++;
	if (o->oCharge >= MAGIKOOPA_MAX_CHARGE) {
		cur_obj_play_sound_2(SOUND_OBJ_FLAME_BLOWN);
		//spawn_object(o, MODEL_MAGIC, bhvMagic);
		o->oCharge = 0;
	}
}

void bhv_magikoopa_update(void) {
	cur_obj_update_floor_and_walls();
	obj_update_standard_actions(MAGIKOOPA_SCALE);
	
	switch (o->oAction) {
		case MAGIKOOPA_ACT_STAND:
			magikoopa_act_stand();
			break;
		case MAGIKOOPA_ACT_WALK:
			magikoopa_act_walk();
			break;
		case MAGIKOOPA_ACT_RUN_TO_MARIO:
			magikoopa_act_run_to_mario();
			break;
		case MAGIKOOPA_ACT_RUN_FROM_MARIO:
			magikoopa_act_run_from_mario();
			break;
		case MAGIKOOPA_ACT_ATTACK_MARIO:
			magikoopa_act_attack_mario();
			break;
	}
	
	obj_handle_attacks(&sMagikoopaHitbox, o->oAction, sMagikoopaAttackHandlers);
	
	cur_obj_move_standard(-78);
	
}

