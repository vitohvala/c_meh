#include <stdio.h>
#include <assert.h>

const short FLAG_ON          = 1 << 0; // 1  (0x01)
const short FLAG_MOVEMENT    = 1 << 1; // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04)
const short FLAG_ALIVE       = 1 << 3; // 8  (0x08)
const short FLAG_BROKEN      = 1 << 4; // 16 (0x16)
const short FLAG_EDIBLE      = 1 << 5; // 32 (0x20)

int main(){
    short atr = 0;

    /* Set the attributes ON, TRANSPARENT, and BROKEN */
    atr |= (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN);
    assert(atr == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));

    /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
    atr &= ~(FLAG_TRANSPARENT | FLAG_BROKEN);
    atr |= (FLAG_ALIVE);

    assert(atr == (FLAG_ALIVE | FLAG_ON));

    /* Check if the ALIVE flag is set */
    assert(atr & FLAG_ALIVE);

    /* Check if the BROKEN flag is not set */
    assert(!(atr & FLAG_BROKEN));

    /* Modify so only the EDIBLE attribute is set */
    atr = FLAG_EDIBLE;

    assert(atr == FLAG_EDIBLE);

    printf("Done\n");
    return 0;
}
