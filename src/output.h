#ifndef _OUTPUT_H_
#define _OUTPUT_H_

// prototypes ::
void err_msg (const char * err);

void help (void);
void usage (const char * itself);

bool to_file (const char * filepath, char * binmsg);
void save_key (const char * key);



#endif /* _OUTPUT_H_ */

