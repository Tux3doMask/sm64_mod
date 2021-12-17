// boom_boom.inc.c

#define BOOM_BOOM_MAX_DISTANCE 1200.0f
#define BOOM_BOOM_WALK_SPEED 8.0f
#define BOOM_BOOM_SPEED_RATE 0.25f
#define BOOM_BOOM_SHELL_SPEED 30.0f

static u8 sBoomBoomAttackHandlers[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP,
};

static u8 sBoomBoomAttackHandlersAttacked[] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_NOP,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_NOP,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_NOP,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_NOP,
};

static struct ObjectHitbox sBoomBoomHitbox = {
    /* interactType: */ INTERACT_BOUNCE_TOP,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 2,
    /* numLootCoins: */ -1,
    /* radius: */ 60,
    /* height: */ 70,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 60,
};

void bhv_boom_boom_init(void) {
	cur_obj_scale(2.0f);
	obj_set_hitbox(o, &sBoomBoomHitbox);
}

void boom_boom_act_stand(void) {
	cur_obj_set_model(MODEL_KOOPA_WITH_SHELL);
	
	// add think animation
	
	if (o->oDistanceToMario <= BOOM_BOOM_MAX_DISTANCE) {
		o->oAction = BOOM_BOOM_ACT_IDLE;
		o->oTimer = 0;
	}
	
	if (o->oTimer >= 80) {
		o->oAction = BOOM_BOOM_ACT_WALK;
		o->oBoomBoomCountdown = random_linear_offset(30, 60);
		o->oTimer = 0;
	}
}

void boom_boom_act_walk(void) {
	if (o->oTimer == 0) {
		o->oBoomBoomTargetYaw = o->oBoomBoomTargetYaw + 0x2000 * (s16) random_sign();
		cur_obj_rotate_yaw_toward(o->oBoomBoomTargetYaw, 0x200);
	}
	
	obj_forward_vel_approach(BOOM_BOOM_WALK_SPEED, BOOM_BOOM_SPEED_RATE);
	
	if (o->oDistanceToMario <= BOOM_BOOM_MAX_DISTANCE) {
		o->oAction = BOOM_BOOM_ACT_IDLE;
		o->oTimer = 0;
	}
	
	if (o->oBoomBoomCountdown != 0) {
        o->oBoomBoomCountdown--;
    } else {
        o->oAction = BOOM_BOOM_ACT_STAND;
    }
}

void boom_boom_act_shell(void) {
	//add spin anim for in shell
	
	cur_obj_set_model(MODEL_KOOPA_SHELL);
	
	cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x500);
	
	o->oForwardVel = BOOM_BOOM_SHELL_SPEED;
	
	if (o->oTimer >= 200) {
		o->oTimer = 0;
		o->oAction = BOOM_BOOM_ACT_IDLE;
	}
	
	if (o->oDistanceToMario >= BOOM_BOOM_MAX_DISTANCE) {
		o->oAction = BOOM_BOOM_ACT_STAND;
		o->oTimer = 0;
	}
}

void boom_boom_act_idle(void) {
	cur_obj_set_model(MODEL_KOOPA_WITH_SHELL);
	
	//add idle anim here
	
	if (o->oTimer >= 50) {
		o->oAction = 0;
		o->oAction = BOOM_BOOM_ACT_SPIN;
	}
	
	o->oForwardVel = 0.0f;
}

void boom_boom_act_spin(void) {
	
	// add spin anim here
	
	cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x250);
	o->oForwardVel = 20.0f;
	
	if (o->oTimer == 200) {
		o->oAction = BOOM_BOOM_ACT_DIZZY;
		o->oTimer = 0;
	}
}

void boom_boom_act_dizzy(void) {
	
	//add animation for dizzy here
	
	o->oForwardVel = 0.0f;
	
	if (o->oTimer >= 200) {
		o->oAction = BOOM_BOOM_ACT_SPIN;
		o->oTimer = 0;
	}
}

void boom_boom_act_attacked(void) {
	//knocked over anim
	cur_obj_init_anim_extend(2);
	
	o->oForwardVel = 0.0f;
	
	if (o->oTimer == 90) {
		o->oTimer = 0;
		o->oAction = BOOM_BOOM_ACT_SHELL;
	}
}

void bhv_boom_boom_loop(void) {
	cur_obj_update_floor_and_walls();
	obj_update_standard_actions(2.0f);
	obj_update_blinking(&o->oKoopaBlinkTimer, 20, 50, 4);
	
	switch (o->oAction) {
		case BOOM_BOOM_ACT_STAND:
			boom_boom_act_stand();
			break;
		case BOOM_BOOM_ACT_WALK:
			boom_boom_act_walk();
			break;
		case BOOM_BOOM_ACT_SHELL:
			boom_boom_act_shell();
			break;
		case BOOM_BOOM_ACT_IDLE:
			boom_boom_act_idle();
			break;
		case BOOM_BOOM_ACT_SPIN:
			boom_boom_act_spin();
			break;
		case BOOM_BOOM_ACT_DIZZY:
			boom_boom_act_dizzy();
			break;
		case BOOM_BOOM_ACT_ATTACKED:
			boom_boom_act_attacked();
			break;
	}
	
	cur_obj_move_standard(-78);
	
	if (o->oAction != BOOM_BOOM_ACT_ATTACKED && o->oAction != BOOM_BOOM_ACT_SHELL) {
		
		if (o->oHealth == 0) {
			obj_handle_attacks(&sBoomBoomHitbox, o->oAction, sBoomBoomAttackHandlers);
		} else if (obj_handle_attacks(&sBoomBoomHitbox, o->oAction, sBoomBoomAttackHandlersAttacked)) {
			o->oTimer = 0;
			o->oHealth--;
			o->oAction = BOOM_BOOM_ACT_ATTACKED;
		}
	} else {
		obj_handle_attacks(&sBoomBoomHitbox, o->oAction, sBoomBoomAttackHandlersAttacked);
	}
	
}