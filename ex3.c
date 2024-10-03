#include <stdint.h>
#include <stdio.h>

typedef union font {
    struct info {
        uint8_t bold : 1;
        uint8_t italic : 1;
        uint8_t size : 6;
        uint8_t type : 8;
    } info;

    uint16_t font;
} font;
 
void get_font_info(union font *f) {
    printf("The font extracted contains the folliwng properties:\n");
    printf("Bold: %i\n", f->info.bold);
    printf("Italic: %i\n", f->info.italic);
    printf("Size: %i\n", f->info.size);
    printf("Type: %i\n", f->info.type);
}

int main() {
    union font f;
    f.font = 0xFFFF;

    get_font_info(&f);
}