#include "consts.h"
#include "types.h"
#include "stdbool.h"

// Cases have to be constant expressions, so this isn't defined as a function
#define EventID(confidantID, points) (100 * confidantID + points + 1)

// TODO
void EventIntro()
{
    return;
}

// TODO
void EventEnding(struct Data data)
{
    return;
};

// TODO
void EventConfidant(struct Confidant confidant)
{
    int eventID = EventID(confidant.id, confidant.points);
    switch (eventID)
    {
        case EventID(SOJIRO, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(SOJIRO, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(SOJIRO, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(SOJIRO, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(ANN, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(ANN, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(ANN, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(ANN, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(YUSUKE, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(YUSUKE, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(YUSUKE, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(YUSUKE, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(MAKOTO, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(MAKOTO, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(MAKOTO, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(MAKOTO, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(FUTABA, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(FUTABA, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(FUTABA, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(FUTABA, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(HARU, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(HARU, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(HARU, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(HARU, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(TAE, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(TAE, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(TAE, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(TAE, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(SADAYO, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(SADAYO, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(SADAYO, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(SADAYO, CONF_LV3):
            printf("Lv3 Event\n");
            break;

        case EventID(SUMIRE, UNLOCKABLE):
            printf("Unlock Event\n");
            break;
        case EventID(SUMIRE, CONF_LV1):
            printf("Lv1 Event\n");
            break;
        case EventID(SUMIRE, CONF_LV2):
            printf("Lv2 Event\n");
            break;
        case EventID(SUMIRE, CONF_LV3):
            printf("Lv3 Event\n");
            break;
    }
}
