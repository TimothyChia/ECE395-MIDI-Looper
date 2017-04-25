#define FS_PORT LPC_GPIO1->DATA
#define FS_DIR LPC_GPIO1->DIR

//Active Low
#define FSB_0 (1UL<<0)
#define FSB_1 (1UL<<1)
#define FSB_2 (1UL<<2)
//Active High
#define FS_SHIFT (1UL<<6)
#define FS_SHIFT_VAL 8
// 0 is currently reserved for no input.
#define FS_NEXT 1
#define FS_PREV 2
#define FS_R0 3
#define FS_R1 4
#define FS_R2 5
#define FS_R3 6
