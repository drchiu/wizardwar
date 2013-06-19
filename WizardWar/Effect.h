//
//  Effect.h
//  WizardWar
//
//  Created by Sean Hess on 6/11/13.
//  Copyright (c) 2013 The LAB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpellInteraction.h"
#import "Simulated.h"

#define EFFECT_INDEFINITE 0

@class Wizard;
@class Spell;

@interface Effect : NSObject
@property (nonatomic) BOOL active;
@property (nonatomic) BOOL disablesPlayer;
@property (nonatomic) BOOL cancelsOnCast;
@property (nonatomic) BOOL cancelsOnHit;
@property (nonatomic) NSTimeInterval delay; // how long it takes to active
@property (nonatomic) NSTimeInterval duration; // how long before it wears off?
@property (nonatomic) NSInteger startTick; // when it began operating.

-(void)start:(NSInteger)tick player:(Wizard*)player;
-(void)cancel:(Wizard*)player;
-(SpellInteraction*)interactPlayer:(Wizard*)player spell:(Spell*)spell currentTick:(NSInteger)currentTick;
-(SpellInteraction*)interactSpell:(Spell*)spell;
-(void)simulateTick:(NSInteger)currentTick interval:(NSTimeInterval)interval player:(Wizard*)player;

@end
