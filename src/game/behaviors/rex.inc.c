// rex.inc.c

//values to be changed
#define REX_MAX_DISTANCE    1200.0f
#define REX_SIZE            2.0f
#define REX_WALK_SPEED      8.0f
#define REX_RUN_SPEED       15.0f
#define REX_SPEED_RATE      0.5f
#define REX_TURN_SPEED      0x250

//self-defining values(don't touch!)
#define REX_SMALL_SIZE REX_SIZE / 2
#define REX_SHRINK_SIZE REX_SIZE / 20

static u8 sRexAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP,
};

static u8 sRexAttackHandlersHurt[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP,
};

static struct ObjectHitbox sRexHitbox = {
    /* interactType: */ INTERACT_BOUNCE_TOP,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 2,
    /* health: */ 1,
    /* numLootCoins: */ 2,
    /* radius: */ 60,
    /* height: */ 70,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 60,
};

void bhv_rex_init(void) {
	obj_set_hitbox(o, &sRexHitbox);
	cur_obj_scale(REX_SIZE);
	o->oRexCountdown = random_linear_offset(30, 60);
}

void rex_standing(void) {
	// add idle animation
	
	if (o->oDistanceToMario <= REX_MAX_DISTANCE) {
		o->oAction = REX_ACT_CHASING;
		o->oTimer = 0;
	}
	
	obj_forward_vel_approach(0.0f, -REX_SPEED_RATE);
	
	if (o->oTimer >= 80) {
		o->oAction = REX_ACT_WALKING;
		o->oRexCountdown = random_linear_offset(30, 60);
		o->oRexTargetYaw = o->oRexTargetYaw + 0x2000 * (s16) random_sign();
		o->oTimer = 0;
	}
}

void rex_walking(void) {
	cur_obj_rotate_yaw_toward(o->oRexTargetYaw, 0x200);
	
	obj_forward_vel_approach(REX_WALK_SPEED, REX_SPEED_RATE);
	
	if (o->oDistanceToMario <= REX_MAX_DISTANCE) {
		o->oAction = REX_ACT_CHASING;
		o->oTimer = 0;
	}
	
    if (o->oTimer >= o->oRexCountdown) {
        o->oAction = REX_ACT_STANDING;
		o->oTimer = 0;
    }
}

void rex_chasing(void) {
	if (o->oDistanceToMario > REX_MAX_DISTANCE) {
		o->oAction = REX_ACT_STANDING;
		o->oTimer = 0;
	}
	
	cur_obj_rotate_yaw_toward(o->oAngleToMario, REX_TURN_SPEED);
	obj_forward_vel_approach(REX_RUN_SPEED, REX_SPEED_RATE);
}

void rex_hurt(void) {
	o->header.gfx.scale[1] -= REX_SHRINK_SIZE;
	
	if (o->oTimer >= 10) {
		o->header.gfx.scale[1] = REX_SMALL_SIZE;
		o->oAction = REX_ACT_CHASING;
		o->oHealth--;
	}
}

void bhv_rex_loop(void) {
	obj_update_blinking(&o->oKoopaBlinkTimer, 20, 50, 4);
	cur_obj_update_floor_and_walls();
	obj_update_standard_actions(REX_SIZE);
	cur_obj_init_anim_and_check_if_end(7);
	
	switch (o->oAction) {
		case REX_ACT_STANDING:
			rex_standing();
			break;
		case REX_ACT_WALKING:
			rex_walking();
			break;
		case REX_ACT_CHASING:
			rex_chasing();
			break;
		case REX_ACT_HURT:
			rex_hurt();
			break;
	}
	
	cur_obj_move_standard(-78);
	
	if (o->oHealth != 0 || o->oAction == REX_ACT_HURT) {
		if (obj_handle_attacks(&sRexHitbox, o->oAction, sRexAttackHandlers)) {
			o->oAction = REX_ACT_HURT;
		}
	} else {
		obj_handle_attacks(&sRexHitbox, o->oAction, sRexAttackHandlersHurt);
	}
}

