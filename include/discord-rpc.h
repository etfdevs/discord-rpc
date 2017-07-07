#pragma once
#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct {
    const char* state;
    const char* details;
    int64_t startTimestamp;
    int64_t endTimestamp;
    const char* largeImageKey;
    const char* largeImageText;
    const char* smallImageKey;
    const char* smallImageText;
    const char* partyId;
    int partySize;
    int partyMax;
    const char* matchSecret;
    const char* joinSecret;
    const char* spectateSecret;
    int8_t instance;
} DiscordRichPresence;

typedef struct {
    void (*ready)();
    void (*disconnected)();
    void (*wantsPresence)();
    void (*joinGame)(const char* joinSecret);
    void (*spectateGame)(const char* spectateSecret);
} DiscordEventHandlers;

void Discord_Initialize(const char* applicationId, DiscordEventHandlers* handlers);
void Discord_Shutdown();
void Discord_UpdatePresence(const DiscordRichPresence* presence);

/* checks for incoming messages, dispatches callbacks */
void Discord_Update();

#ifdef  __cplusplus
} /* extern "C" */
#endif
