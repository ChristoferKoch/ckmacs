#define CTRL(c) ((c) & 0x1f)

void die(const char *);
void disable_raw_mode();
void enable_raw_mode();
char read_key();
void process_input();
void refresh_screen();
void initialize_window();
