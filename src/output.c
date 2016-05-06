#include "output.h"

// functions ::
void
err_msg (const char * err) {
    char msg[128];
    sprintf (msg, "[%s-%s] ", T_RED, NOTHING);
    strncat (msg, err, 128-strlen(msg));

    fprintf (stderr, "%s ...\n", msg);
}

void
help (void) {
    usage (SW_NAME);
    printf ("./%s [OPTIONS]\n" \
            "OPTIONS:\n" \
            "\t-h, --help\tShows this help message.\n\n" \
            "\t-e\tsets encrypt flag\n" \
            "\t-d\tsets decrypt flag\n\n" \
            "\t-c/-v <key>\tsets cryptography type (key is optional)\n\n" \
            "\t-f <filepath>\tsets the file to be used\n" 
            "\t-s <stealthy type>\tsets the stealthy type to hide/unhide the message\n\n",
            SW_NAME);

    exit(0);
}

void
usage (const char * itself) {
   printf ("Usage: %s [-e -d -h] [-c -v] <key> [-m] <message> [-f] <filepath> -s <txt>\n", itself);
}

bool
to_file (const char * filepath, char * binMsg) {
    
    FILE * fp = fopen (filepath, "a+");
    size_t written = 0;
    if (fp == NULL) {
        printf ("Error writing encrypted message to te file: %s\n", filepath);
        return false;
    }

    written = fprintf (fp, "%s", binMsg);
    if (written < strlen (binMsg)) {
        err_msg ("writing to file");   
    }
    return true;
}

void
save_key (const char * key) {
    char dir[DIR_LEN];
    char * home = getenv (HOME_ENV);

    strlen (home) <= DIR_LEN ? strcpy (dir, home) : err_msg ("too large home path");
    if (strlen (dir) == 0)
        exit (1);

    strncat (dir, VIRGULINO_DIR, (DIR_LEN - strlen(dir)));
    struct stat st = {0};
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strncat (dir, KEY_FILE, (DIR_LEN - strlen(dir)));
    FILE * fp = fopen (dir, "a+");
    if (!fp) {
        err_msg ("opening the file");
        exit(1);
    }
    fprintf (fp, "%s", key);
    fclose (fp);
    fflush (fp);

    printf ("[%s+%s] Key saved on %s ...\n", T_BLUE, NOTHING, dir);

}