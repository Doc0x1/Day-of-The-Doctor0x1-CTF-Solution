#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

unsigned char encrypted_flag[] = {
    0x81, 0x76, 0x76, 0x84, 0x6e, 0x66, 0x57, 0x2f, 0x7c, 0x82, 0x47, 0x77,
    0x78, 0x61, 0x52, 0x7a, 0x54, 0x54, 0x7e, 0x64, 0x4e, 0x30, 0x49, 0x45,
    0x82, 0x32, 0x68, 0x60, 0x5c, 0x2b, 0x6c
};
size_t encrypted_flag_len = sizeof(encrypted_flag);

char *generate_stage2_key() {
    const char *quote = "Never be cruel. Never be cowardly. Hate is always foolish. Love is always wise. Always try to be nice, but never fail to be kind.";
    size_t len = strlen(quote);
    char *simplified_key = malloc(len + 1);
    if (!simplified_key) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (quote[i] >= 'A' && quote[i] <= 'Z') {
            simplified_key[j++] = quote[i];
        }
    }
    simplified_key[j] = '\0';
    return simplified_key;
}

void clear_screen() {
  system("clear");
}

void typing_effect(const char *message, int delay_ms) {
  for (const char *c = message; *c != '\0'; c++) {
    putchar(*c);
    fflush(stdout);
    usleep(delay_ms * 1000);
  }
}

void pause_for_dramatic_effect(int seconds) {
  sleep(seconds);
}

void show_ascii_banner() {
    typing_effect(
        "\n"
        "  _____ _           ______                     __   _____ _           ______           _             _____       __  \n", 1);
    typing_effect(
        " |_   _| |          |  _  \\                   / _| |_   _| |          |  _  \\         | |           |  _  |     /  | \n", 1);
    typing_effect(
        "   | | | |__   ___  | | | |__ _ _   _    ___ | |_    | | | |__   ___  | | | |___   ___| |_ ___  _ __| |/' |_  __`| | \n", 1);
    typing_effect(
        "   | | | '_ \\ / _ \\ | | | / _` | | | |  / _ \\|  _|   | | | '_ \\ / _ \\ | | | / _ \\ / __| __/ _ \\| '__|  /| \\ \\/ / | | \n", 1);
    typing_effect(
        "   | | | | | |  __/ | |/ / (_| | |_| | | (_) | |     | | | | | |  __/ | |/ / (_) | (__| || (_) | |  \\ |_/ />  < _| |_ \n", 1);
    typing_effect(
        "   \\_/ |_| |_|\\___| |___/ \\__,_|\\__, |  \\___/|_|     \\_/ |_| |_|\\___| |___/ \\___/ \\___|\\__\\___/|_|   \\___//_/\\_\\\\___/\n", 1);
    typing_effect(
        "                               __/ |                                                                                \n", 1);
    typing_effect(
        "                              |___/                                                                                 \n\n", 1);
    pause_for_dramatic_effect(1);
}

void show_intro() {
    clear_screen();
    show_ascii_banner();

    typing_effect("Welcome to \"The Day of The Doctor0x1\" Challenge! Made by yours truly, The Doctor.", 40);
    pause_for_dramatic_effect(1);

    typing_effect(" (Copyright 2024, Hack Nexus. All Rights Reserved.)", 40);
    pause_for_dramatic_effect(2);

    clear_screen();

    typing_effect("Before we get down to business, here's a quote I find fitting for a challenge like this.", 30);
    pause_for_dramatic_effect(3);

    clear_screen();

    typing_effect("\"Never be cruel. Never be cowardly.", 60);
    pause_for_dramatic_effect(1);
    typing_effect(" Hate is always foolish. Love is always wise.\"", 60);
    pause_for_dramatic_effect(1);
    typing_effect("\n\"Always try to be nice, but never fail to be kind.\"", 60);
    pause_for_dramatic_effect(4);
    clear_screen();
}

char *ask_question_for_key() {
    char answer[20];
    printf("Which of these two is better and more helpful for web developers to work with:\n");
    printf("TypeScript? Or JavaScript?\n\n");
    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);

    // Convert input to lowercase for case-insensitive comparison
    for (int i = 0; answer[i]; i++) {
        answer[i] = tolower(answer[i]);
    }

    if (strstr(answer, "typescript")) {
        typing_effect("\nWell done. TypeScript provides an infinitely better development experience than JavaScript for large projects.\n", 40);
        pause_for_dramatic_effect(1);
        typing_effect("\nNot sure what this is for but: \"TSX\"\n", 40);
        pause_for_dramatic_effect(1);
        printf("\nPress Enter to continue...");
        getchar();

        char *key = malloc(4);
        if (!key) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }
        strcpy(key, "TSX");
        return key;
    } else {
        printf("\nSure, it's JavaScript. I know how much you love running your code over and over in the terminal until it works.\n");
        return NULL;
    }
}

void show_flag_obfuscated() {
    char *stage2_key = generate_stage2_key();
    char intermediate[encrypted_flag_len + 1];
    char parts[encrypted_flag_len][4];

    typing_effect("Okay girl, tell me, what was the flag again?", 40);
    pause_for_dramatic_effect(2);
    clear_screen();

    // Reverse Stage 2 encryption and prepare obfuscated flag display
    for (size_t i = 0; i < encrypted_flag_len; i++) {
        intermediate[i] = ((encrypted_flag[i] - 5) ^ stage2_key[i % strlen(stage2_key)]) & 0xFF;
        snprintf(parts[i], sizeof(parts[i]), "%02x", encrypted_flag[i]);
    }
    intermediate[encrypted_flag_len] = '\0';

    typing_effect("Error. Critical Error. Systems malfunctioning.\n\n", 60);
    typing_effect("P riii nt ingg g g Fl a a ag...\n\n", 100);

    for (size_t i = 0; i < encrypted_flag_len; i++) {
        typing_effect(parts[i], 100);

        if ((i + 1) % 3 == 0) {
            typing_effect(" ", 50);
        }

        if ((i + 1) % 4 == 0) {
            pause_for_dramatic_effect(0.5);
        }
    }

    typing_effect("\n\nHm, that's strange. It doesn't look quite right, does it?", 40);

    memset(intermediate, 0, sizeof(intermediate));
    free(stage2_key);
}

void wait_for_exit() {
    printf("\n\nPress Enter to exit...");
    getchar();
}

int main() {
  show_intro();

  typing_effect("Right, now that that's out the way...\n", 30);
  pause_for_dramatic_effect(1);
  typing_effect("\nLet the games begin!", 30);
  pause_for_dramatic_effect(2);
  clear_screen();

  typing_effect("I suppose it wouldn't be a CTF without some question to answer.\n", 50);
  pause_for_dramatic_effect(1);
  typing_effect("\nSo, here you go, difficult question incoming:\n", 50);
  pause_for_dramatic_effect(1);

  char *stage1_key = ask_question_for_key();
  if (!stage1_key) {
    printf("Thinking JS is better than TS? GLHF buddy. Later!\n");
    return 0;
  }

  clear_screen();

  typing_effect("Nice job getting that one right, we've got a real Einstein taking this challenge on.\n\nNow between you and me, I'm just gonna show you the flag so we don't have to waste any more time.", 50);
  pause_for_dramatic_effect(1.5);

  clear_screen();

  show_flag_obfuscated();

  pause_for_dramatic_effect(2);
  typing_effect("\n\nI could've sworn the flag was \"flag{th1sIsTheFlag}\" or something like that.", 30);
  pause_for_dramatic_effect(2);
  typing_effect("\n\nThe TARDIS definitely gave us the flag. It just gave it to us... In a very useless way.", 30);
  pause_for_dramatic_effect(1);
  typing_effect("\n\nAt any rate it should be simple to figure out why it looks the way it does. Best of luck! - Doc & Robot", 30);
  
  wait_for_exit();
  
  return 0;
}
