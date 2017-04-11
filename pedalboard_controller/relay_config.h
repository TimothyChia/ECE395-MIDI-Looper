#define REL_PORT LPC_GPIO1->DATA
#define REL_DIR LPC_GPIO1->DIR

#define SEL_0 (1UL<<8)
#define SEL_1 (1UL<<9)
/*Enable bits for relay are active low. */
#define REL_RES (1UL<<5)
#define REL_SET (1UL<<4)

//#define UP (1UL<<5)
//#define DOWN (1UL<<6)
