#ifndef POSITION_HPP_
#define POSITION_HPP_

#define X 800
#define Y 600

///MENU
//Taille button
/*JOUER*/
#define JOUER_DIM_X 161
#define JOUER_DIM_Y 73

/*QUITTER*/
#define QUITTER_DIM_X 214
#define QUITTER_DIM_Y 71

//Position button
/*JOUER*/
#define JOUER_POS_X 55
#define JOUER_POS_Y 254

/*QUITTER*/
#define QUITTER_POS_X 22
#define QUITTER_POS_Y 325

///PLAY

#define CADRE_DIM_X 96
#define CADRE_DIM_Y 64

#define CADRE_POS_X 293
#define CADRE_POS_Y 228

//Taille arrow
#define ARROW_DIM_X 100
#define ARROW_DIM_Y 100

//Taille porte
#define DOOR_DIM_X 238
#define DOOR_DIM_Y 411

//Position porte
#define DOOR_POS_X 264
#define DOOR_POS_Y 188

//Position arrow
/*Arrow up*/
#define ARROW_UP_POS_X ((DOOR_DIM_X/2)+DOOR_POS_X)-(ARROW_DIM_X/2)
#define ARROW_UP_POS_Y DOOR_POS_Y+(DOOR_DIM_Y/2)

/*Arrow down*/
#define ARROW_DOWN_POS_X (X/2)-ARROW_DIM_X
#define ARROW_DOWN_POS_Y Y-ARROW_DIM_Y

/*Arrow left*/
#define ARROW_LEFT_POS_X 0
#define ARROW_LEFT_POS_Y (Y/2)-(ARROW_DIM_Y/2)

/*Arrow right*/
#define ARROW_RIGHT_POS_X X-ARROW_DIM_X
#define ARROW_RIGHT_POS_Y (Y/2)-(ARROW_DIM_Y/2)

#endif /* !POSITION_HPP_ */
