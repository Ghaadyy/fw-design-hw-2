#include <stdint.h>
#include <stdio.h>

void get_font_info( uint16_t font, uint8_t *type,
                    uint8_t *size, uint8_t *bold,
                    uint8_t *italic) 
{
    *bold = (font >> 15) & 1; // to extract the first bit
    *italic = (font >> 14) & 1; // to extract the second bit
    *size = (font >> 8) & 0x3F;
    *type = font & 0xFF; // to extract the lower byte
}

int main() {
    uint16_t font = 0xFFFF;

    uint8_t type = 0, size = 0, italic = 0, bold = 0;

    get_font_info(font, &type, &size, &bold, &italic);

    printf("The font extracted contains the folliwng properties:\n");
    printf("Bold: %i\n", bold);
    printf("Italic: %i\n", italic);
    printf("Size: %i\n", size);
    printf("Type: %i\n", type);

    return 0;
}